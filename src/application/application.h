///@brief The main application loop, calls all the logic once per character typed by the user.
///Takes nothing and returns nothing, holds on the execution if called on main thread.
///If its necessary for an application to exit, the other modules will do it, no need for it in main.c.
void RunApplication();

///@brief Call to exit, exits the program clearing after it.
void ExitApplication();

///@brief Call before Run, initializes proper values necessary for the application to run.
void InitApplication();
