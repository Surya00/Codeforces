#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void setprefix(string p,ll A[]){
	ll i,j,k,l,a,b;
	 i=1;
	 j=0;
	 while(i!=p.length()){
	 	if(p[i]== p[j]){
	 		A[i]= j+1;
	 		j++;
	 		i++;
	 	}
	 	else if(j>0){
	 		j= A[j-1];
	 	}
	 	else{
	 		A[i]=0;
	 		i++;

	 	}
	 }
}

 ll stringmatch(string t, string p , ll A[]){
     ll i,j,k,l,a,b,c;
      i=0; j=0; 
      while(i<t.length()){
      	if(p[j]==t[i]){
      		if(j==p.length()-1){
      			return i-j;
      		}
      		else{
      			i++;
      			j++;
      		}
      	}
      	else if(j>0){
      		j= A[j-1];
      	}
      	else{
      		i++;
      	}
      }
    return -1;
 }

int main(int argc, char const *argv[])
{
    ll i,j,k,l,a,b,c,n,m;
    string t;
    cin>>t;
    cin>>n;
    while(n--){
    	string p;
    	cin>>p;
        ll A[p.length()];
        memset(A,0, sizeof(A));
        setprefix(p,A);
          a=stringmatch(t,p,A);
         while(a!=-1){
         	t.erase(a,p.length()); 
         	a=stringmatch(t,p,A);
         }
       
    }
     cout<<t;
	return 0;
}