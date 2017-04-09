#include<bits/stdc++.h>
#include<time.h>
using namespace std;
long long int A[220]={0};
long long int B[46345]={0};
double time_taken;
clock_t start, end;
long long int shieve(){
     long long int i,j,k,count=0;
    for(i=2; i<220; i++){
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
int main()
{
    long long int i,j,k,t,m,n,value,r,c=0,x;
     start =  clock();
    k=shieve();
    long long int Primes[k];
      j=0;
    for(i=2; i<220; i++){
         if(A[i]==1){
         	Primes[j++]=i;
          //cout<<Primes[j-1]<<"   ";
         }
    }
    for(j=0; j<k; j++){
         r=0;
        while(r<=(46345)){
          if(Primes[j]!=r){
           B[r]=1;
            //cout<<"gjhgjhj";
          }
           r= r+Primes[j];
           
        }
      
      }
      for(j=2; j<46345; j++){
      if(B[j]==0){
           c++;
           }        
         }
         long long int prime[c];
            x=c;
         c=0;
      

    for(j=2; j<46345; j++){
      if(B[j]==0){
           prime[c++]=j;
           //cout<<prime[c-1]<<"  ";
           }        
         }

   
    scanf("%lld",&t);
    for(i=0; i<t; i++){
    	scanf("%lld%lld",&m,&n);
    	long long int C[n-m+1];
    	  value=m;
    	for(j=0; j<=(n-m); j++){
    		C[j]=value++;  
        //cout<<value<<"  ";  		
    	}
    	for(j=0; j<x; j++){
          if(m%prime[j]!=0){
          r=prime[j] -(m%prime[j]);
           }
           else{
               r=0;
           }
        while(r<=(n-m)){
          if(prime[j]!=C[r]){
           C[r]=0;
            //cout<<"gafh";
          }
           r= r+prime[j];
           
        }
    	
    	}
    	for(j=0; j<=(n-m); j++){
    	if(C[j]!=0&&C[j]!=1){
         printf("%lld\n",C[j]);
         }    		
    	}} 
       end= clock();

    time_taken= ((double)(end-start))/CLOCKS_PER_SEC;
    //cout<<time_taken<<" SEC time taken by this code\n";

   return 0;
}