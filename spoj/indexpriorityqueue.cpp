/// this 100% checked process you can use it infurther problem
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
vector< pair <int,int> > ve;
map< int, int > mp;
 int swap(int a, int b){
  pair<int, int>  c= ve[a];
  ve[a]= ve[b];
  ve[b]=c;
  return 0;
 }
int  heapify1( int i ){ // checked
  
  int ch1= 2*i+1;
  int ch2= 2*i+2;
   int min=i;
  if(ve[ch1].second<ve[min].second&&ch1<ve.size()){
    min= ch1;
  }
  if(ve[ch2].second<ve[min].second&&ch2<ve.size()){
    min= ch2;
   }

   if(min!= i){
     swap(min,i);
     mp[ve[min].first]= min;
     mp[ve[i].first]=i;
     heapify1((i-1)/2);
   }

   return 0; 
}
int  heapify2( int i){ // checked
  int  ch1= 2*i+1;
  int  ch2= 2*i+2;
   int min=i;
  if(ve[ch1].second<ve[min].second&&ch1<ve.size()){
    min= ch1;
  }
  if(ve[ch2].second<ve[min].second&&ch2<ve.size()){
    min= ch2;
   }

   if(min!= i){
     swap(min,i);
     mp[ve[min].first]= min;
     mp[ve[i].first]=i;
     heapify2(min);
   }

   return 0; 
}
int push( pair<int, int> p){ // checked
  if(ve.empty()){
    ve.push_back(p);
    return 0;
  }
    
   ve.push_back(p);
   heapify1((ve.size()-2)/2);
}

pair<int,int> pop(){ // checked
  pair< int, int> p;
  p= ve[0];
  ve[0].second= inf;
  heapify2(0);
  return p;
}

 bool find(int n){    // checked
  if(mp.find(n)!=mp.end()){
    return true;
  }
  return false;
 }

 int change(int s, int dist){  // checked
     int a;
     a= mp[s];
     ve[a].second= dist;
     heapify1((a-1)/2);
     return 0;
 }

 int main(int argc, char const *argv[])
 {
  int i,j,m,n,v,a,b;
    j=0;
    
    while(j<5){
      cin>>a>>b;
      pair< int ,int > p= make_pair(a,b);
      push(p);
      j++;
    }

  

     for (j = 0; j <5; j++)
     {
         cout<<ve[j].first<<" "<<ve[j].second<<endl;
     }
                
   
  

    /*  for (j = 0; j <5; j++)
      {
         cout<<ve[j].first<<" "<<ve[j].second<<endl;
      }  */
            j=0;
      while(j<5){
        cin>>a>>b;
        change(a,b);
        j++;
      } 
            j=0;
      while(j<5){
        pair<int, int> p= pop();
         cout<<p.first<<" "<<p.second<<endl;
         j++;
       }
  /*    for (j = 0; j <5; j++)
      {
         cout<<ve[j].first<<" "<<ve[j].second<<endl;
      } 
    /*  j=0;
      while(j<5){
        pair<int, int> p= pop();
         cout<<p.first<<" "<<p.second<<endl;
         j++;
      }
      */

   return 0;
 }