/*
  Singly Circular Linkedlist in C++ using oops concepts
  
  Containts :  InsertFirst Function
               InsertLast  Function
               InsertAtPos Function
               
               DeleteFirst Function
               DeleteLast  Function
               DeleteAtPos Function
               
               Display Function
               Count   Function
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
  SinglyCL * obj = new SinglyCL();

  int iChoice = 0 ;
  int iPos = 0;
  int iRet = 0;
  int iNo = 0;
  
  cout<<"\n"<<" 🥰️ Welcome to My Data structure Application....."<<"\n\n";
  while(1)
  {
      cout<<"--------------------------------------------"<<"\n";
      cout<<"   Please select Desired Option  "<<"\n";
      cout<<"--------------------------------------------"<<"\n";
      cout<<"1 : Insert New Node At First Position"<<"\n";
      cout<<"2 : Insert New Node At Last Position"<<"\n";
      cout<<"3 : Insert New Node At Given Position"<<"\n";
      cout<<"4 : Delete Node of First Position"<<"\n";
      cout<<"5 : Delete Node of Last Position"<<"\n";
      cout<<"6 : Delete Node of Given Position"<<"\n";
      cout<<"7 : Display LinkedList"<<"\n";
      cout<<"8 : Count Number of LinkedList"<<"\n";
      cout<<"9 : Exit "<<"\n";
      cout<<"--------------------------------------------"<<"\n\n";
      
      cout<<"Enter Choice : ";
      cin>>iChoice;
      
      switch(iChoice)
      {
         case 1:
            cout<<"Enter Data want to insert : ";
            cin>>iNo;
            
            obj->InsertFirst(iNo);
            break;
            
         case 2:
            cout<<"Enter Data want to insert : ";
            cin>>iNo;
            
            obj->InsertLast(iNo);
            break;  
            
         case 3:
            cout<<"Enter Data want to insert : ";
            cin>>iNo;
            
            cout<<"Enter Position : ";
            cin>>iPos;
            
            obj->InsertAtPos(iNo,iPos);
            break;
            
         case 4:
            obj->DeleteFirst();
            break; 
            
         case 5:
            obj->DeleteLast();
            break;  
         
         case 6:
            cout<<"Enter the position : ";
            cin>>iPos;
            
            obj->DeleteAtPos(iPos);
            break;
            
         case 7:
            obj->Display();
            break;
            
         case 8:
            iRet = obj->Count();
            cout<<"Number of elements are : "<< iRet <<"\n";
            break; 
            
         case 9:
          
            cout<<" 🥰️ Thank you for using application .... !"<<"\n\n";
            return 0;
            
         default:
            cout<<" Invalid Option..!!! 🤕️"<<"\n\t"<<" Please enter Valid Option..."<<"\n";
            break;                    
      }
    }     
  return 0;
}


