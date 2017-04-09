#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int sameanc(vector<pair <int, int> > v,int n,int col){
	int a;
	int i,j,k,l;
	  k= v[n].first;
	    if(v[k].second==col){
	    	return k;
	    }
	    j=0;
	while(k!=1){
        k= v[k].first;
        if(v[k].second==col){
        	j=1;
        	i= k;
        	break;
        }
	}

	if(j==1){
		return i;
	}
	else{
		return -1;
	}
}

int main(int argc, char const *argv[])
{
    int i,j,k,t,m,n,value,r,a,b,q,c;
    vector < pair <int , int > > v;

       cin>>n;
       r=n;
       cin>>c;
        v.push_back(make_pair(0,0));
        v.push_back(make_pair(1,0));
         j=2;
         n= r-1;
       while(n--){
         cin>>m;
          v.push_back(make_pair(m,0));
         j++;
        } 
           n=r;
           j=1;
        while(n--){
         cin>>m;
         v[j].second= m;
         j++;
       }

       for (i=1; i <=r; ++i)
       {
       	  a= sameanc(v,i,v[i].second);
       	  cout<<a<<" ";
       }
    return 0;
}