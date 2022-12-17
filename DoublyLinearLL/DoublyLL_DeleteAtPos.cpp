
/*
  Function to delete Number at the given position
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
  
//Insert At Position Calls //////////////////////////////////////
   
   obj->InsertAtPos(71,5);
   obj->Display();
   
//Delete First Calls //////////////////////////////////////
   
   obj->DeleteFirst();
   obj->Display();
   
//Delete Last Calls //////////////////////////////////////
   
   obj->DeleteLast();
   obj->Display();   
 
//Delete At Position Calls //////////////////////////////////////
   
   obj->DeleteAtPos(4);
   obj->Display();   
 
       

  return 0;
}
