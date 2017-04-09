#include<stdio.h>
main(){
	long long int n,i,k,z,j,t;
  scanf("%lld",&t);
       for ( i = 0; i < t; ++i)
       {
          scanf("%lld",&n);
          z= (3*n*n+n)/2;
          z= z%1000007;
        
          printf("%lld\n",z);
        
       }
      
       	   
             return ;
       }