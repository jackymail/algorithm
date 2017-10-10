#include "stdio.h"
#include "stdlib.h"


typedef int ElementType;

enum EntryType {
    Legitimate,
    Empty
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

    H->TheCells = malloc(sizeof(struct HashEntry)* H->TableSize);
    
    while(TableSize)
    {
	H->TheCells[--TableSize].Info = Empty;
    }
    return H;
}

int Hash(ElementType key,int P)
{
    return key%P;
}

int Find(ElementType key,HashTable H)
{
    int Pos = Hash(key,H->TableSize);
    
    while((H->TheCells[Pos].Info != Empty) && (H->TheCells[Pos].Element!= key))
    {
	Pos++;
        if(Pos == H->TableSize)
        {
	     Pos -= H->TableSize;
        }
    }
    return Pos;
}

void InsertAndOutput(ElementType key,HashTable H)
{
    int Pos = Find(key,H);
    
    if(H->TheCells[Pos].Info == Empty)
    {
	H->TheCells[Pos].Info = Legitimate;
        H->TheCells[Pos].Element = key;
    }
    printf("%d",Pos);
}

int main()
{
    int N = 0;
    int P = 0;
    int key = 0;
    int i = 0;
    HashTable H;
  
    scanf("%d %d",&N,&P);
   
    H = InitializeTable(P);

    scanf("%d",&key);
    
    InsertAndOutput(key,H);
    for(i=1;i<N;i++)
    {
	scanf("%d",&key);
        printf(" ");
        InsertAndOutput(key,H);
    }    
    printf("\n");
    return 0;
}





































