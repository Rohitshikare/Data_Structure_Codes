/*
  Function to Insert element at given position in LinkedList
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

void InsertLast(PPNODE First , PPNODE Last,int iNo) //InsertLast Function
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
      (*Last)->Next = Newn;
      Newn->Prev = *Last;
      *Last = Newn;
      (*First)->Prev = *Last;
      (*Last)->Next = *First;   
   }
}

void DeleteFirst(PPNODE First , PPNODE Last)  //DeleteFirst Function
{
   
   if((*First == NULL) && (*Last == NULL))
   {
      printf("LinkedList is Empty....\n");
      return;
   }
   else if((*First)->Next == *Last)
   {
      free(*First);
      *First = NULL;
      *Last = NULL;
   }
   else
   {
     *First = (*First)->Next;
     free((*Last)->Next);            //free((*First)->Prev)   
     (*First)->Prev = *Last;
     (*Last)->Next = *First;
   }
}

void DeleteLast(PPNODE First , PPNODE Last) //DeleteLast Function
{
   if((*First == NULL) && (*Last == NULL))
   {
      printf("LinkedList is Empty....\n");
      return;
   }
   else if((*First)->Next == *Last)
   {
      free(*First);
      *First = NULL;
      *Last = NULL;
   }
   else
   {
      *Last = (*Last)->Prev;
      free((*First)->Prev);
      (*Last)->Next = *First;
      (*First)->Prev = *Last;
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

int Count(PNODE First , PNODE Last)  //Function To count Number of Nodes
{
  int iCnt = 0;
  PNODE Temp = First;
  
  do
  {
     iCnt++;
     Temp = Temp->Next;
  }
  while(Temp != First);

  return iCnt;
}

void InsertAtPos(PPNODE First , PPNODE Last , int iNo ,int iPos) //Function to Insert at Position
{
  int NodeCount = Count(*First , *Last); 
  PNODE Temp = NULL;
  int iCnt = 0;
  
  if((iPos < 1) || (iPos > NodeCount+1))
  {
    printf("Invalid Position \n");
    return;
  }
   
  if(iPos == 1)
  {
     InsertFirst(First , Last , iNo);
  }
  else if(iPos == NodeCount+1)
  {
     InsertLast(First , Last , iNo);
  }
  else
  {
     PNODE Newn = (PNODE)malloc(sizeof(NODE));
     
     Newn->Prev = NULL;
     Newn->Data = iNo;
     Newn->Prev = NULL;
     
     Temp = *First;
     
     for(iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
     {
         Temp = Temp->Next;
     }
     
     Newn->Next = Temp->Next;
     Temp->Next->Prev = Newn;
     Temp->Next = Newn;
     Newn->Prev = Temp;
  }
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
  
///  Call For Insert At Last Position Function //////////////////////////////
  InsertLast(&Head , &Tail , 101);
  InsertLast(&Head , &Tail , 111);
  Display(Head , Tail);
 

//  Call For Delete elements of First Position Function /////////////////////
  DeleteFirst(&Head , &Tail);
  Display(Head , Tail);    
  
//  Call For Delete elements of Last  Position Function /////////////////////
  DeleteLast(&Head , &Tail);
  Display(Head , Tail);
  
///  Call For Insert At Last Position Function //////////////////////////////
  InsertAtPos(&Head , &Tail , 71, 5 );
  Display(Head , Tail);  
  
  
  return 0;
}  
