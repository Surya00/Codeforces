#include<bits/stdc++.h>
using namespace std;
struct myType{
    int first;
    int second;

};

class 
{
public:
    bool operator()(struct myType x, struct myType y){
        if(y.first<x.first){
            return true;l
        }
        return false;
    }
};

int B[10000]={0};
 int  root(int i){
     while(B[i]!=0){
        i= B[i];
     }
     return i;
 }

int main(){

    int i,j,k,l,t,n,m,a,b,c,sum=0; 
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

         cout<<sum;
    return 0;
}   