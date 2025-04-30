///@brief Initializes the execute module.
void InitExecute();

///@brief Destroys the execute module, and cleans its resource footprint.
void DestroyExecute();

///@brief Executes the command given.
///@param pCommand is the char* that has the command.
///Can be also not just a casual null-terminated string because of n.
///@param n is its length.
int Execute(void* pCommand, int n);
