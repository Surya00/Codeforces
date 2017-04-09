#include<bits/stdc++.h>
#include<time.h>
#include<string>
using namespace std;
#define ll long long int
//double time_taken;
//clock_t start, end;
 ll upto[10];
void countupto(){
	ll i;
	 upto[0]=0;

	for(i=1; i<10; i++){
       upto[i]= 45*pow(10,(i-1))+ upto[i-1]*10;
       //cout<<upto[i]<<"\n";
	}
}
ll uptoN(ll A[],ll l){
	ll i,j,k,s;
	  k=0;
	  s=0;
	for (i=0; i<l; i++)
	{
		k= k+s*A[i]*pow(10,(l-i-1)) + ((A[i]*(A[i]-1))/2)*pow(10,(l-i-1))+upto[l-i-1]*A[i];
		s=s+A[i];
	}
    return k+s;
}  
int main()
{
	ll i,j,k,a,n,m,s,t,l;
	ll A[10];
	ll B[10];
//	start =  clock();
	string b,x;
	countupto();
	cin>>a;
	cin>>b;
    
   if(a<0){
       return 0;
   }
     x= to_string(a-1);
     // cout<<x;
	for (i= 0; i<b.length(); i++)
	{
		A[i]= (int)b[i]-48;
	}
     for (i= 0; i<x.length(); i++)
	{
		B[i]= (int)x[i]-48;
	}
	  n= uptoN(A,b.length());
	  m= uptoN(B,x.length());
   // cout<<n<<endl;
    //cout<<m<<endl;

	  cout<<n-m<<"\n";
    main();
	
   // end= clock();

  //  time_taken= ((double)(end-start))/CLOCKS_PER_SEC;
    //cout<<time_taken<<" SEC time taken by this code\n";
	return 0;
}