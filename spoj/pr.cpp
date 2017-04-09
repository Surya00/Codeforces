#include<bits/stdc++.h>
#include<time.h>
using namespace std;
#define ll long long int
double time_taken;
clock_t start, end;
long long int P[1229];
void shieve(){
	  
	  
     long long int i,j,k,count=0;
       
    for(i=2; i<10000; i++){
    	k=0;

    	for(j=2; j<=(int)sqrt(i); j++){
            if(i%j==0){
            	k=1;
            }
    	}
    	if(k!=1){
    		P[count++]=i;

         
    	} }
    
}
   
int main(int argc, char const *argv[])
{
	ll i,j,k,n,m,s,t,l,x,a;
     shieve();
	
	start =  clock();
	
	   cin>>n;

            x=0;
    for (i =0; (i<1229&&P[i]<=n); i++)
     {
         s=0;
       
             if(x>=1){
             	cout<<"*";
             }
                 a=n;
            while(a){
            	a=a/P[i];
            	s=s+a;
            }
            x++;	
         
         if(s!=0){
         	cout<<P[i]<<"^"<<s;
         }
 	
       }
       cout<<"\n";
   
    end= clock();

    time_taken= ((double)(end-start))/CLOCKS_PER_SEC;
   // cout<<time_taken<<" SEC time taken by this code\n";
	return 0;
}
