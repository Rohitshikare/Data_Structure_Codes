/*
  Function to Delete element of Last position in LinkedList
*/

#include<iostream>
using namespace std;

#pragma pack(1)

struct Node
{
  int Data;
  struct Node * Next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

////////////////////////////////////////
//                                    //
//       Class Decleration            //           
//                                    //              
////////////////////////////////////////

class SinglyCL
{
  public:
    PNODE First;
    PNODE Last;
    
    SinglyCL();
    
    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPos(int iNo,int iPos);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    
    void Display();
    int Count();
};

SinglyCL :: SinglyCL()  //Constructor
{
  First = NULL;
  Last = NULL;
}

//////////////////////////////////////////////////////////////////////////

void SinglyCL :: InsertFirst(int iNo)
{
   PNODE Newn = new NODE;
   
   Newn->Data = iNo;
   Newn->Next = NULL;
   
   if((First == NULL) && (Last == NULL))
   {
     First = Last = Newn;
     (Last)->Next = First;
   }
   else
   {  
     Newn->Next = First;
     First = Newn;
     (Last)->Next = First; 
   }
}

///////////////////////////////////////////////////////////////////////////

void SinglyCL ::InsertLast( int iNo)
{
  PNODE Newn = new NODE;
   
  Newn->Data = iNo;
  Newn->Next = NULL;
  
  if((First == NULL) && (Last == NULL))
  {
    First = Last = Newn;
    (Last)->Next = First;
  }
  else
  {
     (Last)->Next = Newn;
     Last = Newn;
     (Last)->Next = First;
  }
}

////////////////////////////////////////////////////////////////////////

void SinglyCL :: DeleteFirst()
{
   if((First == NULL) && (Last == NULL))
   {
      return;
   }
   else if (First->Next == First)
   {
      delete First;
      First = NULL;
      Last = NULL;
   }
   else
   {
      First = First->Next;
      delete Last->Next;
      Last->Next = First;
   }
}

///////////////////////////////////////////////////////////////////////////

void SinglyCL :: DeleteLast()
{
  PNODE Temp = First;
  
   if((First == NULL) && (Last == NULL))
   {
      return;
   }
   else if (First->Next == First)
   {
      delete First;
      First = Last = NULL;
   }
   else
   {
      while(Temp->Next != Last)
      {
        Temp = Temp->Next;
      }
      
      delete Temp->Next;
      Last = Temp;
      Last->Next = First;
   }
}


///////////////////////////////////////////////////////////////////////

void SinglyCL ::  Display()
{
  PNODE Temp = First; 
  cout<<"Elements is Linkedlist are :"<<"\n";
  do
  {
    cout<<"| "<<Temp->Data<<" |->";
    Temp = Temp->Next;
  }
  while(Temp != Last->Next);
  cout<<"\n";
}

/////////////////////////////////////////////////////////////////////////////

int main()
{
  SinglyCL obj;
 
   
  obj.InsertFirst(51); 
  obj.InsertFirst(21);  
  obj.InsertFirst(11);
  obj.InsertFirst(5);
  obj.Display();  
  
  obj.InsertLast(101);
  obj.Display(); 
  
  obj.DeleteFirst();
  obj.Display();
  
  obj.DeleteLast();
  obj.Display();
  
  return 0;
}

