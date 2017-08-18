#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Graph
    {
    int N,M;
   int count;
           char a,b;
    int mat[26][26],from,to;
    int D[26][26],P[26][26];
    public:
    void get();
    void Floyd();
    void path(int,int);
void disp()
{
	cout<<count;
}
    
};
void Graph::path(int i,int j)
{
if(P[i][j]==0)
  count++;
else
{
path(i,P[i][j]);
path(P[i][j],j);
}
}
void Graph::get()
    {
    count=0;
        cin>>N>>M;
    for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
        {
        mat[i][j]=0;
           
    } 
    }
    for(int i=0;i<M;i++)
        {cin>>a>>b;
         from=i-65;
         to=i-65;
         mat[from][to]=1;
        }
    
}


	void Graph::Floyd()
{
     for(int i = 0; i <=26;i++)
     for(int j=0;j<=26;j++)
      {
       D[i][j]=mat[i][j];
       if(i==j)
       D[i][j]=0;
       P[i][j]=0;
      }

 
 
   for(int k=1;k<=26;k++)
{
    for(int i=1;i<=26;i++)
      for(int j=1;j<=26;j++)
       if(D[i][k]+D[k][j]<D[i][j])
       {
          D[i][j]=D[i][k]+D[k][j];
          P[i][j]=k;
       }
 
}
}
int main() {
    char src,desc;
Graph g;
    g.get();

    cin>>src>>desc;
   g.Floyd();
   g.path(src-65,desc-65);
     g.disp();
    return 0;
}

