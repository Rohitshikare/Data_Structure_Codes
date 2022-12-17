/*
  Function To Insert Element at Last position in LinkedList
*/

#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)

struct Node 
{
  int Data;
  struct Node * Next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE First ,int No)
{
   PNODE Newn = (PNODE)malloc(sizeof(NODE)); //1 : Allocate Memory
   
   Newn->Data = No;
   Newn->Next = NULL;
   
   if(*First == NULL)  // If linkedlist is empty
   {
     *First = Newn;
   } 
   else                // If linkedlist contain atleast one node
   {
     Newn->Next = * First;
     *First = Newn; 
   }
}

////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE First ,int No)
{
   PNODE Newn = (PNODE)malloc(sizeof(NODE)); //1 : Allocate Memory
   PNODE temp = * First;
   
   Newn->Data = No;
   Newn->Next = NULL;
   
   if(*First == NULL)  // If linkedlist is empty
   {
     *First = Newn;
   } 
   else                // If linkedlist contain atleast one node
   {
     while(temp->Next != NULL)
     {
       temp = temp->Next;
     }
     temp->Next = Newn;
   }
}

///////////////////////////////////////////////////////////////////////

void Display(PNODE First)
{
  printf("Elements From LinkedList are : \n");
  
  while(First != NULL)
  {
    printf("| %d |->",First->Data);
    First = First->Next;
  }
  printf("NULL\n");
}

////////////////////////////////////////////////////////////////////////

int main()
{
 
  PNODE Head = NULL;
  
  InsertFirst(&Head,51);
  InsertFirst(&Head,21);
  InsertFirst(&Head,11);
  InsertFirst(&Head,5);
  Display(Head);
  
  InsertLast(&Head,101);
  InsertLast(&Head,111);
  Display(Head);
 
  return 0;
}

