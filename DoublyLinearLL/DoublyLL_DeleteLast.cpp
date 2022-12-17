
/*
  Function to delete Last elements in the given linkedList
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

void DoublyLL :: DeleteFirst()    //DeleteFirst Function
{
  if(First == NULL)
  {
    cout<<"Unable To Delete as LinkedList is Empty...\n";
    return;
  }
  else if(First->Next == NULL)
  {
     delete(First);
     First = NULL;
  }
  else
  {
     PNODE Temp = First;
     
     First = First->Next;
     Temp->Next->Pre = NULL;
     Temp->Next = NULL;
     delete(Temp);
  }
}

void DoublyLL :: DeleteLast()  //DeleteLast Function
{
  if(First == NULL)
  {
    cout<<"Unable To Delete as LinkedList is Empty...\n";
    return;
  }
  else if(First->Next == NULL)
  {
     delete(First);
     First = NULL;
  }
  else
  {
     PNODE Temp1 = First;
     PNODE Temp2 = First->Next;
     
     while(Temp2->Next != NULL)
     {
         Temp1 = Temp1->Next;
         Temp2 = Temp2->Next;
     }
     
     Temp1->Next = NULL;
     Temp2->Pre = NULL;
     delete(Temp2);
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
 
//Delete First Calls //////////////////////////////////////
   
   obj->DeleteFirst();
   obj->Display();
   
//Delete Last Calls //////////////////////////////////////
   
   obj->DeleteLast();
   obj->Display(); 
   
   return 0;
}    
 
