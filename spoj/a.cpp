#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
#define MOD 1000000007
vector< int > graph[1000001];
vector< int > rgraph[1000001];
int reachc[1000001];
int rreachc[1000001];

 void dfs( int s){
    reachc[s]=1;
    for (int i = 0; i <graph[s].size(); ++i)
    {
       dfs(graph[s][i]);
       reachc[s]+=reachc[graph[s][i]];
    }
 }

 void dfs2( int s){
    rreachc[s]=1;
    for (int i = 0; i <rgraph[s].size(); ++i)
    {
       dfs2(rgraph[s][i]);
       rreachc[s]+=rreachc[rgraph[s][i]];
    }
 }
int main()
{
   // gearchange();
    int n;
    scanf("%d",&n);
    for (int i = 1; i <=n-1; ++i)
    {
      int x;
      scanf("%d",&x);
      if(x){
         graph[i].push_back(i+1);
         rgraph[i+1].push_back(i); 
      }
      else{
         graph[i+1].push_back(i);
         rgraph[i].push_back(i+1);
      }
    }

     for (int i = 1; i <=n; ++i)
     {
        if(!reachc[i]){ dfs(i); }
        if(!rreachc[i]){ dfs2(i); }
     }

     int q;
     scanf("%d",&q);
     int x=0;
     while(q--){
        char a;
        cin>>a;
        if(a=='U'){
           x=(x+1)%2;
        }
        else{
          int k;
          scanf("%d",&k);
          if(!x){ printf("%d\n",reachc[k]); }
          else{ printf("%d\n",rreachc[k]); }
        }
     }
    return 0;
}
