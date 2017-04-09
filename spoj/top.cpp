#include <bits/stdc++.h>
using namespace std;
class HandsShaking{
public:
	long long countPerfect(int n){

        long long dp[100]={0};
        for (int i = 0; i <=n/2; i++)
        {
        	if(i==0){ dp[0]=1; continue; }
        	if(i==1){ dp[1]=1; continue; }
        	if(i==2){ dp[2]=2; continue; }
        	for (int j =i-1; j >=0; j=j--)
        	{
        		dp[i]=dp[i]+dp[j]*dp[i-1-j];
        	}
        }

        return dp[n/2];		
	}
};