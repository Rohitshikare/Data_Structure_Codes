/*
   MenuDriven Graph in C++ Programming
   
   Containts : AddNode Function
               
               Display Function
*/

#include<iostream>
#include<list>
using namespace std;

class Graph
{
   public: 
      int Vertex;
      list <int> * ptr;
     
       
      Graph(int Size)
      {
         Vertex = Size;
         ptr = new list<int>[Vertex];
      }
      
      
      
      void AddNode(int x , int y)
      {
         ptr[x].push_back(y);
         ptr[y].push_back(x);
      }
      
      
      
      void Display()
      {
         cout<<"\n";
         
         for(int i = 0 ; i < Vertex ; i++)
         {
            cout<<"Vertex "<<i<<"-> ";
            for(int nbr : ptr[i])
            {
               cout<<nbr<<",";
            }
            
            cout<<"\n";
         }
      }

};

int main()
{
   int iSize = 0; 
   cout<<"Enter Number of Vertex you want : ";
   cin>>iSize;
   
   Graph * obj = new Graph(iSize);
   
   int iChoice = 0;
   int Src = 0;
   int Dest = 0;
   
   while(1)
   {
       cout<<"\n-------------------------\n";
       cout<<"|   Select your choice  |\n";
       cout<<"-------------------------\n";
       cout<<"| 1. Add Node To Graph  |\n";
       cout<<"| 2. Display Node       |  \n";
       cout<<"| 3. Exit               |\n";
       cout<<"-------------------------\n";
       
       cout<<"Enter Your Choice : ";
       cin>>iChoice;
       
       if(iChoice == 1)
       {
           cout<<"Enter Source Node : ";
           cin>>Src;
           
           cout<<"Enter Dest Node : ";
           cin>>Dest;
           
           obj->AddNode(Src,Dest);
       }
       else if(iChoice == 2)
       {
           obj->Display();
       }
       else if(iChoice == 3)
       {   
           cout<<"\nThank You for Using Application ... 🥰️"<<"\n";
           break;
       }
       else 
       {
          cout<<"\nInvalid Choice 🚫️\n\t Please enter valid Choice....!\n";
          continue;
       }
   }
  
   
   return 0;
}
