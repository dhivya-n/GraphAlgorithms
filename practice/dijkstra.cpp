#include<iostream>
using namespace std;
class graph
{
	int matrix[10][10];
	int n;
	public:
		graph()
		{
			cout<<"\nEnter the number of vertices:";
			cin>>n;
			for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
			{
				matrix[i][j]=0;
			}
		}
		void create_graph();
		void display();
		void dijkstra(int);
};
void graph::dijkstra(int s)
{
	int ch=1;
	struct vertex
	{
		int k,d,p;
	};
	vertex v[10];
	for(int j=0;j<=n;j++)	
	{
		v[j].d=999;
		v[j].k=0;
		v[j].p=0;
	}
	v[s].d=0;
		cout<<"\n-----Initial configuration-----\n";
    for(int i=1;i<=n;i++)	
    cout<<"\n"<<v[i].k<<"\t"<<v[i].d<<"\t"<<v[i].p;
	while(ch)
	{
		int small,temp=999;
		for(int j=1;j<=n;j++)
		if(v[j].d<temp&&v[j].k==0)
		{
			temp=v[j].d;
			small=j;
		}
		v[small].k=1;
		for(int i=1;i<=n;i++)
		if(matrix[small][i]!=0)
		 if(v[i].k==0)
		 if(matrix[small][i]+v[small].d<v[i].d)
		 {
		 	v[i].d=matrix[small][i]+v[small].d;
		 	v[i].p=small;
		}	
					cout<<"\n-----After"<<small<<"is known-----\n";
    for(int j=1;j<=n;j++)	
    cout<<"\n"<<v[j].k<<"\t"<<v[j].d<<"\t"<<v[j].p;
		cout<<"\nEnter any non zero value to continue";
		cin>>ch;	
	}
}
void graph::create_graph()
{
	int k,a,b;
	cout<<"\nEnter the number of edges:";
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cout<<"\nEnter the edges:";
		cin>>a>>b;
		cout<<"\nEnter the weight";
		cin>>matrix[a][b];
	}
}
void graph::display()
{
	cout<<"\nThe adjacency matrix is:";
	for(int i=1;i<=n;i++)
	{
	cout<<"\n";
	for(int j=1;j<=n;j++)
	cout<<"\t"<<matrix[i][j];
    }
}
int main()
{
	graph g;
	g.create_graph();
	g.display();
	g.dijkstra(1);
}
