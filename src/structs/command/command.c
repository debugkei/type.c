#include"command.h"

#include<malloc.h>
#include<assert.h>

void ParseCommand(Command* pDest, void* pSrc, int n){
  char* pSrcStr = (char*)pSrc;

  ListNode* pDummyNode = malloc(sizeof(ListNode));
  assert(pDummyNode);

  ListNode* pCurrentNode = pDummyNode;

  //Turn the last character of pSrc into null terminal
  //Thats needed, for the last word of the pSrc to be null-terminated.
  pSrcStr[n] = '\0';

  int parsingWord = 0;
  for (int i = 0; i < n; ++i){
    if (pSrcStr[i] == ' '){
      parsingWord = 0; //End of the word

      pSrcStr[i] = '\0'; //Turn spaces into null-terminals

      continue; //Skip spaces
    }

    if (pSrcStr[i] != ' '){
      if (parsingWord) continue;

      parsingWord = 1;
    }

    pCurrentNode->next = malloc(sizeof(ListNode));
    pCurrentNode = pCurrentNode->next;

    assert(pCurrentNode);

    //Actual parsing logic
    pCurrentNode->value = pSrcStr + i * sizeof(char);
  }

  pDest->pListNode = pDummyNode->next;
  free(pDummyNode);
}

void DestroyCommand(Command* pCommand){
  ListNode* pCurrentNode = pCommand->pListNode;

  while (pCurrentNode){
    void* pCurrentNodeTemp = pCurrentNode;

    pCurrentNode = pCurrentNode->next;

    free(pCurrentNodeTemp);
  }
}
