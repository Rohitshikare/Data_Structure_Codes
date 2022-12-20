/*
  Singly Linear Linkedlist in C++ using oops concepts
  
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

void DeleteFirst(PPNODE First)
{
  PNODE temp = * First;
  if(*First == NULL)  // A LB book dry run
  {
     return;
  }
  else if((*First)->Next == NULL) // B LB book dry run
  {
     free(*First);
     *First = NULL;
  }
  else     // C LB book dry run
  {
     
     (*First) = (*First)->Next;
     free(temp);
  }
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
     free(*First);
     *First = NULL;
  }
  else
  {
     while(temp -> Next ->Next != NULL)
     {
       temp = temp->Next;
     }
     free(temp->Next);
     temp->Next = NULL;
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

///////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE First ,int No ,int iPos)
{
  int NodeCnt = 0;
  PNODE Newn = NULL;
  PNODE temp = NULL;
  int iCnt = 0;
  
  NodeCnt = Count(*First);  //call for count function
  
  if((iPos < 1) || (iPos >(NodeCnt + 1)))
  {
    printf("Invalid Position\n");
    return ;
  }
 
  if(iPos == 1)
  {
    InsertFirst(First,No);
  }
  else if(iPos == NodeCnt+1)
  {
    InsertLast(First,No);
  }
  else
  {
    Newn = (PNODE)malloc(sizeof(NODE));
    
    Newn->Data = No;
    Newn->Next = NULL;
    
    temp = *First;
    
    for(iCnt = 1;iCnt < iPos-1;iCnt++)
    {
      temp = temp->Next;
    }
    
    Newn->Next = temp->Next; 
    temp->Next = Newn;
    
  }
}
/////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE First,int iPos)
{
  PNODE temp = NULL;
  int iCnt = 0;
  int NodeCnt = 0;
  PNODE temp1 = NULL;
  PNODE temp2 = NULL;
  
  NodeCnt = Count(*First);
  
  if((iPos < 1) || (iPos > NodeCnt))
  {
    printf("Invalid Position");
    return ;
  }
  
  if(iPos == 1)
  {
    DeleteFirst(First);
  }
  else if(iPos == NodeCnt)
  {
    DeleteLast(First);
  }
  else
  {
     temp1 = *First;
     
     for(iCnt = 1; iCnt < iPos- 1;iCnt++)
     {
       temp1 = temp1->Next;
     }
     
     temp2 = temp1->Next;
     
     temp1->Next = temp2->Next; //temp->Next = temp->Next->Next;
     free(temp2);
  }
}

///////////////////////////////////////////////////////////////

int main()
{
 
  PNODE Head = NULL;
  
  int iChoice = 0 ;
  int iPos = 0;
  int iRet = 0;
  int iNo = 0;
  
  printf("🥰️ Welcome to My Data structure Application... \n");
  while(1)
  {
      printf("--------------------------------------------\n");
      printf("Please select Desired Option  \n");
      printf("---------------------------------------------\n");
      printf("1 : Insert New Node At First Position\n");
      printf("2 : Insert New Node At Last Position\n");
      printf("3 : Insert New Node At Given Position\n");
      printf("4 : Delete Node of First Position\n");
      printf("5 : Delete Node of Last Position\n");
      printf("6 : Delete Node of Given Position\n");
      printf("7 : Display LinkedList\n");
      printf("8 : Count Number of LinkedList\n");
      printf("9 : Exit\n");
      printf("---------------------------------------------\n\n");
      
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
          
            printf("🥰️ Thank you for using application .... !\n");
            return 0;
            
         default:
            printf("Please enter Valid Option\n");
            break;                    
      }
  }
  
  return 0;
}
