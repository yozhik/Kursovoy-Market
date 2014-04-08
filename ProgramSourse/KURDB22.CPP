//****Create DataBase******//
int CreateDB(char *path)
{
  FILE *db;
  db=fopen(path,"wb");
  if(!db)
  {
    perror("Cannot create Data Base: ");
    exit(1);
  }
  fclose(db);
  return TRUE;
}
//**********************
void ShowTechItem(TechItem &item)
{
  cprintf("%-15s",item.name);
  cprintf("%-30s",item.mainHaracter);
  cprintf("%-10s",item.firma);
  cprintf("%-8u",item.price);
  cprintf("%-8u",item.kilkist);
  cprintf("%-7u",item.m_Artikul);
}
//***Input Data********//
void InputTechItemRecord(TechItem &item,unsigned int mode)
{
  char *inputBuf=(char*)calloc(MAINHARACTER+1,sizeof(char));
  if(inputBuf==NULL)
	  exit(1);
  memset(inputBuf,0,sizeof(inputBuf));
  switch(mode)
  {
    case INPUT_NAME:
		inputBuf[0]=NAME+1;
		strcpy(item.name,cgets(inputBuf));
	    memset(inputBuf,0,sizeof(inputBuf));
      break;
    case INPUT_MAINHARACTER:
		inputBuf[0]=MAINHARACTER+1;
		strcpy(item.mainHaracter,cgets(inputBuf));
	    memset(inputBuf,0,sizeof(inputBuf));
      break;
    case INPUT_FIRMA:
		inputBuf[0]=FIRMA+1;
		strcpy(item.firma,cgets(inputBuf));
	    memset(inputBuf,0,sizeof(inputBuf));
      break;
    case INPUT_PRICE:
		inputBuf[0]=CYFRA+1;
		int pr=0;
		char *s;
		s=cgets(inputBuf);
		pr=atoi(s);
		item.price=pr;
			
	    memset(inputBuf,0,sizeof(inputBuf));
      break;
    case INPUT_KILKIST:
		inputBuf[0]=CYFRA+1;
		item.kilkist=atoi(cgets(inputBuf));
	    memset(inputBuf,0,sizeof(inputBuf));
      break;
    case INPUT_ARTIKUL:
      item.m_Artikul=++Articul;
      break;
  }
  free(inputBuf);
}
//******Get Number of TechItems*****/////
unsigned int GetTechItemSize(FILE *DataBase)
{
  long endPosition=0;
  unsigned int Size=0;
  fseek(DataBase,0L,SEEK_END);
  endPosition=ftell(DataBase);
  fseek(DataBase,0L,SEEK_SET);
  Size=endPosition/sizeof(TechItem);
  return Size;
}
//**********************
FILE *OpenDB(char *path,unsigned int mode)
{
  FILE *DataBase;
  switch(mode)
  {
    case READONLY:
      DataBase=fopen(path,"rb");
      break;
    case READnWRITE:
      DataBase=fopen(path,"r+b");
      break;
    case REWRITECURRENT:
      DataBase=fopen(path,"wb");
      break;
  }
  return DataBase;
}
//*********************
void CloseDB(FILE *DataBase)
{
  fclose(DataBase);
}
//*****Generation Data Base*******//
void LoadDBRecords(FILE *DataBase,unsigned int number)
{
  unsigned int i=0;
  char **NazvaTovaru=(char**)calloc(NT,sizeof(char*));
  NazvaTovaru[0]="Monitor";
  NazvaTovaru[1]="Mysh";
  NazvaTovaru[2]="USB";
  NazvaTovaru[3]="Videokarta";
  NazvaTovaru[4]="Modem";
  NazvaTovaru[5]="OZU";
  NazvaTovaru[6]="CPU";
  TechItem item;
  //*******///
  char **haracter=(char**)calloc(H,sizeof(char*));
  haracter[0]="17' Liquid";
  haracter[1]="21' Plasma";
  haracter[2]="19' Usual";
  haracter[3]="multi mouse";
  haracter[4]="4 buttons";
  haracter[5]="small";
  haracter[6]="3m-black";
  haracter[7]="5m-white";
  haracter[8]="2m-grey";
  haracter[9]="256Mb";
  haracter[10]="512Mb";
  haracter[11]="1024Mb";
  haracter[12]="2048Mb DDR2";
  haracter[13]="4096Mb DDR2";
  haracter[14]="128Mb DDR1";
  haracter[15]="4ports+switch";
  haracter[16]="2ports";
  haracter[17]="simple";
  haracter[18]="2.13Gh";
  haracter[19]="3.0Gh";
  haracter[20]="1.9Gh";
  //*****FIRMY*****
  char **Firma=(char**)calloc(F,sizeof(char*));
  Firma[0]="Samsung ";
  Firma[1]="Sony";
  Firma[2]="ACER";
  Firma[3]="ASUS";
  Firma[4]="HP";
  Firma[5]="MSI";
  Firma[6]="D-Link";
  Firma[7]="Callisto";
  Firma[8]="IntelCore";
  Firma[9]="AMDTurion";
  Firma[10]="A4Tech";
  Firma[11]="AsRock";
  Firma[12]="GForce";
  //**************
  for(i=0;i<number;i++)
  {
    memset(&item,0,sizeof(item));
    unsigned int choice=random(7);
    switch(choice)
    {
      case 0://Monitor
	strcpy(item.name,NazvaTovaru[0]);
	choice=random(3);
	strcpy(item.mainHaracter,haracter[choice]);
	choice=random(2);
	strcpy(item.firma,Firma[choice]);
	item.price=100+rand()%100;
	item.kilkist=random(20);
	item.m_Artikul=++Articul;
	fseek(DataBase, 0, SEEK_END);
	fwrite(&item,sizeof(item),1,DataBase);
	fflush(DataBase);
	break;
      case 1://Mysh
	strcpy(item.name,NazvaTovaru[1]);
	choice=3+rand()%3;
	strcpy(item.mainHaracter,haracter[choice]);
	choice=10+rand()%2;
	strcpy(item.firma,Firma[choice]);
	item.price=10+rand()%20;
	item.kilkist=random(20);
	item.m_Artikul=++Articul;
	fseek(DataBase, 0, SEEK_END);
	fwrite(&item,sizeof(item),1,DataBase);
	fflush(DataBase);
	break;
      case 2://USB
	strcpy(item.name,NazvaTovaru[2]);
	choice=6+rand()%3;
	strcpy(item.mainHaracter,haracter[choice]);
	choice=2+rand()%3;
	strcpy(item.firma,Firma[choice]);
	item.price=1+rand()%7;
	item.kilkist=random(20);
	item.m_Artikul=++Articul;
	fseek(DataBase, 0, SEEK_END);
	fwrite(&item,sizeof(item),1,DataBase);
	fflush(DataBase);
	break;
      case 3://Videokarta
	strcpy(item.name,NazvaTovaru[3]);
	choice=9+rand()%3;
	strcpy(item.mainHaracter,haracter[choice]);
	choice=11+rand()%2;
	strcpy(item.firma,Firma[choice]);
	item.price=100+rand()%50;
	item.kilkist=random(20);
	item.m_Artikul=++Articul;
	fseek(DataBase, 0, SEEK_END);
	fwrite(&item,sizeof(item),1,DataBase);
	fflush(DataBase);
	break;
      case 4://Modem
	strcpy(item.name,NazvaTovaru[4]);
	choice=15+rand()%3;
	strcpy(item.mainHaracter,haracter[choice]);
	choice=6+rand()%2;
	strcpy(item.firma,Firma[choice]);
	item.price=30+rand()%15;
	item.kilkist=random(20);
	item.m_Artikul=++Articul;
	fseek(DataBase, 0, SEEK_END);
	fwrite(&item,sizeof(item),1,DataBase);
	fflush(DataBase);
	break;
      case 5://OZU
	strcpy(item.name,NazvaTovaru[5]);
	choice=12+rand()%3;
	strcpy(item.mainHaracter,haracter[choice]);
	choice=1+rand()%5;
	strcpy(item.firma,Firma[choice]);
	item.price=20+rand()%10;
	item.kilkist=random(20);
	item.m_Artikul=++Articul;
	fseek(DataBase, 0, SEEK_END);
	fwrite(&item,sizeof(item),1,DataBase);
	fflush(DataBase);
	break;
      case 6://CPU
	strcpy(item.name,NazvaTovaru[6]);
	choice=18+rand()%3;
	strcpy(item.mainHaracter,haracter[choice]);
	choice=8+rand()%2;
	strcpy(item.firma,Firma[choice]);
	item.price=70+rand()%50;
	item.kilkist=random(20);
	item.m_Artikul=++Articul;
	fseek(DataBase, 0, SEEK_END);
	fwrite(&item,sizeof(item),1,DataBase);
	fflush(DataBase);
	break;
    }
  }
  //***FREE****//
  free(NazvaTovaru);
  free(haracter);
  free(Firma);
}

