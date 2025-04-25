#include"shortcuts.h"

#include"../../application/application.h"

int HandleCtrlC(char chr){
  if (chr == (char)3){
    ApplicationShouldClose();
    return 1;
  }
  return 0;
}

int HandleCtrlD(char chr){
  if (chr == (char)4){
    ApplicationShouldClose();
    return 1;
  }
  return 0;
}
