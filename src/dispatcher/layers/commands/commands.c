#include"commands.h"

#include"layers/layerChain.h"

SortedVector _layerChain;

void InitCommands(){
  InitLayerChain(&_layerChain);

  //TODO: Add layers
}

int HandleCommands(char chr){
  return DispatchToLayerChain(&_layerChain, chr);
}

void DestroyCommands(){
  DestroyLayerChain(&_layerChain);
}
