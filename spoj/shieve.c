#include<stdio.h>
#include<math.h>
long long int A[31623]={0};
long long int shieve(){
     long long int i,j,k,count=0;
    for(i=2; i<31623; i++){
    	k=0;

    	for(j=2; j<=(int)sqrt(i); j++){
            if(i%j==0){
            	k=1;
            }
    	}
    	if(k!=1){
    		A[i]=1;
          count++;
    	}
    }
    return count;
}
int main(int argc, char const *argv[])
{
    long long int i,j,k,t,m,n,value,r;
    k=shieve();
    long long int Primes[k];
      j=0;
    for(i=2; i<31623; i++){
         if(A[i]==1){
         	Primes[j++]=i;
         }
    }
      // printf("%lld%lld\n",k,j);
       //for(j=0; j<=10; j++){
    		 
     // printf("%lld  ",Primes[j]);
    //}
   
    scanf("%lld",&t);
    for(i=0; i<t; i++){
    	scanf("%lld%lld",&m,&n);
    	long long int B[n-m+1];
    	  value=m;
    	for(j=0; j<=(n-m); j++){
    		B[j]=value++;    		
    	}
    	for(j=0; j<k; j++){
          if(m%Primes[j]!=0){
        r=Primes[j] -(m %Primes[j]);
           }
           else{
               r=0;
           }
        while(r<=(n-m)){
          if(Primes[j]!=B[r]){
           B[r]=0;
          
          }
           r= r+Primes[j];
           
        }
    	
    	}
    	for(j=0; j<=(n-m); j++){
    	if(B[j]!=0&&B[j]!=1){
         printf("%lld\n",B[j]);
         }    		
    	}


    }
	return 0;
}