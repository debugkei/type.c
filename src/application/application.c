#include"application.h"

#include"dispatcher/dispatcher.h"
#include"graphics/graphics.h"

static int applicationShouldClose;
static int applicationClosed;

void InitApplication(){
  InitGraphics();
  InitDispatcher();

  applicationShouldClose = 0;
  applicationClosed = 0;
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
  if (applicationClosed) return;

  applicationClosed = 1;
  applicationShouldClose = 1;

  ExitGraphics();
  DestroyDispatcher();
}
