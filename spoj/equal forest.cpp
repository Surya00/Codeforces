#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll B[100000]={0};  

ll dfs( vector< ll > graph[],ll s, ll ans,ll A[]){
      
     vector< ll > :: iterator it;
     for (it=graph[s].start(); it!= graph[s].end(); it++)
     {
     	if(B[*it]==0){
     		B[*it]=1;
            ans= ans+ A[*it];
     		dfs(graph,*it);
     	}
     }
     return ans;
}
 pair< ll, ll > twotree(vector< ll > graph[], ll n, ll A[]){
       ll i,j,k,l,f;
         f=0;
 	   for(i=1; i<=n; i++){
         if(B[i]==0&&f!=1){
         	f=1;
         	k=dfs(graph,i,A[i],A);
         	pair< ll, ll > p;
         	p= make_pair(k,i);
         }
 	   }
       
 	   return p;
 }

int main()
{
	ll i,j,k,l,a,b,c,n,m,z,q,f;
	cin>>q;
	while(q--){
		cin>>n;
		ll A[n];
		  z=0;
		for (i = 1; i <n+1; i++)
		{
			 cin>>A[i];
			 z= z+A[i];
		}
           a= z%3;
           b= 3-a;
            c= z;
            z= z+b;
            l= z/3;

		vector < ll > graph[n+1];
		for(i=0; i<n-1; i++){
			cin>>a>>b;
			graph[a].push_back(b);
			
		}
		   f=0;

		for (i =1; i<=n; i++)
		{
			for(j=0; j<graph[i].size(); j++){
				k=graph[i][0];
				graph[i].erase(graph[i].begin());
				pair< ll , ll > p ;

                p=twotree(graph, n, A);
                graph[i].push_back(k);
                if(p.first==l||p.fisrt==(c-l)){
                  f=1;
                  break;
                }
			}
			if(f=1){
				break;
			}
		}

		if(f=1){
             cout<<(3*l- z)<<endl;
		}
		else{
			cout<<-1<<endl;
		}

	}

	return 0;
}