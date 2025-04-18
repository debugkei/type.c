# Documentation

## Details

### File retrievement
#### Files that are used to generates texts are:
* Takes 1 from ~/.type.c/
* Specified by the -f flag
* Read from stdin, if piped, though it slows down the performace.

#### Performace
##### The file retrievement will do following:
###### If get from file:
* Get only necessary random words on start.
* Then in backgound in separate thread will get the rest into a vector from which via rand() application will get texts.

###### If get from pipe:
* Read stdin in array, switch the state to done.
* Not the most performant, but added only for intuitive use, not mostly used.

##### Why vector?
* Because fast retrival time, O(1).
* Because Ctrl + C is used to exit, the OS will clear all the memory itself.
* In background so no real need to get fast insertion.
* Ill write myself.

### States
* Application will have states.
#### States
* Frozen, for after finishing the test, and awaiting to press Tab to go to next.
* Command, for waiting for command.
* Type, the regular type during which the background threads are spawned to retrieve file information.

#### Substates of file retrieval
* Done, for after done retrieving.
* Piped, if piped.

### Commands
* Vim style commands
#### List
* :w <words>, where words is the new amount of words in tests.
* :q, the most unknown vim command.

### Stats
* Stats are dynamically shown after each character typed during a test state.
* After done are frozen and user is asked to press tab to go to next.
#### Stats types
* WPM
* CPM
* Accuracy

## TODO/Roadmap
1. Core application.  
2. Ctrl + Bspc to -word.  
3. Next word is highlighted.  
