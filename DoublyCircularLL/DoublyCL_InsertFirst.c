/*
  Function to Insert elements in first position in LinkedList
*/

#include<stdio.h>
#include<stdlib.h>
#pragma pack(2)

struct Node 
{
  struct Node * Prev;
  int Data;
  struct Node * Next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void InsertFirst(PPNODE First , PPNODE Last,int iNo)  //InsertFirst Function
{
   PNODE Newn = (PNODE)malloc(sizeof(NODE));
   
   Newn->Prev = NULL;
   Newn->Data = iNo;
   Newn->Prev = NULL;
   
   if((*First == NULL) && (*Last == NULL))
   {
      *First = Newn;
      *Last = Newn;
      (*First)->Prev = *Last;
      (*Last)->Next = *First;
   }
   else
   {
      Newn->Next = *First;
      (*First)->Prev = Newn;
      *First = Newn;
      (*First)->Prev = *Last;
      (*Last)->Next = *First;
   }
}

void Display(PNODE First , PNODE Last)  //Display Function
{
   if((First == NULL) && (Last == NULL))
   {
      printf("LinkedList is Empty...\n");
      return;
   }

   printf("Elements in LinkedList are : \n");
   
   do
   {
      printf("| %d |<->",First->Data);
      First = First->Next;
   }
   while(First != Last->Next);
   printf("\n");
}


int main()
{
  PNODE Head = NULL;
  PNODE Tail = NULL;

///  Call For Insert At First position Function /////////////////////////////  
  InsertFirst(&Head , &Tail , 51);
  InsertFirst(&Head , &Tail , 21);
  InsertFirst(&Head , &Tail , 11);
  InsertFirst(&Head , &Tail , 5);
  Display(Head , Tail);
  
  return 0;
}  
