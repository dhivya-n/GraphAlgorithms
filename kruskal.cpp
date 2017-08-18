
#include<iostream>
using namespace std;
/**********vertex structure******/
struct vertex
{
	int from;
	int to;
	int cost;
};
/**********Queue class******/
class queue
{
  vertex a[10];
  int size; 
  int front;
  int rear;
  bool isempty();
  bool isfull();
 public:
  void insert(vertex);
  vertex Delete();
  void display();
 queue(int x)
 {
 size=x;
  front=-1;
  rear=-1;
 }
};
/***************Isfull****************/
bool queue :: isfull()
{
  return rear+1==size;
}
/***************Isempty****************/
bool queue :: isempty()
{
  return front==-1;
}
/***************Insert****************/
void queue :: insert(vertex ele)
{ 
 if(rear==-1)
 front=0;
 if(!isfull())
 {
 rear++;
 a[rear]=ele;
 }
 else 
 cout<<"Queue is full";
}
/***************Delete****************/
vertex queue :: Delete()
{
if(!isempty())
 {
 vertex data;
 data=a[front];
 if(front==rear)
  rear=-1;
  front++;
 return data;
}
}
/************************Class Graph*************************/
class Graph
{
   vertex v[10];
   int no_vertices,no_edges;
public:
   void create_graph();
   void display();
   void kruskal();
   Graph();
};
/************************constructor*************************/
Graph::Graph()
{
     cout<<"\nEnter the number of vertices:";
     cin>>no_vertices;
}
/************************krushkal*************************/
void Graph::kruskal()
   {
     queue q(10);
     vertex temp;
     vertex e;
     int set[10][10],pos1,pos2,f,k;
     /*********************initislising sets************************/
     for(int i=1;i<=no_vertices;i++)
     {
     set[1][i]=i;
     set[2][i]=0;
     }
     int edge_accepted=0;
     /************************sorting vertex*************************/
     for(int i=1;i<=no_edges;i++)
     for(int j=1;j<=no_edges-1;j++)
     if(v[j].cost>v[j+1].cost)
     {
        temp=v[j];
        v[j]=v[j+1];
        v[j+1]=temp;
     }
     /************************accepted edges*************************/
     cout<<"\n\tEdges: ";
     for(int i=1;i<no_edges;i++)
     cout<<"\n\t"<<v[i].from<<"->"<<v[i].to<<"  "<<v[i].cost;
     for(int i=1;i<=no_edges;i++)
     q.insert(v[i]);
     cout<<"\n\tEdges added: ";
     while(edge_accepted<no_vertices-1)
     {
       e=q.Delete();
       f=0;
       /************************finding from vertex*************************/
       for(int i=1;i<=no_vertices;i++)
       {
       for(int j=1;set[j][i]!=0;j++)
       {
       if(set[j][i]==e.from)
       { 
       pos1=i;f=1;break;}
       }
       if(f==1) break;
       }
       f=0;
       /************************finding to vertex*************************/
       for(int i=1;i<=no_vertices;i++)
       {
       for(int j=1;set[j][i]!=0;j++)
       {
       if(set[j][i]==e.to)
       {
          
      pos2=i;f=1;break;}
       }
       if(f==1) break;
       }
              /************************merging two sets*************************/
       if(pos1!=pos2)
       {
         edge_accepted++;
         if(pos1<pos2)
         {
           for(k=1;set[k][pos1]!=0;k++);
           for(int i=1;set[i][pos2]!=0;i++)
           {
           set[k][pos1]=set[i][pos2];k++;
            }
           set[k][pos1]=0;
           set[1][pos2]=0;
         }
         
         else
           {
           for(k=1;set[k][pos2]!=0;k++);
           for(int i=1;set[i][pos1]!=0;i++)
           {
           set[k][pos2]=set[i][pos1];k++;
       }
           set[k][pos2]=0;
           set[1][pos1]=0;
         }
   cout<<"\n\t"<<e.from<<"->"<<e.to;
}
        }
         }
         


/*******************create graph*************************/
void Graph::create_graph()
{
  int i,n;
  cout<<"Enter the number of edges:";
  cin>>no_edges;
  for(i=1;i<no_edges+1;i++)
  {
    cout<<"Enter the edges:";
    cin>>v[i].from>>v[i].to;
    cout<<"cost:";
    cin>>v[i].cost;
  }
}
/*********************Display graph*************************/
void Graph:: display()
{
cout<<"\nEdges accepted:"<<no_edges;
for(int i=1;i<=no_edges;i++)
cout<<"\n"<<v[i].from<<"--->"<<v[i].to;
}
/************main*************/
int main()
{
 Graph g;
 g.create_graph();
 g.display();
 g.kruskal();
}
