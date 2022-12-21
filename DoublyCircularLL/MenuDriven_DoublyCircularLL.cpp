/*
  Complete Doubly Circular LinkedList in C++ 
  
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

int DoublyCL :: Count()  // Count Function
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

void DoublyCL :: DeleteAtPos(int iPos) //Function to Delete At Position
{
   int NodeCount = Count();
   PNODE Temp = NULL;
   
   if((iPos < 1) || (iPos > NodeCount))
   {
       cout<<"Invalid Position..."<<"\n";
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
      Temp = First;
      
      for(int iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
      { 
         Temp = Temp->Next;
      } 
      
      Temp->Next = Temp->Next->Next;
      delete(Temp->Next->Prev);
      Temp->Next->Prev = Temp;
   }
}

int main()
{
  DoublyCL * obj = new DoublyCL();
  
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
