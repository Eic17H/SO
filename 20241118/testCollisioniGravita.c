#include <stdlib.h>
#include <curses.h>
#define OBJECT '#'
#define G -9.8
#define ELASTICITY 0.5

int main() {
 initscr(); noecho(); curs_set(0); cbreak();
keypad(stdscr, 1);
box﻿ (stdscr﻿ , ACS_VLINE﻿ , ACS_HLINE﻿ )﻿ ;
int x ﻿ = COLS﻿ /﻿ 2﻿ , y ﻿ = 0 , c﻿ ;
mvaddch﻿ (﻿ y﻿ , x﻿ , OBJECT﻿ )﻿ ; refresh()﻿ ;
int spd=0;
while(1){
mvaddch(y,x,' ');
spd += G;
y += spd;
if(y>=LINES) spd = -spd/2;
mvaddch(y, x, OBJECT);
refresh();
}