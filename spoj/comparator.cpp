/*
 * Satyam Swarnkar (Zyloc), Nit Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,start,end) for (int i=start;i<=end;i++)
#define pool(i,start,end) for(int i=start;i>=end;i--)
#define zyloc() lli t;cin>>t;while(t--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fill(a,value) memset(a,value,sizeof(a)) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
#define INF numeric_limits<double>::infinity()
struct myType {
    int first;
    pair<int,int> p;
};
class comp{
public:
    bool operator()(struct myType f,struct myType s){
        if (f.first>s.first){
            return true;
        }
        return false;
    }       
};

bool oper(pair<ll,double> x, pair<ll,double> y){
       if(y.second<=x.second){
          if(y.second==x.second){
             if(y.first>x.first){
              return true;
             }

             return false;
          }

          return true;
       }
       return false;
   }

int main(){
    priority_queue<struct myType,vector<struct myType>,comp > pq;
    struct myType x,y,z;
    x.first = 80000;
    x.p = mp(10,52);
    y.first = 90000;
    y.p = mp(10,52);
    z.first = 1000;
    z.p = mp(10,52);
    pq.push(x);
    pq.push(y);
    pq.push(z);
    while(!pq.empty()){
        cout<<pq.top().first<<endl;
        pq.pop();
    }
    return 0;
}   