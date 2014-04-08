#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <graphics.h>
#include <alloc.h>
#include <dos.h>
#include "menu.h"
#include "smile.h" //include the screensaver module!

//***************Main****************
void main()
{
  ScreenSaver(); //call screensaver
  restorecrtmode();
  clrscr();
  randomize();
  strcat(temp2,pathToDB);

  RefreshDesctop(1,1,80,ymax,desctopColor);//screen definition!!! BUG
  Menu(x1,y1,bkColor,textColor,ActiveButtonColor,SpaceBetweenButtons,
  "About Avtor","Work with DB","Search Info","Print Results","Basket","Exit",NULL);

  //*******FREE MEMORY********************
  free(buttonLenghtArray);
  free(buttonText);
  free(ppString);
}
