#include<bits/stdc++.h>
using namespace std;
long long int A[50001]={0};
long long int shieve(){
     long long int i,j,k,count=0;
    for(i=2; i<50001; i++){
    	k=0;

    	for(j=2; j<=(int)sqrt(i); j++){
            if(i%j==0){
            	k=1;
                break;
            }
    	}
    	if(k!=1){
    		A[i]=1;
          count++;
         // cout<<i<<"\n";
    	}
    }
    return count;
}
 main()
{
    long long int i,j,k,t,m,n,value,r,ans,count,n1;
    k=shieve();
    long long int Primes[k];
      j=0;
    for(i=2; i<50001; i++){
         if(A[i]==1){
         	Primes[j++]=i;
           // cout<<Primes[k++]<<"\n";
         }
    }

    cin>>t;

    for (i=0; i <t; ++i)
    {
       cin>>n;
       j=0;
       ans=1;
        while(Primes[j]<=n){
             count=0;
             n1=n;
             while(n1){
             	n1= n1/Primes[j];
                count=count+n1;
             } 
             ans=(ans*(count+1))%1000000007;
             j++;
        }
        cout<<ans<<"\n";
    }

 }   