#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll A[1000000]={0};

  ll maxi(ll n, ll a,ll b,ll c){
    if(n==0){
      return 0;
    }
    if(n<0){
     return -100000;
    }
    if(A[n]!=0){
      return A[n];
    }
    ll x=0,y=0,z=0,i,j;
       
       x= maxi(n-a,a,b,c)+1;
         

          A[n]=x;
       y= maxi(n-b,a,b,c)+1;
         A[n]= max(x,y);
         // if(n-c>=0){
       z= maxi(n-c,a,b,c)+1;
      //   }
      
        
       i= max(x,y);
       j= max(i,z);
          A[n]=j;
       return j;

         }

int main()
{
    ll i,j,k,t,m,n,value=0,r,q,c,z,a,b,d;
       cin>>n>>a>>b>>c;

       value= maxi(n,a,b,c);
      
     
        cout<<value;

    return 0;
}