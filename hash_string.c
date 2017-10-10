#include "stdio.h"
#include "stdlib.h"
#include "string.h"


#define MAXS 8
#define MAXD 3
#define MAXB 5
#define Mask ((1 << (MAXD * MAXB)) - 1)

typedef char ElementType[MAXS+1];

enum EntryType {
     Legitimate,Empty
};

struct HashEntry {
   ElementType Element;
   enum EntryType Info;
};

struct HashTbl {
    int TableSize;
    struct HashEntry *TheCells;
};

typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize)
{
    HashTable H = malloc(sizeof(struct HashTbl));
    H->TableSize = TableSize;
    H->TheCells = malloc(sizeof(struct HashEntry) * H->TableSize);
    while(TableSize)
    {
	H->TheCells[--TableSize].Info = Empty;
    }
    return H;
}

int Hash(char *Key,int P)
{
    int h = 0;
    while(*Key != '\0')
    {
	h = (h << MAXB) + (*Key++ - 'A');
    }
    return ((h&Mask) % P);
}

int Find(char *key,HashTable H)
{
   int inc = 0;
   int Cnt = 0;
   int Next = 0;
   int Pos = 0;

   Next = Pos = Hash(key,H->TableSize);

   while((H->TheCells[Next].Info != Empty) && (strcmp(H->TheCells[Next].Element,key)))
   {
       if(++Cnt % 2)
       {
	  inc = ((Cnt+1) * (Cnt+1)) >> 2;
       }
       else
       {
          inc = -(Cnt*Cnt) >> 2;
       }

       Next = Pos + inc;
       if(Next < 0)
       {
	  Next += H->TableSize;
       }
       else if(Next >= H->TableSize)
       {
	  Next -= H->TableSize;
       }
   }
   return Next;
}

void InsertAndOutput(char *key,HashTable H)
{
    int Pos = Find(key,H);
    
    if(H->TheCells[Pos].Info == Empty)
    {
	H->TheCells[Pos].Info = Legitimate;
        strcpy(H->TheCells[Pos].Element,key);
    }
    printf("%d",Pos);
}

int main()
{
    int N = 0;
    int P = 0;
    int i = 0;

    ElementType key;
    HashTable H;

    scanf("%d %d",&N,&P);
    H = InitializeTable(P);
     
    scanf("%s",key);
    InsertAndOutput(key,H);
    for(i=1;i<N;i++)
    {
	scanf("%s",key);
        printf(" ");
        InsertAndOutput(key,H);
    }
    printf("\n");
    return 0;
}













































