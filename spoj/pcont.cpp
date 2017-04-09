#include<bits/stdc++.h>
#include<time.h>
using namespace std;
#define ll long long int
double time_taken;
clock_t start, end;
   
   ll primes[1229];
   void pcount(){
   	ll i,j,k,l=0;
   	for (i = 2; i<10000; i++)
   	{
   		 k=0;
   	   for (j = 2; j<=100; j++)
   	   {
   	   	 if(i%j==0&&j!=i){
   	   	 	k=1;
   	   	 	break;
   	   	 }
   	   }

   	   if(k==0){
          primes[l++]=i;
          //cout<<primes[l-1]<<" ";
   	   }
   	}
   }
int main(int argc, char const *argv[])
{
	ll i,j,k,n,m,s,t,l;
  double ans;
	
	cin>>n;
	start =  clock();
	pcount();
	//cout<<"hfhdsfh";
	ans=(double)n;
	for (i = 0; (primes[i]<=sqrt(n)&&i<1229); i++)
	{
		ans= (ans*((double)(primes[i]-1)))/(double)primes[i];
	}
	///k=ans;
	//cout<<k<<" ";
	for (i=0; (primes[i]<=sqrt(n)&&i<1229); i++)
	{
		ans= ans+1;
	}
	cout<<ans-1<<"\n";
    end= clock();

    time_taken= ((double)(end-start))/CLOCKS_PER_SEC;
    cout<<time_taken<<" SEC time taken by this code\n";
	return 0;
}