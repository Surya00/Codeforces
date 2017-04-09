#include<stdio.h>
main(){
	long long int n,i,k,z,j,t;
  scanf("%lld",&t);
       for ( i = 0; i < t; ++i)
       {
          scanf("%lld",&n);
          z=0;
        for (j = 0; j <n; ++j)
        {
          scanf("%lld",&k);
          z=(z+k)%n;
        }

        if(z==0){
          printf("YES\n");
        }
        else{
          printf("NO\n");
        }
       }
      
       	   
             return ;
       }