#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d,f,h,n;
    
    cin>>n>>a>>b;
    if(a<0||b<0){
      cout<<2;
    }
    else if(a>n||b>n){
      cout<<2;
    }
    else if(a<n||b<n){
      cout<<0;
    }
    else{
      cout<<1;
    }
    return 0;
}