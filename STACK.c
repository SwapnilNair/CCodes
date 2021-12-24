//Stack and its functions

//LL implementation
#include<stdio.h>
#include<stdlib.h>

typedef struct stack_t
{ int* arr;
   int top;
   int size;
}stack;

int pop(stack* s) 
{  return s->arr[s->top--]; }

void push(stack *s,int k)
{  s->arr[++s->top] = k; }

void init(stack *s,int d)
{
   s->size = d;
   s->top = -1;
   s->arr = (int*)calloc(sizeof(int)*d);
}
int main()
{
   stack s;
   init(&s,100);
   push(&s,10);
   push(&s,10);
   push(&s,11);
   printf("%d",pop(&s));  
      printf("%d",pop(&s));  

   printf("%d",pop(&s));  
   printf("%d",pop(&s));  

}








