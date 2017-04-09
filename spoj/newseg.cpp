#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
using namespace std;

struct Node
{
  ll sta;
  ll end;
  ll ca;
  ll da;

};

ll pow2(ll n){
  ll count=0;
   while(n%2==0){
    n/= 2;
     count++;
   }
   return count;
}

ll pow5(ll n){
  ll count=0;
   while(n%5==0){
    n/= 5;
     count++;
   }
   return count;
}

ll A[100001];
struct Node segment[10000000]={0};
struct Node lazy[10000000]={0};

pair< ll, ll >  createsegmenttree(ll asta,ll aend,ll pos){
  if(asta==aend){
    ll m,n;
    m= pow2(A[asta]);
    n= pow5(A[asta]);
    struct Node p;
     p.sta= asta;
     p.end= aend;
     p.ca= m;
     p.da= n;
     segment[pos]= p;
     pair< ll, ll > p1;
     p1.first= m;
     p1.second= n;
     return p1;
  }

    ll mid= (asta+aend)/2;

    pair< ll, ll > p1,p2;

    p1= createsegmenttree(asta,mid,2*pos+1);
    p2= createsegmenttree(mid+1, aend, pos*2+2);

    struct Node p;

     p.sta= asta;
     p.end= aend;
     p.ca= p1.first+ p2.first;
     p.da= p1.second+ p2.second;
     segment[pos]= p;

     return make_pair(p.ca, p.da);
}

void createlazytree(ll asta,ll aend,ll pos){
  if(asta==aend){
    ll m,n;
    m=0;
    n=1;
    struct Node p;
     p.sta= asta;
     p.end= aend;
     p.ca= m;
     p.da= n;
     lazy[pos]= p;
     return ;
  }

    ll mid= (asta+aend)/2;

    createlazytree(asta,mid,2*pos+1);
    createlazytree(mid+1, aend, pos*2+2);

     struct Node p;
     p.sta= asta;
     p.end= aend;
     p.ca= 0;
     p.da= 1;

     lazy[pos]= p;

     return ;
}


 pair< ll, ll > update1(ll qsta,ll qend,ll pos, ll x){
    
    if(segment[pos].sta>=qsta&&segment[pos].end<=qend){
       ll m= pow2(x);
       ll n= pow5(x);

        segment[pos].ca+= m*(segment[pos].end- segment[pos].sta+1)+lazy[pos].ca;
        segment[pos].da+= n*(segment[pos].end- segment[pos].sta+1)+lazy[pos].da;
        lazy[pos].ca=0;
        lazy[pos].da=0;
        lazy[2*pos+1].ca+= m;
        lazy[2*pos+1].da+= n;
        lazy[2*pos+2].ca+= m;
        lazy[2*pos+2].da+= n;

       return make_pair(segment[pos].ca,segment[pos].da);
    }

    if(segment[pos].sta>qend||segment[pos].end<qsta){
      return make_pair(segment[pos].ca,segment[pos].da);
    }

    pair< ll , ll > p1;
    pair< ll, ll > p2;

    p1= update1(qsta,qend,pos*2+1,x);
    p2= update1(qsta,qend,pos*2+2,x);

    segment[pos].ca= p1.first+ p2.first;
    segment[pos].da= p1.second+ p2.second;

    return make_pair( segment[pos].ca, segment[pos].da);
 }


pair< ll, ll > update2(ll qsta,ll qend,ll pos, ll y){
    
    if(segment[pos].sta>=qsta&&segment[pos].end<=qend){
       ll m= pow2(x);
       ll n= pow5(x);

        segment[pos].ca+= m*(segment[pos].end- segment[pos].sta+1)+lazy[pos].ca;
        segment[pos].da+= n*(segment[pos].end- segment[pos].sta+1)+lazy[pos].da;
        lazy[pos].ca=0;
        lazy[pos].da=0;
        lazy[2*pos+1].ca+= m;
        lazy[2*pos+1].da+= n;
        lazy[2*pos+2].ca+= m;
        lazy[2*pos+2].da+= n;

       return make_pair(segment[pos].ca,segment[pos].da);
    }

    if(segment[pos].sta>qend||segment[pos].end<qsta){
      return make_pair(segment[pos].ca,segment[pos].da);
    }

    pair< ll , ll > p1;
    pair< ll, ll > p2;

    p1= update1(qsta,qend,pos*2+1,y);
    p2= update1(qsta,qend,pos*2+2,y);

    segment[pos].ca= p1.first+ p2.first;
    segment[pos].da= p1.second+ p2.second;

    return make_pair( segment[pos].ca, segment[pos].da);
 }





int main(){
  
  ll t,n,m;
  cin>>t;
  while(t--){
    scanf("%lld %lld",&n,&m);

    for (int i = 0; i < n; i++)
    {
      scanf("%lld",&A[i]);
    }

    // create segmenttrre;
    // create lazy tree;

     while(m--){
      ll type,l,r,x;
       scanf("%lld",&type);
        if(type==1){
          scanf("%lld %lld %lld",&l,&r,&x);
          // update1(l,r,x);
        }
        else if(type==2){
          scanf("%lld %lld %lld",&l,&r,&x);
             // update2(l,r,x);
        }
        else{
           scanf("%lld %lld",&l,&r);

           cout<<getans(l,r);
        }
     }

  }
  return 0;
}  