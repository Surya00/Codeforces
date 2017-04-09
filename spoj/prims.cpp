#include<bits/stdc++.h>
using namespace std;
struct myType{
    int first;
    pair< int, int> p;

};
 class comp
 {
    public:
    bool operator()(struct myType s, struct myType c){
      if(s.first>c.first){
        return true;
      }
      return false;
    }    
 };
    
int main(){

    int i,j,k,l,t,n,m,a,b,c,sum=0;
    priority_queue< struct myType, vector< struct myType> , comp> pq;
    struct myType x,y,z;

    cin>>n>>m;
    vector< pair<int, int > > graph[n+1];
     int A[n+1];
     memset(A,0,sizeof(A));

    while(m--){
        cin>>a>>b>>c;
         graph[a].push_back(make_pair(b,c));
         graph[b].push_back(make_pair(a,c));

            }
      cin>>k;

         j=0;
         while(j!=n){
            for (i = 0; i <graph[k].size(); i++)
            {
                if(A[graph[k][i].first]==0){
                x.first= graph[k][i].second;
                x.p= make_pair(k,graph[k][i].first);
                pq.push(x);
               }
            }

               if(!pq.empty()){
                 while(A[pq.top().p.second]!=0){
                    pq.pop();
                 }
                  y= pq.top();
                 sum= sum+ y.first;
                 A[y.p.second]=1;
                  j++;
                  k= y.p.second;
             }
         }

         cout<<sum;
    return 0;
}   s