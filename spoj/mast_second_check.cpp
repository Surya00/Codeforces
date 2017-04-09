#include <bits/stdc++.h> 
using namespace std ;
#define ll long long int
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
int bit[1000001]={0};
ll A[1000001]={0};
ll n;
void add(int ind){
  while(ind<=n){
    bit[ind]++;
    ind+=ind&(-ind);
  }
}
int get(int ind){
   int sum=0;
  while(ind>0){
    sum+= bit[ind];
    ind-= ind&(-ind);
  }
   return sum;
}
int main()
{ 
  gearchange();
  ll q;
  cin>>n>>q;
  
  for (int i = 1; i <=n; ++i)
  {
    cin>>A[i];
  }
  A[0]=0;
  sort(A,A+n+1);
  while(q--){
    int k;
    cin>>k;
    int l=1,r=n;
    int ans=n;
    while(l<=r){
      int mid=(l+r)/2;
      if((mid-get(mid))>=k){
        ans= min(ans,mid);
        r= mid-1;
      }
      else{
        l= mid+1;
      }
    }
    cout<<A[ans]<<endl;
    add(ans);
  }

  return 0;
}
