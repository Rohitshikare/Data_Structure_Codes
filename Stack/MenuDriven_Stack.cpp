/*
   Menu Driven Code of Stack in C++ Programming
   
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
  Stack * obj = new Stack();
  int iChoice = 0;
  int iNo = 0;
  
    while(1)
  {
     cout<<"\n-----------------------------------------------\n";
     cout<<"        Select Desired Option\n";
     cout<<"-----------------------------------------------\n";
     cout<<" 1. Insert Element in Stack \n";
     cout<<" 2. Delete Element in Stack \n";
     cout<<" 3. Display Elements of Stack\n";
     cout<<" 4. Exit\n";
     cout<<"-----------------------------------------------\n";
     
     cout<<"Enter Your Choice : ";
     cin>>iChoice;
     
     switch(iChoice)
     {
        case(1):
          cout<<"Enter Data You want to Insert : ";
          cin>>iNo;
          
          obj->Push(iNo);
          break;
          
        case(2):
          obj->Pop();
          break;
          
        case(3):
          obj->Display();
          break;
          
        case(4):
          cout<<" 🥰️ Thank you for using application .... !"<<"\n\n";
          return 0;
                  
        default :
          cout<<"Invalid Option..!!"<<"\n\t"<<"Please Enter Valid Option\n";
          break;   
     }
  }
  
    
  return 0;
}

