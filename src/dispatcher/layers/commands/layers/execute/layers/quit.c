#include"quit.h"

#include"string.h"

#include"application/application.h"
#include"structs/command/command.h"

#define SIZE 3
static const char* commands[SIZE] = {
  "q",
  "Q",
  "quit",
};

int HandleQuit(void* pVCommand){
  Command* pCommand = (Command*)pVCommand;
  char* placeWithCommand = pCommand->pListNode->value;

  for (int i = 0; i < SIZE; ++i){
    int eql = !strcmp(placeWithCommand, commands[i]);

    if (eql){
      ExitApplication();
      return 1;
    }
  }

  return 0;
}
