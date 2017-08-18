#include<iostream>
using namespace std;
/************************Class Graph*************************/
class Graph
{
   int** matrix;
   int** weight;
   int vertices;
public:
   void prim(int s);
   void create_graph();
   void display();
   Graph();
};
/************************constructor*************************/
Graph::Graph()
{
     cout<<"\nEnter the number of vertices:";
     cin>>vertices;
     matrix = new int*[vertices+1];
     weight = new int*[vertices+1];
     for(int i = 0; i <=vertices;i++)
      {
      matrix[i]=new int[vertices+1];
      weight[i]=new int[vertices+1];
      }
     for(int i = 0; i <=vertices;i++)
     for(int j=0;j<=vertices;j++)
      {
       weight[i][j]=999;
       matrix[i][j]=0;
      }
}
/************************Prim*************************/
void Graph::prim(int s)
{
	/***********************Vertex structure*************************/
	    struct vertex
        {
        int path,distance;
        bool known;
        };
        vertex *v=new vertex[vertices];
        int i,ch=1;
        for(i=1;i<=vertices;i++)
        {
           v[i].distance=9999;
           v[i].known=0;
           v[i].path=0;
        }
        cout<<"\n----Initial configuration---------- ";
		cout<<"\nVertices\tknown\t distance\t path";
        for(int i=1;i<=vertices;i++)
           cout<<"\n"<<i<<"\t\t"<<v[i].known<<"\t|"<<v[i].distance<<"\t\t|"<<v[i].path;
 /************************End display*************************/
        v[s].distance=0;
        while(ch)
        {
        vertex vr;
        /*********Finding the smallest unknown vertex****************/
        int temp=9999,small;
        for(i=1;i<=vertices;i++)
        { 
         if(v[i].distance<temp&&(v[i].known==0))
         {
         temp=v[i].distance;
         small=i;
         }
        }
        /************************End search*************************/
        v[small].known=1;
        for(i=1;i<=vertices;i++)
        if(matrix[small][i]!=0)
            if(v[i].known==0)
             if(weight[small][i]<v[i].distance)
             {
               v[i].distance=weight[small][i];
               v[i].path=small;
             }       
              cout<<"\n----After "<<small<<" is known---------- ";
              cout<<"\nVertices\tknown\t distance\t path";
               for(int i=1;i<=vertices;i++)
                cout<<"\n"<<i<<"\t\t"<<v[i].known<<"\t|"<<v[i].distance<<"\t\t|"<<v[i].path;
           	cout<<"\nDo you want to continue(1-continue||0-stop):";
        	cin>>ch;
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
    matrix[b][a]=1;
    weight[a][b]=c;
    weight[b][a]=c;
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
 int ch;
 Graph g;
 g.create_graph();
 g.display();
 cout<<"\nEnter the source vertex:";
 cin>>ch;
 g.prim(ch);
}
