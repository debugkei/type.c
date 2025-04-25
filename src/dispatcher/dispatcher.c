#include"dispatcher.h"

#include"../graphics/graphics.h"
#include"../structs/sortedVector/sortedVector.h"
#include"../layers/shortcuts/shortcuts.h"

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

  _AddLayer(HandleCtrlC, 10);
  _AddLayer(HandleCtrlD, 10);
}

void Dispatch(char chr){
  int n = _layerVec.length;
  //Iterate in reverse because sort least->greatest
  for (int i = n - 1; i >= 0; --i){
    _Layer layer = *(_Layer*)GetElementAtSortedVector(&_layerVec, i);
    if (layer.func(chr)) break;
  }
}

void DestroyDispatcher(){
  DestroySortedVector(&_layerVec);
}
