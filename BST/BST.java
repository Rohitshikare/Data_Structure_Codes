import java.util.*;


class Node
{
   Node Left;
   Node Right;
   
   int Data;
   
   public Node(int No)
   {
      this.Data = No;
   }   
}


class BST
{
   public static void main(String arg[])
   {
       Scanner sobj = new Scanner(System.in);
       
       Node Root = CreateTree();
       InOrder(Root);
       System.out.println();
       PreOrder(Root);
       System.out.println();
       PostOrder(Root);
       System.out.println();
   }
   
   static Node CreateTree()
   {
   
     Scanner sobj = new Scanner(System.in);
      
      Node Root = null;
      
       System.out.println("Enter Data : ");
       int Data = sobj.nextInt();
       
       if(Data == -1)
       {
          return null;
       }
       
       Root = new Node(Data);
       
       System.out.println("Enter Left for "+Data);
       Root.Left = CreateTree();
       
       System.out.println("Enter right for "+Data);
       Root.Right = CreateTree();
       
       return Root;
       
   }
   
   static void InOrder(Node Root)
   {
      if(Root == null)
      {
         return;
      }
      
      InOrder(Root.Left);
      System.out.print(" "+Root.Data);
      InOrder(Root.Right);
   }
   
   static void PreOrder(Node Root)
   {
      if(Root == null)
      {
         return;
      }
      
      System.out.print(" "+Root.Data);
      InOrder(Root.Left);
      InOrder(Root.Right);
   }
   
   static void PostOrder(Node Root)
   {
      if(Root == null)
      {
         return;
      }
      
      
      InOrder(Root.Left);
      InOrder(Root.Right);
      System.out.print(" "+Root.Data);
   }
   
}
