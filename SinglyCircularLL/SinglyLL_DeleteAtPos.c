/*
  Function to Delete Element of given position in LinkedList
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

//////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE First,PPNODE Last , int iNo)
{
   PNODE Newn = (PNODE)malloc(sizeof(NODE));
   
   Newn->Data = iNo;
   Newn->Next = NULL;
   
   if((*First == NULL) && (*Last == NULL))
   {
     *First = *Last = Newn;
     (*Last)->Next = *First;
   }
   else
   {  
     Newn->Next = *First;
     *First = Newn;
     (*Last)->Next = *First; 
   }
}

/////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE First , PPNODE Last, int iNo)
{
  PNODE Newn = (PNODE)malloc(sizeof(NODE));
  
  Newn->Data = iNo;
  Newn->Next = NULL;
  
  if((*First == NULL) && (*Last == NULL))
  {
    *First = *Last = Newn;
    (*Last)->Next = *First;
  }
  else
  {
     (*Last)->Next = Newn;
     *Last = Newn;
     (*Last)->Next = *First;
  }
}

///////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE First, PPNODE Last)
{
   if((*First == NULL) && (*Last == NULL))
   {
      return;
   }
   else if ((*First)->Next == *First)
   {
      free(*First);
      *First = *Last = NULL;
   }
   else
   {
      *First = (*First)->Next;
      free((*Last)->Next);
      (*Last)->Next = *First;
   }
}

///////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE First , PPNODE Last)
{
  PNODE Temp = *First;
  
   if((*First == NULL) && (*Last == NULL))
   {
      return;
   }
   else if ((*First)->Next == *First)
   {
      free(*First);
      *First = *Last = NULL;
   }
   else
   {
      while(Temp->Next != *Last)
      {
        Temp = Temp->Next;
      }
      
      free(Temp->Next);
      *Last = Temp;
      (*Last)->Next = *First;
   }
}

//////////////////////////////////////////////////////////////////////////

void Display(PNODE First,PNODE Last)
{ 
  printf("Elements is Linkedlist are : \n");
  do
  {
    printf("| %d |->",First->Data);
    First = First->Next;
  }
  while(First != Last->Next);
  printf("\n");
}

///////////////////////////////////////////////////////////////////////////

int Count(PNODE First, PNODE Last)
{
    int iCnt = 0;
    
    do
    {
        iCnt++;
        First = First -> Next;
    }
    while(First != Last->Next);
    return iCnt;
}

////////////////////////////////////////////////////////////////////////////////


void InsertAtPos(PPNODE First ,PPNODE Last ,int iNo , int iPos)
{
  int NodeCount = Count(*First , *Last);
  PNODE Temp = NULL;
  PNODE Newn = NULL;
  int iCnt = 0;
  
  if((iPos < 1 ) || (iPos > NodeCount+1))
  {
     printf("Invalid Position \n");
     return;
  }
  if(iPos == 1)
  {
    InsertFirst(First , Last ,iNo);
  }
  else if(iPos == NodeCount + 1)
  {
    InsertLast(First , Last , iNo);
  }
  else
  {
     Newn = (PNODE)malloc(sizeof(NODE));
     Temp = *First;
     
     Newn->Data = iNo;
     Newn->Next = NULL;
     
     for(iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
     {
       Temp = Temp->Next;
     }
     
     Newn->Next = Temp->Next;
     Temp->Next = Newn;
     
  }
}

//////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE First ,PPNODE Last , int iPos)
{
  int NodeCount = Count(*First , *Last);
  PNODE Temp1 = *First;
  PNODE Temp2 = *First;
  int iCnt = 0;
  
  if(iPos > NodeCount)
  {
     printf("Invalid Position \n");
     return;
  }
  if(iPos == 1)
  {
    DeleteFirst(First , Last);
  }
  else if(iPos == NodeCount)
  {
    DeleteLast(First , Last);
  }
  else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            Temp1 = Temp1->Next;
        }   
        Temp2 = Temp1 ->Next;

        Temp1->Next = Temp2->Next;
        free(Temp2);
    }
}

//////////////////////////////////////////////////////////////////////////

int main()
{
  PNODE Head = NULL;
  PNODE Tail = NULL;
   
  InsertFirst(&Head , &Tail , 51); 
  InsertFirst(&Head , &Tail , 21);  
  InsertFirst(&Head , &Tail , 11);
  InsertFirst(&Head , &Tail , 5); 
  Display(Head , Tail);  
  
  InsertLast(&Head , &Tail , 101);
  Display(Head,Tail); 
  
  DeleteFirst(&Head , &Tail);
  Display(Head,Tail);
  
  DeleteLast(&Head , &Tail);
  Display(Head,Tail);
  
  InsertAtPos(&Head,&Tail,105,3);
  Display(Head,Tail);
  
  DeleteAtPos(&Head,&Tail,3);
  Display(Head,Tail);
   
  return 0;
}

