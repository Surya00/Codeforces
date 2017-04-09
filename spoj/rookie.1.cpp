#include<bits/stdc++.h>
using namespace std;
#define ll long long int
long long int pow(ll m,ll n){
 long long  int b=m;    
 long long  int ans=1;
  while(b>0){
  	   if(b%2==1){
  	   	ans= (ans*n)%1000000007;
  	   }
  	   n=(n*n)%1000000007;
  	   b=b/2;
  }
    return ans;
}
int main()
{
	ll i,j,k,l,a,b,c,n,m,z;
	cin>>a>>b>>t;
    n= pow(t, a+b);
    m= pow(1000000005,2);
    l= pow(t,m);

    cout<<(n*l)%1000000007;

	return 0;
}