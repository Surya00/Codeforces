#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main(){
   ll a,b,n,t,m,c,i,j,k,l;
     cin>>t;
      while(t--){
        cin>>n;
        ll A[n];
        ll bits[n][32];
        memset(bits, 0, sizeof(bits));

         for (i = 0; i <n; i++)
         {
            cin>>a;
            A[i]=a;
            j=0;
            while(a){
              bits[i][j++]=a%2;
              a=a/2;
            }
         }
          
          ll f1=0;
          ll f2=0;
          k= log2(n);

          for (i = 31; i>=0; i--)
          {
               f1=1;
             for (j = 0; j<=31; j++)
             {
                 f2=0;
                for (l= 0; l <n; l++)
                {
                   if(bits[l][j]==0&&bits[l][i]==1){
                    f2=1;
                  //  cout<<bits[l][j]<<" "<<bits[l][i]<<endl;

                    break;
                   }

                   if(j==i){
                    f2=1;
                   }
                   
                }
                if(!f2){
                 // cout<<i<<" "<<j<<" "<<l<<endl;
                  f1=0;
                  break;
                }
             }
             if(f1){
               
               break;
             }
          }
         if(f1){
          cout<<"YES"<<endl;
         }
         else{
          cout<<"NO"<<endl;
         }

      }
  
     
    return 0;
} 