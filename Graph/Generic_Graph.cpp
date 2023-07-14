/*
   Generic Graph in C++ Programming
   
   Containts : AddNode Function
               
               Display Function
*/

#include<iostream>
#include<list>
using namespace std;

template<class T>
class Graph
{
   public:  
      int Vertex;
      list <T> * ptr;
      
      Graph(int Size);     
      
      void AddNode(T x , T y);
           
      void Display();
   
};

template<class T>
Graph <T> :: Graph(int Size)
{
    Vertex = Size;
    ptr = new list<T>[Vertex];
}


  
template<class T>      
void Graph <T> :: AddNode(T x , T y)
{
   ptr[x].push_back(y);
   ptr[y].push_back(x);
}
      


template<class T>      
void Graph <T> :: Display()
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



int main()
{
   int iSize = 0; 
   
   Graph <int> obj(4) ;
   
   obj.AddNode(0 , 1);
   obj.AddNode(0 , 2);
   obj.AddNode(1 , 2);
   obj.AddNode(2 , 3);
   
   obj.Display();
   
   return 0;
}
