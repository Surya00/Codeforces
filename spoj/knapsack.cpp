#include <bits/stdc++.h>
using namespace std;


int main() {
     int i,j,k,l,a,b,c,x,y,z,t,n,m;
     cin>>t;
    while(t--){
        cin>>n>>m;  
        set<int > st;
          
        while(n--){
            cin>>a;
            st.insert(a);
            }
         b= st.size();
  
        int A[b][m+1];
          set < int > :: iterator it;
        i=0;
        for(it=st.begin(); it!=st.end(); it++){
            
            for(j=0; j<m+1; j++){
               if(i==0){
                   A[i][j]= (j/(*it))*(*it);
               }
                else{
                    if(j<*it){
                        A[i][j]= A[i-1][j];
                    }
                    else{
                        c= *it;
                    A[i][j]= max(c+ A[i][j-c],A[i-1][j]);
                    }
                 
                }
                 
            }
            i++;
        }
        
        cout<<A[b-1][m]<<endl;
        
    }
    
    
    return 0;
}
