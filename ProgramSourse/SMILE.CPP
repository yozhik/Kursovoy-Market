#define LETTERSPEED 1

void Paraleli(int x1,int y1,int x2,int y2,char *ch)
{
  int i,j,k,z;
  char *symbol="0";
  if(*ch=='h')
  {
  for(i=x1,j=y1,k=x2,z=y2;i<getmaxx()-100;i++,k++)
  {
    outtextxy(i,j,(char*)symbol);
    outtextxy(k,z,(char*)symbol);
    delay(LETTERSPEED);
  }
  }
  else
  {
  for(i=x1,j=y1,k=x2,z=y2;j<getmaxy()-100;j++,z++)
  {
    outtextxy(i,j,(char*)symbol);
    outtextxy(k,z,(char*)symbol);
    delay(LETTERSPEED);
  }
  }
}
//******LIne2********
void Line2(int x1,int y1,int x2,int y2)
{
  int i,j,k,z,count=0;
  char *symbol="0";
  for(i=x1,j=y1,k=x2,z=y2;i<getmaxx()-110;i++,z--,count++)
  {
    if(z<=100)
    {
      z=y2;
    }
    outtextxy(i,j,(char*)symbol);
    outtextxy(k,z,(char*)symbol);
    delay(LETTERSPEED);
  }
}
//*****Line*******
void Line(int x,int y,int size,char *ch)
{
  int i,j,count=0;
  char *symbol="0";
if(*ch=='v')
{
  for(i=x,j=y;count<size;j++,count++)
  {
    outtextxy(i,j,(char*)symbol);
    delay(LETTERSPEED);
  }
}
else
{
  for(i=x,j=y;count<size;i++,count++)
  {
    outtextxy(i,j,(char*)symbol);
    delay(LETTERSPEED);
  }
}
}
//*******Rect***********
void Rect(int x,int y,int size)
{
  setcolor(15);
  int i,j,count=0;
  char *symbol="0";
  for(i=x,j=y;count<size;j++,count++)
  {
    outtextxy(i,j,(char*)symbol);
    delay(LETTERSPEED);
  }
  count=0;
  for(;count<size;i++,count++)
  {
    outtextxy(i,j,(char*)symbol);
    delay(LETTERSPEED);
  }
  count=0;
  for(;count<size;j--,count++)
  {
    outtextxy(i,j,(char*)symbol);
    delay(LETTERSPEED);
  }
  count=0;
  for(;count<size;i--,count++)
  {
    outtextxy(i,j,(char*)symbol);
    delay(LETTERSPEED);
  }
}
///********T********
void T(int center,int up,int color)
{
 setcolor(color);
 int k,i,j,intsymbol;
 char *symbol;
 intsymbol=0;
 for(k=center+25,i=center-25,j=up;i<center;i++,k--)
 {
      itoa(intsymbol,symbol,10);
      outtextxy(i,j,(char*)symbol);
      outtextxy(k,j,(char*)symbol);
      delay(LETTERSPEED);
 }
 for(i=center,j=up;j<up+65;j++)
 {
      itoa(intsymbol,symbol,10);
      outtextxy(i,j,(char*)symbol);
      delay(LETTERSPEED);
 }
}
//********E*******************
void E(int left,int up,int color)
{
  setcolor(color);
  int i=0,j=0;
  int intsymbol=0;
  char *symbol;
  for(i=left+25,j=up;i>left-20;i--)
  {
      itoa(intsymbol,symbol,10);
      outtextxy(i,j,(char*)symbol);
      delay(LETTERSPEED);
  }
  for(;j<up+65;j++)
  {
      itoa(intsymbol,symbol,10);
      outtextxy(i,j,(char*)symbol);
      delay(LETTERSPEED);
  }
  for(;i<left+25;i++)
  {
      itoa(intsymbol,symbol,10);
      outtextxy(i,j,(char*)symbol);
      delay(LETTERSPEED);
  }
  for(i=left-20,j=up+32;i<left+25;i++)
  {
      itoa(intsymbol,symbol,10);
      outtextxy(i,j,(char*)symbol);
      delay(LETTERSPEED);
  }
}
//*****A**************
void A(int center,int up,int color)
{
 setcolor(color);
 int k,i,j,intsymbol;
 char *symbol;
 intsymbol=0;
 for(i=k=center,j=up;j<up+75;j+=3,i--,k++)
 {
      itoa(intsymbol,symbol,10);
      outtextxy(i,j,(char*)symbol);
      outtextxy(k,j,(char*)symbol);
      intsymbol=4;
      outtextxy(i,j-1,(char*)symbol);
      outtextxy(k,j-1,(char*)symbol);
      intsymbol=4;
      outtextxy(i,j-2,(char*)symbol);
      outtextxy(k,j-2,(char*)symbol);
      delay(LETTERSPEED);
 }
 intsymbol=0;
 for(i=center-30,j=up+45;i<center+30;i++)
 {
      outtextxy(i,j,(char*)symbol);
      delay(LETTERSPEED);
 }
}

