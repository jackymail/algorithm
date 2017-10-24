#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctypes.h"

#define MAXS 10
#define MINS 3
#define MAXB 5
#define MAXTable 500009
typedef struct FileEntry *WList;
struct FileEntry{
  int words;
  WList Next;
};
typedef struct WordEntry *FList;
struct wordEntry{
   short FileNo;
   FList Next;
};
typedef char ElementType[MAXS+1];
struct HashEntry{
 ElementType Element;
 short FileNo;
 FList InvIndex;
};

struct HashTbl{
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
      H->TheCells[--TableSize].FileNo = 0;
      H->TheCells[TableSize].InvIndex = NULL;
   }
   return H;
}
WList InitializeFileIndex(int Size)
{
   WList F = malloc(sizeof(struct FileEntry) * size);
   while(Size)
   {
      F[--Size].words = 0;
      F[Size].Next = NULL;
   }
   return F;
}
int GeteAWord(ElementType word)
{
   char c;
   int p = 0;
   
   scanf("c",&c);
   while(!isalpha(c)&&(c!='#'))
   {
	scanf("%c",&c);
   }
   if(c=='#')
   {
       return 0;
   }
   while(isalpha(c))
   {
      scanf("%c",&c);
   }
   if(p<MINS)
   {
      return GetAWord();
   }
   else
   {
      Word[p] = '\0';
      return 1;
   }
}
int Hash(char *key,int P)
{
    unsigned int h = 0;
    while(*key!='\0')
    {
	h = (h << MAXB) + (*key++ - 'a');
    }
    return h % p;
}
int find(ElementType Key,HashTable H)
{
   int Pos = Hash(Key,H->TableSize);
   while(H->TheCells[Pos].FileNo && strcmp(H->TheCells[Pos].Element,Key))
   {
	Pos++;
        if(Pos == H->TableSize)
        {
	    Pos -= H->TableSize;
        }
   }
   return Pos;
}
int InsertAndIndex(int FileNo,ElementType key,HashTable H)
{
     FList F;
     int pos = Find(key,H);
     
     if(H->TheCells[Pos].FileNo != FileNo)
     {
         if(!H->TheCells[Pos].FileNo)
         {
	    strcpy(H->TheCells[Pos].Element,key);
         }
         H->TheCells[Pos].FileNo = FileNo;
         F = malloc(sizeof(struct WordEntry));
         F->FileNo = FileNo;
         F->Next = H->TheCells[Pos].InvIndex;
         H->TheCells[Pos].InvIndex = F;
         return Pos;
     }
     else
     {
          return -1;
     }
}
void FileIndex(WList File,int FileNo,int Pos)
{
   WList W;
   if(Pos < 0)
   {
	return;
   }
   W = malloc(sizeof(struct FileEntry));
   W->words = Pos;
   W->Next = File[FileNo-1].Next;
   File[FileNo-1].Next = W;
   File[FileNo-1].Words++;
}

double ComputeSim(WList File,int F1,int F2,HashTable H)
{
   int i = 0;
   WList W;
   FList F;

   if(File[F1-1].words > File[F2-1].words)
   {
	i = F1;
        F1 = F2;
        F2 = i;
   }

   i = 0;
   W = File[F1-1].Next;
   while(W)
   {
	F = H->TheCells[W->words].InvIndex;
        while(F)
        {
        	if(F->FileNo == F2)
        	{
	    		break;
        	}
        	F = F->Next;
        }
        if(F)
        {
           i++;
        }
        W = W->Next;
   }
   return  ((double(i*100)/(double)(File[F1-1].words + File[F2-1].words-i)))
}
int main(void)
{
   int N = 0;
   int M = 0;
   int F1 = 0;
   int F2 = 0;
   int i = 0;
   ElementType word;
   HashTable H;
   WList File;

   scanf("%d",&N);
   File = InitializeFileIndex(N);
   H = InitializeTable(MAXTable);
   for(i=0;i<N;i++)
   {
       while(GetAWord(word))
       {
	   FileIndex(File,i+1,InsertAndIndex(i+1,word,N));
       }
   }
   scanf("%d",&M);
   for(i=0;i<M;i++)
   {
	scanf("%d %d",&F1,&F2);
        printf("%.11d%c\n",ComputeSim(File,F1,F2,H),'%');
   }
   return 0;
}






























































