//*********************
void AddRecord(char *path,TechItem &item)
{
  FILE *DataBase=OpenDB(path,READnWRITE);
  unsigned int N=5,i=0;
  for(i=0;i<N;i++)
    InputTechItemRecord(item,i);
  fseek(DataBase, 0L, SEEK_END);
  fwrite(&item,sizeof(item),1,DataBase);
  fflush(DataBase);
  CloseDB(DataBase);
}

//**********Delete TechItem********************//
void DeleteTechItem(char *path,unsigned int delNumber,unsigned int mode)
{
  switch(mode)
  {
    case DELETE_ONE:
	FILE *DataBase=OpenDB(path,READONLY);
	unsigned int Size=GetTechItemSize(DataBase),i=0,k=0;
	if(delNumber>=Size)
	  delNumber=Size-1;
	TechItem *pBuffer=(TechItem*)calloc(Size-1,sizeof(TechItem));
	for(i=0,k=0;i<Size;i++)
	{
	  if(i!=delNumber)
	  {
	    fseek(DataBase,i*sizeof(TechItem), SEEK_SET);
	    fread(&pBuffer[k], sizeof(TechItem),1,DataBase);
	    k++;
	  }
	}
	CloseDB(DataBase);
	CreateDB(path);
	DataBase=OpenDB(path,READnWRITE);
	fwrite(pBuffer,sizeof(TechItem),(Size-1),DataBase);
	CloseDB(DataBase);
	free(pBuffer);
	break;
    case DELETE_ALL:
	CreateDB(path);//rewrites a DataBase file
	break;
  }
}
//******Edit TechItem****************////
void EditTechItemRecord(char *path,unsigned int editNumber)
{
	FILE *DataBase=OpenDB(path,READONLY);
	unsigned int Size=GetTechItemSize(DataBase),i=0;
	if(editNumber>=Size)
	  editNumber=Size-1;
	TechItem *pBuffer=(TechItem*)calloc(Size,sizeof(TechItem));
	fread(pBuffer, sizeof(TechItem),Size,DataBase);
	CloseDB(DataBase);
	CreateDB(path);
	DataBase=OpenDB(path,REWRITECURRENT);
	for(i=0;i<Size;i++)
	{
	  fseek(DataBase,i*sizeof(TechItem), SEEK_SET);
	  if(i==editNumber)
	  {

		  FILE *EX=OpenDB("exch.dat",READONLY);
		  fread(&pBuffer[i],sizeof(TechItem),1,EX);
		  CloseDB(EX);
	  }
	  fwrite(&pBuffer[i],sizeof(TechItem),1,DataBase);
	}
	CloseDB(DataBase);
	free(pBuffer);
}
//***Serch TechItems*****//
unsigned int SearchTechItems(char *path,char *sString,unsigned int mode)
{
  unsigned int numberOfSearchedItems=0,Size=0,i=0,k=0;
  char *lowTechItem=NULL,*lowString=NULL,temp[MAINHARACTER];
  lowString=strlwr(sString);
  TechItem item;
  memset(&item,0,sizeof(TechItem));
  FILE *DataBase=OpenDB(path,READONLY);
  Size=GetTechItemSize(DataBase);
  TechItem *pBuffer=(TechItem*)calloc(Size,sizeof(TechItem));
  fread(pBuffer,sizeof(TechItem),Size,DataBase);
  CloseDB(DataBase);

  FILE *SearchResultDB=OpenDB(temp2,REWRITECURRENT);//analog CreateDB() but not close the file
  switch(mode)
  {
    case SEARCH_BY_NAME:
      for(i=0,k=0;i<Size;i++)
      {
	strcpy(temp,pBuffer[i].name);
	lowTechItem=strlwr(pBuffer[i].name);
	if(strstr(lowTechItem,lowString))
	{
	  strcpy(pBuffer[i].name,temp);
	  fseek(SearchResultDB,k*sizeof(TechItem),SEEK_SET);
	  fwrite(&pBuffer[i],sizeof(TechItem),1,SearchResultDB);
	  k++;
	}
      }
      fflush(SearchResultDB);
      break;
    case SEARCH_BY_MAINHARACTER:
      for(i=0,k=0;i<Size;i++)
      {
	strcpy(temp,pBuffer[i].mainHaracter);
	lowTechItem=strlwr(pBuffer[i].mainHaracter);
	if(strstr(lowTechItem,lowString))
	{
	  strcpy(pBuffer[i].mainHaracter,temp);
	  fseek(SearchResultDB,k*sizeof(TechItem),SEEK_SET);
	  fwrite(&pBuffer[i],sizeof(TechItem),1,SearchResultDB);
	  k++;
	}
      }
      fflush(SearchResultDB);
      break;
    case SEARCH_BY_FIRM:
      for(i=0,k=0;i<Size;i++)
      {
	strcpy(temp,pBuffer[i].firma);
	lowTechItem=strlwr(pBuffer[i].firma);
	if(strstr(lowTechItem,lowString))
	{
	  strcpy(pBuffer[i].firma,temp);
	  fseek(SearchResultDB,k*sizeof(TechItem),SEEK_SET);
	  fwrite(&pBuffer[i],sizeof(TechItem),1,SearchResultDB);
	  k++;
	}
      }
      fflush(SearchResultDB);
      break;
  }
  CloseDB(SearchResultDB);
  numberOfSearchedItems=k;
  free(pBuffer);
  return numberOfSearchedItems;
}
//***Search by price*******//
unsigned int SearchTechItemsByPrice(char *path,unsigned int min,unsigned int max)
{
  unsigned int temp=0,i=0,Size=0,k=0,numberOfSearchedItems=0;
  TechItem item;
  memset(&item,0,sizeof(TechItem));
  FILE *DataBase=OpenDB(path,READONLY);
  Size=GetTechItemSize(DataBase);
  TechItem *pBuffer=(TechItem*)calloc(Size,sizeof(TechItem));
  fread(pBuffer,sizeof(TechItem),Size,DataBase);
  CloseDB(DataBase);

  FILE *SearchResultDB=OpenDB(temp2,REWRITECURRENT);//analog CreateDB() but not close the file
  if(max<min)
  {
    temp=max;
    max=min;
    min=temp;
  }
  for(i=0,k=0;i<Size;i++)
  {
    if((pBuffer[i].price>=min)&&(pBuffer[i].price<=max))
    {
      fseek(SearchResultDB,k*sizeof(TechItem),SEEK_SET);
      fwrite(&pBuffer[i],sizeof(TechItem),1,SearchResultDB);
      k++;
    }
  }
  fflush(SearchResultDB);
  CloseDB(SearchResultDB);
  numberOfSearchedItems=k;

  free(pBuffer);
  return numberOfSearchedItems;
}
//******Sort By Price****/////
void SortTechItemsByPrice(char *path,unsigned int mode)
{
  unsigned int Size=0,j=0,i=0;
  TechItem tempItem;
  memset(&tempItem,0,sizeof(TechItem));
  FILE *DataBase=OpenDB(path,READONLY);
  Size=GetTechItemSize(DataBase);
  TechItem *pBuffer=(TechItem*)calloc(Size,sizeof(TechItem));
  fread(pBuffer,sizeof(TechItem),Size,DataBase);
  CloseDB(DataBase);
  FILE *SortResultDB=OpenDB(path,REWRITECURRENT);//analog CreateDB() but not close the file
  switch(mode)
  {
    case SORT_BY_INCREASE:
      for(j=1;j<Size;j++)
      {
	if(pBuffer[j].price>pBuffer[j-1].price)
	{
	  continue;
	}
	else
	{
	  for(i=j;i>0;i--)
	  {
	    if(pBuffer[i].price>pBuffer[i-1].price)
	    {
	      break;
	    }
	    else
	    {
	      tempItem=pBuffer[i];
	      pBuffer[i]=pBuffer[i-1];
	      pBuffer[i-1]=tempItem;
	    }
	  }
	}
      }
      fwrite(pBuffer,sizeof(TechItem),Size,SortResultDB);
      fflush(SortResultDB);
      CloseDB(SortResultDB);
      SortResultDB=OpenDB(path,READONLY);
      break;
    case SORT_BY_DECREASE:
      for(j=1;j<Size;j++)
      {
	if(pBuffer[j].price<pBuffer[j-1].price)
	{
	  continue;
	}
	else
	{
	  for(i=j;i>0;i--)
	  {
	    if(pBuffer[i].price<pBuffer[i-1].price)
	    {
	      break;
	    }
	    else
	    {
	      tempItem=pBuffer[i];
	      pBuffer[i]=pBuffer[i-1];
	      pBuffer[i-1]=tempItem;
	    }
	  }
	}
      }
      fwrite(pBuffer,sizeof(TechItem),Size,SortResultDB);
      fflush(SortResultDB);
      CloseDB(SortResultDB);
      SortResultDB=OpenDB(path,READONLY);
      break;
  }//end of switch
  CloseDB(SortResultDB);
  free(pBuffer);
}
//******SORT by Name******************************
void SortTechItemsByName(char *path,unsigned int mode)
{
  unsigned int Size=0,j=0,i=0;
  char *arr1=NULL,*arr2=NULL;
  TechItem tempItem;
  memset(&tempItem,0,sizeof(TechItem));
  FILE *DataBase=OpenDB(path,READONLY);
  Size=GetTechItemSize(DataBase);
  TechItem *pBuffer=(TechItem*)calloc(Size,sizeof(TechItem));
  fread(pBuffer,sizeof(TechItem),Size,DataBase);
  CloseDB(DataBase);
  FILE *SortResultDB=OpenDB(path,REWRITECURRENT);//analog CreateDB() but not close the file
  switch(mode)
  {
    case SORT_FROM_A_TO_Z:
  for(j=0;j<Size;j++)
  {
    for (i=0; i<(Size-j-1); i++)
    {
      if (*pBuffer[i].name>*pBuffer[i+1].name)
      {
	tempItem=pBuffer[i];
	pBuffer[i]=pBuffer[i+1];
	pBuffer[i+1]=tempItem;
      }
      if(*pBuffer[i].name==*pBuffer[i+1].name)
      {
	arr1=pBuffer[i].name;
	arr2=pBuffer[i+1].name;
	while((*arr1==*arr2)&&(*arr1!='\0')&&(*arr2!='\0'))
	{
	  arr1++;
	  arr2++;
	}
	if(*arr1>*arr2)
	{
	  tempItem=pBuffer[i];
	  pBuffer[i]=pBuffer[i+1];
	  pBuffer[i+1]=tempItem;
	}
      }
    }
  }
      fwrite(pBuffer,sizeof(TechItem),Size,SortResultDB);
      fflush(SortResultDB);
      CloseDB(SortResultDB);
      SortResultDB=OpenDB(path,READONLY);
      break;
    case SORT_FROM_Z_TO_A:
  for(j=0;j<Size;j++)
  {
    for (i=0; i<(Size-j-1); i++)
    {
      if (*pBuffer[i].name<*pBuffer[i+1].name)
      {
	tempItem=pBuffer[i];
	pBuffer[i]=pBuffer[i+1];
	pBuffer[i+1]=tempItem;
      }
      if(*pBuffer[i].name==*pBuffer[i+1].name)
      {
	arr1=pBuffer[i].name;
	arr2=pBuffer[i+1].name;
	while((*arr1==*arr2)&&(*arr1!='\0')&&(*arr2!='\0'))
	{
	  arr1++;
	  arr2++;
	}
	if(*arr1<*arr2)
	{
	  tempItem=pBuffer[i];
	  pBuffer[i]=pBuffer[i+1];
	  pBuffer[i+1]=tempItem;
	}
      }
    }
  }

      fwrite(pBuffer,sizeof(TechItem),Size,SortResultDB);
      fflush(SortResultDB);
      CloseDB(SortResultDB);
      SortResultDB=OpenDB(path,READONLY);
      break;
  }//end of switch
  CloseDB(SortResultDB);
  free(pBuffer);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//*****Customer*****//

//***Input Data********//
void InputMoney(Customer &cust)
{

  char *inputBuf=(char*)calloc(CYFRA+1,sizeof(char));
  if(inputBuf==NULL)
	  exit(1);
		memset(inputBuf,0,sizeof(inputBuf));
		inputBuf[0]=CYFRA+2;
		cust.Money=atoi(cgets(inputBuf));
	    memset(inputBuf,0,sizeof(inputBuf));
	free(inputBuf);	

}
void InputFIO(Customer &cust)
{

  char *inputBuf=(char*)calloc(FIO_LEN+1,sizeof(char));
  if(inputBuf==NULL)
	  exit(1);
		memset(inputBuf,0,sizeof(inputBuf));
		inputBuf[0]=FIO_LEN+1;
		strcpy(cust.FIO,cgets(inputBuf));
	    memset(inputBuf,0,sizeof(inputBuf));
	free(inputBuf);
}
//**********Make Order********************//
void MakeOrder(char *path,unsigned int buyNumber)
{
	FILE *DataBase=OpenDB(path,READONLY);
	FILE *BusketDB;
	TechItem Buffer;
	memset(&Buffer,0,sizeof(TechItem));
	fseek(DataBase,buyNumber*sizeof(TechItem), SEEK_SET);
	fread(&Buffer,sizeof(TechItem),1,DataBase);
	CloseDB(DataBase);

	Credit-=Buffer.price;
	BusketDB = OpenDB(busket,READnWRITE);
	fseek(BusketDB,0L,SEEK_END);
	fwrite(&Buffer,sizeof(TechItem),1,BusketDB);
	CloseDB(BusketDB);
}
void ConvertTXTtoBINARY(char *pathToTXT)
{
	memset(strres,'\0',sizeof(strres));
	strcpy(strres,pathToTXT);
	strcat(strres,".rsd");
	strcat(pathToTXT,".txt");
	FILE *text;
	int i=0;
	char *s;
	memset(s,'\0',sizeof(s));
	if((text=fopen(pathToTXT,"r"))==NULL)
	{
		perror("Error code: ");
		getch();
		exit(1);
	}
	FILE *binary=fopen(strres,"wb");
	while(!feof(text))
	{
		fgets(s,10,text);
		fseek(binary,0L,SEEK_END);
		fwrite(s,strlen(s),1,binary);
		i++;
	}
	fclose(text);
	fclose(binary);
}
void ShowBinaryInfo(unsigned int wx1,unsigned int wy1,unsigned int tempWinLen, char *pathToBINARY, unsigned int mode)
{
	strcpy(strres,pathToBINARY);
	FILE *binary=fopen(strres,"rb");
	long size=0;
	char s1;
	int y=wy1,k=wx1,i=0;
	switch(mode)
	{
	  case DONTMODIFYTEXT:
	    fseek(binary,0L,SEEK_END);
	    size=ftell(binary)/sizeof(char);
	    y=wy1,k=wx1,i=0;
	    while(i<size)
	    {
	      fseek(binary,i*sizeof(char),SEEK_SET);
	      fread(&s1,sizeof(char),1,binary);
	      delay(5);
	      if(s1=='\n')
	      {
				k=wx1;
				y=wherey()+1;
	      }
	      gotoxy(k,y);
	      cprintf("%c",s1);
	      i++;
	      k++;
	    }
	 break;
  case MODIFYTEXT:
	fseek(binary,0L,SEEK_END);
	size=ftell(binary)/sizeof(char);
	y=wy1,k=wx1,i=0;
	while(i<size)
	{
	 fseek(binary,i*sizeof(char),SEEK_SET);
	 fread(&s1,sizeof(char),1,binary);
	 delay(5);
	if(s1=='<')
	{
	  while(s1!=' ')
	  {
	    textcolor(14);
	    cprintf("%c",s1);
		i++;   k++; y=wherey();
			    fseek(binary,i*sizeof(char),SEEK_SET);
	    fread(&s1,sizeof(char),1,binary);

	  }
	}
	textcolor(7);
	if(s1=='\n'||k>tempWinLen)
	{
	 k=wx1;
	 y=wherey()+1;
	}
	gotoxy(k,y);
	cprintf("%c",s1);
	i++;
	k++;
	}break;
	}
	fclose(binary);
}