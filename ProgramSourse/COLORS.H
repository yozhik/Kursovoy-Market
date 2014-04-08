#define ACTIVE_LINE_STYLE 2
#define ACTIVE_LINE_TEXT_STYLE 7

#define NON_ACTIVE_LINE_TEXT_STYLE 1

#define BACKSPACE 8
#define DELETE1 68
#define DELETE2 100

#define EDIT1 69
#define EDIT2 101

#define ZAMOVYTY1 122
#define ZAMOVYTY2 90

typedef void(*MENU)(int x1,int y1,char *string,...);

MENU pMainMenu[6]={AboutAvtor,WorkWithDataBase,SearchInfo,PrintResults,Busket,Exit};

char **ppString=NULL;
int *buttonLenghtArray=NULL;
char *buttonText=NULL;

unsigned char x1=1, //NOT int but unsigned char!!!
y1=1,
y2=0,
x2=0,
ymax=24,  
xmax=80,
count=0,
bkColor=7,
textColor=16,
ActiveButtonColor=1,
ActiveTextColor=7,
winBK=1,
winTEXT=7,
leftXX=2,
leftYY=6,
SpaceBetweenButtons=3,
acrossSubButtons=1;

int const desctopColor=8; 
int MenuIndex=0,symbol=0;
char password[5]={"1111"};
unsigned int wx1=30,
wy1=10;

unsigned int customerFlag=0;

char sName[]="TechItem";
char sHaracter[]="Main Haracteristic";
char sFirma[]="Firma";
char sNumber[]="Number";
char sPrice[]="Price,$";
char sArtikul[]="Artikul";

TechItem item;
Customer cust;