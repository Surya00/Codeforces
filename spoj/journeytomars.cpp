#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
#define MOD 1000000007

int main()
{
   gearchange();
   int n;
   cin>>n;
   pair< ll,ll > A[n];
   for (int i = 0; i <n; ++i)
   {
      int a,b;
      cin>>a>>b;
      A[i]=make_pair(a,b);
   }
    bool B[n];
    ll C[n];
    ll S[n];
    int vis[n];
    memset(vis,0,sizeof(vis));
    for (int i = n-1; i>=0; i--)
    {
       int start=i;
       ll c=0;
       bool yes= true;
       if(A[start].second<=A[start].first){
        c= A[start].first-A[start].second;
        start++;
        start%=n;
       }
       else{
        yes=false;
       }
       while(start!=i and yes){
          if(vis[start]){
             if(B[start]){ break; }
             else{
               int temp= S[start];
               if(temp>=i and temp<start){
                break;
               }
               else{
                 start= temp;
                 c+=C[start];
               }
             }
          }
          if(A[start].second<=A[start].first+c){
             c+= A[start].first-A[start].second;
             start++;
             start%=n;
          }
          else{
            yes=false;
            break;
          }
       }
       B[i]=yes;
       C[i]=c;
       S[i]=start;
       vis[i]=1;
    }

     for (int i = 0; i < n-1; ++i)
     {
        if(B[i]){
          cout<<"TAK"<<endl;
        }
        else{
           cout<<"NIE"<<endl;
        }
     }
        if(B[n-1]){
          cout<<"TAK";
        }
        else{
           cout<<"NIE";
        }
   
  return 0;
}