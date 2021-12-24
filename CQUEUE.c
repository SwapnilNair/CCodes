//Circular queue(RING BUFFER)
#include<stdio.h>
#include<stdlib.h>

typedef struct Cqueue{
   int *arr;
   int front;
   int rear;
   int size;
}cqueue;

void init(cqueue *q,int k)
{ q->front =-1;
   q->rear = -1;
   q->size = k;
   q->arr = (int*)malloc(sizeof(int)*k);
}

void insert(cqueue *q,int d)
{
   if(q->front ==-1 && q->rear ==-1) //if front and rear are -1
      {q->front = 0;  q->rear=0;
         q->arr[q->rear] = d;
      }
   else if(q->front == (q->rear+1)%q->size)  //If rear is front -1, queue is full
      {printf("Q full");return;}
   else
      {q->rear = (q->rear+1)%q->size;
         q->arr[q->rear] = d;
      } //Else increment rear and store it there

}

void service(cqueue *q)
{
   if(q->front == -1 && q->rear ==-1)  //If front == rear ==-1 , empyt
      {printf("Q is empty");}
   else if(q->front == q->rear) //if only one element is ther in the queue, remove that set f =r =-1
      { printf(" serviced %d ",q->arr[q->front]); 
         q->front = -1; 
         q->front = -1; }
   else
      {printf(" serviced %d ",q->arr[q->front]); //else just increment front and read
        q->front = (q->front+1)%q->size;}
}

void display(cqueue *q)
{
   if(q->front ==-1 && q->rear ==-1 )
      {printf("Q empty");}
   else
   { int i = q->front;
      printf("\nElements are : ");
      while(i!=q->rear)
         {
            printf(" %d ",q->arr[i]);
            i = (i+1)%q->size;
         }
         printf(" %d ",q->arr[i]);
         //Alternate method
         /*
         for (int i =q-> front; i < q->size; i++)
            printf("%d ", q->arr[i]);
 
        for (int i = 0; i <= q->rear; i++)
            printf("%d ", q->arr[i]);
            */
   }
}
int main()
{
   cqueue cq;
   init(&cq,5);
   insert(&cq,2);
   insert(&cq,3);
   insert(&cq,4);
   insert(&cq,5);
   insert(&cq,6);
   insert(&cq,7);
   insert(&cq,8);

   display(&cq);
   service(&cq);
   service(&cq);
   service(&cq);
   insert(&cq,6);
   insert(&cq,7);
   insert(&cq,8);
   display(&cq);
   service(&cq);
   service(&cq);
   insert(&cq,9);
   insert(&cq,10);
   display(&cq);



}
