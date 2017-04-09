#include<bits/stdc++.h>
#include<time.h>
using namespace std;
#define ll long long int
double time_taken;
clock_t start, end;
   
int main(int argc, char const *argv[])
{
	ll i,j,k,n,m,s,t,l,count,mi,mv;

	cin>>n;
	start =  clock();
	ll A[n];
      m=0;
	for (l=0; l<n; l++)
	{
	  cin>>A[l];
      if(m<A[l]){
      	m=A[l];
      }
   }
       count=0;
     while(m){	
     		m>>1;
     		count++;
     	}
       i++;
     for (i =0; i <count; i++)
     {
     	mi=0;
     	mv=0;
          for (j = 0; j<n; j++)
          {
            if((A[j]^m>=m)&&(mv<A[j]^m)){
            	mv=A[j]^m;
            	mi=j;
            }
          }
          m=m^A[mi];
     }
     cout<<m<<"\n";

    end= clock();

    time_taken= ((double)(end-start))/CLOCKS_PER_SEC;
    cout<<time_taken<<" SEC time taken by this code\n";
	return 0;
}