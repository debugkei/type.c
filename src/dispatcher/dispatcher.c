#include"dispatcher.h"

#include"layers/layerChain.h"

#include"layers/shortcuts/shortcuts.h"
#include"layers/commands/commands.h"

SortedVector _layerChain;

void InitDispatcher(){
  InitLayerChain(&_layerChain);

  AddLayer(&_layerChain, HandleCtrlC, 10);

  AddLayer(&_layerChain, HandleCtrlD, 10);

  AddLayer(&_layerChain, HandleCommands, 9);
  InitCommands();
}

void Dispatch(char chr){
  DispatchToLayerChain(&_layerChain, chr);
}

void DestroyDispatcher(){
  DestroyLayerChain(&_layerChain);
  DestroyCommands();
}
