#include"dispatcher.h"

#include"layer/chain/layerChain.h"

#include"layers/shortcuts/shortcuts.h"
#include"layers/commands/commands.h"
#include"layers/test/test.h"

static SortedVector _layerChain;

void InitDispatcher(){
  InitLayerChain(&_layerChain);

  AddLayer(&_layerChain, HandleCtrlC, 10);
  AddLayer(&_layerChain, HandleCtrlD, 10);

  AddLayer(&_layerChain, HandleCommands, 9);
  InitCommands();

  AddLayer(&_layerChain, HandleTest, 8);
}

void Dispatch(char chr){
  DispatchToLayerChain(&_layerChain, &chr);
}

void DestroyDispatcher(){
  DestroyLayerChain(&_layerChain);
  DestroyCommands();
}
