#include<ncurses.h>

int main(){
  char chr;

  //Initalize the screen
  initscr();

  //Dont echo the characters back
  noecho();

  //Enable arrows
  keypad(stdscr, true);

  while (true){
    chr = getch();

    //Clear the screen
    clear();

    //HandleChar(chr);
    printw("The char is %c", chr);

    refresh(); //Refresh the screen
  }

  clear(); //Clear the screen

  endwin(); //Destroy the window

  return 0;
}
