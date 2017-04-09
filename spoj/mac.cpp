#include<bits/stdc++.h>
#include<time.h>
using namespace std;
#define ll long long int
//double time_taken;
//clock_t start, end;
   
int main(int argc, char const *argv[])
{
	ll i,j,k,n,m,s,t,l;

	cin>>n;
	ll A[n];
	m=0;
	s=0;
	t=0;
	//start =  clock();
	for (l=0; l<t; l++)
	{
	    cin>>A[l];
	    if(l%3==0){
	    	s= s+A[l];
	    }
	    if(l%3==1){
	    	m= m+A[l];
	    }
        if(l%3==2){
	    	t= t+A[l];
	    }
      cout<<s<<"\n"<<m<<"\n"<<t<<"\n";

   }
   // end= clock();

    //time_taken= ((double)(end-start))/CLOCKS_PER_SEC;
    //cout<<time_taken<<" SEC time taken by this code\n";
	return 0;
}