// dijstra with priority que and, Dijstra with set.
#include <bits/stdc++.h> 
using namespace std ;
#define ll long long int
#define inf INT_MAX
#define mp make_pair
ll disto[20000];

ll Dijstra(vector< pair< ll, ll> > graph[],ll s,ll d){
  set< pair<ll, ll> >st;
  st.insert(mp(0,s));
  disto[s]=0;
  ll k=0;
  while(!st.empty()){
    disto[st.begin()->second]=st.begin()->first;
        s= st.begin()->second;
        if(s==d){ return disto[s];}
        st.erase(mp(disto[s],s));
     for (int i = 0; i < graph[s].size(); ++i)
     {
      if(disto[graph[s][i].first]> graph[s][i].second+disto[s]){
        st.erase(mp(disto[graph[s][i].first],graph[s][i].first));
        st.insert(mp(graph[s][i].second+ disto[s],graph[s][i].first));
        disto[graph[s][i].first]= graph[s][i].second+ disto[s];
      }
     }
  }
  return inf;
}
int main()
{
  ll t;
  cin>>t;
  while(t--){
    ll n; cin>>n;
    vector< pair< ll, ll> > graph[n+1];
    ll m; cin>>m;
    while(m--){
      ll a,b,c;
      cin>>a>>b>>c;
      graph[a].push_back(make_pair(b,c));
    }
    for (int i = 0; i <=10000; i++){ disto[i]=inf;}
    ll s; cin>>s; ll d; cin>>d;
      ll x=Dijstra(graph,s,d);
      if(x==inf){ cout<<"NO";}
      else{ cout<<disto[d];}
      cout<<endl;
  }
  
return 0;
}

/*#include <bits/stdc++.h> 
using namespace std ;
#define ll long long int
#define inf INT_MAX
#define mp make_pair
ll disto[20000];

void Dijstra(vector< pair< ll, ll> > graph[],ll s,ll d){
	priority_queue< pair< ll , ll> > que;
	que.push(mp(0,s));
	disto[s]=0;
	while(!que.empty()){
       s= que.top().second;
       que.pop();
       for (int i = 0; i < graph[s].size(); ++i)
       {
       	 if(disto[graph[s][i].first]> graph[s][i].second+disto[s]){
       	 	disto[graph[s][i].first]= graph[s][i].second+ disto[s];
       	 	que.push(mp(disto[graph[s][i].first], graph[s][i].first));
       	 }
       }
	}
}
int main()
{
	ll t;
	cin>>t;
	while(t--){
		ll n; cin>>n;
		vector< pair< ll, ll> > graph[n+1];
		ll m; cin>>m;
		while(m--){
			ll a,b,c;
			cin>>a>>b>>c;
			graph[a].push_back(make_pair(b,c));
		}
		for (int i = 0; i <=10000; i++){ disto[i]=inf;}
		ll s; cin>>s;
	    ll d; cin>>d;
	    Dijstra(graph,s,d);
	    if(disto[d]==inf){
	    	cout<<"NO";
	    }
	    else{
	    	cout<<disto[d];
	    }
	    cout<<endl;
	}
	
return 0;
}*/