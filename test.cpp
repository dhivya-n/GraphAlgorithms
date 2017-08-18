#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,lastchooseni=999,lastchoosenj=999,count=0,v[1000],s[1000];
    cin>>n;
    for(int i=0;i<n;i++)
        {
         cin>>v[i];
        
       }
           for(int i=0;i<n;i++)
        {
         cin>>s[i];
        
       }
    for(int i=0;i<n;i++)
        {
        for(int j=0;j<n;j++)
            {
        
            if(v[j]==s[i]&&i>lastchooseni&&j>lastchoosenj)
                {
                 count++;
                     cout<<v[j]<<s[j]<<"\n";
                lastchooseni=i;
                lastchoosenj=j;
                }
            else if(v[j]==s[i]&&i<lastchooseni&&j<lastchoosenj)
                {
                                 count++;
                lastchooseni=i;
                lastchoosenj=j;
               
                }
         
                
             
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