//*********M**********
void M(int center,int up,int color)
{
  setcolor(color);
  int i=0,j=0;
  char *symbol="0";
  for(i=center-30,j=up+50;j>up-10;j-=3,i++)
  {
    outtextxy(i,j,(char*)symbol);
    outtextxy(i,j-2,(char*)symbol);
    outtextxy(i,j-1,(char*)symbol);
    delay(LETTERSPEED);
  }
  for(;j<up+30;j+=3,i++)
  {
    outtextxy(i,j,(char*)symbol);
    outtextxy(i,j+2,(char*)symbol);
    outtextxy(i,j+1,(char*)symbol);
    delay(LETTERSPEED);
  }
  for(;j>up-10;j-=3,i++)
  {
    outtextxy(i,j,(char*)symbol);
    outtextxy(i,j-2,(char*)symbol);
    outtextxy(i,j-1,(char*)symbol);
    delay(LETTERSPEED);
  }
  for(;j<up+51;j+=3,i++)
  {
    outtextxy(i,j,(char*)symbol);
    outtextxy(i,j+2,(char*)symbol);
    outtextxy(i,j+1,(char*)symbol);
    delay(LETTERSPEED);
  }
}
void ScreenSaver(void)
{
  randomize();
  int gDriver=DETECT, gMode,errorcode;
  initgraph(&gDriver,&gMode,"");
  errorcode=graphresult();
  if(errorcode!=grOk)
  {
    printf("ERROR: %s\nPress any key to EXIT\n",grapherrormsg(errorcode));
    getch();
    exit(1);
  }
//******START***********
  int x=1,y=1,i=0,j=0,intsymbol,bkColor=0,Color=2;
  char *symbol;
  setbkcolor(bkColor);
  setcolor(Color);
  unsigned int A_Size=imagesize(553,390,625,467);
  void *bigTemp=malloc(A_Size);

  memset(bigTemp,0,sizeof(bigTemp));

  getimage(25,10,85,90,bigTemp);
  setcolor(15);
  Rect(1,1,100);
  T(50,15,14);
  setcolor(15);
  Line(50,101,266,"v");
  Rect(1,370,100);
  E(50,390,14);
  setcolor(15);
  Line(100,420,430,"h");
  Rect(530,370,100);
  A(580,390,2);
  setcolor(15);
  Line2(101,50,580,369);
  Rect(530,1,100);
  M(580,30,14);
  setcolor(15);
  Paraleli(100,100,100,370,"h");
  Paraleli(100,100,530,100,"v");
  settextstyle(0,0,2);
  unsigned int T_Size=imagesize(25,10,85,90);
  unsigned int E_Size=imagesize(25,390,85,465);
  unsigned int M_Size=imagesize(545,10,625,90);
  unsigned int temp_Size=imagesize(220,250,281,252);
  void *T_Array=malloc(T_Size);
  void *E_Array=malloc(E_Size);
  void *A_Array=malloc(A_Size);
  void *M_Array=malloc(M_Size);
  void *temp_Array=malloc(temp_Size);
  void *temp_A=malloc(A_Size);

  memset(T_Array,0,sizeof(T_Array));
  memset(E_Array,0,sizeof(E_Array));
  memset(A_Array,0,sizeof(A_Array));
  memset(M_Array,0,sizeof(M_Array));
  memset(temp_Array,0,sizeof(temp_Array));
  memset(temp_A,0,sizeof(temp_A));

  getimage(25,10,85,90,T_Array);
  getimage(25,390,85,465,E_Array);
  getimage(553,390,625,467,A_Array);
  getimage(545,10,625,90,M_Array);
  getimage(220,250,281,252,temp_Array);
  ///*****WORK WITH BITMAPS************
  int i_E,j_E,i_A,j_A,i_M,j_M;
  putimage(380,120,M_Array,COPY_PUT);
  putimage(380,260,A_Array,COPY_PUT);
  for(i=150,j=110,i_E=110,j_E=290,i_A=380,j_A=260,i_M=400,j_M=120;(j<220)&&(i_A>280)&&(i_E<220);j++,i_E++,i_A--)
  {
    putimage(i,j,T_Array,COPY_PUT);
    putimage(i_E,j_E,E_Array,COPY_PUT);
    delay(LETTERSPEED);
      while((j_E>253)&&(i_M>330))
      {
	putimage(i_E,j_E,E_Array,COPY_PUT);
	j_E--;
	putimage(i_M,j_M,M_Array,COPY_PUT);
	i_M--;
      }
    putimage(i_A,j_A,A_Array,COPY_PUT);
  }
  while(j_M<240)
  {
    putimage(i_M,j_M,M_Array,COPY_PUT);
    j_M++;
    if((j_M>200)&&(j_M<220))
    i_M--;
  }
  for(;j_E>120;j_A--,j_E--,j_M--)
  {

    putimage(i_E,j_E,E_Array,COPY_PUT);
    putimage(i_A+random(2),j_A,A_Array,COPY_PUT);
    putimage(i_M,j_M,M_Array,COPY_PUT);
  }
  setcolor(14);
  for(;j_E<215;j_E++,j_M++)
  {
    putimage(i_E,j_E-1,temp_Array,COPY_PUT);
    putimage(i_E,j_E,E_Array,COPY_PUT);
    putimage(i_M+5,j_M,M_Array,COPY_PUT);
    delay(random(LETTERSPEED*2));
  }
  for(;j_A<270;j_A++)
  {
    putimage(i_A,j_A+70,temp_Array,COPY_PUT);
    putimage(i_A,j_A,A_Array,COPY_PUT);
    putimage(i_A,j_A-1,temp_Array,COPY_PUT);
  }
  for(i=0;i<15;i++)
  {
    putimage(i_A,j_A+=5,temp_Array,COPY_PUT);
  }
  getimage(280,270,350,350,temp_A);
  putimage(280,270,bigTemp,COPY_PUT);
  putimage(280,250,bigTemp,COPY_PUT);
  putimage(290,245,bigTemp,COPY_PUT);
  putimage(280,210,temp_A,COPY_PUT);
  x=(getmaxx()/2)-70,y=getmaxy()-50;
  //***************************
  outtextxy(x,y,"Made by");
  outtextxy(x-70,y+20,"Serhiy Radkivskiy");
  setcolor(14);
//*****CLOSE************
 getch();
// free(symbol);
  memset(T_Array,0,sizeof(T_Array));
  memset(E_Array,0,sizeof(E_Array));
  memset(A_Array,0,sizeof(A_Array));
  memset(M_Array,0,sizeof(M_Array));
  memset(temp_Array,0,sizeof(temp_Array));
  memset(temp_A,0,sizeof(temp_A));

 free(T_Array);
 free(E_Array);
 free(A_Array);
 free(M_Array);
 free(temp_Array);
 free(bigTemp);
 free(temp_A);
 cleardevice();
 closegraph();
}