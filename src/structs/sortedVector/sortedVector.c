#include"sortedVector.h"

#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<malloc.h>

static void _DefaultDest(void* pV){}

///@brief This function slides a part between start and middle pointers to the end, and end slides left.
///@param pStart is the starting point, which will be filled with middle values.
///@param pMiddle is the middle point all starting from it will be sliden to the left to starting point.
///@param pEnd is the ending point, pStart - pMiddle will be now at the very end.
static void Slide(void* pStart, void* pMiddle, void* pEnd){
  int nFirst = (char*)pMiddle - (char*)pStart;
  int nSecond = (char*)pEnd - (char*)pMiddle;
  char buffer[nFirst];

  memcpy(buffer, pStart, nFirst);
  memmove(pStart, pMiddle, nSecond);
  void* pNewEnd = (char*)pEnd - nFirst;
  memcpy(pNewEnd, buffer, nFirst);
}

///@brief Expands the vector's allocated space.
static void ExpandVector(SortedVector* pVec){
  assert(pVec != NULL);

  //Just double the vector's allocated space
  int newSize = pVec->_allocLength * 2;

  pVec->_elems = realloc(pVec->_elems, newSize * pVec->_elemSize);
  assert(pVec->_elems != NULL);

  pVec->_allocLength = newSize;
}

///@brief Utilizes binary search to find a place to insert an element to
///@param pElems is the array at which at every element theres a priority measure, represented by offset and int.
///@param pElem is the element itself that has to be inserted
///@param elemSize is the size of a single element within the array.
///@param n is the length of pElems.
static int BSearchForInsertPos(void* pElems, void* pElem, int elemSize, int n, _CmpFn cmpFn){
  int left = 0, right = n - 1;

  while (left <= right){
    int middle = left + (right - left) / 2;
    void* middleElem = pElems + middle * elemSize;
    int cmpRes = cmpFn(pElem, middleElem);

    if (cmpRes > 0){
      //pElem > middleElem
      left = middle + 1;
    } else if (cmpRes < 0){
      //pElem < middleElem
      right = middle - 1;
    } else{
      return middle;
    }
  }

  return left;
}

int _IntCmp(void* pV1, void* pV2){
  int i1 = *(int*)pV1;
  int i2 = *(int*)pV2;

  return i1 - i2;
}

void InitSortedVector(SortedVector* pVec, int elemSize, _DestFn destFn, _CmpFn cmpFn){
  assert(pVec != NULL);

  pVec->length = 0;
  pVec->_allocLength = 4;
  pVec->_elemSize = elemSize; 

  pVec->_elems = malloc(pVec->_elemSize * pVec->_allocLength);
  assert(pVec->_elems != NULL);

  if (destFn != NULL){
    pVec->_destFn = destFn;
  } else{
    pVec->_destFn = _DefaultDest;
  }

  if (cmpFn != NULL){
    pVec->_cmpFn = cmpFn;
  } else{
    pVec->_cmpFn = _IntCmp;
  }
}

void* GetElementAtSortedVector(SortedVector* pVec, int index){
  assert(pVec->length > index);
  assert(pVec->length != 0);
  assert(pVec != NULL);

  void* pElem = pVec->_elems + index * pVec->_elemSize;
  return pElem;
}

void PopElementAtSortedVector(SortedVector* pVec, int index){
  assert(pVec->length > index);
  assert(pVec->length != 0);
  assert(pVec != NULL);

  int elemSize = pVec->_elemSize;
  char* elems = pVec->_elems;
  int n = pVec->length;

  //Slide the element to pop to the back
  void* pElemStart = elems + index * elemSize;
  void* pElemEnd = elems + (index + 1) * elemSize;
  void* pElemsEnd = elems + n * elemSize;
  Slide(pElemStart, pElemEnd, pElemsEnd);

  //Destroy that element accordingly to destFn
  void* pElem = GetElementAtSortedVector(pVec, n - 1);
  pVec->_destFn(pElem);

  --pVec->length;
}

void PushElementSortedVector(SortedVector* pVec, void* pElem){
  assert(pVec != NULL);

  int n = pVec->length;

  //Expand if needed
  if (n >= pVec->_allocLength){
    ExpandVector(pVec);
    n = pVec->length;
  }

  int elemSize = pVec->_elemSize;

  //Insert at specific place
  int insertAt = BSearchForInsertPos(pVec->_elems, pElem, elemSize, n, pVec->_cmpFn);

  void* pElemStart = (char*)pVec->_elems + insertAt * elemSize;
  void* pElemsEnd = (char*)pVec->_elems + n * elemSize;
  void* pElemAfterEnd = pElemsEnd + elemSize;
  Slide(pElemStart, pElemsEnd, pElemAfterEnd);

  memcpy(pElemStart, pElem, elemSize);

  ++pVec->length;
}

void ClearSortedVector(SortedVector* pVec){
  int n = pVec->length;
  for (int i = 0; i < n; ++i){
    PopElementAtSortedVector(pVec, 0);
  }
}

void DestroySortedVector(SortedVector* pVec){
  ClearSortedVector(pVec);
  free(pVec->_elems);
}
