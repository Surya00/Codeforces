#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll vis[1000000]={0};

bool cycle(set<ll > graph[], ll s){
   if(vis[s]){
    return false;
   }
    vis[s]=1;
    set< ll > :: iterator it;
            bool a=true;
    for (it = graph[s].begin(); it!= graph[s].end(); it++)
    {
      a=a&cycle(graph,*it);
    }

    return a;
}

   int main(){
      
      ll t;
      cin>>t;
      ll m;
      for (int i = 0; i < t; i++)
      {
          ll n;
          cin>>n;
          m=n;

          set< string > st;
          vector< string > ve;
          while(n--){
          string s,a;
          cin>>s;
          ve.push_back(s);
            a="";
           for (int j = 0; j < s.length(); j++)
           {
             
             if(s[j]=='='){
              st.insert(a);
              a= "";
             }
             a=a+s[j];
             if(s[j]=='('){
               j++;
               string b;

               while(1){
                
                 if(s[j]==','){
                  st.insert(b);
                  b="";
                 }
                 else if(s[j]==')'){
                  break;
                 }
                 else{
                   b=b+s[j];
                 }
                 j++;
               }

               if(b!=""){
                st.insert(b);
                b="";
               }

             }

           }
         }

         ll s= st.size();
         map< string, ll> mp;
         ll val=0;
         set<string > :: iterator it;

          for (it=st.begin(); it!=st.end(); it++)
          {
             val++;
             mp[*it]=val;
          }

        set < ll > graph[st.size()+1];

        //  cout<<st.size()<<endl;
      for (int u = 0; u < m; u++)
        {
          string s,a,c;
            s= ve[u];
            a="";
           for (int j = 0; j < s.length(); j++)
           {
             
             if(s[j]=='='){
              c= a;
              a= "";

             }
             a=a+s[j];
             if(s[j]=='('){
               j++;
               string b;

               while(1){
                
                 if(s[j]==','){
                  graph[mp[b]].insert(mp[c]);
                //  cout<<c<<" "<<b<<endl;
                  b="";
                 }
                 else if(s[j]==')'){
                  break;
                 }
                 else{
                   b=b+s[j];
                 }
                 j++;
               }

               if(b!=""){
              //   cout<<c<<" "<<b<<endl;
                graph[mp[b]].insert(mp[c]);
                b="";
               }

             }

           }
         }


         bool ans= true;
          for (int x = 1; x <st.size(); x++)
          {
             ans= ans&cycle(graph,x);
             memset(vis,0,sizeof(vis));
          }

          if(ans){
            cout<<"Case #"<<i+1<<": "<<"GOOD"<<endl;
          }
          else{
            cout<<"Case #"<<i+1<<": "<<"BAD"<<endl; 
          }
      }
        return 0;
    }
       