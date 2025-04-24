#include"application.h"

#include<stdlib.h>

#include"../dispatcher/dispatcher.h"
#include"../graphics/graphics.h"

void InitApplication(){
  InitDispatcher();
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
