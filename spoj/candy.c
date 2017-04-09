#include<stdio.h>
main(){
	long long int n,i,k,z;
       float a;
       scanf("%lld",&n);
       if(n!=-1){
       	long long int A[n];
          z=0;
       	for (i = 0; i <n; ++i)
       	{
       	  scanf("%lld",&A[i]);
       	  z=z+A[i];
       	}
       	    a=(float)z/(float)n;
       	    k= z/n;
       	    if((float)k==a){
       	    	  z=0;
              for(i=0; i<n; i++){
              	if(A[i]>k){
              		z=z+(A[i]-k);
              	}
              }
              printf("%lld\n",z);    
       	    }
       	    else{
       	    	printf("-1\n");
       	    }

       	 main();
       }
       else{
             return ;
       }
}