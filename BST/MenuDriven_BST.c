/*
   MenuDriven Binary Search  Tree in C Programming
   
   Containts : InsertNode Function
               Inorder Function
               Preorder Function
               Postorder Function
               
*/


#include<stdio.h>
#include<stdlib.h>

struct Node
{
  struct Node * lchild;	
  int Data;
  struct Node * rchild;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void InsertNode(PPNODE Root , int iNo)
{
   PNODE Newn = (PNODE)malloc(sizeof(NODE));

   Newn->lchild= NULL;
   Newn->rchild = NULL;
   Newn->Data = iNo; 

   if((*Root) == NULL)
   {
      (*Root) = Newn;
   }
   else
   {
      PNODE Temp = *Root;	   
     
      while(1)
      {
         if(iNo > Temp->Data)
	 {
            if(Temp->rchild == NULL)
	    {
               Temp->rchild = Newn;
	       break;
	    }

	    Temp = Temp->rchild;
	 }
         else if(iNo < Temp->Data)
	 {
            if(Temp->lchild == NULL)
	    {
               Temp->lchild = Newn;
	       break;
	    }

	    Temp = Temp->lchild;
	 }
	 else if(iNo == Temp->Data)
	 {
            printf("No Duplicate Elements allowed in BST\n");
	    free(Newn);
	    break;
	 }
      }
   }
}

void Inorder(PNODE Root)
{
   if(Root != NULL)
   {
      Inorder(Root->lchild);
      printf("%d\t",Root->Data);
      Inorder(Root->rchild);
   }

}

void Preorder(PNODE Root)
{
   if(Root != NULL)
   {
      printf("%d\t",Root->Data);
      Preorder(Root->lchild);
      Preorder(Root->rchild);
   }
 
}

void Postorder(PNODE Root)
{
  if(Root != NULL)
  {
     Postorder(Root->lchild);
     Postorder(Root->rchild);
     printf("%d\t",Root->Data);
  }
}

int main()
{
  PNODE Head = NULL;

  int iChoice = 0;
  int iNo = 0;
  
  while(1)
  { 
     printf("\n------------------------\n");
     printf("Select Your Choice\n");
     printf("------------------------\n");
     printf("1. Insert Node in BST \n");
     printf("2. Display in Inorder \n");
     printf("3. Display in Preorder \n");
     printf("4. Display in PostOrder \n");
     printf("5. Exit\n");
     printf("------------------------\n");
     
     printf("Enter Your choice : ");
     scanf("%d",&iChoice);
     
     if(iChoice == 1)
     {
        printf("Enter Data You want : ");
        scanf("%d",&iNo);
        
        InsertNode(&Head , iNo);
     }
     else if(iChoice == 2)
     {
        printf("\nInorder sequence is : \n");
        Inorder(Head);
     }
     else if(iChoice == 3)
     {
        printf("\nPreorder sequence is : \n");
        Preorder(Head);
     }
     else if(iChoice == 4)
     {
        printf("\nPostorder sequence is : \n");
        Postorder(Head);
     }
     else if(iChoice == 5)
     {
        printf("Thank You .....! \n\t for using our application .... 🥰️ \n");
        return 0;
     }
  }
  

  return 0;
}
