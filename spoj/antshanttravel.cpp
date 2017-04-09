#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 ll A[1000];
vector<pair< ll, char> > ve;
bool solve(ll i, ll j ,ll of){
      if(j==i){ return true;}
     ll maxx=0;
     ll k= of+1;
     for (int x = i; x <=j; x++) {   maxx= max(A[x],maxx);}
     	ll f=1;
     for (int x = i; x <=j; x++){ if(A[x]!=maxx){ f=0;}}
     if(f){ return false; }
     map<ll,ll> mp;
    
     ll ind=0;
     for(int x=i; x<=j; x++){ 
     mp[x]=A[x]; 
     }
  
     for(int x=i; x<=j; x++){ 
     if(A[x]==maxx){
     	if(x+1<=j&&A[x+1]!= maxx){ ind= x; break;}
     	if(x-1>=i&&A[x-1]!= maxx){ ind= x; break;}
     }
      k++;
     }
     
     map< ll , ll> :: iterator it,it1;
     it= mp.find(ind);
     while(mp.size()!=1){
     	   it1= it;
     	   it1++;
          if((it1)!=mp.end()&&(it1)->second<maxx){
             maxx= it->second= maxx+ (it1)->second;
             mp.erase((it1)->first);
             ve.push_back(make_pair(k,'R'));
          }
          else {
          	 it--;
          	 it1= it;
          	 it1++;
          	 maxx= it->second= maxx+ (it1)->second;
             mp.erase((it1)->first);
             ve.push_back(make_pair(k,'L'));
             k--;
          }
     }

     return true;
}

int main (){      
 
  ll n,k;
  cin>>n;
  
    ll sum1=0,sum2=0;
    ll sum[n+1];
    sum[0]=0;
   for (int i = 0; i < n; i++)
   {
   	 cin>>A[i];
   	 sum1+= A[i];
   	 sum[i+1]= sum[i]+A[i];
   }
    cin>>k;

   ll B[k];
   for (int i = 0; i < k; i++)
   {
   	 cin>>B[i];
   	 sum2+=B[i];
   }
   
    if(sum1== sum2){
    	ll j=0;
    	ll k=0;
    	ll of=0;
       for (int i = 0; i < n; i++)
       {
       	  if(sum[i+1]-sum[k]>B[j]){
            cout<<"NO";
            return 0;
       	  }
       	  else if(sum[i+1]- sum[k]<B[j]){
             continue;
       	  }
       	  else{
       	  	  if(!solve(k,i,of)){
       	  	  	cout<<"NO";
       	  	  	return 0;
       	  	  }
       	  	  of++;
       	  	  j++;
       	  	  k= i+1;
       	  }
       }
    }
    else{
    	cout<<"NO";
    	return 0;
    }

    cout<<"YES"<<endl;

     for (int i = 0; i < ve.size(); i++)
     {
       cout<<ve[i].first<<" "<<ve[i].second<<endl;
     }

    return 0;
}