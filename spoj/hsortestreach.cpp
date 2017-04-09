#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll disto[1000];
ll A[1000];
queue < ll > que;
void bfs(vector <ll>  graph[],ll s){
   ll j,k,a,b;
   vector< ll >::iterator i;
   for(i=graph[s].begin(); i!=graph[s].end(); i++){
           if(A[*i]==0){
            que.push(*i);
            disto[*i]= disto[s]+ 6;
            A[*i]=1;
           }
    }
        
    while(!que.empty()){
    que.pop();
    k= que.front();
    bfs(graph,k);
    }
    return;
 } 

int main()
{
	ll a,b,n,t,z,i,j,l,s,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector< ll > graph[n+1];
        memset(A,0,sizeof(A));
        while(m--){
        	cin>>a>>b;
        	graph[a].push_back(b);
        	graph[b].push_back(a);
        }
        cin>>s;
         z=s;
        memset(disto,0,sizeof(disto));
         que.push(s);
         bfs(graph,s);
        for(i=1; i<=n; i++){
           if(disto[i]==0){
           	if(i!=z){
           		cout<<-1<<" ";
           	}
           	
           }
           else{
           		if(i!=z){
           		cout<<disto[i]<<" ";
           	}
           
           }

        }
        cout<<endl;
	}

	return 0;
}