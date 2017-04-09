#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define scan1(a) scanf("%lld",&a)
#define scan2(a,b) scanf("%lld %lld",&a,&b)
#define scan3(a,b,c) scanf("%lld",&a,&b,&c)
ll vis[10000]={0};
 queue< ll > que;

bool twoco(vector< ll >* graph,ll s,ll color){
 
   for (ll i= 0; i <graph[s].size(); ++i)
   {
      if(vis[graph[s][i]]==0){
       // cout<<graph[s][i]<<" ";
        if(color==2){
           vis[graph[s][i]]=3;
          }
        if(color==3){
           vis[graph[s][i]]=2;
          }
         que.push(graph[s][i]);
      }
      else if(color==2&&vis[graph[s][i]]==2){
        //cout<<"yaha galat h"<<s<<vis[s]<<color<<endl;
        return false;
      }
      else if(color==3&&vis[graph[s][i]]==3){
       // cout<<"yaha galat h"<<s<<vis[s]<<color<<endl;
        return false;
      }
      
   }
     //cout<<endl;
      bool b=true;
   while(!que.empty()){
      ll a=que.front();
          que.pop();
        if(!twoco(graph,a,vis[a])){
          b=false;
        }
   }
  return b;
} 
int main(){
   ll a,b,n,t,m,c,i,j,k,l,f;
     scan1(t);
     while(t--){
        scan2(n,m);
        vector< ll > graph[n+1];
        vector< ll > revgraph[n+1];
        while(m--){
        
          scan2(a,b);
          graph[a].push_back(b);
          graph[b].push_back(a);
        }
           ll f=1;
           ll A[n+1];
        for (i=1; i<=n; i++)
        {
           if(graph[i].size()!=(n-1)){
             f=0;
           }
           memset(A,0,sizeof(A));
           for (j= 0; j<graph[i].size(); j++)
           {
              A[graph[i][j]]=1;
              //cout<<graph[i][j]<<" ";
           }
         //  cout<<endl;
             A[i]=1;

           for (j=1; j<=n; j++)
           {
              if(A[j]==0){
             //   cout<<j<<" ";
                revgraph[i].push_back(j);
              }
           }
          // cout<<endl;
        }
           ll g=1;
        for (i=1; i <=n; ++i)
        {
           if(vis[i]==0){
              vis[i]=2;
              if(!twoco(revgraph,i,2)){
               // cout<<"NO"<<" "<<i;
                g=0;
              }
             // else{
              //  cout<<"YES"<<" "<<i;
              //}
           }
        }

        if(g||f){
          cout<<"YES"<<endl;
          }
          else{
            cout<<"NO"<<endl;
          } 
          memset(vis,0,sizeof(vis));
        }  
 
    return 0;
}  