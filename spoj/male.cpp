#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

ll check(ll n,double k, ll c){
	if (n==1)
		return c;
    
	if((double)log2(k)>(n-2)){
		if(c==1)
		    return check(n-1,(k-(1<<(n-2))),0);
		return check(n-1,(k-(1<<(n-2))),1);
	}
	else{
		if(c==1)
			return check(n-1,k,1);
		return check(n-1,k,0);
	}
	
}

int main(){
	ll i,j,n,t;
    double k;
	cin>>t;
	for (i = 0; i <t; ++i)
	{
	    cin>>n;
	    cin>>k;
	    j= check(n,k,1);
	    if(j==1){
	    	cout<<"Male\n";
	    }
	    else{
	    	cout<<"Female\n";
	    }
	}
	return 0;
}