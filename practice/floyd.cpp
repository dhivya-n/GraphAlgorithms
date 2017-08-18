#include<iostream>
using namespace std;
class graph
{
	int matrix[10][10],p[10][10],d[10][10];
	int n;
	public:
		graph()
		{
			cout<<"\nEnter the number of vertices:";
			cin>>n;
			for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
			{
				d[i][j]=9999;
				matrix[i][j]=0;
			}
		}
		void path(int,int);
		void create_graph();
		void display();
		void floyd();
};
void graph::floyd()
{
	for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)	
    {
    	if(matrix[i][j]!=0)
    	d[i][j]=matrix[i][j];
    	if(i==j)
    	d[i][j]=0;
    	p[i][j]=0;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(d[i][k]+d[k][j]<d[i][j])
		{
		d[i][j]=d[i][k]+d[k][j];
	    p[i][j]=k;
		}
		cout<<"\nDistance matrix---"<<k;
		for(int a=1;a<=n;a++)
		{
			cout<<"\n";
			for(int b=1;b<=n;b++)
			{
				cout<<"\t"<<d[a][b];
			}
		}
		cout<<"\nPredecessor matrix---"<<k;
		for(int a=1;a<=n;a++)
		{
			cout<<"\n";
			for(int b=1;b<=n;b++)
			{
				cout<<"\t"<<p[a][b];
			}
		}
	}
}
void graph::path(int i,int j)
{
	if(p[i][j]==0)
	cout<<"\n"<<i<<"----->"<<j;
	else
	{
		path(i,p[i][j]);
		path(p[i][j],j);
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
	int a,b,ch=1;
	graph g;
	g.create_graph();
	g.display();
	g.floyd();
	while(ch)
	{
	cout<<"\n enter vertex to find path:";
	cin>>a>>b;
	g.path(a,b);
	cout<<"\nPress any non zero to continue:";
	cin>>ch;
    }
}
