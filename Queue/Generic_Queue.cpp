/*
   Stack using C++ Programming
   
   Containts : Enqueue Function
               Dequeue Function
               
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
class Queue
{
  public :
    struct SNode <T> * First;
    
    Queue();
    
    void Enqueue(T Data);
    void Dequeue();
    
    void Display();
};

template<class T>
Queue <T> :: Queue()
{
   First = NULL;
}

template<class T>
void Queue <T> :: Enqueue(T No)
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
      struct SNode <T> * Temp = First;
      
      while(Temp->Next != NULL)
      {
         Temp = Temp->Next;
      }
      
      Temp->Next = Newn;
   }
}

template<class T>
void Queue <T> :: Dequeue()
{
   if(First == NULL)
   {  
      cout<<"Queue is empty\n";
   }
   else
   {
      struct SNode <T> * Temp = First;
      
      First = First->Next;
      cout<<"Dequeued elements is : "<<First->Data<<"\n";
      delete(Temp);
   }
}

template<class T>
void Queue <T> :: Display()
{
   struct SNode <T> * Temp = First;
   
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
  Queue <int> obj;
  
  obj.Enqueue(10);
  obj.Enqueue(20);
  obj.Enqueue(30);
  obj.Enqueue(40);
  obj.Enqueue(50);
  
  obj.Dequeue();
  
  obj.Display();
  return 0;
}
