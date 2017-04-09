#include <bits/stdc++.h> 
using namespace std ;
#define ll long long int
#define inf INT_MAX
#define MOD 1000000007
#define MAX_SIZE 10000000
long int dp[MAX_SIZE+1][4]={0};

int main()
{
  ll n;
  cin>>n;

  for (ll i = 0; i <=n; i++)
  {
  	 for (int j = 0; j <4; j++)
  	 {
  	 	if(i==0&&(j==1||j==2||j==0)){ dp[i][j]=0; continue;}
  	 	if(i==0&&j==3){ dp[i][j]=1; continue; }
  	 	if(j==1){ dp[i][j]= ((dp[i-1][2]+ dp[i-1][3])%MOD+ dp[i-1][0])%MOD; }
  	 	if(j==0){ dp[i][j]= ((dp[i-1][2]+ dp[i-1][1])%MOD+ dp[i-1][3])%MOD; }
  	    if(j==2){ dp[i][j]= ((dp[i-1][0]+ dp[i-1][1])%MOD+ dp[i-1][3])%MOD; }
  	    if(j==3){ dp[i][j]= ((dp[i-1][2]+ dp[i-1][1])%MOD+ dp[i-1][0])%MOD; }
  	 }
  }

  cout<<dp[n][3];

return 0;
}