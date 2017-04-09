#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll A[320]={0};
ll shieve(){
     ll i,j,k,count=0;
    for(i=2; i<320; i++){
    	 k=0;

    	for(j=2; j<=(ll)sqrt(i); j++){
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
    ll i,j,k,t,m,n,value,r,a,b,q;
    k=shieve();
    ll Primes[k];
      j=0;
    for(i=2; i<320; i++){
         if(A[i]==1){
         	Primes[j++]=i;
         }
    }
   ll naughty[100001];
   ll count;

    memset(naughty,0,sizeof(naughty));

     for (i=2; i <=100000; i++)
     {
     	  n=i;
     	  j=0;
     	  count=0;

     	  while(Primes[j]<=n&&j<k){
     	        
              if(n%Primes[j]==0){
          	      count++;
          	    
          	   while(n%Primes[j]==0){
          		n= n/Primes[j];
          	     }

             }
          j++;

     	  }
     	  if(n!=1){
          	count++;
          }
         
     	if(count==((ll)log10(i)+1)){
     		naughty[i]=1;
     		
          }
        
        }
       naughty[1]=1;
       ll naughtycount[100001];
       ll z=0;
       for (i = 0; i <=100000; i++)
       {
       	  z= z+naughty[i];
       	  naughtycount[i]=z; 
       }

       cin>>q;
       while(q--){
       	cin>>a>>b;
       	cout<<naughtycount[b]-naughtycount[a-1]<<endl;
       } 
    return 0;
}