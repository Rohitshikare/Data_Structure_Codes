/*
  Singly Circular Linkedlist in C Programming 
  
  Containts :  InsertFirst Function
               InsertLast  Function
               InsertAtPos Function
               
               DeleteFirst Function
               DeleteLast  Function
               DeleteAtPos Function
               
               Display Function
               Count   Function
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
  
  int iChoice = 0 ;
  int iPos = 0;
  int iRet = 0;
  int iNo = 0;
  
  printf("🥰️ Welcome to My Data structure Application... \n");
  while(1)
  {
      printf("--------------------------------------------\n");
      printf("   Please select Desired Option  \n");
      printf("--------------------------------------------\n");
      printf("1 : Insert New Node At First Position\n");
      printf("2 : Insert New Node At Last Position\n");
      printf("3 : Insert New Node At Given Position\n");
      printf("4 : Delete Node of First Position\n");
      printf("5 : Delete Node of Last Position\n");
      printf("6 : Delete Node of Given Position\n");
      printf("7 : Display LinkedList\n");
      printf("8 : Count Number of LinkedList\n");
      printf("9 : Exit\n");
      printf("--------------------------------------------\n\n");
      
      printf("Enter Choice : ");
      scanf("%d",&iChoice);
      
      switch(iChoice)
      {
         case 1:
            printf("Enter Data want to insert : ");
            scanf("%d",&iNo);
            
            InsertFirst(&Head,&Tail,iNo);
            break;
            
         case 2:
            printf("Enter Data want to insert : ");
            scanf("%d",&iNo);
            
            InsertLast(&Head,&Tail,iNo);
            break;  
            
         case 3:
            printf("Enter Data want to insert : ");
            scanf("%d",&iNo);
            
            printf("Enter Position : ");
            scanf("%d",&iPos);
            
            InsertAtPos(&Head,&Tail,iNo,iPos);
            break;
            
         case 4:
            DeleteFirst(&Head,&Tail);
            break; 
            
         case 5:
            DeleteLast(&Head,&Tail);
            break;  
         
         case 6:
            printf("Enter the position : ");
            scanf("%d",&iPos);
            
            DeleteAtPos(&Head,&Tail,iPos);
            break;
            
         case 7:
            Display(Head,Tail);
            break;
            
         case 8:
            iRet = Count(Head,Tail);
            printf("Number of elements are : %d\n", iRet);
            break; 
            
         case 9:
          
            printf("🥰️ Thank you for using application .... !\n");
            return 0;
            
         default:
            printf("Please enter Valid Option\n");
            break;                    
      }
    }  
   
  return 0;
}
