/*
  Complete Doubly Circular LinkedList in  C progrmmming using Functional Approach
  
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

void DeleteAtPos(PPNODE First , PPNODE Last , int iPos) //Delete Elements from given Position
{
  int NodeCount = Count(*First , *Last); 
  PNODE Temp = NULL;
  int iCnt = 0;
  
  if((iPos < 1) || (iPos > NodeCount))
  {
    printf("Invalid Position \n");
    return;
  }
   
  if(iPos == 1)
  {
     DeleteFirst(First , Last );
  }
  else if(iPos == NodeCount)
  {
     DeleteLast(First , Last );
  }
  else
  {    
     Temp = *First;
     
     for(iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
     {
         Temp = Temp->Next;
     }
     
     Temp->Next = Temp->Next->Next;
     free(Temp->Next->Prev);
     Temp->Next->Prev  = Temp;
  }
}

int main()
{
  PNODE Head = NULL;
  PNODE Tail = NULL;
  
  int iChoice = 0 ;
  int iPos = 0;
  int iRet = 0;
  int iNo = 0;
  
  printf("\n 🥰️ Welcome to My Data structure Application.....\n\n");
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
          
            printf("\n 🥰️ Thank you for using application .... !\n\n");
            return 0;
            
         default:
            printf("Please enter Valid Option\n");
            break;                    
      }
    }     
  
  return 0;
} 
