///@brief Moves the cursor relatively to its current position by x and y.
///@param x is the x + current cursor position = new cursor position.
///@param y is same as x but its y.
void MoveCursor(int x, int y);

///@brief Updates the frame on the screen, like SwappingBuffers in OpenGL.
void RefreshScreen();

///@brief Clears the screen from all text on it.
void ClearScreen();

///@brief Prints some text on the cursor position.
///@param str is the string to print at the cursor position, it has to be in proper format (printf).
void PrintScreen(char* str, ...);

///@brief Initializes the graphics.
void InitGraphics();

///@brief Gets a character from user.
///@return Character that user input.
char GetChar();

///@brief Terminates the graphics.
void ExitGraphics();
