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
				matrix[i][j]=0;
			}
		}
		void create_graph();
		void display();
};
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
}
