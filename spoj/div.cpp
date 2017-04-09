#include<bits/stdc++.h>
using namespace std;
long long int A[1000]={0};
long long int shieve(){
     long long int i,j,k,count=0;
    for(i=2; i<1000; i++){
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
    long long int i,j,k,t,m,n,value,r,count,last;
    k=shieve();
    long long int Primes[k];
      j=0;
    for(i=2; i<1000; i++){
         if(A[i]==1){
         	Primes[j++]=i;
         }
    }
        count =0;
      for(j=1; j<=100; j++){
      	n=0;
      	m=0;
      	value=1;
      	last=0;
      	while(Primes[n]<=j){
      		if(m>2){
      			value=0;
      			break;
      		}
            if(j%Primes[n]==0){
            	m++;
            }
            n++;
      	}
      	if(m==1||m==2){
      		count++;
      		last=j;
      	}

       if(count%9==0&& last==j){
       	printf("%lld\n",j);
       }
      }
 }   