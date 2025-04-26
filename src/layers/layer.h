typedef int(*TLayerFn)(char);

typedef struct{
  TLayerFn func;
  int priority;
} Layer;

///@brief This function compares layers.
///@return Returns 1 if pV1 is greater, 0 if equal, and -1 if less.
int LayerCmp(void* pV1, void* pV2);

///@brief This function destroys a layer.
///@param pV is the layer in form of a void pointer.
void DestroyLayer(void* pV);
