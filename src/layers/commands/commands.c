#include"commands.h"

#include"../../graphics/graphics.h"

int isCapturingCommandInput = 0;

char commandCaptureToggle = ':';
char stopCommandCapture = (char)27; //Escape
char submitCommand = (char)10; //Enter
char decreaseCapture = (char)7; //Backspace

const int MAXCOMMANDLENGTH = 128;
char command[MAXCOMMANDLENGTH];
int currentCommandWriteIndex = 0;

void _EchoBack(){
  MoveCursor(0, 0);
  IVec2 maxPos = GetMaxCursorPos();
  int startingY = maxPos.y - 1;

  MoveCursor(0, startingY);

  PrintScreen("%c", commandCaptureToggle);
  for (int i = 0; i < currentCommandWriteIndex; ++i){
    PrintScreen("%c", command[i]);
  }
}

int HandleCommands(char chr){
  //Enter/leave/submit
  if (chr == commandCaptureToggle){
    isCapturingCommandInput = 1;
    currentCommandWriteIndex = 0;

  } else if (chr == stopCommandCapture){
    isCapturingCommandInput = 0;
    return 1;

  } else if (chr == submitCommand){
    //TODO: submit logic
    isCapturingCommandInput = 0;
    return 1;
  }

  else if (chr == decreaseCapture){
    if (currentCommandWriteIndex == 0){ //Trying to delete toggle char
      isCapturingCommandInput = 0; //Just exit
      return 1;
    }

    --currentCommandWriteIndex;
  }

  if (currentCommandWriteIndex >= MAXCOMMANDLENGTH){
    return 1;
  }

  if (isCapturingCommandInput){
    if (chr != commandCaptureToggle && chr != decreaseCapture) //Dont capture the toggle command
      command[currentCommandWriteIndex++] = chr;

    _EchoBack();

    return 1;
  }

  return 0;
}
