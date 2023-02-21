/*
   Stack in C++ Programming
   
   Containts : Push Function
               Pop  Function
               
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
typedef struct SNode * PNODE;

class Stack
{
   public :
     PNODE First;
     
     Stack();
     
     void Push(int No);
     void Pop(); 
     
     void Display();  
};

Stack :: Stack()
{
   First == NULL;
}

void Stack :: Push(int No) 
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
      Newn->Next = First;
      First = Newn;
   }
}

void Stack :: Pop()
{
   if(First == NULL)
   {
      cout<<"Stack is Empty\n";
   }
   else
   {
      PNODE  Temp = First;
        
      First = First->Next;
      cout<<"Poped element is : "<<Temp->Data<<"\n";
      delete(Temp);
   }
}


void Stack :: Display()
{
   PNODE Temp = First;
   
   while(Temp != NULL)
   {
      cout<<"| "<<Temp->Data<<" |"<<"\n";
      Temp = Temp->Next;
   }
}

int main()
{
  Stack obj;
  
  obj.Push(10);
  obj.Push(20);
  obj.Push(30);
  obj.Push(40);
  obj.Display();
  
  obj.Pop();
  obj.Display();
    
  return 0;
}
