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
  int iChoice = 0;
  int iNo = 0;
  int iRet = 0;
  
  while(1)
  {
     cout<<"\n-----------------------------------------------\n";
     cout<<"        Select Desired Option\n";
     cout<<"-----------------------------------------------\n";
     cout<<" 1. Insert Element in Queue \n";
     cout<<" 2. Delete Element in Queue \n";
     cout<<" 3. Display Elements of Queue\n";
     cout<<" 4. Count Number of Elements\n";
     cout<<" 5. Exit\n";
     cout<<"-----------------------------------------------\n";
     
     cout<<"Enter Your Choice : ";
     cin>>iChoice;
     
     switch(iChoice)
     {
        case(1):
          cout<<"Enter Data You want to Insert : ";
          cin>>iNo;
          
          obj->Enqueue(iNo);
          break;
          
        case(2):
          obj->Dequeue();
          break;
          
        case(3):
          obj->Display();
          break;
          
        case(4):
          iRet = obj->Count();
          cout<<"Number of Elements in Queue are : "<<iRet;
          break;
          
        case(5):
          cout<<" 🥰️ Thank you for using application .... !"<<"\n\n";
          return 0;
        
        default :
          cout<<"Invalid Option..!!"<<"\n\t"<<"Please Enter Valid Option\n";
          break;   
     }
  }
  
  return 0;
}
