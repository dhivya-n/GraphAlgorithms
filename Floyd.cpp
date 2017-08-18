#include<iostream>
using namespace std;
/************************Class Graph*************************/
class Graph
{
   int** matrix;
   int** weight;
   int **D,**P;
   int vertices;
public:
 Graph();
 void create_graph();
 void Floyd();
 void display();
 void path(int i, int j);
};
/************************constructor*************************/
Graph::Graph()
{
     int t;
     cout<<"\nEnter the number of vertices:";
     cin>>vertices;
     t=vertices+1;
     matrix = new int*[t];
     weight = new int*[t];
     D=new int*[vertices+1];
     P=new int*[vertices+1];
     for(int i = 0; i <=vertices;i++)
      {
      matrix[i] = new int[t];
      weight[i] = new int[t];
      D[i] = new int[vertices+1];
      P[i] = new int[vertices+1];
      }
     for(int i = 0; i <=vertices;i++)
     for(int j=0;j<=vertices;j++)
      {
       weight[i][j]=999;
       matrix[i][j]=0;
      }	
}
/**********************Path*************************/
void Graph::path(int i,int j)
{
if(P[i][j]==0)
  cout<<i<<"---"<<j<<"\n";
else
{
path(i,P[i][j]);
path(P[i][j],j);
}
}
/************************Floyd*************************/
void Graph::Floyd()
{
     for(int i = 0; i <=vertices;i++)
     for(int j=0;j<=vertices;j++)
      {
       D[i][j]=weight[i][j];
       if(i==j)
       D[i][j]=0;
       P[i][j]=0;
      }

      cout<<"\n----------initial Distance--------- "; 
      for(int i=1;i<=vertices;i++)
      {
      cout<<"\n";
      for(int j=1;j<=vertices;j++)
      {
        cout<<"\t"<<D[i][j];
      }
      }
      cout<<"\n----------initial Predesesor-------- "; 
      for(int i=1;i<=vertices;i++)
      {
      cout<<"\n";
      for(int j=1;j<=vertices;j++)
      {
        cout<<"\t"<<P[i][j];
      }
      }
   for(int k=1;k<=vertices;k++)
{
    for(int i=1;i<=vertices;i++)
      for(int j=1;j<=vertices;j++)
       if(D[i][k]+D[k][j]<D[i][j])
       {
          D[i][j]=D[i][k]+D[k][j];
          P[i][j]=k;
       }
 
      cout<<"\n----------Distance["<<k<<"]--------- "; 
      for(int i=1;i<=vertices;i++)
      {
      cout<<"\n";
      for(int j=1;j<=vertices;j++)
      {
        cout<<"\t"<<D[i][j];
      }
      }
      cout<<"\n----------Predesesor["<<k<<"]-------- "; 
      for(int i=1;i<=vertices;i++)
      {
      cout<<"\n";
       for(int j=1;j<=vertices;j++)
      {
        cout<<"\t"<<P[i][j];
      }
      }
}
}
/*******************create graph*************************/
void Graph::create_graph()
{
  int i,n,a,b,c;
  cout<<"Enter the number of edges:";
  cin>>n;
  for(i=0;i<n;i++)
  {
    cout<<"Enter the edges:";
    cin>>a>>b;
    cout<<"Weight:";
    cin>>c;
    matrix[a][b]=1;
    weight[a][b]=c;
  }
}
/*********************Display graph*************************/
void Graph:: display()
{
 cout<<"\n\t";
 for(int j=1;j<=vertices;j++)
  cout<<"\t"<<j;
  cout<<"\n\n";
 for(int i=1;i<=vertices;i++)
  {
  cout<<"Vertices ["<<i<<"]:";
  for(int j=1;j<=vertices;j++)
  {
  cout<<"\t"<<matrix[i][j];
  }
  cout<<"\n";
  }
  cout<<"\nWeight matrix:";
  cout<<"\n\t";
  for(int j=1;j<=vertices;j++)
   cout<<"\t"<<j;
   cout<<"\n\n";
  for(int i=1;i<=vertices;i++)
  {
    cout<<"Vertices ["<<i<<"]:";
  for(int j=1;j<=vertices;j++)
  {
    cout<<"\t"<<weight[i][j];
  }
  cout<<"\n";
  }
}
/************main*************/
int main()
{
 int ch,a,b;
 Graph g;
 g.create_graph();
 g.display();
 g.Floyd();
 do
 {
 cout<<"\nEnter two vertices to find the path:";
 cin>>a>>b;
 cout<<"\nThe path is ";
 g.path(a,b);
 cout<<"\nDo you want to continue :(1-yes||2-NO):";
 cin>>ch;
 }while(ch==1);
 cout<<"\n";
}
