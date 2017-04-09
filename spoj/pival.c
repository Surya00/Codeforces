#include<stdio.h>
#include<math.h>

main(){
	float a,b,c ,ans;
  int i,j,n;

//	int A[1000000+2]={0};
	// int B[1000000+2]; 
	   c=1;
     n=6;
    for (i =0; i <23; i++)
    {
        a= sqrt(1- (c/2)*(c/2));
       // printf("%f\n",a);
        b= 1-a;
        c= sqrt(c*c/4 + b*b);
        n=n*2;  
    }
       ans = n*c/2;
     printf("%.25f\n",ans);
}