/*
   Graph in C++ Programming
   
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
   
   Graph * obj = new Graph(4);
   
   obj->AddNode(0 , 1);
   obj->AddNode(0 , 2);
   obj->AddNode(1 , 2);
   obj->AddNode(2 , 3);
   
   obj->Display();
   
   return 0;
}ter
