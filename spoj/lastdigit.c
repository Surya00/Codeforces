#include<stdio.h>
long long int powmod(long long int a, long long int b,long long int m){
 long long  int ans=1;
  while(b>0){
  	   if(b%2==1){
  	   	ans= (ans*a)%m;
  	   }
  	   a=(a*a)%m;
  	   b=b/2;
  }
    return ans;
}
long long int main()
{
    long long int a,b,i,z,m,t;
     scanf("%lld",&t);
     for (i = 0; i <t; ++i)
     {
            scanf("%lld%lld",&a,&b);

            z= powmod(a,b,10);
            printf("%lld\n",z%10);

     	     }
 
    
  return 0;
}