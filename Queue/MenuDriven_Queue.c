/*
   Stack using C Programming
   
   Containts : Enqueue Function
               Dequeue Function
               
               Display Function
*/

#include<stdio.h>
#include<stdlib.h>

struct SNode 
{
   int Data;
   struct SNode * Next;
};

typedef struct SNode NODE;
typedef struct SNode *  PNODE;
typedef struct SNode ** PPNODE;

void Enqueue(PPNODE First, int No)
{
   PNODE Newn = (PNODE)malloc(sizeof(NODE));
   
   Newn->Data = No;
   Newn->Next = NULL;
   
   if(*First == NULL)
   {
     *First = Newn;
   }
   else
   {
      PNODE Temp = *First;
      
      while(Temp->Next != NULL)
      {
         Temp = Temp->Next;
      }
      
      Temp->Next = Newn;
   }
}


void Dequeue(PPNODE First)
{
   PNODE Temp = *First;
   
   if(*First == NULL)
   {  
      printf("Queue is empty\n");
      return;
   }
   else if((*First)->Next == NULL)
   {
      printf("Dequeued elements is : %d\n", Temp->Data);
      free(*First);  
      *First = NULL;
   }
   else
   {
      (*First) = (*First)->Next;
      printf("Dequeued elements is : %d\n", Temp->Data);
      free(Temp);
   }
}

int Count(PNODE First)
{
   PNODE Temp = First;
   int iCount = 0;
   
   while(Temp != NULL)
   {
     iCount++;
     Temp = Temp->Next;
   }
   
   return iCount;
}


void Display(PNODE First)
{
   PNODE Temp = First;
   
   if(Temp == NULL)
   {
      printf("Queue is Empty\n");
      return;
   }
   else
   {
      printf("Elements in Queue are : \n");
   }
   
   while(Temp != NULL)
   {
     printf(" | %d",Temp->Data);
     Temp = Temp->Next;
   }
   
   printf("\n");
}

int main()
{
  PNODE Head = NULL;
  int iChoice = 0;
  int iNo = 0;
  int iRet = 0;
  
  while(1)
  {
     printf("\n-----------------------------------------------\n");
     printf("        Select Desired Option\n");
     printf("-----------------------------------------------\n");
     printf(" 1. Insert Element in Queue \n");
     printf(" 2. Delete Element in Queue \n");
     printf(" 3. Display Elements of Queue\n");
     printf(" 4. Count Number of Elements\n");
     printf(" 5. Exit\n");
     printf("-----------------------------------------------\n");
     
     printf("Enter Your Choice : ");
     scanf("%d",&iChoice);
     
     switch(iChoice)
     {
        case(1):
          printf("Enter Data You want to Insert : ");
          scanf("%d",&iNo);
          
          Enqueue(&Head,iNo);
          break;
          
        case(2):
          Dequeue(&Head);
          break;
          
        case(3):
          Display(Head);
          break;
          
        case(4):
          iRet = Count(Head);
          printf("Number of Elements in Queue are : %d\n",iRet);
          break;
          
        case(5):
          printf(" 🥰️ Thank you for using application .... !\n\n");
          return 0;
        
        default :
          printf("Invalid Option..!!\n\tPlease Enter Valid Option\n");
          break;   
     }
  }
  
  return 0;
}
