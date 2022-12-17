/*
  Function To Delete element of Last Position in LinkedList
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

/////////////////////////////////////
//                                 // 
//     Class Decleration           //    
//                                 //
/////////////////////////////////////

class SinglyLL
{
  public:
     PNODE First;                
     int iCount;                 
     
     SinglyLL();                 
     
     void InsertFirst(int iNo);
     void InsertLast(int iNo);
     void InsertAtPos(int iNo,int iPos);
     
     void DeleteFirst();
     void DeleteLast();
     void DeleteAtPos(int iPos);
     
     void Display();
};

//////////////////////////////////////////////////////////////////

SinglyLL :: SinglyLL()  //Constructor
{
   First = NULL;
   iCount = 0;
}

///////////////////////////////////////////////////////////////////

void SinglyLL :: InsertFirst(int iNo)
{
   //step 1 : Allocate Memory for Node
   PNODE Newn = new NODE;
   
   //Step 2 : Initailise node
   Newn->Data = iNo;
   Newn->Next = NULL;
   
   //Step 3 : Check if LL is empty or Not
   if(First == NULL)
   {
      First = Newn;
      iCount++;
   }
   else 
   {
      Newn->Next = First;
      First = Newn;
      iCount++;
   }
}

//////////////////////////////////////////////////////////////////

void SinglyLL :: InsertLast(int iNo)
{
  //step 1 : Allocate Memory for Node
   PNODE Newn = new NODE;
   
   //Step 2 : Initailise node
   Newn->Data = iNo;
   Newn->Next = NULL;
   
   //Step 3 : Check if LL is empty or Not
   if(First == NULL)
   {
      First = Newn;
      iCount++;
   }
   else 
   {
     PNODE Temp = First;
     
     while(Temp->Next != NULL)
     {
       Temp = Temp->Next;
     }
     Temp->Next = Newn;
     iCount++;
   }
}

//////////////////////////////////////////////////////////////////

void SinglyLL :: DeleteFirst()
{
  if(First == NULL)
  {
     return ;
  }
  else if(First->Next == NULL)
  {
     delete First;
     First = NULL;
     iCount--;
  }
  else
  {
     PNODE Temp = First;
     First = First->Next;
     delete Temp;
     iCount--;
  }
}

//////////////////////////////////////////////////////////////////

void SinglyLL :: DeleteLast()
{
  if(First == NULL)
  {
     return ;
  }
  else if(First->Next == NULL)
  {
     delete First;
     First = NULL;
     iCount--;
  }
  else
  {
    PNODE Temp = First;
    
    while(Temp->Next->Next != NULL)
    {
       Temp = Temp->Next;
    }
    
    delete Temp->Next;
    Temp->Next = NULL;
  }
}

//////////////////////////////////////////////////////////////////

void SinglyLL :: Display()
{
   PNODE Temp = First;
   cout<<"Elements in LinkedList are : \n";
   
   while(Temp != NULL)
   {
     cout<<"| "<<Temp->Data<<" |->";
     Temp = Temp->Next;
   }
   cout<<"NULL\n";
}

/////////////////////////////////////////////////////////////////

int main()
{
  SinglyLL * obj = new SinglyLL();

  obj->InsertFirst(51); 
  obj->InsertFirst(21);  
  obj->InsertFirst(11);
  obj->InsertFirst(5);
  obj->Display();  
  
  obj->InsertLast(101);
  obj->Display(); 
  
  obj->DeleteFirst();
  obj->Display();
  
  obj->DeleteLast();
  obj->Display();
  
  return 0;
}
