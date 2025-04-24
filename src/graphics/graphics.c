#include"graphics.h"

#include<ncurses.h>
#include<stdarg.h>

void MoveCursor(int x, int y){
  move(x, y);
}

void RefreshScreen(){
  refresh();
}

void ClearScreen(){
  clear();
}

void PrintScreen(char* str, ...){
  va_list args;
  char buffer[1024];

  va_start(args, str);
  vsnprintf(buffer, sizeof(buffer), str, args);
  va_end(args);

  printw("%s", buffer);
}

void InitGraphics(){
  //Initalize the screen
  initscr();

  //Dont echo the characters back
  noecho();

  //Enable arrows
  keypad(stdscr, true);
}

void ExitGraphics(){
  endwin();
}

char GetChar(){
  return getch();
}
