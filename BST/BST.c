/*
   Binary Search  Tree in C Programming
   
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

  
  InsertNode(&Head , 50);
  InsertNode(&Head , 30);
  InsertNode(&Head , 20);
  InsertNode(&Head , 40);
  InsertNode(&Head , 70);
  InsertNode(&Head , 60);
  InsertNode(&Head , 80);



  Inorder(Head);
  printf("\n");

  Preorder(Head);
  printf("\n");

  Postorder(Head);
  printf("\n");

  return 0;
}
