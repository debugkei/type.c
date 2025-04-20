///@brief Dispatches the char handling to appropriate layer of execution.
///The layers that can potentially be dispatched to: commands, filewords, test.
///Gets called once per char that was recieved from the user.
void Dispatch(char c);
