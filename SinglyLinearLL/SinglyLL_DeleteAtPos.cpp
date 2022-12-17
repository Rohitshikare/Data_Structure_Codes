/*
  Function To Delete element at given Position in LinkedList
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

//////////////////////////////////////////////////////////////////

void SinglyLL :: InsertAtPos(int iNo ,int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE Newn = new NODE;

        Newn->Data = iNo;
        Newn->Next = NULL;

        PNODE Temp = First;
        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            Temp = Temp->Next;
        }

        Newn->Next = Temp->Next;
        Temp->Next = Newn;

        iCount++;
    }   
}

//////////////////////////////////////////////////////////////////

void SinglyLL :: DeleteAtPos(int iPos)
{
  if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
       PNODE Temp1 = First;
       PNODE Temp2 = First;
        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            Temp1 = Temp1->Next;
        }
        Temp2 = Temp1->Next;
        
        Temp1->Next = Temp2->Next;
        delete(Temp2);
    }
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
  
  obj->InsertAtPos(105,3);
  obj->Display();
  
  
  obj->DeleteAtPos(3);
  obj->Display();
   
  return 0;
}
