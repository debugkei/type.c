#include"layer.h"

int LayerCmp(void* pV1, void* pV2){
  Layer l1 = *(Layer*)pV1;
  Layer l2 = *(Layer*)pV2;

  return l1.priority - l2.priority;
}

void DestroyLayer(void* pV){}
