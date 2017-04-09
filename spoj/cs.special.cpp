#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 bool isspecial(string s,ll k){
  ll i,j,a,l,z,b,f;
        f=0;
   for(i=1; i<=s.length(); i++){
        j=0;
        z=0;
        while(j!=i){
          z= z*10 + ((int)s[j]-48);
          j++;
        }
       // cout<<z<<endl;
        if(z%k==0){
           f=1;
         break;
        }
          b=0;

        for (j=i;j<s.length(); j++)
        {
           z= z- ((int)s[b]- 48)*pow(10,i-1);
            
           z= z*10+ ((int)s[j]-48);
           b++;
          // cout<<z<<endl;
           if(z%k==0){
            f=1;
            break;
           } 
        }
   }

     if(f){
      return false;
     }

     return true;

 }

int main()
{
	ll i,j,k,l,a,b,c,n,m,z,t,f;
	cin>>t;

	while(t--){
		cin>>a>>b>>k;
    ll count=0;

    for (i=a;i<=b; i++)
      {
          string s;
           m=i;
          while(m){
            s= (char)(m%10 + 48) + s;
            m= m/10;
          }
          
          if(isspecial(s,k)){
           //cout<<s<<endl;
           count++;
          } 
      }
      cout<<count<<endl;
	}

	return 0;
}