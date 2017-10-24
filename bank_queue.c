#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MaxProc 60
#define MAXTEAM 100
#define MAXCHAR 3
#define MAXNAME 26426

struct People{
   char Name[MAXCHAR+1];
   int T;
   int P;
};
struct TeamQueueRecord{
   int Tfront;
   int Trear;
   int Tsize;
   struct People *Customer;
};

typedef struct TeamQueueRecord *TeamQueue;

struct QueueRecord{
    int front; 
    int rear;
    int size;
    TeamQueue TeamQ;
};

typedef struct QueueRecord *Queue;
int Team[MAXNAME];
struct TeamNode{
    int Position;
    int size;
}TeamInfo[MAXTEAM];

int NameHash(char name[])
{  
    int i = 0;
    int j = 0;
    i = name[0] - 'A';
    while(name[j] != '\0')
    {
	i = (i<<5)+name[j++]-'A';
    }
    return i;
}
int Read_Set_Teams(int M)
{
    int L = 0;
    int MaxL = 0;
    char name[MAXCHAR+1];
    for(i=0;i<MAXNAME;i++)
    {
	Team[i] = -1;
    }
    MaxL = 0;
   
    for(i=0;i<M;i++)
    {
	scanf("%d",&L);
        if(L > MaxL)
        {
	   MaxL = L;
        }
        for(j=0;j<L;j++)
        {
	   scanf("%s",name);
           Team[NameHash(name)] = i;
        }
    }
    for(i=0;i<M;i++)
    {
	TeamInfo[i].Size = 0;
    }
    return MaxL;
}

Queue CreateQueue(int MaxQSize,int MaxTSize)
{
   Queue Q;
   int i = 0;
   Q = malloc(sizeof(struct QueueRecord));
   Q->TeamQ = malloc(sizeof(struct TeamQueueRecord)*MaxTSize);
   Q->size = 0;
   Q->front = 0;
   Q->rear = -1;
   for(i=0;i<MaxTSize;i++)
   {
	Q->TeamQ[i].Customer = malloc(sizeof(struct People)*MaxQSize);
        Q->TeamQ[i].Tsize = 0;
        Q->TeamQ[i].Tfront = 0;
        Q->TeamQ[i].Trear = -1;
   }
   return Q;
}

void AddQ(Queue Q,struct People)
{
  int i = 0;
  int pos = 0;
  int r = 0;

  if(X.P > MaxProc)
  {
    X.P = MaxProc;
  }

  i = Team[NameHash(X.Name)];
  if((i==-1) || (!TeamInfo[i].Size))
  {
    Q->rear++;
    r = ++Q->TeamQ[Q->rear].Trear;
    Q->TeamQ[Q->rear].Customer[r].T = X.T;
    Q->TeamQ[Q->rear].Customer[r].P = X.P;
    strcpy(Q->TeamQ[Q->rear].Customer[r].Name,X.Name);
    Q->TeamQ[Q->rear].Tsize++;
    Q->size++;
    if(i != -1)
    {
	TeamInfo[i].Position = Q->rear;
        TeamInfo[i].Size++;
    }
  }
  else 
  {
     pos = TeamInfo[i].Position;
     r = ++Q->TeamQ[pos].Trear;
     Q->TeamQ[pos].Customer[r].T = X.T;
     Q->TeamQ[pos].Customer[r].P = X.P;
     strcpy(Q->TeamQ[pos].Customer[r].Name,X.Name);
     Q->TeamQ[pos].Tsize++;
     TeamInfo[i].Size++;
  }
}
struct People FrontQ(Queue Q)
{
   struct People X;
   int f;
   f = Q->TeamQ[Q->front].Tfront;
   X.T = Q->TeamQ[Q->front].Customer[f].T;
   X.P = Q->TeamQ[Q->front].Customer[f].P;
   strcpy(X.name,Q->TeamQ[Q->front].Customer[f].Name)
   return X;
}

void DeleteQ(Queue Q)
{
   int i = 0;
   int f = 0;
   f = Q->TeamQ[Q->front].Tfront;
   Q->TeamQ[Q->front].Tfront++;
   Q->TeamQ[Q->front].Tsize--;
   i = Team[NameHash(Q->TeamQ[Q->front])].Customer[f].Name;
   if(i != -1)
   {
	TeamInfo[i].Size--;
   }
   if(!Q->TeamQ[Q->front].Tsize)
   {
	Q->front++;
        Q->size--;
   }
}
int IsEmpty(Queue Q)
{
    return (Q->size==0);
}

struct People Enter(int *i)
{
   struct People X;
   char c;
   if((*i))
   {
	scanf("%s %d %d %c",X.Name,&X.T,&X.P,&c);
        (*i)--;
   }
   else
   {
	X.T = -1;
   }
   return X;
}

double QueueingAtBank(Queue Q,int N)
{
   struct People Next,Wait;
   int TotalTime = 0;
   int CurrentTime = 0;
   int i = N;
   TotalTime = CurrentTime = 0;
   Wait = Enter(&i);
   AddQ(Q,Wait);
   if(!i)
   {
	Next = FrontQ(Q);
        printf("%s \n",Next.Name);
        return 0.0;
   }
   else Wait = Enter(&i);
   while(!IsEmpty(Q) || (Wait.T >= 0))
   {
       if(!IsEmpty(Q))
       {
	 Next = FrontQ(Q);
         printf("%s \n",Next.Name);
         if(CurrentTime >= Next.T)
         {
		TotalTime += (CurrentTime - Next.T);
         }
         else
         {
		CurrentTime = Next.T;
         }
         CurrentTime += Next.P; 
         while((Wait.T >=0) && (Wait.T <= CurrentTime))
         {
		Add(Q.Wait);
                wait = Enter(&i);
         }
         DeleteQ(Q);
       }
       else
       {
	   AddQ(Q,Wait);
           wait = Enter(&i);
       }
   }
   return (double)TotalTime/(double)N;
}

int main()
{
    int N = 0;
    int M = 0;
    int MaxQSize;
    Queue Q;
    
    scanf("%d %d\n",&N,&M);
    MaxQsize = Read_and_Set_Teams(M);
    Q = CreateQueue(MaxQSize,N);
    printf("%.1lf\n",QueueingAtBank(Q,N));
    return 0;
}



























































