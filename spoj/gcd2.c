#include<stdio.h>
#include<string.h>
  int simplegcd(int a,int b){
  	if(a==0){
  		return b;
  	}
  	return simplegcd(b%a,a);
  }
main(){
	int i,j,k,l,n,m,r,t,s;
	scanf("%d",&t);
	for ( i = 0; i <t; i++)
	{
		char A[251];
		int B[251]={0};

	     scanf("%d",&n);
	     scanf("%s",A);
        l= strlen(A);
                  k=0;
        for (j = 251-l; j <251; j++)
        {
           B[j]= (int)A[k++]-48; 
          // printf("%d\n",B[j] );

        }
           k=0;
           s=0;
           if(n!=0){
         for (j = 0; j <251; j++)
        {
        	s= s*10+ B[j];
        	r= s%n;
        	s=r;
          // if()   
           //printf("%d",B[j] );
           
        }
           m=simplegcd(s,n);
          printf("%d\n",m);
	}
	else{
		  for (j = 251-l; j <251; j++)
        {
           
           printf("%d",B[j] );

        }  
        printf("\n");
	}
}

}