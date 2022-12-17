/*
  Function to Insert At Given Position in LinkedList
*/
#include<iostream>
using namespace std;
#pragma pack(2)

struct Node
{
  struct Node * Prev;
  int Data;
  struct Node * Next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

class DoublyCL              //Class Declaration
{
  public:
    PNODE First ;
    PNODE Last;
    
    DoublyCL();
    
    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPos(int iNo , int iPos);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    
    void Display();
    int Count();
};

DoublyCL :: DoublyCL()  //Constructor
{
  First = NULL;
  Last = NULL;
}

void DoublyCL :: InsertFirst(int iNo)  //InsertFirst Function
{
  PNODE Newn = new NODE;
  
  Newn->Prev = NULL;
  Newn->Data = iNo;
  Newn->Next = NULL;
  
  if((First == NULL) && (Last == NULL))
  {
     First = Newn;
     Last = Newn;
     Last->Next = First;
     First->Prev = Last;
  }
  else
  {
     Newn->Next = First;
     First->Prev = Newn;
     First = Newn;
     Last->Next = First;
     First->Prev = Last;
  }
}

void DoublyCL :: InsertLast(int iNo)  //InsertLast Function
{
  PNODE Newn = new NODE;
  
  Newn->Prev = NULL;
  Newn->Data = iNo;
  Newn->Next = NULL;
  
  if((First == NULL) && (Last == NULL))
  {
     First = Newn;
     Last = Newn;
     Last->Next = First;
     First->Prev = Last;
  }
  else
  {
     Last->Next = Newn;
     Newn->Prev = Last;
     Last = Newn;
     Last->Next = First;
     First->Prev = Last;
  }
}

void DoublyCL :: DeleteFirst() //Function to delete First elements in LinkedList
{
  if((First == NULL) && (Last == NULL))
  {
     cout<<"LinkedList is empty ...\n";
  }
  else if (First->Next == Last)
  {
     delete(First);
     First = NULL;
     Last = NULL;
  }
  else
  {
     First = First->Next;
     delete(First->Prev);
     First->Prev = Last;
     Last->Next = First;
  }
}

void DoublyCL :: DeleteLast()  //Function to delete Last elements in LinkedList
{
  if((First == NULL) && (Last == NULL))
  {
     cout<<"LinkedList is empty ...\n";
  }
  else if (First->Next == Last)
  {
     delete(First);
     First = NULL;
     Last = NULL;
  }
  else
  {
     Last = Last->Prev;
     delete(First->Prev);
     Last->Next = First;
     First->Prev = Last;
  }
}


void DoublyCL :: Display()   //Function to Display LinkedList
{
  cout<<"Elements in LinkedList are : "<<"\n";
  
  do
  {
    cout<<"| "<<First->Data<<" |<=>";
    First = First->Next;
  }
  while(First != Last->Next);
  cout<<"\n";
}

int DoublyCL :: Count()  // Function to count the number of elements in LiskedList
{
  int iCnt = 0;
  
  do
  {
    iCnt++;
    First = First->Next;
  }
  while(First != Last->Next);
  
  return iCnt;
}

void DoublyCL :: InsertAtPos(int iNo , int iPos) //Function to Insert At Position
{
  int NodeCount = Count();
  PNODE Temp = NULL;
  
  if((iPos < 1 ) || (iPos > NodeCount+1))  //Filter
  {
     cout<<"Invalid Position...."<<"\n";
     return;
  }
  
  if(iPos == 1)
  {
     InsertFirst(iNo);
  }
  else if (iPos == NodeCount+1)
  {
     InsertLast(iNo);
  }
  else
  {
     PNODE Newn = new NODE;
     
     Newn->Prev = NULL;
     Newn->Data = iNo;
     Newn->Next = NULL;
     
     Temp = First;
     
     for(int iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
     { 
        Temp = Temp->Next; 
     }
     
     Newn->Next = Temp->Next;
     Temp->Next->Prev = Newn;
     Temp->Next = Newn;
     Newn->Prev = Temp;
     
  }
}

int main()
{
  DoublyCL * obj = new DoublyCL();
  
  obj->InsertFirst(51);
  obj->InsertFirst(21);
  obj->InsertFirst(11);
  obj->InsertFirst(5);
  obj->Display();
  
  obj->InsertLast(101);
  obj->InsertLast(111);
  obj->Display();
  
  obj->DeleteFirst();
  obj->Display();
  
  obj->DeleteLast();
  obj->Display();
  
  obj->InsertAtPos(71,4);
  obj->InsertAtPos(81,5);
  obj->Display();
  
  
  return 0;
}
