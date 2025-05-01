#include"structs/list/list.h"

///@brief (argv, argc)-like struct that holds commands.
///It contains a single list with all commands split by ' '.
///@field pListNode is a pointer to a list of commands.
typedef struct {
  ListNode* pListNode;
} Command;

///@brief Constructs a struct Command, initializes it.
///This function assumes that pSrc at n is allocated.
///@param pDest is a pointer to a Command struct to initialize, to parse to the commands.
///@param pSrc is a character array with length n that is going to get parsed into commands.
///@param n is a length of pSrc.
void ParseCommand(Command* pDest, void* pSrc, int n);

///@brief Clears the resource footprint left by the command after parsing.
///@param pCommand is the command to destroy.
void DestroyCommand(Command* pCommand);
