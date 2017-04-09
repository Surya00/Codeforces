#include <bits/stdc++.h> 
using namespace std ;
#define ll long long int

int main()
{
	ll n, x,m;
    ll t=1;
    ll key1=1, key2=2, key3= 3, key4= 4;
    ll keyforall= 1000000;
    map< ll, pair<ll, ll> > mp;
    ll h=1;
    cin>>n;
    while(n--){
    	 string a;
    	 cin>>a;
    	 if(a=="E"){ 
    	   ll s,r;
           scanf("%lld %lld",&s,&r);
           if(s==1){
           	 if(mp.find(key1)!=mp.end()){ mp[key1+h]= make_pair(s,r); key1= key1+h;}
           	 else{ keyforall= keyforall+1000000; mp[keyforall]=make_pair(s,r); key1= keyforall; }
           }
           if(s==2){
           	 if(mp.find(key2)!=mp.end()){ mp[key2+h]= make_pair(s,r); key2= key2+h;}
           	 else{ keyforall= keyforall+1000000; mp[keyforall]=make_pair(s,r); key2= keyforall; }
           }
           if(s==3){
           	 if(mp.find(key3)!=mp.end()){ mp[key3+h]= make_pair(s,r); key3= key3+h;}
           	 else{ keyforall= keyforall+1000000; mp[keyforall]=make_pair(s,r); key3= keyforall; }
           }
           if(s==4){
           	 if(mp.find(key4)!=mp.end()){ mp[key4+h]= make_pair(s,r); key4= key4+h;}
           	 else{ keyforall= keyforall+1000000; mp[keyforall]=make_pair(s,r); key4= keyforall; }
           }
         }
         else{
            cout<<mp.begin()->second.first<<" "<<mp.begin()->second.second<<endl;
            mp.erase(mp.begin()->first);
         }
      }
	return 0;
}