/*
   Stack in C Programming
   
   Containts : Push Function
               Pop  Function
               
               Display Function
*/

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
  int Data;
  struct Node * Next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void Push(PPNODE First , int No) 
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
      Newn->Next = *First;
      *First = Newn;
   }
}

void Pop(PPNODE First)
{
   if(*First == NULL)
   {
      printf("Stack is Empty\n");
   }
   else
   {
      PNODE Temp = *First;
        
      (*First) = (*First)->Next;
      printf("Poped element is : %d\n",Temp->Data);
      free(Temp);
   }
}


void Display(PNODE First)
{
   PNODE Temp = First;
   
   while(Temp != NULL)
   {
      printf("| %d |\n",Temp->Data);
      Temp = Temp->Next;
   }
}

int main()
{ 
  PNODE Head = NULL;
  int iChoice = 0;
  int iNo = 0;
  
  while(1)
  {
     printf("\n-----------------------------------------------\n");
     printf("        Select Desired Option\n");
     printf("-----------------------------------------------\n");
     printf(" 1. Insert Element in Stack \n");
     printf(" 2. Delete Element in Stack \n");
     printf(" 3. Display Elements of Stack\n");
     printf(" 4. Exit\n");
     printf("-----------------------------------------------\n");
     
     printf("Enter Your Choice : ");
     scanf("%d",&iChoice);
     
     switch(iChoice)
     {
        case(1):
          printf("Enter Data You want to Insert : ");
          scanf("%d",&iNo);
          
          Push(&Head,iNo);
          break;
          
        case(2):
          Pop(&Head);
          break;
          
        case(3):
          Display(Head);
          break;
          
        case(4):
          printf(" 🥰️ Thank you for using application .... !\n\n");
          return 0;
          
        default :
          printf("Invalid Option..!!\n\tPlease Enter Valid Option\n");
          break;   
     }
  }
  
    
  return 0;
}
