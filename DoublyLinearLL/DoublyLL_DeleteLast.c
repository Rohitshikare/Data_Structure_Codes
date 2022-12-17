/*
   Function To Delete Element of Last position
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

void InsertLast(PPNODE First,int No)
{
  PNODE Newn = (PNODE)malloc(sizeof(NODE));
  PNODE temp = *First;
  
  Newn->Data = No;
  Newn->Next = NULL;
  Newn->Prev = NULL;  
  
  if(*First == NULL)
  {
     *First = Newn;
  }
  else
  {
     while(temp->Next != NULL)
     {
        temp = temp->Next;
     }
     
     temp->Next = Newn;
     Newn->Prev = temp;   
  }
}

//////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE First)
{
  PNODE temp = *First;
  
  if(*First == NULL)
  {
    return;
  }
  else if((*First)->Next == NULL)
  {
    *First = NULL; 
    free(temp);
    
    ///////////////////////
    //                   //
    //   free(*First)'   //
    //   *First = NULL;  //
    //                   // 
    ///////////////////////
  }                                  //Not for singly LinkedList
  else                               //////////////////////////////// 
  {                                  //                            //
     *First = temp->Next;            //  *First = (*First)->Next;  //
     temp->Next = NULL;              //  free((*First)->Prev);     //
     (*First)->Prev = NULL;          //  (*First)->Prev = NULL;    //
     free(temp);                     //                            //
  }                                  ////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE First)
{
  PNODE temp = *First;
  
  if(*First == NULL)
  {
    return;
  }
  else if((*First)->Next == NULL)
  {
    *First = NULL; 
    free(temp);
  }            
  else
  {
    while(temp->Next->Next != NULL)
    {
       temp = temp->Next;
    }
    
    free(temp->Next);
    temp->Next = NULL;
    
  }          
}

////////////////////////////////////////////////////////////////////////

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
  
  InsertLast(&Head,101);
  InsertLast(&Head,111);
  Display(Head);
  
  DeleteFirst(&Head);
  Display(Head);
  
  DeleteLast(&Head);
  Display(Head); 
  
  return 0;
}
