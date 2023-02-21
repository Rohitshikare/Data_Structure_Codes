/*
   Stack using C++ Programming
   
   Containts : Enqueue Function
               Dequeue Function
               
               Display Function
*/

#include<iostream>
using namespace std;

struct SNode 
{
   int Data;
   struct SNode * Next;
};

typedef struct SNode NODE;
typedef struct SNode *  PNODE;

class Queue
{
  public :
    PNODE First;
    
    Queue();
    
    void Enqueue(int Data);
    void Dequeue();
    
    void Display();
    int Count();
};


Queue :: Queue()
{
   First = NULL;
}

void Queue :: Enqueue(int No)
{
   PNODE Newn = new NODE;
   
   Newn->Data = No;
   Newn->Next = NULL;
   
   if(First == NULL)
   {
     First = Newn;
   }
   else
   {
      PNODE Temp = First;
      
      while(Temp->Next != NULL)
      {
         Temp = Temp->Next;
      }
      
      Temp->Next = Newn;
   }
}


void Queue :: Dequeue()
{
   if(First == NULL)
   {  
      cout<<"Queue is empty\n";
   }
   else
   {
      PNODE Temp = First;
      
      First = First->Next;
      cout<<"Dequeued elements is : "<<First->Data<<"\n";
      delete(Temp);
   }
}

int Queue :: Count()
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


void Queue :: Display()
{
   PNODE Temp = First;
   
   if(Temp == NULL)
   {
      cout<<"Queue is Empty\n";
      return;
   }
   else
   {
      cout<<"Elements in Queue are : \n";
   }
   
   while(Temp != NULL)
   {
     cout<<" | "<<Temp->Data;
     Temp = Temp->Next;
   }
   
   cout<<"\n";
}

int main()
{
  Queue * obj = new Queue();
  int iRet = 0;
  
  obj->Enqueue(10);
  obj->Enqueue(20);
  obj->Enqueue(30);
  obj->Enqueue(40);
  obj->Enqueue(50);
  obj->Display();
  
  obj->Dequeue();
  
  iRet = obj->Count();
  cout<<"Number of element in Queue are : "<<iRet<<"\n";

  return 0;
}
