#include"application.h"

#include"../dispatcher/dispatcher.h"
#include"../graphics/graphics.h"

int applicationShouldClose;

void InitApplication(){
  InitGraphics();
  InitDispatcher();

  applicationShouldClose = 0;
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
}

void ApplicationShouldClose(){
  applicationShouldClose = 1;
}
