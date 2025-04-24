///Just a function signature that is called on destruction.
typedef void(*_DestFn)(void*);

///Vector data structure.
///Look in vector.h for more information on existing functions.
typedef struct{
  int _offsetOfSortElem;
  char* _elems;
  int length;
  int _allocLength;
  _DestFn _destFn;
} Vector;

///@brief Initializes a Vector Instance to be ready to serve.
///@param pVec is a pointer to a Vector struct created.
///@param elemSize is the size of a single element stored in the Vector in bytes.
///@param destFn is the function that is used to destroy a single element, it takes a void pointer to an element to destroy.
///If the values are not pointers just pass in null.
void InitVector(Vector* pVec, int elemSize, _DestFn destFn);

///@brief Destroys the Vector and clears the space occupied by it.
///@param pVec is a pointer to pVector to destroy, after this function the pVector can be initalized with InitVector.
void DestroyVector(Vector* pVec);

///@brief Gets an element and returns a pointer to it at specific index.
void* GetElementAtVector(Vector* pVec, int index);

///@brief Pops an element at specified index and it that element is needed then pass a pointer to a pointer of preallocated space.
///@param pVec is the Vector from which element is popped.
///@param index is the index at which the element has to be popped.
///@param elemBasket is a pointer to a pointer of preallocated space to which the element will be copied.
void PopElementAtVector(Vector* pVec, int index, void** elemBasket);

///@brief This function pushes an element onto Vector.
///@param pVec is the vector that the element is pushed onto.
///@param elem is a pointer to an element which will be copied and put onto the vector.
void PushElementVector(Vector* pVec, void* elem);
