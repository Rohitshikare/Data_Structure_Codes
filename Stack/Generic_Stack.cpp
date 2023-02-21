/*
   Generic Stack in C++ Programming
   
   Containts : Push Function
               Pop  Function
               
               Display Function
*/

#include<iostream>
using namespace std;

template<class T>
struct SNode 
{
  T Data;
  struct SNode * Next;
};

template<class T>
class Stack
{
   public :
     struct SNode <T> * First;
     
     Stack();
     
     void Push(T No);
     void Pop(); 
     
     void Display();  
};

template<class T>
Stack <T> :: Stack()
{
   First == NULL;
}

template<class T>
void Stack <T> :: Push(T No) 
{
   struct SNode <T> * Newn = new (struct SNode <T>);
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

template<class T>
void Stack <T> :: Pop()
{
   if(First == NULL)
   {
      cout<<"Stack is Empty\n";
   }
   else
   {
      struct SNode <T> * Temp = First;
        
      First = First->Next;
      cout<<"Poped element is : "<<Temp->Data<<"\n";
      delete(Temp);
   }
}

template<class T>
void Stack <T> :: Display()
{
   struct SNode <T> * Temp = First;
   
   while(Temp != NULL)
   {
      cout<<"| "<<Temp->Data<<" |"<<"\n";
      Temp = Temp->Next;
   }
}

int main()
{
  Stack <int> obj;
  
  obj.Push(15);
  obj.Push(11);
  obj.Push(12);
  
  obj.Pop();
  
  obj.Display();
    
  return 0;
}
