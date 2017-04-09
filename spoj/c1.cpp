#include<bits/stdc++.h>
#include<time.h>
using namespace std;
#define ll long long int

   
int main(int argc, char const *argv[])
{
	ll i,j,k,n,m,s,t,l,x;

	cin>>n;
	ll A[n];
	for (l=0; l<n; l++)
	{
	 cin>>A[l]; 
    }
      x=0;
     for (l=0; l<n-1 ; l++){
	
	 m=__gcd(A[l],A[l+1]);
         if(m!=1){
             x++;
           }
    }
       cout<<x<<endl;
    for (l=0; l<n-1 ; l++){
        cout<<A[l]<<" ";
	
	 m=__gcd(A[l],A[l+1]);
         if(m!=1){
            cout<<"999999733 "; 
           }
    }
       cout<<A[n-1]<<"\n";
     
	return 0;
}