#include"test.h"

#include"layer/chain/layerChain.h"

static SortedVector _layerChain;

void InitTest(){
}

int HandleTest(void* pChr){
  return DispatchToLayerChain(&_layerChain, pChr);
}

void DestroyTest(){
  DestroyLayerChain(&_layerChain);
}
