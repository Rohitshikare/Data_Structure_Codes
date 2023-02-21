/*
   Stack in C Programming
   
   Containts : Push Function
               Pop  Function
               
               Display Function
*/

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
  int Data;
  struct Node * Next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void Push(PPNODE First , int No) 
{
   PNODE Newn = (PNODE)malloc(sizeof(NODE));
   
   Newn->Data = No;
   Newn->Next = NULL;
   
   if(*First == NULL)
   {
      *First = Newn;
   }
   else
   {
      Newn->Next = *First;
      *First = Newn;
   }
}

void Pop(PPNODE First)
{
   if(*First == NULL)
   {
      printf("Stack is Empty\n");
   }
   else
   {
      PNODE Temp = *First;
        
      (*First) = (*First)->Next;
      printf("Poped element is : %d\n",Temp->Data);
      free(Temp);
   }
}


void Display(PNODE First)
{
   PNODE Temp = First;
   
   while(Temp != NULL)
   {
      printf("| %d |\n",Temp->Data);
      Temp = Temp->Next;
   }
}

int main()
{ 
  PNODE Head = NULL;
  
  Push(&Head,10);
  Push(&Head,20);
  Push(&Head,30);
  Push(&Head,40);
  Display(Head);
  
  Pop(&Head);
  Display(Head);
    
  return 0;
}
