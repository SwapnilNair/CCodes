//Singly Linked list and functions
// INSERT | DELETE | REVERSE | DISPLAY

#include<stdio.h>
#include<stdlib.h>

//Defining the structure of each node
typedef struct node_t{
   int data;
   struct node_t* next;
}node;

//Defining head of the linked list
typedef struct linked_list{
   node* head;
}ll;

//Initialize the linkedlist
void init(ll* p)
{   p->head = NULL;  }

//Newnode
node* newnode(int d)
{ node* temp = (node*)malloc(sizeof(node));
   temp->next = NULL;
   temp->data = d;
   return temp;
}

//Insert elements to the linked list
void insert(ll *p)
{  int val;
   printf("Enter the value to be added");
   scanf("%d",&val);
   node* temp = newnode(val);
   node* start = p->head;
   if(start == NULL)
      {p->head = temp;
      }
   else{
      while(start->next!=NULL)
         {start = start->next;}
         start->next = temp;
         }
}


//Delete 
void del(ll *p,int k)
{  node* q = p->head;
    if(q == NULL)
      {printf("\nList is Empty \n");}
   else  if(q->data == k)
      { p->head =q->next;   printf("Element was in position 1\n");}
    else
      { while(q->next !=NULL && q->next->data !=k)
               {q=q->next;}
            if(q->next == NULL)
               {printf("Element not found...\n");}
            else{
                  node* del = q->next;
                  q->next = q->next->next;
                  free(del);
                  printf("Deleted succesfully\n");
                  }
      }
}

//Reverse
void reverse(ll* p)
{  node *prev = NULL, *curr = p->head,*next = NULL;
   while(curr!=NULL)
   { next = curr->next;
      curr->next = prev;
      prev = curr;
      curr= next;
   }
   p->head = prev;

}
//Display
void display(ll *p)
{ node* q = p->head;
   if(q == NULL)
         {printf("\nThe list is empty !\n");}
   else{printf("The list is :");
         while(q!=NULL)
            {printf(" %d ",q->data);    q= q->next;}
         printf("\n");
         }
}

int main()
{  ll* p = (ll*)malloc(sizeof(ll));
   init(p);
   
   insert(p);
   display(p);
   
   insert(p);
   display(p);
   
   insert(p);
   display(p);
   
   reverse(p);
   display(p);
   
   del(p,5);
   display(p);

   del(p,8);
   display(p);
   
   del(p,8);
   display(p);
}




