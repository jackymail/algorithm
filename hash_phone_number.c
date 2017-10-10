#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define MAXS 11
#define MAXD  5

typedef struct HashEntry *List;
struct HashEntry {
  char PhoneNo[MAXS+1];
  int Cnt; 
  List Next;
};

//typedef struct HashEntry *List;

struct HashTbl {
 int TableSize;
 List TheLists;
};

typedef struct HashTbl *HashTable;

int NextPrime(int N)
{
    int i = 0;
    if(!(N%2)) 
    {
	N++;
    }
    for(;;N+=2)
    {
       for(i=(int)sqrt(N);i>2;i--)
       {
	  if(!(N%i))
          {
	      break;
          }
          if(i==2)
          {
	     break;
          }
       }
    }
    return N;
}

HashTable InitializeTable(int N)
{
    int i = 0;
    HashTable H = malloc(sizeof(struct HashTbl));
    H->TableSize = NextPrime(N);
    H->TheLists = malloc(sizeof(struct HashEntry) * H->TableSize);
    for(i=0; i<H->TableSize;i++)
    {
	H->TheLists[i].PhoneNo[0]= '\0';
        H->TheLists[i].Cnt = 0;
        H->TheLists[i].Next = NULL;
    }
    return H;
}

int Hash(int key,int P)
{
   return key%P;
}

void InsertAndCount(char *key,HashTable H)
{
   List Ptr,NewCell,L;
   L = &(H->TheLists[Hash(atoi(key+6),H->TableSize)]);     
   Ptr = L->Next;
   while(Ptr && strcmp(Ptr->PhoneNo,key))
   {
	Ptr = Ptr->Next;
   }
   if(Ptr)
   {
	Ptr->Cnt++;
   }
   else
   {
       NewCell = malloc(sizeof(struct HashEntry));
       strcpy(NewCell->PhoneNo,key);
       NewCell->Cnt = 1;
       NewCell->Next = L->Next;
       L->Next = NewCell;
   }
}

void Output(HashTable H)
{
   int i = 0;
   int MaxCnt = 0; 
   int PCnt;
   List Ptr;
   char MinPhone[MAXS + 1];
 
   MaxCnt  = PCnt = 0;
   MinPhone[0] = '\0';

   for(i=0;i<H->TableSize;i++)
   {
	Ptr = H->TheLists[i].Next;
        while(Ptr)
        {
            if(Ptr->Cnt > MaxCnt)
            {
		MaxCnt = Ptr->Cnt;
                strcpy(MinPhone,Ptr->PhoneNo);
                PCnt = 1;
            }
            else if(Ptr->Cnt == MaxCnt)
            {
		PCnt++;
                if(strcmp(MinPhone,Ptr->PhoneNo) > 0)
                {
		    strcpy(MinPhone,Ptr->PhoneNo);
                }
            }
        }
        Ptr = Ptr->Next;
   }
   printf("%s %d",MinPhone,MaxCnt);
   if(PCnt > 1)
   {
      printf(" %d",PCnt);
   }
   printf("\n");
}

int main()
{
   int N = 0;
   int i = 0;
   
   char key[MAXS+1];

   HashTable H;

   scanf("%d",&N);
   H = InitializeTable(N);

   for(i=0;i<N;i++)
   {
      scanf("%s",key);
      InsertAndCount(key,H);
      scanf("%s",key);
      InsertAndCount(key,H);
   }
   Output(H);
   return 0;
}






























