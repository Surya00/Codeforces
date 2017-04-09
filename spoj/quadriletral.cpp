int t;
   cin>>t;
   while(t--){
     int n;
     cin>>n;
     int A[n];
     ll count=0;
     for (int i = 0; i < n; ++i)
     {
       cin>>A[i];
     }
     sort(A,A+n);
     for (int i = 0; i < n; ++i)
     {
       for (int j = i+1; j <n; j++)
       {
         for (int k = j+1; k <n; k++)
         {
            ll x= A[i]+A[j]+A[k];
            ll y= lower_bound(A+k,A+n,x)-A;
           // if(t==4){ cout<<y<<endl;}
            y--;
            count+=(y-k);
         }
       }
     }
    // cout<<count<<endl;
     ll y= n*(n-1)*(n-2)*(n-3);
     ll d= 24LL;
     y=y/d;
     if(y==0){ cout<<"0/1"<<endl; continue; }
    // count=count/d;
     d= __gcd(y,count);
     y=y/d;
     count=count/d;
     cout<<count<<"/"<<y<<endl;
   }