///@brief Dispatches the char handling to appropriate layer of execution.
///The layers that can potentially be dispatched to: commands, filewords, test.
///Gets called once per char that was recieved from the user.
void Dispatch(char c);

///@brief Initializes the dispatcher, adds appropriate layers to the layer list.
///This function has to be modified in dispatcher.c in order to add new layer to which the char will be dispatcher.
void InitDispatcher();

///@brief Destroys the dispatcher instance, cleaning up all resource footprints.
void DestroyDispatcher();
