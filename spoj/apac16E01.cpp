#include <bits/stdc++.h> 
using namespace std ;
#define ll long long int
#define inf INT_MAX
#define mp make_pair

ll countB(string s){
	ll cou=0;
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]=='B'){ cou++;}
	}
	return cou;
}
int main()
{
 ll t;
  cin>>t;
  for (int u = 0; u < t; u++)
  {
  	 string s;
  	 cin>>s;
  	 ll sta,end;
  	 cin>>sta>>end;
  	 sta--;
  	 ll n= s.length();
  	 ll y= countB(s);
  	 y= y*(end/n);
  	 for (int i = 0; i <end%n; i++)
  	 {
  	  if(s[i]=='B'){ y++; }
  	 }

  	 ll x= countB(s);
  	 x= x*(sta/n);
  	 for (int i = 0; i < sta%n; i++)
  	 {
  	 	if(s[i]=='B'){ x++;}
  	 }
  	 cout<<"Case #"<<u+1<<": "<<(y-x)<<endl;
  }
return 0;
}