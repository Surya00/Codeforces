#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
       {
	   ll t,i,j,k,l,n,m,dif,min,max,a,b;
	    cin>>t;    
	for (i = 0; i <t; i++)
	 {
	    cin>>n;
        vector< pair<int,int> > v;
      
        for (j = 0; j<n; j++)
        {
            cin>>a;
            cin>>b;
            v.push_back(make_pair(b,a));   
        }
        sort(v.begin(),v.end());
        
            k= v[0].first;
         max=1;
        for ( j=0; j<n; j++)
        {
           if(v[j].second>=k){
            k= v[j].first;
             max++;
           }  
        }
        cout<<max<<"\n";

	}
 
    return 0;
}
