///@brief Initializes the inputs.
void InitInputs();

///@brief Destroys and clean after inputs.
void DestroyInputs();

///@brief This function handles the start of going into typing command state.
int HandleStart(void* pChr);

///@brief This function handles the case when enter is pressed (command is queried to be executed).
int HandleExecute(void* pChr);

///@brief This function handles the case when escape is pressed (stop typing the command).
int HandleStop(void* pChr);

///@brief This funcion handles deletion of a character.
int HandleDelChar(void* pChr);

///@brief This function adds the character to a command.
int HandleChar(void* pChr);

///@brief This function handles command's length overflow.
int HandleCommandOverflow(void* pChr);

///@brief This function outputs the character back to a specific area.
///Only if the command is typed.
void OutputIfCommands();
