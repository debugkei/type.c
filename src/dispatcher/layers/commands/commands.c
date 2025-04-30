#include"commands.h"

#include"layer/chain/layerChain.h"
#include"layers/input.h"

static SortedVector _layerChain;

void InitCommands(){
  InitLayerChain(&_layerChain);

  InitInputs();
  AddLayer(&_layerChain, HandleStop, 10);
  AddLayer(&_layerChain, HandleExecute, 10);
  AddLayer(&_layerChain, HandleDelChar, 10);
  AddLayer(&_layerChain, HandleStart, 10);
  AddLayer(&_layerChain, HandleCommandOverflow, 9);
  AddLayer(&_layerChain, HandleChar, 8);
}

int HandleCommands(void* pChr){
  int didDispatchSuccessfully = DispatchToLayerChain(&_layerChain, pChr);

  OutputIfCommands();

  return didDispatchSuccessfully;
}

void DestroyCommands(){
  DestroyLayerChain(&_layerChain);
  DestroyInputs();
}
