/*
   Binary Search  Tree in C++ Programming
   
   Containts : InsertNode Function
               Inorder Function
               Preorder Function
               Postorder Function
               
*/

#include<iostream>
using namespace std;

class Node
{
  public:
   Node * lchild;
   int Data;
   Node * rchild;
};

typedef class Node NODE;
typedef class Node * PNODE;
typedef class Node ** PPNODE;

class BST
{
   public:
   
     void InsertNode(PPNODE Root , int iNo)
     {
         PNODE Newn = new NODE;
         
         Newn->lchild = NULL;
         Newn->Data = iNo;
         Newn->rchild = NULL;
         
         
         if(*Root == NULL)
         {
            *Root = Newn;
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
                   cout<<"Duplicate Elements are Not Allowed \n";
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
            cout<<Root->Data<<"\t";
            Inorder(Root->rchild);
         }
     }
     
     void Preorder(PNODE Root)
     {
        if(Root != NULL)
        {
           cout<<Root->Data<<"\t";
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
           cout<<Root->Data<<"\t";
        }
     }
};

int main()
{
  PNODE Head = NULL;
  
  BST * obj = new BST();
  
  obj->InsertNode(&Head , 50);
  obj->InsertNode(&Head , 40);
  obj->InsertNode(&Head , 30);
  obj->InsertNode(&Head , 45);
  obj->InsertNode(&Head , 60);
  obj->InsertNode(&Head , 70);
  obj->InsertNode(&Head , 55);
  
  cout<<"Inorder Sequence is : \n";
  obj->Inorder(Head);
  cout<<"\n";
  
  cout<<"Preorder Sequence is : \n";
  obj->Preorder(Head);
  cout<<"\n";
  
  cout<<"Postorder Sequence is : \n";
  obj->Postorder(Head);
  cout<<"\n";
  
  return 0;
}
