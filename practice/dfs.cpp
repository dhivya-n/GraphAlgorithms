#include<iostream>
using namespace std;
class graph
{
	int matrix[10][10],tree[10][10],v[10];
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
				tree[i][j]=0;
			}
			for(int i=0;i<=n;i++)
			v[i]=0;		
		}
		void create_graph();
		void display();
		void dfs(int);
};
void graph::dfs(int s)
{
	v[s]=1;
	for(int i=1;i<=n;i++)
	if(matrix[s][i]!=0)
	if(v[i]==0)
	{
	tree[s][i]=1;
	dfs(i);	
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
		matrix[a][b]=1;
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
    	cout<<"\nThe output tree is matrix :";
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++)
	if(tree[i][j]!=0)
	cout<<i<<"-->"<<j;
    }
}
int main()
{
	graph g;
	g.create_graph();
	g.dfs(1);
	g.display();
}
