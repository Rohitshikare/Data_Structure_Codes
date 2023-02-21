/*
   Stack using C Programming
   
   Containts : Enqueue Function
               Dequeue Function
               
               Display Function
               Count Function
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
  int iRet = 0;
  
  Enqueue(&Head,10);
  Enqueue(&Head,20);
  Enqueue(&Head,30);
  Enqueue(&Head,40);
  Enqueue(&Head,50); 
  Display(Head);
  
  Dequeue(&Head);
  Display(Head);
 
  iRet = Count(Head);
  printf("Number of Elements in Queue are : %d \n",iRet);
  
  
  return 0;
}
