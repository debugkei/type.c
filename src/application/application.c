#include"application.h"

#include<stdlib.h>

#include"../dispatcher/dispatcher.h"
#include"../graphics/graphics.h"

int applicationShouldClose = 0;

void InitApplication(){
  InitGraphics();
  InitDispatcher();
}

void RunApplication(){
  char chr;
  while (!applicationShouldClose){
    chr = GetChar();
    ClearScreen();
    Dispatch(chr);
    RefreshScreen();
  }
}

void ExitApplication(){
  ExitGraphics();
  DestroyDispatcher();

  applicationShouldClose = 1;
}
