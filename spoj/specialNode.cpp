#include <bits/stdc++.h> 
using namespace std ;
#define ll long long int
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
vector< int > graph[1000001];
int vis[1000001]={0};
int ans[1000001]={0};
void dfs(int s){
  vis[s]=1;
  int dis=0;
  for (int i = 0; i <graph[s].size(); ++i)
  {
    if(!vis[graph[s][i]]){
       dfs(graph[s][i]);
       dis= max(dis,ans[graph[s][i]]+1);
    }
  }
  ans[s]=dis;
}
int minn=10000000;
int ind=0;
void dfs2(int s){
  vis[s]=1;
  int a,b;
  a=0; b=0;
  for (int i = 0; i <graph[s].size(); i++)
  {
      if(graph[s][i]){
       int y=ans[graph[s][i]]+1;
       if(a<=ans[graph[s][i]]+1){
        y=a;
        a= ans[graph[s][i]]+1;
       }
       b= max(y,b);
     }  
  }
  for (int i = 0; i <graph[s].size(); ++i)
  {
    if(!vis[graph[s][i]]){
      int z=a;
      if(ans[graph[s][i]]+1==a){ z=b;}
      if(b==0){ ans[graph[s][i]]= max(ans[graph[s][i]],max(a-1,1)); }
      else{ ans[graph[s][i]]=max(ans[graph[s][i]],z+1); }
      if(ans[graph[s][i]]<minn){ minn= ans[graph[s][i]]; ind= graph[s][i]; }
      int y= ans[s];
      ans[s]=z;
      dfs2(graph[s][i]);
      ans[s]=y;
    }
  }
}
int main()
{ 
  gearchange();
  int n;
  cin>>n;
  int x=n-1;
  int maxxpivot=0;
  while(x--){
    int a, b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  if(n==2){ cout<<0<<endl; cout<<1<<" "<<2; return 0; }
  dfs(1);
  memset(vis,0,sizeof(vis));
  minn=ans[1];
  ind=1;
  dfs2(1);
  int a,b;
  a= ind;
 // cout<<ind<<endl;
  for (int i = 1; i <=n; ++i)
  {
  ///  cout<<ans[i]<<" ";
  }
  int maxx=0;
//  cout<<endl;
  memset(vis,0,sizeof(vis));
  dfs(ind);
 // cout<<ind<<endl;
  for (int i = 0; i < graph[ind].size(); ++i)
  {
    //cout<<graph[ind][i]<<" ";
    if(ans[graph[ind][i]]>=maxx){ maxx= ans[graph[ind][i]]; b=graph[ind][i]; }
  }
  //cout<<endl;
  for (int i = 0; i <graph[a].size(); ++i)
  {
    if(graph[a][i]==b){ graph[a][i]=0; break; }
  }
  for (int i = 0; i <graph[b].size(); ++i)
  {
    if(graph[b][i]==a){ graph[b][i]=0; }
  }
 
  memset(vis,0,sizeof(vis));
  vis[0]=1;
  dfs(a);
  memset(vis,0,sizeof(vis));
  vis[0]=1;
  ind=a;
  minn= ans[a];
  dfs2(a);
  a= ind;
  maxxpivot= max(maxxpivot,ans[a]);
  memset(vis,0,sizeof(vis));
   vis[0]=1;
  dfs(b);
  memset(vis,0,sizeof(vis));
   vis[0]=1;
  ind=b;
  minn= ans[b];
  dfs2(b);
  b=ind;
  maxxpivot= max(maxxpivot,ans[b]);
  cout<<maxxpivot<<endl;
  cout<<a<<" "<<b;

  return 0;
}