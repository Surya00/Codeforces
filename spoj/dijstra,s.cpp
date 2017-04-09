#include <bits/stdc++.h> 
using namespace std ;
#define ll long long int
#define inf 1000000000000LL
#define mp make_pair
set< pair<ll, ll> >st;
ll disto[100001];
//ll cost=0;
map<ll,ll> maap;
//ll source[100001];
void Dijstra(vector< pair< ll, ll> > graph[], ll s){
  //ll s=1;
  st.insert(mp(0,s));
  disto[s]=0;
  ll k=0;
  while(!st.empty()){
       disto[st.begin()->second]=st.begin()->first;
        s= st.begin()->second;
        st.erase(mp(disto[s],s));
       // maap[source[s]*1000000+s]=1;
        cout<<source[s]<<" "<<s<<endl;
     for (ll i = 0; i < graph[s].size(); ++i)
     {
      if(disto[graph[s][i].first]> graph[s][i].second+disto[s]){
        st.erase(mp(disto[graph[s][i].first],graph[s][i].first));
        st.insert(mp(graph[s][i].second+ disto[s],graph[s][i].first));
        disto[graph[s][i].first]= graph[s][i].second+ disto[s];
        //source[graph[s][i].first]= s;
      }
     }
  }
}

int main()
{
    ll n; cin>>n;
    vector< pair< ll, ll> > graph[n+1];
    ll m; cin>>m;
    pair<pair< ll, ll>, ll > A[m];
    for (int i = 0; i <m; i++)
    {
      ll a,b,c;
      cin>>a>>b>>c;
      A[i]= make_pair(mp(a,b),c);
      graph[a].push_back(make_pair(b,c));
      graph[b].push_back(make_pair(a,c));
    }
    for (int i = 0; i <=100000; i++){ disto[i]=inf;}
     source[1]=1;
      Dijstra(graph);
  
return 0;
}