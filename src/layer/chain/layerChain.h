#include"structs/sortedVector/sortedVector.h"
#include"layer/layer.h"

///@brief Adds a layer to a previously created layer chain.
///To create use CreateLayerChain();
///@param func is the function that takes a void* and return an int.
///This function is supposed to return either 1 if layer handled the void*.
///Or 0 to keep dispatching to below layers.
///@param priority is a priority used for the layer.
///The bigger the priority the higher the layer is in the chain, and the faster it gets the character dispatched to it.
void AddLayer(SortedVector* pVec, TLayerFn func, int priority);

///@brief Removes a layer by index.
///@param pVec is the vector from which to remove layer.
///@param index is the index which is used to remove layer from SortedVector.
void RemoveLayer(SortedVector* pVec, int index);

///@brief Initializes a LayerChain that is actually a SortedVector.
///@param pVec is a SortedVector to initialize.
void InitLayerChain(SortedVector* pVec);

///@brief Cleans up after using LayerChain.
///@param pVec is the SortedVector that was used as LayerChain.
void DestroyLayerChain(SortedVector* pVec);

///@brief Dispatches a character to the layer chain.
///@param pVec is the layer chain to which dispatch the character.
///@param pV is the void* to dispatch upon.
///@return Returns 1 if successfully a layer handled, 0 if no layers handled the char.
int DispatchToLayerChain(SortedVector* pVec, void* pV);
