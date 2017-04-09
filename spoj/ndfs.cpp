#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int A[1000]={0};
 void dfs(vector< ll > graph[], ll s){
 	vector< ll >::iterator i;
 	for (i=graph[s].begin(); i!=graph[s].end(); i++)
 	{
 	  if(A[*i]==0){
 	  	A[*i]=1;
 	  	cout<<*i<<"    ";
 	  	dfs(graph,*i);
 	  } 
 	}
 	return;
 }
int main(int argc, char const *argv[])
{
	ll i,j,k,a,b,c,n,m,s,t;
	cin>>t;
	while(t--){
		cin>>n>>m;

    vector < ll > graph[n+1];
     while(m--){
     	cin>>a>>b;
     	graph[a].push_back(b);
     	graph[b].push_back(a);
     }
       cin>>s;

       dfs(graph,s);
	}
	
	return 0;
}