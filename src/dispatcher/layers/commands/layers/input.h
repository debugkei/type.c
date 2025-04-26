//TODO: implement commands logic

//Old code
int isCapturingCommandInput = 0;

const char commandCaptureToggle = ':';
const char stopCommandCapture = (char)27; //Escape
const char submitCommand = (char)10; //Enter
const char decreaseCapture = (char)7; //Backspace

#define MAXCOMMANDLENGTH 128
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
  switch (chr){
    case commandCaptureToggle:
      isCapturingCommandInput = 1;
      currentCommandWriteIndex = 0;
      break;

    case stopCommandCapture:
      isCapturingCommandInput = 0;
      return 1;

    case submitCommand:
      //TODO: submit logic
      isCapturingCommandInput = 0;
      return 1;

    case decreaseCapture:
      if (currentCommandWriteIndex == 0){ //Trying to delete toggle char
        isCapturingCommandInput = 0; //Just exit
        return 1;
      }
      --currentCommandWriteIndex;
      break;

    default: //Type in command
      if (currentCommandWriteIndex >= MAXCOMMANDLENGTH && isCapturingCommandInput){
        return 1;
      }

      if (isCapturingCommandInput){
        if (chr != commandCaptureToggle && chr != decreaseCapture) //Dont capture the toggle command
          command[currentCommandWriteIndex++] = chr;

        _EchoBack();
        return 1;
      }

      break;
  }

  return 0;
}

//Refactoring
///@brief This function handles the start of going into typing command state.
int HandleStart(char chr);
int HandleExecute(char chr);
int HandleStop(char chr);
int HandleDelChar(char chr);
int HandleChar(char chr);
int Output(char chr);
