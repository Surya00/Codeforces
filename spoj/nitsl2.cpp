#include<bits/stdc++.h>
#include<time.h>
using namespace std;
#define ll long long int
double time_taken;
clock_t start, end;
   
int main(int argc, char const *argv[])
{
	ll i,j,k,n,m,s,t,l,x,ans,max,maxa;

	cin>>t;
	start =  clock();
	for (l=0; l<t; l++)
	{
	     cin>>n;
	     ll A[n];
	     ll B[n];
     for (i = 0; i <n; i++)
      {
       cin>>A[i];
       }
     for (i = 0; i <n; i++)
      {
       cin>>B[i];
       }
          maxa=0;
         for (i =0; i <n; i++)
         {   
         	   s=0;
         	   ans=0;
            for (j = 0; j<n; j++)
            	{
            		max=0; 
            	   if(A[i]==A[j]){
                       s=s++;
                       m=0;
                       for (x = 0; x < n; x++)
                       {
                       	 if(B[x]==B[j]){
                       	 	m++;
                       	 }
                       }
                     if(max<m){max++;}
            	   }
            	}
            ans= s+max;	
            if(maxa<ans){
            	maxa= ans;
            }
         }
         cout<<maxa<<"\n";
   }
    end= clock();

    time_taken= ((double)(end-start))/CLOCKS_PER_SEC;
    cout<<time_taken<<" SEC time taken by this code\n";
	return 0;
}