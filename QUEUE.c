//Regular queue

#include<stdio.h>
#include<stdlib.h>

typedef struct Queue_t{
   int *arr;
   int rear;
   int size;
}queue;

void insert(queue *q,int d)
{ if(q->rear == q->size-1)
      {printf("Q full"); return;}
   else
      {  q->arr[++q->rear] = d; }
}

void service(queue *q)
{if(q->rear == -1)
   {printf("Q empty");}
   else{
      for(int i=0;i<=q->rear-1;i++)
         {q->arr[i] = q->arr[i+1]; }
      q->rear--;
         
   }
}
void print(queue *q)
{  if(q->rear == -1)
      {printf("Q empty");}
   else{
      
      for(int i=0;i<=q->rear;i++)
         {  printf(" %d ",q->arr[i]);   }
   }
}
void init(queue *q,int s)
{  q->arr = (int*)malloc(sizeof(int)*s);
   q->rear = -1;
   q->size = s;
}

int main()
{
   queue q;
   init(&q,10);
   
   insert(&q,1);
   insert(&q,2);
   insert(&q,3);

   print(&q);
   printf("\n");
   service(&q);
   service(&q);
   service(&q);
   service(&q);


}

