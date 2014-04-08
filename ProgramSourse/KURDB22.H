#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <mem.h>

#define NAME 15
#define MAINHARACTER 30
#define FIRMA 10
#define ARTIKUL 0
#define CYFRA 4

#define FIO_LEN 30

#define TRUE 1
#define FALSE 0

#define gNUM 10   /*max possible DataBase size=997 records=60817b*/

#define F 13
#define NT 7
#define H 21

#define READONLY 0
#define READnWRITE 1
#define REWRITECURRENT 2

#define INPUT_NAME 0
#define INPUT_MAINHARACTER 1
#define INPUT_FIRMA 2
#define INPUT_PRICE 3
#define INPUT_KILKIST 4
#define INPUT_ARTIKUL 5

#define DELETE_ONE 0
#define DELETE_ALL 1

#define SEARCH_BY_NAME 0
#define SEARCH_BY_MAINHARACTER 1
#define SEARCH_BY_FIRM 2

#define SORT_BY_INCREASE 0
#define SORT_BY_DECREASE 1

#define SORT_FROM_A_TO_Z 0
#define SORT_FROM_Z_TO_A 1

#define DONTMODIFYTEXT 0
#define MODIFYTEXT 1

char pathToDB[32]="db.dat";
char temp2[37]="temp";

char pathToTXT[30]="task";
char strres[30]="task";

char customerDB[10]="cstmr.dat"; //For Customer's FIO and money
char busket[11]="busket.dat";

int Credit=0,Articul=0;
//*********************
typedef struct Record
  {
    char name[NAME];
    char mainHaracter[MAINHARACTER];
    char firma[FIRMA];
    unsigned int price;
    unsigned int kilkist;
    unsigned int m_Artikul;
  }TechItem;
//***********************
typedef struct _Customer
{
	char FIO[FIO_LEN];
	unsigned int Money;
}Customer;

//****Prototypes****//
int  CreateDB(char *path);
FILE *OpenDB(char *path,unsigned int mode);
void CloseDB(FILE *DataBase);
void LoadDBRecords(FILE *DataBase,unsigned int number);
void AddRecord(char *path,TechItem &myItem);//
void EditTechItemRecord(char *path,unsigned int editNumber);
void ShowTechItem(TechItem &item);
void InputTechItemRecord(TechItem &item,unsigned int mode);
void DeleteTechItem(char *path,unsigned int delNumber,unsigned int mode);
unsigned int GetTechItemSize(FILE *DataBase);
unsigned int SearchTechItems(char *path,char *sString,unsigned int mode);
unsigned int SearchTechItemsByPrice(char *path,unsigned int min,unsigned int max);
void SortTechItemsByPrice(char *path,unsigned int mode);
void SortTechItemsByName(char *path,unsigned int mode);
//******For Customer*******//
void MakeOrder(char *path,unsigned int buyNumber);
void InputFIO(Customer &cust);
void InputMoney(Customer &cust);
void ConvertTXTtoBINARY(char *pathToTXT);
void ShowBinaryInfo(unsigned int wx1,unsigned int wy1,unsigned int tempWinLen, char *pathToBINARY, unsigned int mode);

#include "kurdb22.cpp"