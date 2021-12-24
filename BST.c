//Program to implement BSt

#include<stdio.h>
#include<stdlib.h>

typedef struct node_t
{ int info;
   struct node_t *left;
   struct node_t *right;
}node;

typedef struct BST_t{
   node* root;
}BST;

void io(node* r)
{ if(r!=NULL)
   { io(r->left);
      printf(" %d ",r->info);
      io(r->right);
   }  
}

void po(node* r)
{  if(r!=NULL)
   {  po(r->left);
       po(r->right);
       printf(" %d ",r->info);
   }
}

void pro(node* r)
{  if(r!=NULL)
   {  printf(" %d ",r->info);
       pro(r->left);
       pro(r->right);
   }

}

node* newnode(int d)
{ node* temp = (node*)malloc(sizeof(node));
   temp->left = NULL;
   temp->right = NULL;
   temp->info = d;
   return temp;
}

node* insert(node *p,int k)
{ if(p==NULL)
      {return  newnode(k);}
   else if(k<p->info)
      {p->left = insert(p->left,k);}
   else if(k>p->info)
      {p->right = insert(p->right,k);}
   return p;
}

node* delnode(node* r,int ele)
{  //if null just return r
   node *temp,*p;
   if(r==NULL) {return r;}
   if(ele< r->info)
      {r->left = delnode(r->left,ele);} //delete from left tree
   else if(ele>r->info)
      {r->right = delnode(r->right,ele);} //delete from right tree
   else { if(r->left ==NULL)
               {  temp = r->right; 
                   free(r);
                  return temp;
               }
            else if(r->right == NULL)
               {  temp= r->left;
                   free(r);
                   return temp;
               }
            else
            { p = r->right;
               while(p->left!=NULL)
                  {p = p->left;}
                r->info = p->info;
               r->right = delnode(r->right,p->info);
            }
            }
   return r;
}

int main()
{
   BST *p = (BST*)malloc(sizeof(BST));
   p->root =NULL;
   int d,k;

do{
        printf("Enter the choice:\n 1 for Insert \n 2 for Display \n 3 for Exit\n");
        scanf("%d",&k);
        switch(k){
                case 1: printf("enter the value : "); 
                            scanf("%d",&d);
                            if(p->root ==NULL)
                              {p->root = insert(p->root,d);}
                            else
                              { insert(p->root,d); }
                            break;
                case 2:   io(p->root);
                              po(p->root);
                              pro(p->root);
                              break;
                case 3: exit(0);
                        break;
               case 4: printf("Enter the value to be deleted :");
                           scanf("%d",&d);
                           delnode(p->root,d);
                }
        }while(1);

}
