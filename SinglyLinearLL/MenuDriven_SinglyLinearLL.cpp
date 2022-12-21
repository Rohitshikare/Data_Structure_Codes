/*
  Singly Linear Linkedlist in C++ using oops concepts
  
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
            iRet = obj->iCount;
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
