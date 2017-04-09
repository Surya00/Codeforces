#include<bits/stdc++.h>
using namespace std;
 main(int argc, char const *argv[])
{
	int t,i,j,k,l,n,m,min,max;
	cin>>t;
	for (i = 0; i <t; ++i)
	{
	    cin>>n;
	    cin>>m;
	    min=n;
	    max=n;
	    if(max<=m)
	    	max=m;
	    if(min>=m)
	    	min=m;
	 //   l= min%3;
	  //  k=min/3;

	//    j= max-k*3;
	   // k= k*2;
	    if(max>=2*min){
	     k=min;
	    }
	    else{
	       k=(max+min)/3;
	     }


	    cout<<k<<"\n";

	}

}
