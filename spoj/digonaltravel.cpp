#include <bits/stdc++.h>
using namespace std;
#define ll long long int  


int main(){
  ll A[1000][1000];
  memset(A,0,sizeof(A));
   ll n;
   cin>>n;
   while(n--){
    ll a,b;
    cin>>a>>b;
    A[a-1][b-1]=1;
   }

   ll ans=0;
   n=0;
   while(n<=1998){

     ll cou=0;
    for (int i = max(n-999,0LL); i <=min(n,999LL); i++)
    {
       if(A[i][n-i]){
        cou++;
       }
    }
     if(cou>=2){
      ans+= (cou-1)*cou/2;
     }
    n++;
   }

     n=0;
    while(n<1000){
        ll a=n;
        ll b=0;
      ll cou=0;
     while(max(a,b)<1000){
       if(A[a][b]){
        cou++;
       }
       a++;
       b++;
    }
     if(cou>=2){
      ans+= (cou-1)*cou/2;
     }
    n++;
    }

    n=1;
    while(n<1000){
        ll a=0;
        ll b=n;
      ll cou=0;
     while(max(a,b)<1000){
       if(A[a][b]){
        cou++;
       }
       a++;
       b++;
    }
     if(cou>=2){
      ans+= (cou-1)*cou/2;
     }
    n++;
    }

    cout<<ans;

  return 0;
}  