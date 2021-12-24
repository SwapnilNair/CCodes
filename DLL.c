//Double linked list and its functions
#include<stdio.h>
#include<stdlib.h>
//Structures
typedef struct node_t{
   int data;
   struct node_t *prev;
   struct node_t *next;
}node;

typedef struct doublylinkedlist{
   node* head;
}dll;

//Initialization
void init(dll* p)
{  p->head = NULL;    }

//Newnode function
node* newnode(int d)
{ node* temp = (node*)malloc(sizeof(node));
   temp->data = d;
   temp->prev = NULL;
   temp->next = NULL;
   return temp;
}


//Insert function
void insert(dll* p,int k)
{ node* start = p->head;
   node* temp = newnode(k);
   if(p->head == NULL)
      {p->head = temp;}
   else
   {  while(start->next !=NULL)
         {start = start->next;}
          start->next = temp;
          temp->prev = start;
   }
}

void insertio(dll* p ,int k)
{ node* start = p->head;
   node* temp = newnode(k);
   if(p->head == NULL)
      {p->head = temp;
      printf("here1");}
      
   else  if(p->head->data >k)
      { p->head->prev = temp;
         temp->next = p->head;
         p->head = temp;
         printf("here2");}
         
   else{ while(start->next != NULL && start->next->data <k)
                  {  start = start->next;} 
            if(start->next == NULL)
                  { start->next = temp;
                    printf("Here2");
                     temp->prev = start;} 
            else{
               temp ->next= start->next;
               start->next->prev = temp;
               start->next = temp;
               temp->prev = start;
               }
   }
}

void reverse(dll *p,int k)
{
   node *prev = NULL,*curr = p->head,*next =NULL;
   while(curr!=NULL)
   {
      next = curr->next;
      curr->next =prev;
      prev = curr;
      curr = next;
   }
   p->head = curr;
}

//Display function
void display(dll *p)
{
   if(p->head == NULL){printf("Empty list.\n");}
   else{
      node* start = p->head;
      printf("List forwards is  :");
      while(start!=NULL)
      { printf(" %d ",start->data);  
         start = start->next;}
      printf("\n");
   }
}

//Display reverse
void displayr(dll *p)
{
   node* start = p->head;
   if(start==NULL)
   { printf("List is empty");}
   else{
      while(start->next !=NULL)
         {start = start->next;}
      printf("List backwards is :");
      while(start!=NULL)
         { printf(" %d ",start->data);
            start = start->prev;}
         printf("\n");
      }
}
//main
int main()
{ dll *p = (dll*)malloc(sizeof(dll)); 
 init(p);
    insertio(p,3);
      display(p);
   displayr(p);
   insertio(p,1);
      display(p);
   displayr(p);
       insertio(p,2);
   
         insertio(p,4);
   display(p);
   displayr(p);
}
