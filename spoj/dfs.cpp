#include<bits/stdc++.h>
using namespace std;
  //int A[6]={0};
#define ll long long int
 void dfs(int i,int n,int A[], vector<int > graph[]){
     int a,b,t;
     if(A[i]==1){
     	cout<<i<<endl;
     	return ;
     }

     t=0;
     while(t<n){
     a= graph[i][t];
    
      A[i]=1;
     dfs(a,graph[a].size(),A,graph);
      t++;
     }
     return ;
 }
int main()
{
    ll i,j,k,l,m,n;
     cout<<" Enter the no of vetex";
     cin>>n;
      int A[n+1];
  
     memset(A,0,sizeof(A));
     vector<int> graph[n+1];
     cout<<"enter the no of edges";
      cin>>m;
     while(m--){
     	cin>>l>>k;
     	graph[l].push_back(k);
     	graph[k].push_back(l);

    }
     dfs(1,graph[1].size(),A,graph);
    //cout<<graph[1].size()<<endl;

	return 0;
}