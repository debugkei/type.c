#include"dispatcher.h"

#include"../graphics/graphics.h"
#include"../structs/sortedVector/sortedVector.h"

typedef int(*_TLayerFn)(char);

typedef struct{
  _TLayerFn func;
  int priority;
} _Layer;

static int _LayerCmp(void* pV1, void* pV2){
  _Layer l1 = *(_Layer*)pV1;
  _Layer l2 = *(_Layer*)pV2;

  return l1.priority - l2.priority;
}

SortedVector _layerVec;

///@brief Adds a layer to dispatcher to consider, with certain priority.
///If the layer is not supposed to handle, its function that the char is disptached to returns 0.
///Otherwise the function returns 1 to signal that the character was handled.
///@param func is a function pointer to which the dispatcher dispatches the char recieved.
///It returns 0 if didnt handle, and 1 if did.
///It takes a char.
///@param priority is the priority in which the function is going to get dispathed to, more priority marks the function for earlier dispaching.
void _AddLayer(_TLayerFn func, int priority){
  _Layer layer;
  layer.func = func;
  layer.priority = priority;

  PushElementSortedVector(&_layerVec, &layer);
}

void InitDispatcher(){
  InitSortedVector(&_layerVec, sizeof(_Layer), 0, _LayerCmp);
  //TODO: Push the layers on the SortedVector
}

void Dispatch(char chr){
  PrintScreen("The char is %c", chr); //Debug
  //TODO: Dispatch to layers
}

void DestroyDispatcher(){
  DestroySortedVector(&_layerVec);
}
