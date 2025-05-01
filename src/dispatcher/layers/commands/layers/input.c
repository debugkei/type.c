#include"input.h"

#include"graphics/graphics.h"
#include"execute/execute.h"

static int isCapturingCommandInput = 0;

#define COMMANDCAPTURETOGGLE ':'
#define STOPCOMMANDCAPTURE (char)27 //Escape
#define SUBMITCOMMAND (char)10 //Enter
#define DECREASECAPTURE (char)7 //Backspace

#define MAXCOMMANDLENGTH 128
static char command[MAXCOMMANDLENGTH];
static int currentCommandWriteIndex = 0;

static void _ExitCommands(){
  isCapturingCommandInput = 0;
}

int HandleStart(void* pChr){
  char chr = *(char*)pChr;

  if (chr == COMMANDCAPTURETOGGLE && !isCapturingCommandInput){
    isCapturingCommandInput = 1;
    currentCommandWriteIndex = 0;

    return 1;
  }

  return 0;
}

int HandleExecute(void* pChr){
  char chr = *(char*)pChr;

  if (chr == SUBMITCOMMAND && isCapturingCommandInput){
    isCapturingCommandInput = 0;
    int didExecute = Execute(command, currentCommandWriteIndex);
    return didExecute;
  }

  return 0;
}

int HandleStop(void* pChr){
  char chr = *(char*)pChr;

  if (chr == STOPCOMMANDCAPTURE && isCapturingCommandInput){
    _ExitCommands();
    return 1;
  }

  return 0;
}

int HandleDelChar(void* pChr){
  char chr = *(char*)pChr;

  if (chr == DECREASECAPTURE && isCapturingCommandInput){
    if (currentCommandWriteIndex == 0){ //Trying to delete toggle char
      _ExitCommands();
    }

    --currentCommandWriteIndex;
    return 1;
  }

  return 0;
}

int HandleCommandOverflow(void* pChr){
  if (isCapturingCommandInput){
    if (currentCommandWriteIndex >= MAXCOMMANDLENGTH){
      return 1;
    }
  }

  return 0;
}

int HandleChar(void* pChr){
  char chr = *(char*)pChr;

  if (isCapturingCommandInput){
    command[currentCommandWriteIndex++] = chr;
    return 1;
  }

  return 0;
}

void OutputIfCommands(){
  if (isCapturingCommandInput){
    MoveCursor(0, 0);
    IVec2 maxPos = GetMaxCursorPos();
    int startingY = maxPos.y - 1;

    MoveCursor(0, startingY);

    PrintScreen("%c", COMMANDCAPTURETOGGLE);
    for (int i = 0; i < currentCommandWriteIndex; ++i){
      PrintScreen("%c", command[i]);
    }
  }
}

void InitInputs(){
  InitExecute();
}

void DestroyInputs(){
  DestroyExecute();
}
