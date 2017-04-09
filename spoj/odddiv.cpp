#include<bits/stdc++.h>
//#include<time.h>
using namespace std;
#define ll long long int
//double time_taken;
//clock_t start, end;
ll A[317]={0};
ll dcount[100001]={0};
ll shieve(){
     ll i,j,k,count=0;
    for(i=2; i<317; i++){
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
 void divcount(ll P[],ll k){
  ll i,j,z,x,a,b,y;
    for (i=2; i<=100000; i++)
    {
    	x=1;
    	for (j =0; j<k; j++)
    	{
    		y=0;
    		a=i;
    		while(a%P[j]==0){
               a= a/P[j];
    		  y++;
    		}
           x=x*(2*y+1);
    	}
    	if(x==1){
    		dcount[i]=3;
    	}
    	else{
    		dcount[i]=x;
    	}
    }
 }
int main(int argc, char const *argv[])
{
	ll i,j,k,n,m,s,t,l,lo,hi,count,a;

	cin>>t;
	//start =  clock();
	 k=shieve();
    ll Primes[k];
      j=0;
    for(i=2; i<317; i++){
         if(A[i]==1){
         	Primes[j++]=i;
         }
    }
     divcount(Primes,k);
	for (l=0; l<t; l++)
	{
	
      cin>>n;
      cin>>lo;
      cin>>hi;
      a=sqrt(lo);
      if(a*a==lo){
      	j=a;
      }
      else{
      	j=a+1;
      }
      //cout<<j<<" ";
      count=0;
      while(j*j<=hi){
      	if(dcount[j]==n){
      		count++;
      	}
      	j++;
      }
      cout<<count<<"\n";

   }
     //for (i =2; i <100; ++i)
    // {
     //	cout<<dcount[i]<<"   ";
     //}
   // end= clock();

  //  time_taken= ((double)(end-start))/CLOCKS_PER_SEC;
   // cout<<time_taken<<" SEC time taken by this code\n";
	return 0;
}