#include"graphics.h"

#include<ncurses.h>
#include<stdarg.h>

void MoveCursor(int x, int y){
  move(y, x);
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

  raw(); //Handle ctrl + c in application

  //Disable cursor
  curs_set(0);
}

void ExitGraphics(){
  endwin();
}

char GetChar(){
  return getch();
}

IVec2 GetCursorPos(){
  IVec2 vec;
  vec.x = getcurx(stdscr);
  vec.y = getcury(stdscr);
  return vec;
}

IVec2 GetMaxCursorPos(){
  IVec2 vec;
  vec.x = getmaxx(stdscr);
  vec.y = getmaxy(stdscr);
  return vec;
}
