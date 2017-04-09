#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(int argc, char const *argv[])
{        ll i,j,k,l,a,b,c,n,z;
         cin>>n;
         ll A[n];
         for (i = 0; i < n; i++)
         {
            cin>>A[i];
         }

         vector< string > set;
         vector< string > unset;
         

         for (i = 0; i <n; i++)
         {    string s,r;
              cin>>s;
              set.push_back(s);

              for (j= 0; j <s.length(); j++)
              {
                 r=  s[j]+ r;
              }
              unset.push_back(r);
         }

         ll cost[2][n];
           cost[0][0]= 0;
           cost[1][0]= A[0];

          for (i = 1; i <n; i++)
          {
              int f=0;
               a= 100000000000000;
               b= 100000000000000;
             if(set[i-1]<=set[i]){
              a= cost[0][i-1]; 
               f=1;
               //cout<<" mai hu 1"<<endl;
             }
             if(unset[i-1]<=set[i]){
              b= cost[1][i-1]; 
               f=1;
               // cout<<" mai hu 2"<<endl;
             }
              cost[0][i]= min(a,b);

               a= 100000000000000;
               b= 100000000000000;
             if(set[i-1]<=unset[i]){
               // cout<<unset[i]<<endl;
              a= cost[0][i-1]+A[i]; 
               f=1;
               // cout<<" mai hu 3"<<endl;
             }
             if(unset[i-1]<=unset[i]){
              b= cost[1][i-1]+A[i]; 
               f=1;
               // cout<<" mai hu 4"<<endl;
             }
               cost[1][i]= min(a,b);
              if(f==0){
                cout<<-1;
                return 0;
              }

          }
                     z=min(cost[0][n-1], cost[1][n-1]);
            if(z==100000000000000){
              cout<<-1;

            }
            else{
              cout<<z;
            }
    return 0;
}