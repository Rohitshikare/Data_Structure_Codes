
/*
  Function to Insert Element at Last position in LinkedList
*/

#include<iostream>
using namespace std;

struct Node 
{
  struct Node * Pre;
  int Data;
  struct Node * Next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

class DoublyLL
{
  public:
    PNODE First;
    
    DoublyLL();
    
    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPos(int iNo ,int iPos);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    
    void Display();
    int Count();
      
};

DoublyLL :: DoublyLL()        //Constructor
{
   First = NULL;
}

void DoublyLL :: InsertFirst(int iNo)  //InsertFirst Function
{
   PNODE Newn = new NODE;
   PNODE Temp = First;
   
   Newn->Pre = NULL;
   Newn->Data = iNo;
   Newn->Next = NULL;
   
   if(First == NULL)
   {
     First = Newn;
   }
   else
   {
     Newn->Next = First;
     Temp->Pre = Newn;
     First = Newn;
   }
   
}

void DoublyLL :: InsertLast(int iNo)     //InsertLast Function
{
   PNODE Newn = new NODE;
   PNODE Temp = First;
   
   Newn->Pre = NULL;
   Newn->Data = iNo;
   Newn->Next = NULL;
   
   if(First == NULL)
   {
     First = Newn;
   }
   else
   {
     while(Temp->Next != NULL)
     {
       Temp = Temp->Next;
     }  
     Temp->Next = Newn;
     Newn->Pre = Temp;
   }
   
}


void DoublyLL :: Display()   //Display Function
{
  PNODE Temp = First;
  cout<<"Elements in LinkedList are : "<<"\n";
  
  while(Temp != NULL)
  {
    cout<<"| "<<Temp->Data<<" |->";
    Temp = Temp->Next;
  }
  cout<<"NULL\n";
}



int main()
{
  
   DoublyLL * obj = new DoublyLL();

//Insert First Calls //////////////////////////////////////
   
   obj->InsertFirst(51);
   obj->InsertFirst(21);
   obj->InsertFirst(11);
   obj->InsertFirst(5);
   obj->Display();
 
//Insert Last Calls //////////////////////////////////////
   
   obj->InsertLast(101);
   obj->InsertLast(121);
   obj->Display();

  return 0;
}
