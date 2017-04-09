#include<bits/stdc++.h>
#include<stdlib.h>
#define ll unsigned long long int
using namespace std;

ll powmod(ll n,ll m){
 ll b= m-1;
ll ans=1;
  while(b>0){
  	   if(b%2==1){
  	   	ans= (ans*n)%m;
  	   }
  	   n=((n%m)*(n%m))%m;
  	   b=b/2;
  }
    return ans;
}

int main(int argc, char const *argv[])
{
 ll i,j,k,l,t,n,a,flag;

 cin>>t;
    for ( i = 0; i <t; ++i)
        {
        	cin>>n;
        
        	flag=0;
        	//k=pow(n,1./3.);
        	k=sqrt(n);
        	if(n!=1){
             for (j = 2; j <=k+2; ++j)
             {
             	  a= rand()%(n-1);
             	l= powmod(a,n);
             	if(l==1)
                    flag=1;
                else{
                	flag=0;
                	break;
                }
             }
         }
             if(n==2||n==3)
             	flag=1;
             if(n==1)
             	flag=0;

             if(flag==1)
             	cout<<"YES\n";
             else
             	cout<<"NO\n";
        
        }    
}