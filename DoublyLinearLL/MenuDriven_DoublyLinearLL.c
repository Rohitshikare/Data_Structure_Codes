/*
 Complete Doubly Linear LinkedList in C programming
 
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
  struct Node * Prev;   //X
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
     (*First)->Prev = Newn;  
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
    printf("| %d |<->",First->Data);
    First = First->Next;
  }
  
  printf(" NULL\n");
}

////////////////////////////////////////////////////////////////////////

int Count(PNODE First)
{
  int iCnt = 0;
  
  while(First != NULL)
  {
     iCnt++;
     First = First->Next;
  }
  
  return iCnt;
}

/////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE First,int iNo,int iPos)
{
   int NodeCount = Count(*First);
   PNODE Temp = NULL;
   int iCnt = 0;
   
   if((iPos < 1) || (iPos > NodeCount+1))
   {
     printf("Invalid Position....\n");
     return;
   } 
   
   if(iPos == 1)
   {
     InsertFirst(First,iNo);
   }
   else if(iPos == NodeCount+1)
   {
     InsertLast(First,iNo);
   }
   else
   {
     Temp = *First;
     PNODE Newn = (PNODE)malloc(sizeof(NODE));
     Newn->Data = iNo;
     Newn->Next = NULL;
     Newn->Prev = NULL;
     
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

///////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE First,int iPos)
{
   int NodeCount = Count(*First);
   PNODE Temp = NULL;
   int iCnt = 0;
   
   if((iPos < 1) || (iPos > NodeCount+1))
   {
     printf("Invalid Position....\n");
     return;
   } 
   
   if(iPos == 1)
   {
     DeleteFirst(First);
   }
   else if(iPos == NodeCount)
   {
     DeleteLast(First);
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
     Temp->Next->Prev = Temp;
     
   } 
}

int main()
{
  PNODE Head = NULL;
  
  int iChoice = 0 ;
  int iPos = 0;
  int iRet = 0;
  int iNo = 0;
  
  printf("\n🥰️ Welcome to My Data structure Application... \n\n");
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
            
            InsertFirst(&Head,iNo);
            break;
            
         case 2:
            printf("Enter Data want to insert : ");
            scanf("%d",&iNo);
            
            InsertLast(&Head,iNo);
            break;  
            
         case 3:
            printf("Enter Data want to insert : ");
            scanf("%d",&iNo);
            
            printf("Enter Position : ");
            scanf("%d",&iPos);
            
            InsertAtPos(&Head,iNo,iPos);
            break;
            
         case 4:
            DeleteFirst(&Head);
            break; 
            
         case 5:
            DeleteLast(&Head);
            break;  
         
         case 6:
            printf("Enter the position : ");
            scanf("%d",&iPos);
            
            DeleteAtPos(&Head,iPos);
            break;
            
         case 7:
            Display(Head);
            break;
            
         case 8:
            iRet = Count(Head);
            printf("Number of elements are : %d\n", iRet);
            break; 
            
         case 9:
          
            printf("\n🥰️ Thank you for using application .... !\n\n");
            return 0;
            
         default:
            printf("Please enter Valid Option\n");
            break;                    
      }
    } 
  return 0;
}
