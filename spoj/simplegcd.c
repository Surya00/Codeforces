#include<stdio.h>
long long int gcd(long long int a,long long int b){
	long long int gd;
	if (b==0)
	{
	   return a;
	}
  return gcd(b,a%b);


}
main(){
	long long int i,j,t,k,a,b,c;
     scanf("%lld",&t);
for ( i = 0; i < t; ++i)
{
	scanf("%lld%lld%lld",&a,&b,&c);
	 k= gcd(a,b);
	 if(c>a&&c>b){
	 	printf("NO\n");
	 }
	 else{
	 	if(c%k==0){
	 	printf("YES\n");
	 }
	 else{
	 	printf("NO\n");
	 }
	 	}
	 
}

}