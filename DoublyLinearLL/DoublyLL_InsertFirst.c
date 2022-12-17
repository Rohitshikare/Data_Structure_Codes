/*
   Function To Insert Element at First position
*/

#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)

struct Node
{
  
  int Data;
  struct Node * Next;
  struct Node * Prev;   
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;  
 

void InsertFirst(PPNODE First,int No)
{
  PNODE Newn = (PNODE)malloc(sizeof(NODE));
  
  Newn->Data = No;
  Newn->Next = NULL;
  Newn->Prev = NULL;  
  
  if(*First == NULL)
  {
     *First = Newn;
  }
  else
  {
     Newn->Next = *First;
     (*First)->Prev = Newn;  //X
     *First = Newn;
  }
}

/////////////////////////////////////////////////////////////////

void  Display(PNODE First)
{
  printf("Elements in DoublyLinkedList :\n");
   
  while(First != NULL)
  {
    printf("| %d | <-> ",First->Data);
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
  
  return 0;
}
