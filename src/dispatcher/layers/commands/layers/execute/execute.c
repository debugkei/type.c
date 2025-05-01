#include"execute.h"

#include<memory.h>

#include"structs/command/command.h"

#include"layer/chain/layerChain.h"
#include"layers/quit.h"
#include"layers/error.h"

static SortedVector _layerChain;

void InitExecute(){
  InitLayerChain(&_layerChain);

  AddLayer(&_layerChain, HandleQuit, 10);
  AddLayer(&_layerChain, HandleError, 9);
}

void DestroyExecute(){
  DestroyLayerChain(&_layerChain);
}

//Potentially TODO: Refactor
int Execute(void* pCommand, int n){
  char commandBuffer[(n + 1) * sizeof(char)]; //Create another for the ParseCommand, it requires an array where command[n] is always allocated.
  memcpy(commandBuffer, pCommand, n * sizeof(char));

  Command command;
  ParseCommand(&command, commandBuffer, n);

  if (!command.pListNode) return 1;

  int didDispatch = DispatchToLayerChain(&_layerChain, &command);

  DestroyCommand(&command);

  return didDispatch;
}
