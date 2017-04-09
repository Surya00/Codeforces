#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define scan1(a) scanf("%lld",&a)
#define scan2(a,b) scanf("%lld %lld",&a,&b)
#define scan3(a,b,c) scanf("%lld %lld %lld ",&a,&b,&c)
 vector< ll > graph[10001];
 vector< pair < ll,ll > > ticket[10001];
 ll dp[10001]= {0};
 ll dp2[1001][1001];
ll solve(ll country,ll k){
   if(country==1){
      return 0;
     }
     ll i,j,l,n,m,a,b;
     ll nextcountry= graph[country][0];
     ll mini=INT_MAX;
      
    if(k==0){
        if(dp[country]!=0){
          return dp[country];
        }
        for (i= 0; i <ticket[country].size(); i++)
        {
          n = ticket[country][i].second+solve(nextcountry,ticket[country][i].first-1);

          if(n<mini){
            mini=n;
          }  
        }
        return dp[country]=mini;
     }
       if(dp2[country][k]!=0){
       //  cout<<"hamare pass bhi nahi aaya";
         return dp2[country][k];
       }
       k--;
       a= solve(nextcountry,k);
    
      if(dp[country]!=0){
        mini= dp[country];
      }
      else{
        for (i= 0; i <ticket[country].size(); i++)
        {
          n = ticket[country][i].second+solve(nextcountry,ticket[country][i].first-1);
          if(n<mini){
            mini=n;
          }  
        }
      }
      
    return dp2[country][k] =min(mini,a);
}

int main(){
   ll a,b,n,t,m,c,i,j,k,l,f;
     memset(dp2,0,sizeof(dp2));
     scan2(n,m);
     for (i= 0; i <n-1; ++i)
     {
      scan2(a,b);
      graph[a].push_back(b);      
     }

     while(m--){
      scan3(a,b,c);
      ticket[a].push_back(make_pair(b,c)); 
      }
      scan1(a);
      while(a--){
        scan1(b);
       cout<<solve(b,0)<<endl;
      }
    return 0;
}  