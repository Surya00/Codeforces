#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
using namespace std;

int main(){
  char a,b;
  ll x1,x2,y1,y2;
   cin>>a;
   cin>>y1;
   x1= a-'a';

   cin>>b;
   cin>>y2;
   x2= b- 'a';

    if(x1<=x2&&y1<=y2){
      cout<<max(x2-x1,y2-y1)<<endl;
      if(x2-x1>y2-y1){
        ll m= (x2-x1)- (y2-y1);
         while(m--){
          cout<<"R"<<endl;
         }
         m= min(x2-x1,y2-y1);
         while(m--){
          cout<<"RU"<<endl;
         }
      }
      else{
        ll m= abs((x2-x1)- (y2-y1));
         while(m--){
          cout<<"U"<<endl;
         }
         m= min(x2-x1,y2-y1);
         while(m--){
          cout<<"RU"<<endl;
         }
      }
    }
    else if(x1>x2&&y1<=y2){
       cout<<max(abs(x2-x1),y2-y1)<<endl;
      if(abs(x2-x1)>y2-y1){
        ll m= abs(x2-x1)- (y2-y1);
         while(m--){
          cout<<"L"<<endl;
         }
         m= min(abs(x2-x1),y2-y1);
         while(m--){
          cout<<"LU"<<endl;
         }
      }
       else{
        ll m= abs(abs(x2-x1)- (y2-y1));
         while(m--){
          cout<<"U"<<endl;
         }
         m= min(abs(x2-x1),y2-y1);
         while(m--){
          cout<<"LU"<<endl;
         }
      }
    }
    else if(x1<=x2&&y1>y2){
       cout<<max(x2-x1,abs(y2-y1))<<endl;
      if(x2-x1>abs(y2-y1)){
        ll m= (x2-x1)- abs(y2-y1);
         while(m--){
          cout<<"R"<<endl;
         }
         m= min(x2-x1,abs(y2-y1));
         while(m--){
          cout<<"RD"<<endl;
         }
      }
      else{
        ll m= abs((x2-x1)- abs(y2-y1));
         while(m--){
          cout<<"D"<<endl;
         }
         m= min(x2-x1,abs(y2-y1));
         while(m--){
          cout<<"RD"<<endl;
         }
      }
    }
    else if(x1>x2&&y1>y2){
      cout<<max(abs(x2-x1),abs(y2-y1))<<endl;
      if(abs(x2-x1)>abs(y2-y1)){
        ll m= abs(x2-x1)- abs(y2-y1);
         while(m--){
          cout<<"L"<<endl;
         }
         m= min(abs(x2-x1),abs(y2-y1));
         while(m--){
          cout<<"LD"<<endl;
         }
      }
      else{
        ll m= abs(abs(x2-x1)- abs(y2-y1));
         while(m--){
          cout<<"D"<<endl;
         }
         m= min(abs(x2-x1),abs(y2-y1));
         while(m--){
          cout<<"LD"<<endl;
         }
       }
     }
    

  return 0;
}  