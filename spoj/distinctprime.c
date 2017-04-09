#include<stdio.h>
#include<math.h>
long long int A[10000]={0};
long long int shieve(){
     long long int i,j,k,count=0;
    for(i=2; i<10000; i++){
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
    long long int i,j,k,t,m,n,value,l;
    k=shieve();
    long long int Primes[k];
      j=0;
    for(i=2; i<10000; i++){
         if(A[i]==1){
         	Primes[j++]=i;
         }
    }
    printf("%lld\n", k);
    scanf("%lld",&t);
    for(i=0; i<t; i++){
      scanf("%lld",&n);
      value=6;
      long long int B[n];
      long long int C[n];
      m=2;
      B[0]=30;
      C[0]=0;
      for(j=1; j<n; j++){
           min=B[0]*Primes[C[0]];
           mini=0;
         for(l=0; l<1; l++){
         if(min>B[l]*Primes[C[l]]){
          min= B[l]*Primes[C[l]];
          min=l;
         }
         }
          if(min<Prime[m+1]*value)
      }

    }
    return 0;
  }