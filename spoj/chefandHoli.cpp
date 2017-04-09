#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
ll ans[1100000]={0};
int main()
{
   gearchange();
    int n;
    ll t;
    cin>>n>>t;
    t--;
    vector< int > adj[n];
    for (int i = 0; i <n; ++i)
    {
       string s;
       cin>>s;
       for (int j = 0; j < s.length(); j++)
       {
          if(s[j]=='1'){ adj[i].push_back(j); }
       }
    }
     int la;
     int ind;
     ll last[n];
     memset(last,0,sizeof(last));
     for (int i = 0; i <adj[0].size(); ++i)
     {
       last[adj[0][i]]=1;
       ans[0]++;

     }

     map< vector< int >,int> mp;
     vector< int > ve;
     for (int i = 0; i < n; ++i)
     {
       if(last[i]){ ve.push_back(1); }
       else{ ve.push_back(0); }
     }
     mp[ve]=0;
     for (int i = 1; i <=(1<<n + 1); ++i)
     {
        ll cur[20]={0};
        vector< int > vec;
        for (int j = 0; j <n; j++)
        {
            if(last[j]&1){ 
            for (int k = 0; k <adj[j].size(); k++)
            {
             cur[adj[j][k]]++;
            }
            }
            else{
            for (int k = 0; k <adj[j].size(); k++)
            {
             cur[adj[j][k]]+=2;
            }
            }
        }
      
        for (int j = 0; j < n; j++)
        {
          ans[i]+=cur[j];
          last[j]=cur[j];
          if(cur[j]&1){ vec.push_back(1); }
          else{ vec.push_back(0); }
        }
        if(mp.find(vec)!=mp.end()){ la=i;ind= mp[vec]; break; }
        else{ mp[vec]=i;}
     }
  
     ll y= (t-ind)%(la-ind);
     ll z=(t-ind)/(la-ind);
     ll x=0;
     ll sum=0;
     for (int i = 0; i <=min((ll)ind,t); ++i)
     {
       sum+=ans[i];
     }
     for (int i = ind+1; i <=la; ++i)
     {
        x+=ans[i];
       
     }
      //cout<<x<<" "<<y<<" "<<z<<endl;
     if(z<0){ z=0; }
     sum+= x*z;
     for (int i = ind+1; i <=ind+y; ++i)
     {
        sum+=ans[i];
     }
     cout<<sum;
  return 0;
}