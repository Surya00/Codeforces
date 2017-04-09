#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

       ll n,m,a,b,i,c;
       scanf("%I64d %I64d",&n,&m);
       map<ll, ll> mp;
         for (i = 0; i <m;i++)
         {
            scanf("%I64d",&a);
            mp[a]=i+1;
         }
         ll f=0;
     for (i = 2; i <=n/2; i++)
     {
        if(mp.find(i)!=mp.end()){
             c=2*i;
           while(c<=n){
             if(mp.find(c)!=mp.end()){
               f=1;
                a= i;
                b= c;
               break;
             }
             c= c+i;
           }
        }
          if(f){
            break;
          }
     }

     if(f){
       cout<<mp[a]<<" "<<mp[c];
     }
     else if(mp.find(1)!=mp.end()){
        map< ll , ll > :: iterator it;
        it= mp.find(1);
        it++;
        cout<<mp[1]<<" "<<it->second;
     }
     else{
      cout<<0<<" "<<0;
     }
}  