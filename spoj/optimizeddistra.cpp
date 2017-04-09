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
    return 0;
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
int main(){

    int i,j,k,l,t,n,m,a,b,s,c,sum=0,f;

      scanf("%d",&t);
      while(t--){
       cin>>n>>m;
       vector< pair< int, int > > graph[n+1];
       int disto[n+1];
    
     while(m--){
         scanf("%d %d %d",&a, &b, &c);
         graph[a].push_back(make_pair(b,c));
         graph[b].push_back(make_pair(a,c));
       }
         scanf("%d",&s);
           
           
           for (i =1; i<=n; i++)
           {
               disto[i]= inf; 
           }
            disto[s]= 0;
            push(make_pair(s,disto[s]));
           j=0;
        while(j<n+20){
            j++;
            pair<int,int>  y= pop();
              s= y.first;

            if(disto[s]<=y.second){
             for (i= 0; i < graph[s].size(); i++)
             {
                 int dis;
                 dis= disto[s]+ graph[s][i].second;
                 
                 if(disto[graph[s][i].first]>dis){
              
                          disto[graph[s][i].first]= dis;
                          int node= graph[s][i].first;
                          if(find(node)){
                            change(node,dis);
                          }else{
                            push(make_pair(node, dis));
                          }
                 }
              
              }

            }
          }

        for(i=1; i<=n; i++){
            if(disto[i]!=0&&disto[i]!=inf){
                printf("%d ",disto[i]);
             }
            
            if(disto[i]==inf){
                printf("-1 ");
            }
          
            }
              printf("\n");
            while(!ve.empty()){
              ve.pop_back();
            }

            mp.clear();
       
        }     
    return 0;
}   