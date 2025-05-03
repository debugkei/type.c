#include<stdio.h>

///@brief Initializes the filewords module.
void InitFilewords();

///@brief Parses specific amount of words from specified file.
///File has to have 1 word per line.
///@param pFile is a pointer to a file.
///@param count count is the final count of words parsed and returned.
///@return array of strings, with length of count.
char** ParseWords(FILE* pFile, int count);

///@brief Destroys the filewords module, cleaning resources after it.
void DestroyFilewords();
