#include"layerChain.h"

void AddLayer(SortedVector* pVec, TLayerFn func, int priority){
  Layer layer = { func, priority };
  PushElementSortedVector(pVec, &layer);
}

void RemoveLayer(SortedVector* pVec, int index){
  PopElementAtSortedVector(pVec, index);
}

void InitLayerChain(SortedVector* pVec){
  InitSortedVector(pVec, sizeof(Layer), DestroyLayer, LayerCmp);
}

void DestroyLayerChain(SortedVector* pVec){
  DestroySortedVector(pVec);
}

int DispatchToLayerChain(SortedVector* pVec, void* pV){
  int n = pVec->length;
  //Iterate in reverse because sort least->greatest
  for (int i = n - 1; i >= 0; --i){
    Layer layer = *(Layer*)GetElementAtSortedVector(pVec, i);
    if (layer.func(pV)) return 1;
  }
  return 0;
}
