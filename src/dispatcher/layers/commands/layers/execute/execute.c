#include"execute.h"

#include"layer/chain/layerChain.h"

static SortedVector _layerChain;

static void _ParseCommand(Command* pThisCommand, void* pCommand, int n){
  //TODO: create a command struct
  //That command struct will be just an array of pointers to chars in pCommand after every whitespace and on start of every word
  
  //TODO: logic of execute
  //TODO: logic of quit
  //TODO: logic of words command
}

void InitExecute(){
  InitLayerChain(&_layerChain);
}

void DestroyExecute(){
  DestroyLayerChain(&_layerChain);
}

int Execute(void* pCommand, int n){
  Command command;
  _ParseCommand(&command, pCommand, n);
  return DispatchToLayerChain(&_layerChain, &command);
}
