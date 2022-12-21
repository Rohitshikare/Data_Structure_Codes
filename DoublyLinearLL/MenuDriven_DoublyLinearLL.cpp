/*
  Doubly Linear LinkedList in C++ using oops concepts
  
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

int DoublyLL :: Count()  //Function to count Number of elements in LinkedList
{
   PNODE Temp = First;
   int iCnt = 0;
   
   while(Temp != NULL)
   {
     iCnt++;
     Temp = Temp->Next;
   }
   
   return iCnt; 
}

void DoublyLL :: InsertAtPos(int iNo , int iPos)   // InsertAt Position Function
{
  int NodeCount = Count();
  
  PNODE Newn = new NODE;
  PNODE Temp = First;
  
  Newn->Pre = NULL;
  Newn->Data = iNo;
  Newn->Next = NULL;
  
  if((iPos < 1) || (iPos > NodeCount+1)) //Filter
  {
    cout<<"Invalid Position\n";
    return;
  }
  
  if(iPos == 1)
  {
    InsertFirst(iNo);
  }
  else if(iPos == NodeCount+1)
  {
    InsertLast(iNo);
  }
  else
  {
    for(int iCnt = 1; iCnt < iPos-1; iCnt++)
    {
      Temp = Temp->Next;
    }
    
    Newn->Next = Temp->Next;
    Temp->Next->Pre = Newn;
    Newn->Pre = Temp;
    Temp->Next = Newn;
  }
} 


void DoublyLL :: DeleteAtPos(int iPos) //Delete At position function
{
  int NodeCount = Count();
  
  if((iPos < 1)|| (iPos > NodeCount))
  {
    cout<<"Invalid Position\n";
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
     PNODE Temp1 = First;
     PNODE Temp2 = First->Next;
     
     for(int iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
     {
        Temp1 = Temp1->Next;
        Temp2 = Temp2->Next;
     }
     
     Temp1->Next = Temp2->Next;
     Temp2->Pre = NULL;
     Temp2->Next = NULL;
     Temp1->Next->Pre = Temp1;
     delete(Temp2);
     
  }
}

int main()
{
  DoublyLL * obj = new DoublyLL();

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
          
            cout<<"\n"<<" 🥰️ Thank you for using application .... !"<<"\n\n";
            return 0;
            
         default:
            cout<<" Invalid Option..!!! 🤕️"<<"\n\t"<<" Please enter Valid Option..."<<"\n";
            break;                    
      }
    }    
 
       

  return 0;
}
