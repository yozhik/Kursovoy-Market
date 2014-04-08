#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <graphics.h>
#include <alloc.h>
#include <dos.h>

//************Functions*****************
unsigned int GetLeftXPos(unsigned int tempWinLen)
{
  unsigned int resLeftx1=(xmax-tempWinLen)/2;
  return resLeftx1;
}

void Menu(unsigned char x1,unsigned char y1,unsigned char bkColor,unsigned char textColor,unsigned char ActiveButtonColor,unsigned char SpaceBetweenButtons,char *string,...)
{
  count=0;
  va_list par;
  char *pString=string;
  va_start(par,string);
  while(pString!=NULL)
  {
    count++;
    pString=va_arg(par,char*);
  }
  va_end(par);
 x2=80;
 Window(x1,y1,x2,y1+2,textColor,bkColor);
 unsigned char i=0;
 buttonLenghtArray=(int*)calloc(count,sizeof(int));
 if(buttonLenghtArray==NULL)
 {
   printf("Error! No free memory!");
   exit(0);
 }
 ppString=(char**)calloc(count,sizeof(char*));
 for(i=0;i<count;i++)
 {
   *ppString=NULL;
 }
 i=0;

 pString=string;
 va_start(par,string);
 while(pString!=NULL)
 {
   ppString[i]=pString;
   unsigned char textCount=0;
   while(*pString!='\0')
   {
     textCount++;
     pString++;
   }
   buttonLenghtArray[i]=textCount+SpaceBetweenButtons;
   i++;
   pString=va_arg(par,char*);
 }
 va_end(par);
 unsigned int temp_x1=x1+1;
 for(i=0;i<count;i++)
 {
   gotoxy(temp_x1,y1+1);
   SetButtonText(ppString[i]);
   temp_x1+=buttonLenghtArray[i];
 }
   StatusBar(1,ymax,80,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");////////////////
 Engine();
}
//************************
void Engine()
{
  int i=0,menuHolder=0,fEnter=0,fLastMenuItem=0; //if Right then fRIGHTorLEFT=1; if Left then fRIGHTorLEFT=-1;
  int c=count;
  unsigned char temp=0;
  unsigned int a=0;
  int *ar;
  ar=(int*)calloc(c,sizeof(int));
  if(ar==NULL)
  {
    printf("Error! No free memory!");
    exit(0);
  }
  for(i=0;i<c;i++)
  {
    ar[i]=i+1;
  }
  MenuIndex=menuHolder;
  i=0;
  while(1)
  {
    if(fEnter)
    {
      a=2;
      for(temp=0;temp<(menuHolder-fLastMenuItem);temp++) 
      {
		a+=buttonLenghtArray[temp];
      }
      x1=1;
      gotoxy(a,y1+1);
      if(fLastMenuItem)
      {
        textbackground(ActiveButtonColor);
        textcolor(ActiveTextColor);
      }
      else
      {
        textbackground(bkColor);
        textcolor(textColor);        
      }
      SetButtonText(ppString[menuHolder-fLastMenuItem]);
      fEnter=0;
      fLastMenuItem=0;
      temp=0;
      MenuIndex=menuHolder;
	  menuHolder=0;
      a=2;
    }
    symbol=getch();
    switch(symbol)
    {
      case 77:++MenuIndex;  //RIGHT:  100
	if(MenuIndex>c)
	{
	  MenuIndex=1;
	  a=2;
	  for(temp=0;temp<(c-1);temp++)
	  {
	    a+=buttonLenghtArray[temp];
	  }
	  x1=1;
	  gotoxy(a,y1+1);
	  textbackground(bkColor);
	  textcolor(textColor);
	  SetButtonText(ppString[c-1]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==1)
	  {
	    gotoxy(x1+1,y1+1);
	    textbackground(ActiveButtonColor);
		textcolor(ActiveTextColor);//@@@@@@@@@
	    SetButtonText(ppString[0]);
	    StatusBar(1,ymax,80,ymax,textColor,bkColor,ppString[0]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      x1=1;
	      temp=0;
	      a=x1+1;
	      for(temp=0;temp<i;temp++)
	      {
			a+=buttonLenghtArray[temp];
	      }
	      gotoxy(a-buttonLenghtArray[temp-1],y1+1);
	      textcolor(textColor);
	      textbackground(bkColor);
	      SetButtonText(ppString[i-1]);
	      gotoxy(a,y1+1);
	      textbackground(ActiveButtonColor);
		  textcolor(ActiveTextColor);//@@@@@@@@@
	      SetButtonText(ppString[i]);
	      StatusBar(1,ymax,80,ymax,textColor,bkColor,ppString[i]); 
	      break;
	    }
	  }
	i++;
	}//end of case 100:
	break;
      case 75:--MenuIndex;//LEFT: 97
	if(MenuIndex<=0)
	{
	  MenuIndex=c;
	  a=2;
	  x1=1;
	  gotoxy(a,y1+1);
	  textbackground(bkColor);
	  textcolor(textColor);
	  SetButtonText(ppString[0]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 //**************************
	  if(MenuIndex==c)
	  {
	    a=2;
	    for(temp=0;temp<(c-1);temp++)
	    {
	      a+=buttonLenghtArray[temp];
	    }
	    gotoxy(a,y1+1);
	    textbackground(ActiveButtonColor);
		textcolor(ActiveTextColor);//@@@@@@@@@
	    SetButtonText(ppString[c-1]);
	    StatusBar(1,ymax,80,ymax,textColor,bkColor,ppString[c-1]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      x1=1;
	      temp=0;
	      a=x1+1;
	      for(temp=0;temp<(i+1);temp++)
	      {
			a+=buttonLenghtArray[temp];
	      }
	      gotoxy(a,y1+1);
	      textcolor(textColor);
	      textbackground(bkColor);
	      SetButtonText(ppString[i+1]);
	      gotoxy(a-buttonLenghtArray[temp-1],y1+1);
	      textcolor(ActiveTextColor);//@@@@@@@@@
	      textbackground(ActiveButtonColor);
	      SetButtonText(ppString[i]);
	      StatusBar(1,ymax,80,ymax,textColor,bkColor,ppString[i]); 
	      break;
	    }
	  }
	i++;
	}//end of case 97
	break;
      case 27: break;
      case 13:
	  
	if((MenuIndex>0)&&(MenuIndex<=c))
	{
	menuHolder=MenuIndex;
	  switch(MenuIndex)
	  {
	    case 6:
	      (*pMainMenu[MenuIndex-1])(71,4,"Quit",NULL);
              fLastMenuItem=1;
	      break;
	    case 1:
	       (*pMainMenu[MenuIndex-1])(1,4,"Author","Task","Help",NULL);
		break;
	    case 2:
	       char s1[]={"Password"};
	       char s2[]={"ACCESS..."};
	       char s3[]={"WRONG PASSWORD"};
	       unsigned int t=strlen(s1)+4;
	       wx1=GetLeftXPos(t);
	       WindowText(wx1,wy1,wx1+t,wy1+4,7,4,s1);
	       gotoxy(wx1+2,wy1+2);
	       char *s;
	       int i=0,symFlag=0;
	       for(i;i<4;i++)
	       {
				*s=getch();
				if((*s==27)||(*s==13)||(*s==32))
				{
					symFlag=1;
					break;

				}
				cprintf("*");
				s++;
	       }
	       *s='\0';
	       s-=4;
	       if(strcmp(password,s)==0)
	       {
				RefreshDesctop(wx1,wy1,wx1+t,wy1+4,desctopColor);///////////////////////
				WindowText(wx1,wy1,wx1+t,wy1+4,7,2,"Password");
				gotoxy(wx1+1,wy1+2);
				cprintf("%s",s2);
				getch();
				RefreshDesctop(wx1,wy1,wx1+t,wy1+4,desctopColor);
				(*pMainMenu[MenuIndex-1])(16,4,"Create","Add","Delete","Edit","Delete All",NULL);
	       }
	       else
	       {
				if(symFlag)
				{
					RefreshDesctop(wx1,wy1,wx1+t,wy1+4,desctopColor);///////////////////////
					symFlag=0;
					wx1=GetLeftXPos(50);
					WindowText(wx1,wy1,wx1+51,wy1+4,7,4,"Password");
					gotoxy(wx1+1,wy1+2);
					cprintf("%s","Password can't include such symbols! Try again...");
					getch();
					RefreshDesctop(wx1,wy1,wx1+51,wy1+4,desctopColor);
				}
				else
				{
					RefreshDesctop(wx1,wy1,wx1+t,wy1+4,desctopColor);///////////////////////
					t=strlen(s3)+2;
					wx1=GetLeftXPos(t);
					WindowText(wx1,wy1,wx1+t,wy1+4,7,4,"Password");
					gotoxy(wx1+1,wy1+2);
					cprintf("%s",s3);
					getch();
					RefreshDesctop(wx1,wy1,wx1+t,wy1+4,desctopColor);
				}
	       }
	       break;
	    case 3:
	       (*pMainMenu[MenuIndex-1])(31,4,"Search by NAME","Search by HARACTER","Search by FIRM","Search by PRICE",NULL);
	       break;
	    case 4:
	       (*pMainMenu[MenuIndex-1])(45,4,"Sort by NAME","Sort by PRICE","Print All",NULL);
		   break;
	    case 5: //for Customer
			if(!customerFlag)
			{
			  AddCustomer();
			  CreateDB(busket);
			  customerFlag=1;
			  CustomerInfo ();
			}
			  (*pMainMenu[MenuIndex-1])(61,4,"Make Order","Buy",NULL);
	       break;
	    default: break;
	  }//end of switch(MenuIndex)
	  fEnter=1;
	  i=0;
	  break; //!!????
	}//end of case 13:
	break;
    }//End of switch(symbol)
  }//End of while(1)
}//END
//************************
void Show()
{
  x2=80; 
  x1=1; 
  Window(x1,y1,x2,y1+2,textColor,bkColor);
  for(int i=0;i<count;i++)
  {
   gotoxy(x1+1,y1+1);
   SetButtonText(ppString[i]);
   x1+=buttonLenghtArray[i]-1;
  }
  x1=1;
  Engine();
}
//***********************
void WindowText(unsigned char lx,unsigned char ly,unsigned char x2,unsigned char y2,unsigned char textColor,unsigned char bkColor,char *WindowText)
{
  unsigned int len=strlen(WindowText);
  textcolor(bkColor);
  textbackground(bkColor);
  unsigned int i=0,j=0;
  for(i=lx; i<=x2; i++)
  {
    for(j=ly; j<=y2; j++)
    {
      gotoxy(i,j);
      cprintf("%c",219);
    }
  }
    textcolor(textColor);
    textbackground(bkColor);
    for(j=ly; j<y2; j++)//vertikal
    {
      gotoxy(lx,j);
      cprintf("%c",186);
      gotoxy(x2,j);
      cprintf("%c",186);
    }
    gotoxy(lx+1,ly);
    cprintf("%s",WindowText);
    for(i=(lx+len+1); i<x2; i++)
    {
      gotoxy(i,ly);
      cprintf("%c",205);
    }
    for(i=lx;i<x2;i++)
    {
      gotoxy(i,y2);
      cprintf("%c",205);
    }
    gotoxy(x2,y2);
    cprintf("%c",188);
    gotoxy(x2,ly);
    cprintf("%c",187);
    gotoxy(lx,y2);
    cprintf("%c",200);
    gotoxy(lx,ly);
    cprintf("%c",201);
}
//***********************
void Window(unsigned char lx,unsigned char ly,unsigned char x2,unsigned char y2,unsigned char textColor,unsigned char bkColor)
{
  textcolor(bkColor);
  textbackground(bkColor);
  unsigned char i=0,j=0;
  for(i=lx; i<=x2; i++)
  {
    for(j=ly; j<=y2; j++)
    {
      gotoxy(i,j);
      cprintf("%c",219);
    }
  }
    textcolor(textColor);
    textbackground(bkColor);
    for(i=lx; i<x2; i++)
    {
      gotoxy(i,ly);
      cprintf("%c",205);
      gotoxy(i,y2);
      cprintf("%c",205);
    }
    for(j=ly; j<y2; j++)
    {
      gotoxy(lx,j);
      cprintf("%c",186);
      gotoxy(x2,j);
      cprintf("%c",186);
    }
    gotoxy(x2,y2);
    cprintf("%c",188);
    gotoxy(x2,ly);
    cprintf("%c",187);
    gotoxy(lx,y2);
    cprintf("%c",200);
    gotoxy(lx,ly);
    cprintf("%c",201);
}
//***********************
void WindowBG(unsigned char lx,unsigned char ly,unsigned char x2,unsigned char y2,unsigned char textColor,unsigned char bkColor)
{
  textcolor(bkColor);
  textbackground(bkColor);
  unsigned char i=0,j=0;
  for(i=lx; i<=x2; i++)
  {
    for(j=ly; j<=y2; j++)
    {
      gotoxy(i,j);
      cprintf("%c",219);
    }
  }
    textcolor(textColor);
    textbackground(bkColor);
    gotoxy(x2,y2);
    cprintf("%c",188);
    gotoxy(x2,ly);
    cprintf("%c",187);
    gotoxy(lx,y2);
    cprintf("%c",200);
    gotoxy(lx,ly);
    cprintf("%c",201);
}
//****************************
void StatusBar(unsigned char lx,unsigned char ly,unsigned char x2,unsigned char y2,unsigned char textColor,unsigned char bkColor,char *statusText)
{
  textcolor(bkColor);
  textbackground(bkColor);
  unsigned char i=lx,j=ly;
  for(i=lx,j=ly;i<=x2;i++) /*StatusBar only for 1 line*/
  {
      gotoxy(i,j);
      cprintf("%c",219);
  }
    textcolor(textColor);
    textbackground(bkColor);
    gotoxy(lx+1,ly);
    y2;//now not used
    SetButtonText(statusText);
}
//****************************
void RefreshDesctop(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2,unsigned char desctopColor)
{
  textcolor(desctopColor);
  textbackground(desctopColor);
  unsigned char i=0,j=0;
  for(i=x1; i<=x2; i++)
  {
    for(j=y1; j<=y2; j++)
    {
      gotoxy(i,j);
      cprintf("%c",176);
    }
  }
}
//********************
void Hide()
{
  x1=1,x2=80,y1=1;
  RefreshDesctop(x1,y1,x2,y1+2,desctopColor);
}
//*****************
void SetButtonText(char *str)
{
  strcpy(buttonText,str);
  cprintf(buttonText);
}

//****EditTechItem***///
void EditTechItem(void)
{
	     memset(&item,0,sizeof(TechItem));
		 CreateDB("exch.dat");
		 FILE *f=OpenDB("exch.dat",READnWRITE);

	     int tempWinLen=50;
	      wx1=GetLeftXPos(tempWinLen);
	      wy1-=5;
	      WindowText(wx1,wy1,wx1+tempWinLen,wy1+12,winTEXT,winBK,"Enter Item");
		  textcolor(winTEXT);
		  textbackground(winBK);
		  gotoxy(wx1+2,wy1+2); cprintf("Name:");
		  gotoxy(wx1+2,wy1+4); cprintf("Haracteristic:");
		  gotoxy(wx1+2,wy1+6); cprintf("Firm:");
		  gotoxy(wx1+2,wy1+8); cprintf("Price,$:");
		  gotoxy(wx1+2,wy1+10); cprintf("Number:");
	      
		  textbackground(winTEXT);
		  textcolor(winBK);
			 gotoxy(wx1+17,wy1+2); cprintf("                                 ");
			 gotoxy(wx1+17,wy1+4); cprintf("                                 ");
			 gotoxy(wx1+17,wy1+6); cprintf("                                 ");
			 gotoxy(wx1+17,wy1+8); cprintf("                                 ");
			 gotoxy(wx1+17,wy1+10);cprintf("                                 ");


		  
		  textcolor(winBK);  
		   gotoxy(wx1+17,wy1+2);
		  InputTechItemRecord(item,INPUT_NAME);
		  		   gotoxy(wx1+17,wy1+4);
		  InputTechItemRecord(item,INPUT_MAINHARACTER);
		  		   gotoxy(wx1+17,wy1+6);
		  InputTechItemRecord(item,INPUT_FIRMA);
		  		   gotoxy(wx1+17,wy1+8);
		  InputTechItemRecord(item,INPUT_PRICE);
		  		   gotoxy(wx1+17,wy1+10);
		  InputTechItemRecord(item,INPUT_KILKIST);
		  InputTechItemRecord(item,INPUT_ARTIKUL);
			fwrite(&item,sizeof(TechItem),1,f);
			CloseDB(f);
		  getch();
		  RefreshDesctop(wx1,wy1,wx1+tempWinLen,wy1+12,desctopColor);
		  wy1+=5;
}
//*******************************************
void AddCustomer(void)
{
	     memset(&cust,0,sizeof(Customer));
		 CreateDB(customerDB);
		 FILE *f=OpenDB(customerDB,READnWRITE);

	      int tempWinLen=50;
	      wx1=GetLeftXPos(tempWinLen);
	      wy1-=5;
	      WindowText(wx1,wy1,wx1+tempWinLen,wy1+6,winTEXT,winBK,"Log in");
		  textcolor(winTEXT);
		  textbackground(winBK);
		  gotoxy(wx1+2,wy1+2); cprintf("Name:");
		  gotoxy(wx1+2,wy1+5); cprintf("Price,$:");
		  
		  textbackground(winTEXT);

			 gotoxy(wx1+17,wy1+2); cprintf("                             ");
			gotoxy(wx1+17,wy1+5);  cprintf("                             ");
		  textcolor(winBK);  
		  
		  gotoxy(wx1+17,wy1+2);
		  InputFIO(cust);
		  
		  gotoxy(wx1+17,wy1+5);
		  InputMoney(cust);
			
		  fwrite(&cust,sizeof(Customer),1,f);
			CloseDB(f);
			Credit=cust.Money;
		  getch();
		  RefreshDesctop(wx1,wy1,wx1+tempWinLen,wy1+6,desctopColor);
		  wy1+=5;
}
//***********SubMenu Functions****************
void AboutAvtor(int leftX,int leftY,char *string,...)
{
  int counter=0,Height=0,Width=0,i=0;
  va_list par;
  char *pString=string;
  va_start(par,string);
  while(pString!=NULL)
  {
    counter=0;
    while(*pString!='\0')
    {
      counter++;
      pString++;
    }//end of 2 while
    Height++;
    if(counter>Width)
    {
      Width=counter;
    }
    pString=va_arg(par,char*);
  }//end of 1 while
  va_end(par);
  int *ar;
  ar=(int*)calloc(Height,sizeof(int));
  if(ar==NULL)
  {
    printf("Error! No free memory!");
    exit(1);
  }
  for(i=0;i<Height;i++)
  {
    ar[i]=i+1;
  }
  char **ppSubString=NULL;
  ppSubString=(char**)calloc(Height,sizeof(char*));
  pString=string;
  va_start(par,string);
  i=0;
  while(pString!=NULL)
  {
     ppSubString[i]=pString;
     i++;
     pString=va_arg(par,char*);
   }
  va_end(par);
  Window(leftX,leftY,leftX+Width+1,(leftY+Height*acrossSubButtons)+1,textColor,bkColor);
  leftY++;
  int holder=leftY;
  for(i=0;i<Height;i++)
  {
    gotoxy(leftX+1,leftY);
    SetButtonText(ppSubString[i]);
    leftY+=acrossSubButtons;
  }
//****SubMenu Engine***************
  int c=Height;
  unsigned char temp=0;
  unsigned int a=0;
  MenuIndex=0;
  i=0;
  while(1){
    symbol=getch();
    switch(symbol)
    {
      case 80:++MenuIndex;  //DOWN: 115
	if(MenuIndex>c)
	{
	  MenuIndex=1;
	  a=holder;
	  gotoxy(leftX+1,a+(Height*acrossSubButtons)-acrossSubButtons);
	  textbackground(bkColor);
	  textcolor(textColor);
	  SetButtonText(ppSubString[c-1]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==1)
	  {
	    gotoxy(leftX+1,holder);
	    textcolor(ActiveTextColor);//@@@@@@@@@
	    textbackground(ActiveButtonColor);
	    SetButtonText(ppSubString[0]);
	    StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[0]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<i;temp++)
	      {
		a+=acrossSubButtons;
	      }
	      gotoxy(leftX+1,a-acrossSubButtons);
	      textcolor(textColor);
	      textbackground(bkColor);
	      SetButtonText(ppSubString[i-1]);
	      gotoxy(leftX+1,a);
	      textcolor(ActiveTextColor);//@@@@@@@@@
	      textbackground(ActiveButtonColor);
	      SetButtonText(ppSubString[i]);
	      StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 100:
	break;
      case 72:--MenuIndex;//UP: 119
	if(MenuIndex<=0)
	{
	  MenuIndex=c;
	  a=holder;
	  gotoxy(leftX+1,a);
	  textbackground(bkColor);
	  textcolor(textColor);
	  SetButtonText(ppSubString[0]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==c)
	  {
	    a=holder+(Height*acrossSubButtons)-acrossSubButtons;
	    gotoxy(leftX+1,a);
	    textcolor(ActiveTextColor);//@@@@@@@@@
	    textbackground(ActiveButtonColor);
	    SetButtonText(ppSubString[c-1]);
	    StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[c-1]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<(i+1);temp++)
	      {
			a+=acrossSubButtons;
	      }
	      gotoxy(leftX+1,a);
	      textcolor(textColor);
	      textbackground(bkColor);
	      SetButtonText(ppSubString[i+1]);
	      gotoxy(leftX+1,a-acrossSubButtons);
	      textcolor(ActiveTextColor);//@@@@@@@@@
	      textbackground(ActiveButtonColor);
	      SetButtonText(ppSubString[i]);
	      StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 97
	break;
      case 27:
	RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	StatusBar(1,ymax,80,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");
	goto EXIT;
      case 13:
	if((MenuIndex>0)&&(MenuIndex<=c))
	{
	unsigned int tempWinLen=0;
	  switch(MenuIndex)
	  {
	    case 1:
	      RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	      tempWinLen=45;
	      wx1=GetLeftXPos(tempWinLen);
	      WindowText(wx1,wy1,wx1+tempWinLen,wy1+4,winTEXT,winBK,"About me");
		  textcolor(winTEXT);
		  textbackground(winBK);
		  gotoxy(wx1+2,wy1+2);

		  memset(pathToTXT,'\0',sizeof(pathToTXT));
		  strcpy(pathToTXT,"avtor");
		  ConvertTXTtoBINARY(pathToTXT);
		  ShowBinaryInfo(wx1+2,wy1+2,tempWinLen,strres,DONTMODIFYTEXT);

		  getch();
		  RefreshDesctop(wx1,wy1,wx1+tempWinLen,wy1+4,desctopColor);
	      goto EXIT;     
	    case 2:
	       RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	      tempWinLen=78;
	      wx1=GetLeftXPos(tempWinLen);
	      WindowText(wx1,4,wx1+tempWinLen,4+19,winTEXT,winBK,"Ind.Task");
		  textcolor(winTEXT);
		  textbackground(winBK);
		  gotoxy(wx1+2,4+2); 


		  memset(pathToTXT,'\0',sizeof(pathToTXT));
		  strcpy(pathToTXT,"task");
		  ConvertTXTtoBINARY(pathToTXT);
		  ShowBinaryInfo(wx1+2,4+2,tempWinLen,strres,MODIFYTEXT);

		  getch();
		  RefreshDesctop(wx1,4,wx1+tempWinLen,4+19,desctopColor);
		  if(customerFlag)
		  {
		    CustomerInfo ();
		  }
	      goto EXIT;
	    case 3:
	      RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	      tempWinLen=60;
	      wx1=GetLeftXPos(tempWinLen);
	      WindowText(wx1,4,wx1+tempWinLen-10,4+13,winTEXT,winBK,"Help");
		  textcolor(winTEXT);
		  textbackground(winBK);
		  gotoxy(wx1+2,4+2);

		  memset(pathToTXT,'\0',sizeof(pathToTXT));
		  strcpy(pathToTXT,"help");
		  ConvertTXTtoBINARY(pathToTXT);
		  ShowBinaryInfo(wx1+2,4+2,tempWinLen,strres,MODIFYTEXT);

		  getch();
		  RefreshDesctop(wx1,4,wx1+tempWinLen-10,4+13,desctopColor);
	      goto EXIT;
	    default: break;
	  }
	  break; //!!????
	}//end of case 13:
	break;
    }//End of switch(symbol)
  }//End of while(1)
EXIT: //free(ar); //free memory
//*****************
 free(ppSubString);
 free(ar);
 free(pString);
}
//***********Work with Data Base********************
void WorkWithDataBase(int leftX,int leftY,char *string,...)
{
  int counter=0,Height=0,Width=0,i=0;
  va_list par;
  char *pString=string;
  va_start(par,string);
  while(pString!=NULL)
  {
    counter=0;
    while(*pString!='\0')
    {
      counter++;
      pString++;
    }//end of 2 while
    Height++;
    if(counter>Width)
    {
      Width=counter;
    }
    pString=va_arg(par,char*);
  }//end of 1 while
  va_end(par);
  int *ar;
  ar=(int*)calloc(Height,sizeof(int));
  if(ar==NULL)
  {
    printf("Error! No free memory!");
    exit(1);
  }
  for(i=0;i<Height;i++)
  {
    ar[i]=i+1;
  }
  char **ppSubString=NULL;
  ppSubString=(char**)calloc(Height,sizeof(char*));
  pString=string;
  va_start(par,string);
  i=0;
  while(pString!=NULL)
  {
     ppSubString[i]=pString;
     i++;
     pString=va_arg(par,char*);
   }
  va_end(par);
  Window(leftX,leftY,leftX+Width+1,(leftY+Height*acrossSubButtons)+1,textColor,bkColor);
  leftY++;
  int holder=leftY;
  for(i=0;i<Height;i++)
  {
    gotoxy(leftX+1,leftY);
    SetButtonText(ppSubString[i]);
    leftY+=acrossSubButtons;
  }
//****SubMenu Engine***************
  int c=Height;
  unsigned char temp=0;
  unsigned int a=0;
  MenuIndex=0;
  i=0;
  while(1){
    symbol=getch();
    switch(symbol)
    {
      case 80:++MenuIndex;  //DOWN: 115
	if(MenuIndex>c)
	{
	  MenuIndex=1;
	  a=holder;
	  gotoxy(leftX+1,a+(Height*acrossSubButtons)-acrossSubButtons);
	  textbackground(bkColor);
	  textcolor(textColor);
	  SetButtonText(ppSubString[c-1]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==1)
	  {
	    gotoxy(leftX+1,holder);
	    textcolor(ActiveTextColor);//@@@@@@@@@
	    textbackground(ActiveButtonColor);
	    SetButtonText(ppSubString[0]);
	    StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[0]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<i;temp++)
	      {
			a+=acrossSubButtons;
	      }
	      gotoxy(leftX+1,a-acrossSubButtons);
	      textcolor(textColor);
	      textbackground(bkColor);
	      SetButtonText(ppSubString[i-1]);
	      gotoxy(leftX+1,a);
	      textcolor(ActiveTextColor);//@@@@@@@@@
	      textbackground(ActiveButtonColor);
	      SetButtonText(ppSubString[i]);
	      StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 100:
	break;
      case 72:--MenuIndex;//UP: 119
	if(MenuIndex<=0)
	{
	  MenuIndex=c;
	  a=holder;
	  gotoxy(leftX+1,a);
	  textbackground(bkColor);//!!!!!
	  textcolor(textColor);
	  SetButtonText(ppSubString[0]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==c)
	  {
	    a=holder+(Height*acrossSubButtons)-acrossSubButtons;
	    gotoxy(leftX+1,a);
	    textcolor(ActiveTextColor);//@@@@@@@@@
	    textbackground(ActiveButtonColor);
	    SetButtonText(ppSubString[c-1]);
	    StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[c-1]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<(i+1);temp++)
	      {
			a+=acrossSubButtons;
	      }
	      gotoxy(leftX+1,a);
	      textcolor(textColor);
	      textbackground(bkColor);
	      SetButtonText(ppSubString[i+1]);
	      gotoxy(leftX+1,a-acrossSubButtons);
	      textcolor(ActiveTextColor);//@@@@@@@@@
	      textbackground(ActiveButtonColor);
	      SetButtonText(ppSubString[i]);
	      StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 97
	break;
      case 27:
	RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	StatusBar(1,ymax,80,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");///////
	goto EXIT;
      case 13:
	if((MenuIndex>0)&&(MenuIndex<=c))
	{
	  switch(MenuIndex)
	  {
	    case 1:
	      RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	      unsigned int tempWinLen=30;
	      wx1=GetLeftXPos(tempWinLen);
	      WindowText(wx1,wy1,wx1+tempWinLen,wy1+4,winTEXT,winBK,"Create DB");
		  textcolor(winTEXT);
		  textbackground(winBK);
		  gotoxy(wx1+2,wy1+2); cprintf("Name:");
		  gotoxy(wx1+2+7,wy1+2);
		  cprintf("                 ");
		  gotoxy(wx1+2+7,wy1+2);
		  gets(pathToDB);
		  RefreshDesctop(wx1,wy1,wx1+tempWinLen,wy1+4,desctopColor);
		  strcat(pathToDB,".dat");
		  strcpy(temp2,"temp");
		  strcat(temp2,pathToDB);
		  if(CreateDB(pathToDB))
		  {
			 char *s1="DataBase";
			 char *s2="created successfuly...  ";
			 int tempLen=strlen(s1)+strlen(s2)+strlen(pathToDB)+5;
			 wx1=GetLeftXPos(tempLen);
			 WindowText(wx1,wy1,wx1+tempLen,wy1+4,winTEXT,winBK,"[***]");
			 gotoxy(wx1+2,wy1+2); cprintf("%s %s %s",s1,pathToDB,s2);
			 getch();
			 RefreshDesctop(wx1,wy1,wx1+tempLen,wy1+4,desctopColor);
		  }
	      goto EXIT;
	    case 2: //Add Record
	      RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	      tempWinLen=35;
	      wx1=GetLeftXPos(tempWinLen);
	      int tx1=wx1+2,tx2=wx1+2+15,zx=0,f3=0;
	      WindowText(wx1,wy1,wx1+tempWinLen,wy1+4,winTEXT,winBK,"Add Item");
		  textcolor(winTEXT);
		  textbackground(winBK);
		  gotoxy(tx1,wy1+2); cprintf(" Add One Item: X ");
		  gotoxy(tx2+1,wy1+2); cprintf("  Load Items:");
		  gotoxy(tx1+15,wy1+2);
		  tx1+=15;
		  tx2=tx1+15;
		  zx=tx1;
		  while(1)
		  {
		    char ch=getch();
			switch(ch)
			{
			  case 9: case 75: case 77://TAB
					if(zx==tx1)
					{
					  f3=1;
					  gotoxy(zx-1,wy1+2);
					  cprintf("  ");
					  zx=tx2;
					  gotoxy(zx,wy1+2);
					  cprintf("X");
					}
					else
					{
					  f3=0;
					  gotoxy(zx-1,wy1+2);
					  cprintf("  ");
					  zx=tx1;
					  gotoxy(zx-1,wy1+2);
					  cprintf("X");
					}
					break;
			  case 27: 	RefreshDesctop(wx1,wy1,wx1+tempWinLen,wy1+4,desctopColor); 
				  goto EXIT;
			  case 13:
					RefreshDesctop(wx1,wy1,wx1+tempWinLen,wy1+4,desctopColor);
					if(f3==0)
					{
					    EditTechItem();

						FILE *DataBase=OpenDB(pathToDB,READnWRITE);
						fseek(DataBase, 0L, SEEK_END);
						fwrite(&item,sizeof(item),1,DataBase);
						fflush(DataBase);
						CloseDB(DataBase);
					}
					else
					{
						FILE *DataBase=OpenDB(pathToDB,READnWRITE);
						LoadDBRecords(DataBase,gNUM);
						CloseDB(DataBase);
					}
					goto EXIT;
			  default: break;	
			}
		  }
	      //goto EXIT;
	    case 3: //Delete
	      RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	      SpecialViewBrowser(pathToDB);
	      break;
	    case 4: //Edit!!! 
	      RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
          SpecialViewBrowser(pathToDB);
		  

	      goto EXIT;
	    case 5: //Delete All
	      RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	      StatusBar(1,ymax,80,ymax,textColor,bkColor,"Press: [ 'Enter' - to delete DataBase,  'Esc' -  to cancel the operation ]");
	      char *chW="Do you really want to delete all DB?";
	      tempWinLen=strlen(chW)+3;
	      wx1=GetLeftXPos(tempWinLen);
	      WindowText(wx1,wy1,wx1+tempWinLen,wy1+4,winTEXT,winBK,"Delete");
		  textcolor(winTEXT);
		  textbackground(winBK);
		  gotoxy(wx1+2,wy1+2); cprintf("%s",chW);
		  int answ=getch();
		  if(answ==13)
		  {
		    DeleteTechItem(pathToDB,1,DELETE_ALL);
		    WindowText(wx1,wy1,wx1+tempWinLen+2,wy1+4,winTEXT,winBK,"[***]");
		    textcolor(winTEXT);
		    textbackground(winBK);
		    tempWinLen=strlen(chW);
		    gotoxy(wx1+2,wy1+2); cprintf("Data Base %s deleted successfully! ",pathToDB);
		    getch();
		  }
		  RefreshDesctop(wx1,wy1,wx1+tempWinLen+10,wy1+4,desctopColor);
	      StatusBar(1,ymax,80,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");
	      goto EXIT;
	    default: break;
	  }
	  break; //!!????
	}//end of case 13:
	break;
    }//End of switch(symbol)
  }//End of while(1)
EXIT: //free(ar); //free memory
//*****************
 free(ppSubString);
 free(ar);
 free(pString);
}
//***********Search Information********************
void SearchInfo(int leftX,int leftY,char *string,...)
{
  int counter=0,Height=0,Width=0,i=0;
  va_list par;
  char *pString=string;
  va_start(par,string);
  while(pString!=NULL)
  {
    counter=0;
    while(*pString!='\0')
    {
      counter++;
      pString++;
    }//end of 2 while
    Height++;
    if(counter>Width)
    {
      Width=counter;
    }
    pString=va_arg(par,char*);
  }//end of 1 while
  va_end(par);
  int *ar;
  ar=(int*)calloc(Height,sizeof(int));
  if(ar==NULL)
  {
    printf("Error! No free memory!");
    exit(1);
  }
  for(i=0;i<Height;i++)
  {
    ar[i]=i+1;
  }
  char **ppSubString=NULL;
  ppSubString=(char**)calloc(Height,sizeof(char*));
  pString=string;
  va_start(par,string);
  i=0;
  while(pString!=NULL)
  {
     ppSubString[i]=pString;
     i++;
     pString=va_arg(par,char*);
   }
  va_end(par);
  Window(leftX,leftY,leftX+Width+1,(leftY+Height*acrossSubButtons)+1,textColor,bkColor);
  leftY++;
  int holder=leftY;
  for(i=0;i<Height;i++)
  {
    gotoxy(leftX+1,leftY);
    SetButtonText(ppSubString[i]);
    leftY+=acrossSubButtons;
  }
//****SubMenu Engine***************
  int c=Height;
  FILE *SearchDB; //temp DataBase
  unsigned char temp=0;
  unsigned int a=0;
  MenuIndex=0;
  i=0;
  while(1){
    symbol=getch();
    switch(symbol)
    {
      case 80:++MenuIndex;  //DOWN: 115
	if(MenuIndex>c)
	{
	  MenuIndex=1;
	  a=holder;
	  gotoxy(leftX+1,a+(Height*acrossSubButtons)-acrossSubButtons);
	  textbackground(bkColor);//!!!!!
	  textcolor(textColor);
	  SetButtonText(ppSubString[c-1]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==1)
	  {
	    gotoxy(leftX+1,holder);
	    textcolor(ActiveTextColor);//@@@@@@@@@
	    textbackground(ActiveButtonColor);
	    SetButtonText(ppSubString[0]);
	    StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[0]); 
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<i;temp++)
	      {
			a+=acrossSubButtons;
	      }
	      gotoxy(leftX+1,a-acrossSubButtons);
	      textcolor(textColor);
	      textbackground(bkColor);
	      SetButtonText(ppSubString[i-1]);
	      gotoxy(leftX+1,a);
	      textcolor(ActiveTextColor);//@@@@@@@@@
	      textbackground(ActiveButtonColor);
	      SetButtonText(ppSubString[i]);
	      StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[i]); 
	      break;
	    }
	  }
	i++;
	}//end of case 100:
	break;
      case 72:--MenuIndex;//UP: 119
	if(MenuIndex<=0)
	{
	  MenuIndex=c;
	  a=holder;
	  gotoxy(leftX+1,a);
	  textbackground(bkColor);//!!!!!
	  textcolor(textColor);
	  SetButtonText(ppSubString[0]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==c)
	  {
	    a=holder+(Height*acrossSubButtons)-acrossSubButtons;
	    gotoxy(leftX+1,a);
	    textcolor(ActiveTextColor);//@@@@@@@@@
	    textbackground(ActiveButtonColor);
	    SetButtonText(ppSubString[c-1]);
	    StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[c-1]); 
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<(i+1);temp++)
	      {
		    a+=acrossSubButtons;
	      }
	      gotoxy(leftX+1,a);
	      textcolor(textColor);
	      textbackground(bkColor);
	      SetButtonText(ppSubString[i+1]);
	      gotoxy(leftX+1,a-acrossSubButtons);
	      textcolor(ActiveTextColor);//@@@@@@@@@
	      textbackground(ActiveButtonColor);
	      SetButtonText(ppSubString[i]);
	      StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 97
	break;
      case 27:
	RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	StatusBar(1,ymax,80,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");
	goto EXIT;
      case 13:
		char *s1="records was found.";
	if((MenuIndex>0)&&(MenuIndex<=c))
	{
	  switch(MenuIndex)
	  {
	    case 1:	//Name
	      RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	      unsigned int tempWinLen=30;
	      wx1=GetLeftXPos(tempWinLen);
	      WindowText(wx1,wy1,wx1+tempWinLen,wy1+4,winTEXT,winBK,"Search by Name");
		  textcolor(winTEXT);
		  textbackground(winBK);
		  gotoxy(wx1+2,wy1+2); cprintf("Name:");
		  gotoxy(wx1+2+7,wy1+2);
		  textbackground(winTEXT);
		  cprintf("                    ");
		  char searchBuf[17];
		  memset(searchBuf,'\0',sizeof(searchBuf));
		  gotoxy(wx1+2+7,wy1+2);
		  textbackground(winTEXT);
		  textcolor(winBK);
		  searchBuf[0]=16;//how much to read
		  char *searchedName=cgets(searchBuf);
		  RefreshDesctop(wx1,wy1,wx1+tempWinLen,wy1+4,desctopColor);
		  unsigned int num=SearchTechItems(pathToDB,searchedName,SEARCH_BY_NAME);
		  int tempLen=strlen(s1)+5;
		  wx1=GetLeftXPos(tempLen);
		  WindowText(wx1,wy1,wx1+tempLen,wy1+4,winTEXT,winBK,"[***]");
		  gotoxy(wx1+2,wy1+2); cprintf("%u %s",num,s1);
		  getch();
		  RefreshDesctop(wx1,wy1,wx1+tempLen+10,wy1+4,desctopColor);
          
		if(num)
		  ViewBrowser(temp2); //obrobka oshibok!!!!!!
		  goto EXIT;
	    case 2:	//mainHaracteristic
	      RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	      tempWinLen=53;
	      wx1=GetLeftXPos(tempWinLen);
	      WindowText(wx1,wy1,wx1+tempWinLen,wy1+4,winTEXT,winBK,"Search by Haracteristic");
		  textcolor(winTEXT);
		  textbackground(winBK);
		  gotoxy(wx1+2,wy1+2); cprintf("Haracteristic:");
		  gotoxy(wx1+2+17,wy1+2);
		  textbackground(winTEXT);
		  cprintf("                                 ");
		  char searchHBuf[32];
		  memset(searchHBuf,'\0',sizeof(searchHBuf));
		  searchHBuf[0]=33;
		  gotoxy(wx1+2+17,wy1+2);
		  textbackground(winTEXT);
		  textcolor(winBK);
		  char *searchedHaracter=cgets(searchHBuf);
		  RefreshDesctop(wx1,wy1,wx1+tempWinLen,wy1+4,desctopColor);
		  num=SearchTechItems(pathToDB,searchedHaracter,SEARCH_BY_MAINHARACTER);
		  tempLen=strlen(s1)+5;
		  wx1=GetLeftXPos(tempLen);
		  WindowText(wx1,wy1,wx1+tempLen,wy1+4,winTEXT,winBK,"[***]");
		  gotoxy(wx1+2,wy1+2); cprintf("%u %s",num,s1);
		  getch();
		  RefreshDesctop(wx1,wy1,wx1+tempLen+10,wy1+4,desctopColor);
		  
		if(num)
		  ViewBrowser(temp2);

	      goto EXIT;
	    case 3:	//Firm
	      RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	      tempWinLen=20;
	      wx1=GetLeftXPos(tempWinLen);
	      WindowText(wx1,wy1,wx1+tempWinLen,wy1+4,winTEXT,winBK,"Search by Firm");
		  textcolor(winTEXT);
		  textbackground(winBK);
		  gotoxy(wx1+2,wy1+2); cprintf("Firm:");
		  gotoxy(wx1+2+7,wy1+2);
		  textbackground(winTEXT);
		  cprintf("          ");
		  char searchFBuf[12];
		  memset(searchFBuf,'\0',sizeof(searchFBuf));
		  searchFBuf[0]=11;
		  gotoxy(wx1+2+7,wy1+2);
		  textbackground(winTEXT);
		  textcolor(winBK);
		  char *searchedFirm=cgets(searchFBuf);
		  RefreshDesctop(wx1,wy1,wx1+tempWinLen,wy1+4,desctopColor);
		  num=SearchTechItems(pathToDB,searchedFirm,SEARCH_BY_FIRM);
		  tempLen=strlen(s1)+5;
		  wx1=GetLeftXPos(tempLen);
		  WindowText(wx1,wy1,wx1+tempLen,wy1+4,winTEXT,winBK,"[***]");
		  gotoxy(wx1+2,wy1+2); cprintf("%u %s",num,s1);
		  getch();
		  RefreshDesctop(wx1,wy1,wx1+tempLen+10,wy1+4,desctopColor);

		if(num)
		  ViewBrowser(temp2);

	      goto EXIT;
	    case 4:  //Price
	      RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	      tempWinLen=22;
	      wx1=GetLeftXPos(tempWinLen);
	      WindowText(wx1,wy1,wx1+tempWinLen,wy1+4,winTEXT,winBK,"Search by Price");
		  textcolor(winTEXT);
		  textbackground(winBK);
		  gotoxy(wx1+2,wy1+2); cprintf("Min:");
		  gotoxy(wx1+2+10,wy1+2); cprintf("Max:");
		  textcolor(winBK);
		  textbackground(winTEXT);
		  gotoxy(wx1+2+4,wy1+2); cprintf("    ");
		  gotoxy(wx1+2+14,wy1+2); cprintf("    ");
		  unsigned int min=0,max=0;
		  gotoxy(wx1+2+4,wy1+2);
		  char *res,resBuf[6];
		  memset(resBuf,0,sizeof(resBuf));
		  resBuf[0]=5;
		  res=cgets(resBuf);
		  min=atoi(res);
		  gotoxy(wx1+2+14,wy1+2);
		  memset(resBuf,0,sizeof(resBuf));
		  resBuf[0]=5;
		  res=cgets(resBuf);
		  max=atoi(res);
		  memset(resBuf,0,sizeof(resBuf));
		  RefreshDesctop(wx1,wy1,wx1+tempWinLen,wy1+4,desctopColor);
		  num=SearchTechItemsByPrice(pathToDB,min,max);
		  tempLen=strlen(s1)+5;
		  wx1=GetLeftXPos(tempLen);
		  WindowText(wx1,wy1,wx1+tempLen,wy1+4,winTEXT,winBK,"[***]");
		  gotoxy(wx1+2,wy1+2); cprintf("%u %s",num,s1);
		  getch();
		  RefreshDesctop(wx1,wy1,wx1+tempLen+10,wy1+4,desctopColor);

		if(num)
		  ViewBrowser(temp2);

	      goto EXIT;
	    default: break;
	  }
	  break; //!!????
	}//end of case 13:
	break;
    }//End of switch(symbol)
  }//End of while(1)
EXIT: 
//*****************
 free(ppSubString);
 free(ar);
 free(pString);
}
//***********Print Reasults********************
void PrintResults(int leftX,int leftY,char *string,...)
{
  int counter=0,Height=0,Width=0,i=0;
  FILE *help;
  va_list par;
  char *pString=string;
  va_start(par,string);
  while(pString!=NULL)
  {
    counter=0;
    while(*pString!='\0')
    {
      counter++;
      pString++;
    }//end of 2 while
    Height++;
    if(counter>Width)
    {
      Width=counter;
    }
    pString=va_arg(par,char*);
  }//end of 1 while
  va_end(par);
  int *ar;
  ar=(int*)calloc(Height,sizeof(int));
  if(ar==NULL)
  {
    printf("Error! No free memory!");
    exit(1);
  }
  for(i=0;i<Height;i++)
  {
    ar[i]=i+1;
  }
  char **ppSubString=NULL;
  ppSubString=(char**)calloc(Height,sizeof(char*));
  pString=string;
  va_start(par,string);
  i=0;
  while(pString!=NULL)
  {
     ppSubString[i]=pString;
     i++;
     pString=va_arg(par,char*);
   }
  va_end(par);
  Window(leftX,leftY,leftX+Width+1,(leftY+Height*acrossSubButtons)+1,textColor,bkColor);
  leftY++;
  int holder=leftY;
  for(i=0;i<Height;i++)
  {
    gotoxy(leftX+1,leftY);
    SetButtonText(ppSubString[i]);
    leftY+=acrossSubButtons;
  }
//****SubMenu Engine***************
  int c=Height;
  unsigned char temp=0;
  unsigned int a=0;
  MenuIndex=0;
  i=0;
  while(1){
    symbol=getch();
    switch(symbol)
    {
      case 80:++MenuIndex;  //DOWN: 115
	if(MenuIndex>c)
	{
	  MenuIndex=1;
	  a=holder;
	  gotoxy(leftX+1,a+(Height*acrossSubButtons)-acrossSubButtons);
	  textbackground(bkColor);
	  textcolor(textColor);
	  SetButtonText(ppSubString[c-1]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==1)
	  {
	    gotoxy(leftX+1,holder);
	    textcolor(ActiveTextColor);//@@@@@@@@@
	    textbackground(ActiveButtonColor);
	    SetButtonText(ppSubString[0]);
	    StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[0]); 
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<i;temp++)
	      {
		a+=acrossSubButtons;
	      }
	      gotoxy(leftX+1,a-acrossSubButtons);
	      textcolor(textColor);
	      textbackground(bkColor);
	      SetButtonText(ppSubString[i-1]);
	      gotoxy(leftX+1,a);
	      textcolor(ActiveTextColor);//@@@@@@@@@
	      textbackground(ActiveButtonColor);
	      SetButtonText(ppSubString[i]);
	      StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 100:
	break;
      case 72:--MenuIndex;//UP: 119
	if(MenuIndex<=0)
	{
	  MenuIndex=c;
	  a=holder;
	  gotoxy(leftX+1,a);
	  textbackground(bkColor);//!!!!!
	  textcolor(textColor);
	  SetButtonText(ppSubString[0]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==c)
	  {
	    a=holder+(Height*acrossSubButtons)-acrossSubButtons;
	    gotoxy(leftX+1,a);
	    textcolor(ActiveTextColor);//@@@@@@@@@
	    textbackground(ActiveButtonColor);
	    SetButtonText(ppSubString[c-1]);
	    StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[c-1]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<(i+1);temp++)
	      {
			a+=acrossSubButtons;
	      }
	      gotoxy(leftX+1,a);
	      textcolor(textColor);
	      textbackground(bkColor);
	      SetButtonText(ppSubString[i+1]);
	      gotoxy(leftX+1,a-acrossSubButtons);
	      textcolor(ActiveTextColor);//@@@@@@@@@
	      textbackground(ActiveButtonColor);
	      SetButtonText(ppSubString[i]);
	      StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 97
	break;
      case 27:
	RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	StatusBar(1,ymax,80,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");//////
	goto EXIT;
      case 13:
	FILE *txt,*db;
	if((MenuIndex>0)&&(MenuIndex<=c))
	{
	  unsigned int tempWinLen=0,tx1=0,tx2=0,f1=0,f2=0,zx=0,ch=0;
	  switch(MenuIndex)
	  {
	    case 1: //SortTechItemsByName
	      RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	      tempWinLen=20;
	      wx1=GetLeftXPos(tempWinLen);
	      tx1=wx1+3,tx2=wx1+3+8,zx=0,f1=0;
	      WindowText(wx1,wy1,wx1+tempWinLen,wy1+4,winTEXT,winBK,"Sort by Name");
		  textcolor(winTEXT);
		  textbackground(winBK);
		  gotoxy(tx1,wy1+2); cprintf("A-Z: X");
		  gotoxy(tx2,wy1+2); cprintf("Z-A:");
		  gotoxy(tx1+5,wy1+2);
		  tx1+=5;
		  tx2=tx1+8;
		  zx=tx1;
		  while(1)
		  {
		    ch=getch();
			switch(ch)
			{
			  case 9: case 75: case 77://TAB
					if(zx==tx1)
					{
					  f1=1;
					  gotoxy(zx-1,wy1+2);
					  cprintf("   ");
					  zx=tx2;
					  gotoxy(zx,wy1+2);
					  cprintf("X ");
					}
					else
					{
					  f1=0;
					  gotoxy(zx-1,wy1+2);
					  cprintf("   ");
					  zx=tx1;
					  gotoxy(zx,wy1+2);
					  cprintf("X ");
					}	
					break;
			  case 27: 	RefreshDesctop(wx1,wy1,wx1+tempWinLen,wy1+4,desctopColor); 
				  goto EXIT;
			  case 13:
					help=OpenDB(pathToDB,READONLY);
					if(GetTechItemSize(help))
					{
						RefreshDesctop(wx1,wy1,wx1+tempWinLen,wy1+4,desctopColor);
						if(f1==0)
						{
							SortTechItemsByName(pathToDB,SORT_BY_INCREASE);
						}
						else
						{
							SortTechItemsByName(pathToDB,SORT_BY_DECREASE);	
						}
					}
					else
					{
						char *s1="Data Base is empty.";  
						int tempLen=strlen(s1)+5;

						wx1=GetLeftXPos(tempLen);
						WindowText(wx1,wy1,wx1+tempLen,wy1+4,winTEXT,winBK,"[***]");
						gotoxy(wx1+2,wy1+2); cprintf("%s",s1);
						getch();
						RefreshDesctop(wx1,wy1,wx1+tempLen,wy1+4,desctopColor);
	
					}
					CloseDB(help);
					goto EXIT;
			  default: break;	
			}
		  }
	    //  goto EXIT;
	    case 2: //SortTechItemsByPrice
	      RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	      tempWinLen=30;
	      wx1=GetLeftXPos(tempWinLen);
	      tx1=wx1+2,tx2=wx1+2+15,zx=0,f2=0;
	      WindowText(wx1,wy1,wx1+tempWinLen,wy1+4,winTEXT,winBK,"Sort by Price");
		  textcolor(winTEXT);
		  textbackground(winBK);
		  gotoxy(tx1,wy1+2); cprintf("min->max: X");
		  gotoxy(tx2,wy1+2); cprintf("max->min:");
		  gotoxy(tx1+10,wy1+2);
		  tx1+=10;
		  tx2=tx1+15;
		  zx=tx1;
		  while(1)
		  {
		    ch=getch();
			switch(ch)
			{
			  case 9: case 75: case 77://TAB
					if(zx==tx1)
					{
					  f2=1;
					  gotoxy(zx-1,wy1+2);
					  cprintf("   ");
					  zx=tx2;
					  gotoxy(zx,wy1+2);
					  cprintf("X ");
					}
					else
					{
					  f2=0;
					  gotoxy(zx-1,wy1+2);
					  cprintf("   ");
					  zx=tx1;
					  gotoxy(zx,wy1+2);
					  cprintf("X ");
					}	
					break;
			  case 27: 	RefreshDesctop(wx1,wy1,wx1+tempWinLen,wy1+4,desctopColor); 
				  goto EXIT;
			  case 13:
					RefreshDesctop(wx1,wy1,wx1+tempWinLen,wy1+4,desctopColor);
					help=OpenDB(pathToDB,READONLY);
					if(GetTechItemSize(help))
					{
						if(f2==0)
						{
							SortTechItemsByPrice(pathToDB,SORT_BY_INCREASE);
						}
						else
						{
				    		SortTechItemsByPrice(pathToDB,SORT_BY_DECREASE);	
						}
					}
					else
					{
						char *s1="Data Base is empty.";  
						int tempLen=strlen(s1)+5;

						wx1=GetLeftXPos(tempLen);
						WindowText(wx1,wy1,wx1+tempLen,wy1+4,winTEXT,winBK,"[***]");
						gotoxy(wx1+2,wy1+2); cprintf("%s",s1);
						getch();
						RefreshDesctop(wx1,wy1,wx1+tempLen,wy1+4,desctopColor);
	
					}
					CloseDB(help);
					goto EXIT;
			  default: break;	
			}
		  }
	     // goto EXIT;
	    case 3: //Print All DataBase
	      RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	      txt=fopen("print.txt","w");
	      db=OpenDB(pathToDB,READONLY);
	      TechItem TechBuf;
	      memset(&TechBuf,0,sizeof(TechItem));
	      int across=0;
	      fprintf(txt,"%-15s %-30s %-10s %-8s %-8s %-7s\n","Name","Haracteristic",
	      "Firma","Price,$","Number","Artikul\n");
	      for(across=0;across<GetTechItemSize(db);across++)
	      {
		fseek(db,across*sizeof(TechItem),SEEK_SET);
		fread(&TechBuf,sizeof(TechItem),1,db);
		fprintf(txt,"%-15s %-30s %-10s %-8u %-8u %-7u\n",TechBuf.name,TechBuf.mainHaracter,
		TechBuf.firma,TechBuf.price,TechBuf.kilkist,TechBuf.m_Artikul);
		memset(&TechBuf,0,sizeof(TechItem));
	      }
	      CloseDB(db);
	      fclose(txt);
	      ViewBrowser(pathToDB);
	      goto EXIT;

	    default: break;
	  }
	  break; //!!????
	}//end of case 13:
	break;
    }//End of switch(symbol)
  }//End of while(1)
EXIT: //free(ar); //free memory
//*****************
 free(ppSubString);
 free(ar);
 free(pString);
}
//***********Customer's Busket********************
void Busket(int leftX,int leftY,char *string,...)
{
  int counter=0,Height=0,Width=0,i=0;
  va_list par;
  char *pString=string;
  va_start(par,string);
  while(pString!=NULL)
  {
    counter=0;
    while(*pString!='\0')
    {
      counter++;
      pString++;
    }//end of 2 while
    Height++;
    if(counter>Width)
    {
      Width=counter;
    }
    pString=va_arg(par,char*);
  }//end of 1 while
  va_end(par);
  int *ar;
  ar=(int*)calloc(Height,sizeof(int));
  if(ar==NULL)
  {
    printf("Error! No free memory!");
    exit(1);
  }
  for(i=0;i<Height;i++)
  {
    ar[i]=i+1;
  }
  char **ppSubString=NULL;
  ppSubString=(char**)calloc(Height,sizeof(char*));
  pString=string;
  va_start(par,string);
  i=0;
  while(pString!=NULL)
  {
     ppSubString[i]=pString;
     i++;
     pString=va_arg(par,char*);
   }
  va_end(par);
  Window(leftX,leftY,leftX+Width+1,(leftY+Height*acrossSubButtons)+1,textColor,bkColor);
  leftY++;
  int holder=leftY;
  for(i=0;i<Height;i++)
  {
    gotoxy(leftX+1,leftY);
    SetButtonText(ppSubString[i]);
    leftY+=acrossSubButtons;
  }
//****SubMenu Engine***************
  int c=Height;
  unsigned char temp=0;
  unsigned int a=0;
  MenuIndex=0;
  i=0;
  while(1){
    symbol=getch();
    switch(symbol)
    {
      case 80:++MenuIndex;  //DOWN: 115
	if(MenuIndex>c)
	{
	  MenuIndex=1;
	  a=holder;
	  gotoxy(leftX+1,a+(Height*acrossSubButtons)-acrossSubButtons);
	  textbackground(bkColor);
	  textcolor(textColor);
	  SetButtonText(ppSubString[c-1]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==1)
	  {
	    gotoxy(leftX+1,holder);
	    textcolor(ActiveTextColor);//@@@@@@@@@
	    textbackground(ActiveButtonColor);
	    SetButtonText(ppSubString[0]);
	    StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[0]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<i;temp++)
	      {
			a+=acrossSubButtons;
	      }
	      gotoxy(leftX+1,a-acrossSubButtons);
	      textcolor(textColor);
	      textbackground(bkColor);
	      SetButtonText(ppSubString[i-1]);
	      gotoxy(leftX+1,a);
	      textcolor(ActiveTextColor);//@@@@@@@@@
	      textbackground(ActiveButtonColor);
	      SetButtonText(ppSubString[i]);
	      StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 100:
	break;
      case 72:--MenuIndex;//UP: 119
	if(MenuIndex<=0)
	{
	  MenuIndex=c;
	  a=holder;
	  gotoxy(leftX+1,a);
	  textbackground(bkColor);
	  textcolor(textColor);
	  SetButtonText(ppSubString[0]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==c)
	  {
	    a=holder+(Height*acrossSubButtons)-acrossSubButtons;
	    gotoxy(leftX+1,a);
	    textcolor(ActiveTextColor);//@@@@@@@@@
	    textbackground(ActiveButtonColor);
	    SetButtonText(ppSubString[c-1]);
	    StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[c-1]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<(i+1);temp++)
	      {
			a+=acrossSubButtons;
	      }
	      gotoxy(leftX+1,a);
	      textcolor(textColor);
	      textbackground(bkColor);
	      SetButtonText(ppSubString[i+1]);
	      gotoxy(leftX+1,a-acrossSubButtons);
	      textcolor(ActiveTextColor);//@@@@@@@@@
	      textbackground(ActiveButtonColor);
	      SetButtonText(ppSubString[i]);
	      StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 97
	break;
      case 27:
	RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	StatusBar(1,ymax,80,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");
	goto EXIT;
      case 13:
	if((MenuIndex>0)&&(MenuIndex<=c))
	{
	  switch(MenuIndex)
	  {
	    case 1: //Make order
	      RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
		  ViewBrowser(pathToDB);
	      goto EXIT;
	    case 2: //Buy
	      RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
		  if(Credit==cust.Money)
		  {
			 char *s3="You have no buy anything,", *s4="Make your choice,please!";
			 int t=strlen(s3)+strlen(s4)+strlen(cust.FIO)+5;
			  wx1=GetLeftXPos(t);	
			 WindowText(wx1,wy1,wx1+t,wy1+4,winTEXT,winBK,"[***]");
			 gotoxy(wx1+2,wy1+2); cprintf("%s %s. %s",s3,cust.FIO,s4);
			 getch();
			 RefreshDesctop(wx1,wy1,wx1+t,wy1+4,desctopColor);
			 goto EXIT;
		  }
		  if(Credit>=0)  
		  {
			 char *s1="Thank's for buying,", *s2="Good luck!";
			 FILE *textDB=fopen("cstmr.txt","a+");
			 Customer custBuf;/////////////
			 memset(&custBuf,0,sizeof(Customer));
			 FILE *custDB=OpenDB(customerDB,READONLY);
			 fread(&custBuf,sizeof(Customer),1,custDB);
			 CloseDB(custDB);
			 FILE *busketDB=OpenDB(busket,READONLY);
			 TechItem *pBusketBuf=(TechItem*)calloc(GetTechItemSize(busketDB),sizeof(TechItem));
			 fread(pBusketBuf,sizeof(TechItem),GetTechItemSize(busketDB),busketDB);
			 

			 fprintf(textDB,"%-30s$%-4u\n",custBuf.FIO,custBuf.Money);
			 fprintf(textDB,"%s","  >>Buyed TechItems:+\n");
			 memset(&custBuf,0,sizeof(Customer));
			 for(int items=0;items<GetTechItemSize(busketDB);items++)
				 
			 {
					fprintf(textDB,"                    |-%-15s",pBusketBuf[items].name);
					fprintf(textDB,"%-30s",pBusketBuf[items].mainHaracter);
					fprintf(textDB,"%-10s",pBusketBuf[items].firma);
					fprintf(textDB,"$%-8u\n",pBusketBuf[items].price);
			 }
			 fprintf(textDB,"\n");
             CloseDB(busketDB); 
			 fclose(textDB);
			 memset(pBusketBuf,0,GetTechItemSize(busketDB));
			 free(pBusketBuf);


			 int t=strlen(s1)+strlen(s2)+strlen(cust.FIO)+5;
			  wx1=GetLeftXPos(t);	
			 WindowText(wx1,wy1,wx1+t,wy1+4,winTEXT,winBK,"[***]");
			 gotoxy(wx1+2,wy1+2); cprintf("%s %s. %s",s1,cust.FIO,s2);
			 getch();
			 RefreshDesctop(wx1,wy1,wx1+t,wy1+4,desctopColor);
			 RefreshDesctop(1,19,80,22,desctopColor);
			 customerFlag=0;
		  }
		  else 
		  {
			  char *q="Not enough money. Please delete some goods and try again.";
			  int t2=strlen(q)+2;
			 wx1=GetLeftXPos(t2);
			 WindowText(wx1,wy1,wx1+t2,wy1+4,winTEXT,winBK,"[***]");
			 gotoxy(wx1+2,wy1+2); cprintf("%s",q);
			 getch();
			 RefreshDesctop(wx1,wy1,wx1+t2,wy1+4,desctopColor);
			 DeleteExcessItems(busket);
		  }
	      goto EXIT;
	    default: break;
	  }
	  break; 
	}//end of case 13:
	break;
    }//End of switch(symbol)
  }//End of while(1)
EXIT: //free(ar); //free memory
//*****************
 free(ppSubString);
 free(ar);
 free(pString);
}
//***********Exit********************
void Exit(int leftX,int leftY,char *string,...)
{
  int counter=0,Height=0,Width=0,i=0;
  va_list par;
  char *pString=string;
  va_start(par,string);
  while(pString!=NULL)
  {
    counter=0;
    while(*pString!='\0')
    {
      counter++;
      pString++;
    }//end of 2 while
    Height++;
    if(counter>Width)
    {
      Width=counter;
    }
    pString=va_arg(par,char*);
  }//end of 1 while
  va_end(par);
  int *ar;
  ar=(int*)calloc(Height,sizeof(int));
  if(ar==NULL)
  {
    printf("Error! No free memory!");
    exit(1);
  }
  for(i=0;i<Height;i++)
  {
    ar[i]=i+1;
  }
  char **ppSubString=NULL;
  ppSubString=(char**)calloc(Height,sizeof(char*));
  pString=string;
  va_start(par,string);
  i=0;
  while(pString!=NULL)
  {
     ppSubString[i]=pString;
     i++;
     pString=va_arg(par,char*);
   }
  va_end(par);
  Window(leftX,leftY,leftX+Width+1,(leftY+Height*acrossSubButtons)+1,textColor,bkColor);
  leftY++;
  int holder=leftY;
  for(i=0;i<Height;i++)
  {
    gotoxy(leftX+1,leftY);
    SetButtonText(ppSubString[i]);
    leftY+=acrossSubButtons;
  }
//****SubMenu Engine***************
  int c=Height;
  unsigned char temp=0;
  unsigned int a=0;
  MenuIndex=0;
  i=0;
  while(1){
    symbol=getch();
    switch(symbol)
    {
      case 80:++MenuIndex;  //DOWN: 115
	if(MenuIndex>c)
	{
	  MenuIndex=1;
	  a=holder;
	  gotoxy(leftX+1,a+(Height*acrossSubButtons)-acrossSubButtons);
	  textbackground(bkColor);//!!!!!
	  textcolor(textColor);
	  SetButtonText(ppSubString[c-1]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==1)
	  {
	    gotoxy(leftX+1,holder);
	    textcolor(ActiveTextColor);//@@@@@@@@@
	    textbackground(ActiveButtonColor);
	    SetButtonText(ppSubString[0]);
	    StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[0]); //////
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<i;temp++)
	      {
			a+=acrossSubButtons;
	      }
	      gotoxy(leftX+1,a-acrossSubButtons);
	      textcolor(textColor);
	      textbackground(bkColor);
	      SetButtonText(ppSubString[i-1]);
	      gotoxy(leftX+1,a);
	      textcolor(ActiveTextColor);//@@@@@@@@@
	      textbackground(ActiveButtonColor);
	      SetButtonText(ppSubString[i]);
	      StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 100:
	break;
      case 72:--MenuIndex;//UP: 119
	if(MenuIndex<=0)
	{
	  MenuIndex=c;
	  a=holder;
	  gotoxy(leftX+1,a);
	  textbackground(bkColor);
	  textcolor(textColor);
	  SetButtonText(ppSubString[0]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==c)
	  {
	    a=holder+(Height*acrossSubButtons)-acrossSubButtons;
	    gotoxy(leftX+1,a);
	    textcolor(ActiveTextColor);//@@@@@@@@@
	    textbackground(ActiveButtonColor);
	    SetButtonText(ppSubString[c-1]);
	    StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[c-1]); 
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<(i+1);temp++)
	      {
			a+=acrossSubButtons;
	      }
	      gotoxy(leftX+1,a);
	      textcolor(textColor);
	      textbackground(bkColor);
	      SetButtonText(ppSubString[i+1]);
	      gotoxy(leftX+1,a-acrossSubButtons);
	      textcolor(ActiveTextColor);//@@@@@@@@@
	      textbackground(ActiveButtonColor);
	      SetButtonText(ppSubString[i]);
	      StatusBar(1,ymax,80,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 97
	break;
      case 27:
	RefreshDesctop(leftX,holder-1,leftX+Width+1,holder+(Height*acrossSubButtons),desctopColor);
	StatusBar(1,ymax,80,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");
	goto EXIT;
      case 13:
	if((MenuIndex>0)&&(MenuIndex<=c))
	{
	  exit(0);
	  break; //!!????
	}//end of case 13:
	break;
    }//End of switch(symbol)
  }//End of while(1)
EXIT: //free(ar); //free memory
//*****************
 free(ppSubString);
 free(ar);
 free(pString);
}
//*******View Browser*********

int ViewBrowser(char *path)
{
	FILE *DataBase=OpenDB(path,READnWRITE);
    int i=0,DBIndex=0,holder=leftYY+1,N=0;
    N=GetTechItemSize(DataBase);
	if(N==0)
	{
	 	  char *s1="Data Base is empty.";  
		  int tempLen=strlen(s1)+5;
		  wx1=GetLeftXPos(tempLen);
		  WindowText(wx1,wy1,wx1+tempLen,wy1+4,winTEXT,winBK,"[***]");
		  gotoxy(wx1+2,wy1+2); cprintf("%s",s1);
		  getch();
		  RefreshDesctop(wx1,wy1,wx1+tempLen,wy1+4,desctopColor);
		return FALSE;
	}
    TechItem item;
	if(N<=15)
	{
      WindowBG(leftXX-1,leftYY-1,80,leftYY+(N*acrossSubButtons)+1,ACTIVE_LINE_STYLE,bkColor);
	}
    else
	{
		WindowBG(leftXX-1,leftYY-1,80,leftYY+20,ACTIVE_LINE_STYLE,bkColor);
	}
	gotoxy(leftXX,leftYY); 
    textcolor(4);
    cprintf("%-10s     %-30s%-10s%-8s%-8s%-7s",sName,sHaracter,sFirma,sPrice,sNumber,sArtikul);
	textcolor(NON_ACTIVE_LINE_TEXT_STYLE); 
    for(i=0;i<N;i++)
	{
	gotoxy(leftXX,leftYY+acrossSubButtons+i);
	    fseek(DataBase,i*sizeof(TechItem),SEEK_SET);
		fread(&item,sizeof(TechItem),1,DataBase);
		ShowTechItem(item);
		memset(&item,0,sizeof(TechItem));
	}
	StatusBar(1,ymax,80,ymax,textColor,bkColor,"Press: [ 'Z' - to put TechItems in your busket,  'Esc' - to exit ]");
  int *ar;
  ar=(int*)calloc(N,sizeof(int));
  if(ar==NULL)
  {
    printf("Error! No free memory!");
    exit(1);
  }
  for(i=0;i<N;i++)
  {
    ar[i]=i+1;
  }
  char symbolV;
  int c=N;
  unsigned char temp=0;
  unsigned int a=leftYY+1;////
  DBIndex=0;
  i=0;
  while(1){
    symbolV=getch();
	memset(&item,0,sizeof(TechItem));
    switch(symbolV)
    {
      case 80:++DBIndex;  //DOWN: 115
	if(DBIndex>c)
	{
	  DBIndex=1;
	  a=leftYY+1;
	  gotoxy(leftXX,a+(N*acrossSubButtons)-acrossSubButtons);  
	  textbackground(bkColor);
	  textcolor(NON_ACTIVE_LINE_TEXT_STYLE);
	  //SetButtonText(ppSubString[c-1]);
	  fseek(DataBase, (N-1)*sizeof(TechItem), SEEK_SET); 
	  fread(&item, sizeof(TechItem),1,DataBase);
	  //gotoxy(leftXX,7+1+i);
	  ShowTechItem(item);
	}
	while((DBIndex<=c)&&(DBIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(DBIndex==1)
	  {
	    gotoxy(leftXX,a); //+1
	    textcolor(ACTIVE_LINE_TEXT_STYLE);
	    textbackground(ACTIVE_LINE_STYLE);
	    //SetButtonText(ppSubString[0]);
	    fseek(DataBase, (DBIndex-1)*sizeof(TechItem), SEEK_SET); 
	    fread(&item, sizeof(TechItem),1,DataBase);
	    ShowTechItem(item);

	    break;
	  }
	  else
	  {
	    if(DBIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<i;temp++)
	      {
		    a+=acrossSubButtons;
	      }
	      gotoxy(leftXX,a-acrossSubButtons);
	      textcolor(NON_ACTIVE_LINE_TEXT_STYLE);
	      textbackground(bkColor);

		  fseek(DataBase,(DBIndex-2)*sizeof(TechItem), SEEK_SET);
	      fread(&item, sizeof(TechItem),1,DataBase);
	      ShowTechItem(item);

	      gotoxy(leftXX,a);
	      textcolor(ACTIVE_LINE_TEXT_STYLE);
	      textbackground(ACTIVE_LINE_STYLE);

	      fseek(DataBase,(DBIndex-1)*sizeof(TechItem), SEEK_SET);
	      fread(&item, sizeof(TechItem),1,DataBase);
	      ShowTechItem(item);

	      break;
	    }
	  }
	i++;
	}//end of case 100:
	break;
	//////////++++++UP++++++///////////
      case 72:--DBIndex;//UP: 119
	if(DBIndex<=0)
	{
	  DBIndex=c;
	  a=holder;
	  gotoxy(leftXX,a);
	  textbackground(bkColor);//!!!!!
	  textcolor(NON_ACTIVE_LINE_TEXT_STYLE);

	  fseek(DataBase, 0*sizeof(TechItem), SEEK_SET);
	  fread(&item, sizeof(TechItem),1,DataBase);
	  ShowTechItem(item);
	}
	while((DBIndex<=c)&&(DBIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(DBIndex==c)
	  {
	    a=holder+(N*acrossSubButtons)-acrossSubButtons;
	    gotoxy(leftXX,a);
	    textcolor(ACTIVE_LINE_TEXT_STYLE);
	    textbackground(ACTIVE_LINE_STYLE);

	  fseek(DataBase, (DBIndex-1)*sizeof(TechItem), SEEK_SET);
	  fread(&item, sizeof(TechItem),1,DataBase);
	  ShowTechItem(item);

	    break;
	  }
	  else
	  {
	    if(DBIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<(i+1);temp++)
	      {
		    a+=acrossSubButtons;
	      }
	      gotoxy(leftXX,a);
	      textcolor(NON_ACTIVE_LINE_TEXT_STYLE);
	      textbackground(bkColor);

		  fseek(DataBase,(DBIndex)*sizeof(TechItem), SEEK_SET);
	      fread(&item, sizeof(TechItem),1,DataBase);
	      ShowTechItem(item);

	      gotoxy(leftXX,a-acrossSubButtons);
	      textcolor(ACTIVE_LINE_TEXT_STYLE);
	      textbackground(ACTIVE_LINE_STYLE);

		  fseek(DataBase,(DBIndex-1)*sizeof(TechItem), SEEK_SET);
	      fread(&item, sizeof(TechItem),1,DataBase);
	      ShowTechItem(item);

	      break;
	    }
	  }
	i++;
	}//end of case 97
	break;
      case 27:
	    if(N<=15)
		{
		  RefreshDesctop(leftXX-1,leftYY-1,80,leftYY+(N*acrossSubButtons)+1,desctopColor);
	}
		else
		{
		  RefreshDesctop(leftXX-1,leftYY-1,80,leftYY+20,desctopColor);
		}
		StatusBar(1,ymax,80,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");
	    goto EXIT;

	  case  ZAMOVYTY1:
	  case  ZAMOVYTY2:
		  if(customerFlag)
		 {
		    CloseDB(DataBase);

			MakeOrder(path,DBIndex-1);//zamovlenna!!!!

		    DataBase=OpenDB(path,READnWRITE);	
		    CustomerInfo ();
			if(N<=15)
			{
				RefreshDesctop(leftXX-1,leftYY-1,80,leftYY+(N*acrossSubButtons)+1,desctopColor);
			}
			else
			{
				RefreshDesctop(leftXX-1,leftYY-1,80,leftYY+20,desctopColor);
			}
			//**PaintAgain**///
			if(N<=15)
			{
				WindowBG(leftXX-1,leftYY-1,80,leftYY+(N*acrossSubButtons)+1,ACTIVE_LINE_STYLE,bkColor);
			}
			else
			{
				WindowBG(leftXX-1,leftYY-1,80,leftYY+20,ACTIVE_LINE_STYLE,bkColor);
			}
			gotoxy(leftXX,leftYY); //leftYY=6
			textcolor(4);
			cprintf("%-10s     %-30s%-10s%-8s%-8s%-7s",sName,sHaracter,sFirma,sPrice,sNumber,sArtikul);
			textcolor(NON_ACTIVE_LINE_TEXT_STYLE); 
			for(i=0;i<N;i++)
			{
				gotoxy(leftXX,leftYY+acrossSubButtons+i);
				fseek(DataBase,i*sizeof(TechItem),SEEK_SET);
				fread(&item,sizeof(TechItem),1,DataBase);
				ShowTechItem(item);
				memset(&item,0,sizeof(TechItem));
			}
		  }
	        break;
    }//End of switch(symbol)
  }//End of while(1)
EXIT:
//*****************
  CloseDB(DataBase);
  free(ar);
  return TRUE;
}
//*******View Browser for system programmer****///
int SpecialViewBrowser(char *path)
{
	FILE *DataBase=OpenDB(path,READnWRITE);
    int i=0,DBIndex=0,holder=leftYY+1,N=0;
    N=GetTechItemSize(DataBase);
	char *s1="Data Base is empty.";  
	int tempLen=strlen(s1)+5;
	if(N==0)
	{
		  wx1=GetLeftXPos(tempLen);
		  WindowText(wx1,wy1,wx1+tempLen,wy1+4,winTEXT,winBK,"[***]");
		  gotoxy(wx1+2,wy1+2); cprintf("%s",s1);
		  getch();
		  RefreshDesctop(wx1,wy1,wx1+tempLen,wy1+4,desctopColor);
		return FALSE;
	}
    TechItem item;
	if(N<=15)
	{
      WindowBG(leftXX-1,leftYY-1,80,leftYY+(N*acrossSubButtons)+1,ACTIVE_LINE_STYLE,bkColor);
	}
    else
	{
		WindowBG(leftXX-1,leftYY-1,80,leftYY+20,ACTIVE_LINE_STYLE,bkColor);
	}
	gotoxy(leftXX,leftYY); //leftYY=6
    textcolor(4);
    cprintf("%-10s     %-30s%-10s%-8s%-8s%-7s",sName,sHaracter,sFirma,sPrice,sNumber,sArtikul);
	textcolor(NON_ACTIVE_LINE_TEXT_STYLE); 
    for(i=0;i<N;i++)
	{
	gotoxy(leftXX,leftYY+acrossSubButtons+i);
	    fseek(DataBase,i*sizeof(TechItem),SEEK_SET);
		fread(&item,sizeof(TechItem),1,DataBase);
		ShowTechItem(item);
		memset(&item,0,sizeof(TechItem));
	}
	StatusBar(1,ymax,80,ymax,textColor,bkColor,"Press: [ 'D' - to delete,  'E' - to edit,  'Esc' - to exit ]");
  int *ar;
  ar=(int*)calloc(N,sizeof(int));
  if(ar==NULL)
  {
    printf("Error! No free memory!");
    exit(1);
  }
  for(i=0;i<N;i++)
  {
    ar[i]=i+1;
  }
  char symbolV;
  int c=N;
  unsigned char temp=0;
  unsigned int a=leftYY+1;
  DBIndex=0;
  i=0;
  while(1){
    c=N;
	if(!c)
	{
		  wx1=GetLeftXPos(tempLen);
		  WindowText(wx1,wy1,wx1+tempLen,wy1+4,winTEXT,winBK,"[***]");
		  gotoxy(wx1+2,wy1+2); cprintf("%s",s1);
		  getch();
		  RefreshDesctop(wx1,wy1,wx1+tempLen,wy1+4,desctopColor);
		  RefreshDesctop(leftXX-1,leftYY-1,80,leftYY+(N*acrossSubButtons)+1,desctopColor);
		  goto EXIT;	  
	}
    symbolV=getch();
	memset(&item,0,sizeof(TechItem));
    switch(symbolV)
    {
      case 80:++DBIndex;  //DOWN: 115
	if(DBIndex>c)
	{
	  DBIndex=1;
	  a=leftYY+1;
	  gotoxy(leftXX,a+(N*acrossSubButtons)-acrossSubButtons);  
	  textbackground(bkColor);
	  textcolor(NON_ACTIVE_LINE_TEXT_STYLE);

	  fseek(DataBase, (N-1)*sizeof(TechItem), SEEK_SET); 
	  fread(&item, sizeof(TechItem),1,DataBase);

	  ShowTechItem(item);
	}
	while((DBIndex<=c)&&(DBIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(DBIndex==1)
	  {
	    gotoxy(leftXX,a); 
	    textcolor(ACTIVE_LINE_TEXT_STYLE);
	    textbackground(ACTIVE_LINE_STYLE);

	    fseek(DataBase, (DBIndex-1)*sizeof(TechItem), SEEK_SET);
	    fread(&item, sizeof(TechItem),1,DataBase);

	    ShowTechItem(item);

	    break;
	  }
	  else
	  {
	    if(DBIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<i;temp++)
	      {
		    a+=acrossSubButtons;
	      }
	      gotoxy(leftXX,a-acrossSubButtons);
	      textcolor(NON_ACTIVE_LINE_TEXT_STYLE);
	      textbackground(bkColor);

	      fseek(DataBase,(DBIndex-2)*sizeof(TechItem), SEEK_SET);
	      fread(&item, sizeof(TechItem),1,DataBase);
	      ShowTechItem(item);

	      gotoxy(leftXX,a);
	      textcolor(ACTIVE_LINE_TEXT_STYLE);
	      textbackground(ACTIVE_LINE_STYLE);

	      fseek(DataBase,(DBIndex-1)*sizeof(TechItem), SEEK_SET);
	      fread(&item, sizeof(TechItem),1,DataBase);
	      ShowTechItem(item);
	      break;
	    }
	  }
	i++;
	}//end of case 100:
	break;
	//////////++++++UP++++++///////////
      case 72:--DBIndex;//UP: 119
	if(DBIndex<=0)
	{
	  DBIndex=c;
	  a=holder;
	  gotoxy(leftXX,a);
	  textbackground(bkColor);//!!!!!
	  textcolor(NON_ACTIVE_LINE_TEXT_STYLE);

	  fseek(DataBase, 0*sizeof(TechItem), SEEK_SET);
	  fread(&item, sizeof(TechItem),1,DataBase);
	  ShowTechItem(item);
	}
	while((DBIndex<=c)&&(DBIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(DBIndex==c)
	  {
	    a=holder+(N*acrossSubButtons)-acrossSubButtons;
	    gotoxy(leftXX,a);
	    textcolor(ACTIVE_LINE_TEXT_STYLE);
	    textbackground(ACTIVE_LINE_STYLE);

	  fseek(DataBase, (DBIndex-1)*sizeof(TechItem), SEEK_SET);
	  fread(&item, sizeof(TechItem),1,DataBase);
	  ShowTechItem(item);

	    break;
	  }
	  else
	  {
	    if(DBIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<(i+1);temp++)
	      {
		    a+=acrossSubButtons;
	      }
	      gotoxy(leftXX,a);
	      textcolor(NON_ACTIVE_LINE_TEXT_STYLE);
	      textbackground(bkColor);

		  fseek(DataBase,(DBIndex)*sizeof(TechItem), SEEK_SET);
	      fread(&item, sizeof(TechItem),1,DataBase);
	      ShowTechItem(item);

	      gotoxy(leftXX,a-acrossSubButtons);
	      textcolor(ACTIVE_LINE_TEXT_STYLE);
	      textbackground(ACTIVE_LINE_STYLE);

		  fseek(DataBase,(DBIndex-1)*sizeof(TechItem), SEEK_SET);
	      fread(&item, sizeof(TechItem),1,DataBase);
	      ShowTechItem(item);

	      break;
	    }
	  }
	i++;
	}//end of case 97
	break;
      case 27:
	    if(N<=15)
		{
		  RefreshDesctop(leftXX-1,leftYY-1,80,leftYY+(N*acrossSubButtons)+1,desctopColor);
		}
		else
		{
		  RefreshDesctop(leftXX-1,leftYY-1,80,leftYY+20,desctopColor);
		}
		StatusBar(1,ymax,80,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");
	    goto EXIT;
	  case  BACKSPACE:
      case  DELETE1:
      case  DELETE2:
		    DeleteTechItem(pathToDB,DBIndex-1,DELETE_ONE);
			int FirstSize=N;
			N=GetTechItemSize(DataBase);
			if(N<=15)
			{
				RefreshDesctop(leftXX-1,leftYY-1,80,leftYY+(FirstSize*acrossSubButtons)+1,desctopColor);
			}
			else
			{
				RefreshDesctop(leftXX-1,leftYY-1,80,leftYY+20,desctopColor);
			}
			//**PaintAgain**///
			if(N<=15)
			{
				WindowBG(leftXX-1,leftYY-1,80,leftYY+(N*acrossSubButtons)+1,ACTIVE_LINE_STYLE,bkColor);
			}
			else
			{
				WindowBG(leftXX-1,leftYY-1,80,leftYY+20,ACTIVE_LINE_STYLE,bkColor);
			}
			gotoxy(leftXX,leftYY); //leftYY=6
			textcolor(4);
			cprintf("%-10s     %-30s%-10s%-8s%-8s%-7s",sName,sHaracter,sFirma,sPrice,sNumber,sArtikul);
			textcolor(NON_ACTIVE_LINE_TEXT_STYLE); 
			for(i=0;i<N;i++)
			{
				gotoxy(leftXX,leftYY+acrossSubButtons+i);
				fseek(DataBase,i*sizeof(TechItem),SEEK_SET);
				fread(&item,sizeof(TechItem),1,DataBase);
				ShowTechItem(item);
				memset(&item,0,sizeof(TechItem));
			}
	        break;
	  case  EDIT1:
      case  EDIT2:
		    EditTechItem();
			EditTechItemRecord(pathToDB,DBIndex-1);
			FirstSize=N;
			N=GetTechItemSize(DataBase);
			if(N<=15)
			{
				RefreshDesctop(leftXX-1,leftYY-1,80,leftYY+(FirstSize*acrossSubButtons)+1,desctopColor);
			}
			else
			{
				RefreshDesctop(leftXX-1,leftYY-1,80,leftYY+20,desctopColor);
			}
			//**PaintAgain**///
			if(N<=15)
			{
				WindowBG(leftXX-1,leftYY-1,80,leftYY+(N*acrossSubButtons)+1,ACTIVE_LINE_STYLE,bkColor);
			}
			else
			{
				WindowBG(leftXX-1,leftYY-1,80,leftYY+20,ACTIVE_LINE_STYLE,bkColor);
			}
			gotoxy(leftXX,leftYY); //leftYY=6
			textcolor(4);
			cprintf("%-10s     %-30s%-10s%-8s%-8s%-7s",sName,sHaracter,sFirma,sPrice,sNumber,sArtikul);
			textcolor(NON_ACTIVE_LINE_TEXT_STYLE); 
			for(i=0;i<N;i++)
			{
				gotoxy(leftXX,leftYY+acrossSubButtons+i);
				fseek(DataBase,i*sizeof(TechItem),SEEK_SET);
				fread(&item,sizeof(TechItem),1,DataBase);
				ShowTechItem(item);
				memset(&item,0,sizeof(TechItem));
			}
	        break;
    }//End of switch(symbol)
  }//End of while(1)
EXIT:
//*****************
  CloseDB(DataBase);
  free(ar);
  return TRUE;
}
//*******Customer Info****************
void CustomerInfo (void)
{
	if(customerFlag)
	{
		WindowText(1,19,80,22,winTEXT,winBK,"Customer Info");
		  textcolor(winTEXT);
		  textbackground(winBK);
		  gotoxy(3,19+1);	cprintf("Customer FIO:      %s",cust.FIO);
		  gotoxy(3,19+2);
		  if(Credit>=0)
							cprintf("Available Money:   %d",Credit);
		  else
		  {
							cprintf("Available Money:   %d",0);
		  }
			gotoxy(3+40,19+2);
			if(Credit<0)
			{
					textcolor(4);		cprintf("Borg:              %d",Credit*(-1));
			}
			else
			{
							cprintf("Borg:              %d",0);
			}
		  textcolor(ACTIVE_LINE_STYLE);  
	}
}
int DeleteExcessItems(char *path)
{
	FILE *DataBase=OpenDB(busket,READnWRITE);
    int i=0,DBIndex=0,holder=leftYY+1,N=0;
    N=GetTechItemSize(DataBase);
	char *s1="Your busket is empty.";  
	int tempLen=strlen(s1)+5;
	if(N==0)
	{
		  wx1=GetLeftXPos(tempLen);
		  WindowText(wx1,wy1,wx1+tempLen,wy1+4,winTEXT,winBK,"[***]");
		  gotoxy(wx1+2,wy1+2); cprintf("%s",s1);
		  getch();
		  RefreshDesctop(wx1,wy1,wx1+tempLen,wy1+4,desctopColor);
		return FALSE;
	}
    TechItem item;
	if(N<=15)
	{
      WindowBG(leftXX-1,leftYY-1,80,leftYY+(N*acrossSubButtons)+1,ACTIVE_LINE_STYLE,bkColor);
	}
    else
	{
		WindowBG(leftXX-1,leftYY-1,80,leftYY+20,ACTIVE_LINE_STYLE,bkColor);
	}
	gotoxy(leftXX,leftYY); //leftYY=6
    textcolor(4);
    cprintf("%-10s     %-30s%-10s%-8s%-8s%-7s",sName,sHaracter,sFirma,sPrice,sNumber,sArtikul);
	textcolor(NON_ACTIVE_LINE_TEXT_STYLE); 
    for(i=0;i<N;i++)
	{
	gotoxy(leftXX,leftYY+acrossSubButtons+i);
	    fseek(DataBase,i*sizeof(TechItem),SEEK_SET);
		fread(&item,sizeof(TechItem),1,DataBase);
		ShowTechItem(item);
		memset(&item,0,sizeof(TechItem));
	}
	StatusBar(1,ymax,80,ymax,textColor,bkColor,"Press: ['D' - to delete TechItems from the busket,  'Esc' - to exit]");
  int *ar;
  ar=(int*)calloc(N,sizeof(int));
  if(ar==NULL)
  {
    printf("Error! No free memory!");
    exit(1);
  }
  for(i=0;i<N;i++)
  {
    ar[i]=i+1;
  }
  char symbolV;
  int c=N;
  unsigned char temp=0;
  unsigned int a=leftYY+1;
  DBIndex=0;
  i=0;
  while(1){
    c=N;
	if(!c)
	{
		  wx1=GetLeftXPos(tempLen);
		  WindowText(wx1,wy1,wx1+tempLen,wy1+4,winTEXT,winBK,"[***]");
		  gotoxy(wx1+2,wy1+2); cprintf("%s",s1);
		  getch();
		  RefreshDesctop(wx1,wy1,wx1+tempLen,wy1+4,desctopColor);
		  RefreshDesctop(leftXX-1,leftYY-1,80,leftYY+(N*acrossSubButtons)+1,desctopColor);
		  goto EXIT;	  
	}
    symbolV=getch();
	memset(&item,0,sizeof(TechItem));
    switch(symbolV)
    {
      case 80:++DBIndex;  //DOWN: 115
	if(DBIndex>c)
	{
	  DBIndex=1;
	  a=leftYY+1;
	  gotoxy(leftXX,a+(N*acrossSubButtons)-acrossSubButtons);  
	  textbackground(bkColor);
	  textcolor(NON_ACTIVE_LINE_TEXT_STYLE);

	  fseek(DataBase, (N-1)*sizeof(TechItem), SEEK_SET); 
	  fread(&item, sizeof(TechItem),1,DataBase);

	  ShowTechItem(item);
	}
	while((DBIndex<=c)&&(DBIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(DBIndex==1)
	  {
	    gotoxy(leftXX,a); //+1
	    textcolor(ACTIVE_LINE_TEXT_STYLE);
	    textbackground(ACTIVE_LINE_STYLE);

	    fseek(DataBase, (DBIndex-1)*sizeof(TechItem), SEEK_SET);
	    fread(&item, sizeof(TechItem),1,DataBase);

	    ShowTechItem(item);
	    break;
	  }
	  else
	  {
	    if(DBIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<i;temp++)
	      {
		    a+=acrossSubButtons;
	      }
	      gotoxy(leftXX,a-acrossSubButtons);
	      textcolor(NON_ACTIVE_LINE_TEXT_STYLE);
	      textbackground(bkColor);

	      fseek(DataBase,(DBIndex-2)*sizeof(TechItem), SEEK_SET);
	      fread(&item, sizeof(TechItem),1,DataBase);
	      ShowTechItem(item);

	      gotoxy(leftXX,a);
	      textcolor(ACTIVE_LINE_TEXT_STYLE);
	      textbackground(ACTIVE_LINE_STYLE);

	      fseek(DataBase,(DBIndex-1)*sizeof(TechItem), SEEK_SET);
	      fread(&item, sizeof(TechItem),1,DataBase);
	      ShowTechItem(item);

	      break;
	    }
	  }
	i++;
	}//end of case 100:
	break;
	//////////++++++UP++++++///////////
      case 72:--DBIndex;//UP: 119
	if(DBIndex<=0)
	{
	  DBIndex=c;
	  a=holder;
	  gotoxy(leftXX,a);
	  textbackground(bkColor);
	  textcolor(NON_ACTIVE_LINE_TEXT_STYLE);

	  fseek(DataBase, 0*sizeof(TechItem), SEEK_SET);
	  fread(&item, sizeof(TechItem),1,DataBase);
	  ShowTechItem(item);
	}
	while((DBIndex<=c)&&(DBIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(DBIndex==c)
	  {
	    a=holder+(N*acrossSubButtons)-acrossSubButtons;
	    gotoxy(leftXX,a);
	    textcolor(ACTIVE_LINE_TEXT_STYLE);
	    textbackground(ACTIVE_LINE_STYLE);

	  fseek(DataBase, (DBIndex-1)*sizeof(TechItem), SEEK_SET);
	  fread(&item, sizeof(TechItem),1,DataBase);
	  ShowTechItem(item);
	    break;
	  }
	  else
	  {
	    if(DBIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<(i+1);temp++)
	      {
		    a+=acrossSubButtons;
	      }
	      gotoxy(leftXX,a);
	      textcolor(NON_ACTIVE_LINE_TEXT_STYLE);
	      textbackground(bkColor);

		  fseek(DataBase,(DBIndex)*sizeof(TechItem), SEEK_SET);
	      fread(&item, sizeof(TechItem),1,DataBase);
	      ShowTechItem(item);

	      gotoxy(leftXX,a-acrossSubButtons);
	      textcolor(ACTIVE_LINE_TEXT_STYLE);
	      textbackground(ACTIVE_LINE_STYLE);

		  fseek(DataBase,(DBIndex-1)*sizeof(TechItem), SEEK_SET);
	      fread(&item, sizeof(TechItem),1,DataBase);
	      ShowTechItem(item);

	      break;
	    }
	  }
	i++;
	}//end of case 97
	break;
      case 27:
	    if(N<=15)
		{
		  RefreshDesctop(leftXX-1,leftYY-1,80,leftYY+(N*acrossSubButtons)+1,desctopColor);
		}
		else
		{
		  RefreshDesctop(leftXX-1,leftYY-1,80,leftYY+20,desctopColor);
		}
		StatusBar(1,ymax,80,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");
	    goto EXIT; //const expretion
	  if(customerFlag)
	  {
	  case  BACKSPACE:
      case  DELETE1:
      case  DELETE2:
		    DeleteTechItem(path,DBIndex-1,DELETE_ONE);
			int FirstSize=N;
			N=GetTechItemSize(DataBase);
			if(N<=15)
			{
				RefreshDesctop(leftXX-1,leftYY-1,80,leftYY+(FirstSize*acrossSubButtons)+1,desctopColor);
			}
			else
			{
				RefreshDesctop(leftXX-1,leftYY-1,80,leftYY+20,desctopColor);
			}
			//**PaintAgain**///
			if(N<=15)
			{
				WindowBG(leftXX-1,leftYY-1,80,leftYY+(N*acrossSubButtons)+1,ACTIVE_LINE_STYLE,bkColor);
			}
			else
			{
				WindowBG(leftXX-1,leftYY-1,80,leftYY+20,ACTIVE_LINE_STYLE,bkColor);
			}
			gotoxy(leftXX,leftYY); //leftYY=6
			textcolor(4);
			cprintf("%-10s     %-30s%-10s%-8s%-8s%-7s",sName,sHaracter,sFirma,sPrice,sNumber,sArtikul);
			textcolor(NON_ACTIVE_LINE_TEXT_STYLE); 
			Credit=cust.Money;
			for(i=0;i<N;i++)
			{
				gotoxy(leftXX,leftYY+acrossSubButtons+i);
				fseek(DataBase,i*sizeof(TechItem),SEEK_SET);
				fread(&item,sizeof(TechItem),1,DataBase);
				Credit-=item.price;
				ShowTechItem(item);
				memset(&item,0,sizeof(TechItem));
			}
			CustomerInfo ();
	  }
	        break;
    }//End of switch(symbol)
  }//End of while(1)
EXIT:
//*****************
  CloseDB(DataBase);
  free(ar);
  return TRUE;
}