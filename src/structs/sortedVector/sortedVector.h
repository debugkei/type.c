///Just a function signature that is called on destruction.
typedef void(*_DestFn)(void*);

///SortedVector data structure.
///Look in sortedVector.h for more information on existing functions.
///Sorted least->greatest.
///Can either contain structs with priority int at specific offset, or ints with offset of 0.
typedef struct{
  int _offsetOfSortElem;
  char* _elems;
  int length;
  int _allocLength;
  _DestFn _destFn;
} SortedVector;

///@brief Initializes a SortedVectorInstance to be ready to serve.
///@param pVec is a pointer to a SortedVector struct created.
///@param sortedElementOffset is the offset of the int value in bytes, that is going to be used to sort (least->greatest).
///The element has to be a struct or an int.
///@param elemSize is the size of a single element stored in the SortedVector in bytes.
///@param destFn is the function that is used to destroy a single element, it takes a void pointer to an element to destroy.
///If the values are not pointers just pass in null.
void InitSortedVector(SortedVector* pVec, int sortedElementOffset, int elemSize, _DestFn destFn);

///@brief Destroys the SortedVector and clears the space occupied by it.
///@param pVec is a pointer to pVector to destroy, after this function the pVector can be initalized with InitSortedVector.
void DestroySortedVector(SortedVector* pVec);

///@brief Gets an element and returns a pointer to it at specific index.
void* GetElementAtSortedVector(SortedVector* pVec, int index);

///@brief Pops an element at specified index and it that element is needed then pass a pointer to a pointer of preallocated space.
///@param pVec is the SortedVector from which element is popped.
///@param index is the index at which the element has to be popped.
///@param elemBasket is a pointer to a pointer of preallocated space to which the element will be copied.
void PopElementAtSortedVector(SortedVector* pVec, int index, void** elemBasket);

///@brief This function pushes an element onto SortedVector, and orders it in the right order, least->greatest.
///@param pVec is the vector that the element is pushed onto.
///@param elem is a pointer to an element which will be copied and put onto the vector.
void PushElementSortedVector(SortedVector* pVec, void* elem);
