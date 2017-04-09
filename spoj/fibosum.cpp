#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define m 1000000007
ll fibo(ll n){
 ll e=n-2;
 //completly tested an fibo(0)=1, fibo(1)=1, fib(2)=1, fibo(3)=2
 //100% varified 
   ll a=0,b=1,c=1,d=1; 
   ll a1,b1,c1,d1,a2=0,b2=1,c2=1,d2=1;  
  while(e>0){
  	   if(e%2==1){
  	   	   a1= (a*a2+b*c2)%m;
  	   	   c1= (c*a2+d*c2)%m;
  	   	   b1= (a*b2+ b*d2)%m;
  	   	   d1= (b2*c+ d*d2)%m;
  	   	   a=a1;
  	   	   b=b1;
  	   	   c=c1;
  	   	   d= d1;
  	   }
  	       a1= (a2*a2+b2*c2)%m;
  	   	   c1= (c2*a2+d2*c2)%m;
  	   	   b1= (a2*b2+ b2*d2)%m;
  	   	   d1= (b2*c2+ d2*d2)%m;
  	   	   a2=a1;
  	   	   b2=b1;
  	   	   c2=c1;
  	   	   d2= d1;
  	   	   e= e/2;
  	  
  }
    return d;
}
int main()
{
	ll i,j,k,a,b,t,n;

	cin>>t;
	for ( i = 0; i <t; i++)
	{
		cin>>a;
		cin>>b;
		k= fibo(b+2);
      n=fibo(a+1);
    j= 1+n/m;
    j= j*m;
    j=j-n;
    k= (k+j)%m;
		cout<<k<<"\n";
   }

	return 0;
}