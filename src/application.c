#include"application.h"

#include<stdlib.h>

#include"dispatcher.h"
#include"graphics.h"

void InitApplication(){
  InitGraphics();
}

void RunApplication(){
  char chr;
  while (1){
    chr = GetChar();
    ClearScreen();
    Dispatch(chr);
    RefreshScreen();
  }
}

void ExitApplication(int code){
  ExitGraphics();
  exit(code);
}
