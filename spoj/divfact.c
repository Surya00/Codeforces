#include<stdio.h>
long long int inversemodulo(long long int n, long long int m){
 long long  int b= m-2;
 long long  int ans=1;
  while(b>0){
  	   if(b%2==1){
  	   	ans= (ans*n)%m;
  	   }
  	   n=((n%m)*(n%m))%m;
  	   b=b/2;
  }
    return ans;
}
long long int ncr(long long int n,int r,long long int m){
     long long int z=1,i,l;
    for(i=n; i>=(n-r+1); i--){
      z= (z*i)%m;
    }
    for(i=2; i<=r; i++){
      l= inversemodulo(i,m);
      z=(z*l)%m;
    }
    return z;
}
long long int main()
{
    long long int n,m,r,z;
    scanf("%d%d%d",&n,&r,&m);

    z= ncr(n,r,m);
    printf("%d\n",z );
  return 0;
}