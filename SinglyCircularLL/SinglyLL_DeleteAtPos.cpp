/*
  Function to Delete element og given position in LinkedList
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

////////////////////////////////////////////////////////////////////////

int SinglyCL ::Count()
{
   PNODE Temp = First;
   
    int iCnt = 0;
    do
    {
        iCnt++;
        Temp = Temp->Next;
    }while(Temp != Last->Next);
    return iCnt;
}


/////////////////////////////////////////////////////////////////////////

void SinglyCL ::InsertAtPos(int iNo , int iPos)
{
  int NodeCount = Count();
  PNODE Temp = NULL;
  PNODE Newn = NULL;
  int iCnt = 0;
  
  if((iPos < 1) || (iPos > NodeCount+1))
  {
     cout<<"Invalid Position "<< "\n";
     return;
  }
  if(iPos == 1)
  {
    InsertFirst(iNo);
  }
  else if(iPos == NodeCount + 1)
  {
    InsertLast(iNo);
  }
  else
  {
    // Newn = (PNODE)malloc(sizeof(NODE));
     Newn = new NODE;
     Temp = First;
     
     Newn->Data = iNo;
     Newn->Next = NULL;
     
     for(iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
     {
       Temp = Temp->Next;
     }
     
     Newn->Next = Temp->Next;
     Temp->Next = Newn;
     
  }
}

/////////////////////////////////////////////////////////////////////

void SinglyCL ::DeleteAtPos( int iPos)
{
  int NodeCount = Count();
  PNODE Temp1 = First;
  PNODE Temp2 = First;
  int iCnt = 0;
  
  if(iPos > NodeCount)
  {
     cout<<"Invalid Position "<< "\n";
     return;
  }
  if(iPos == 1)
  {
    DeleteFirst();
  }
  else if(iPos == NodeCount)
  {
    DeleteLast();
  }
  else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            Temp1 = Temp1->Next;
        }   
        Temp2 = Temp1 ->Next;

        Temp1->Next = Temp2->Next;
        delete Temp2;
    }
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
  
  obj.InsertAtPos(105,3);
  obj.Display();
  
  
  obj.DeleteAtPos(3);
  obj.Display();
   
  return 0;
}

