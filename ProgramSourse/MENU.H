#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <graphics.h>
#include <alloc.h>
#include <dos.h>
//#include "smile.h" //include the screensaver module!
#include "kurdb22.h"//DataBase


//---------------------------------
//************Prototypes***********
//++++++++++++Menu Functions+++++++
void Menu(unsigned char x1,unsigned char y1,unsigned char bkColor,unsigned char textColor,unsigned char ActiveButtonColor,unsigned char SpaceBetweenButtons,char *string,...);
void Hide();
void Show();

void RefreshDesctop(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2,unsigned char desctopColor);

void Window(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2,unsigned char textColor,unsigned char bkColor);
void WindowBG(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2,unsigned char textColor,unsigned char bkColor);
void WindowText(unsigned char lx,unsigned char ly,unsigned char x2,unsigned char y2,unsigned char textColor,unsigned char bkColor,char *WindowText);

void EditTechItem(void);
void AddCustomer(void);
void CustomerInfo (void);
int  DeleteExcessItems(char *path);

unsigned int GetLeftXPos(unsigned int tempWinLen);
void StatusBar(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2,unsigned char textColor,unsigned char bkColor,char *statusText);
void SetButtonText(char *str);
void Engine();
//+++++++++++SubMenu Functions++++++
void AboutAvtor(int x1,int y1,char *string,...);
void WorkWithDataBase(int x1,int y1,char *string,...);
void SearchInfo(int x1,int y1,char *string,...);
void PrintResults(int x1,int y1,char *string,...);
void Busket(int x1,int y1,char *string,...); //for buing tovar
void Exit(int x1,int y1,char *string,...);
int  SpecialViewBrowser(char *path);
int  ViewBrowser(char *path);

//***************Include***************
#include "colors.h"
#include "menu.cpp"