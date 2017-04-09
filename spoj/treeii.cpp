/*#include <bits/stdc++.h> 
using namespace std ;
#define ll long long int
#define MOD 1000000007
struct TrieNode{
  bool data;
  struct TrieNode* A[2];
};
ll ans=0;
struct TrieNode* createnewNode(){
     struct TrieNode* newnode= (struct TrieNode*)malloc(sizeof( struct TrieNode));
        newnode->data= false;
        newnode->A[0]= NULL;
        newnode->A[1]= NULL;
   return newnode;
}

void findMaxXor(string s,struct TrieNode* head){
       ll j=0; 
     while(head!=NULL){
        if(head->A[(s[j]-'0'+1)%2]!=NULL){
           ans=ans*2+ (s[j]-'0'+1)%2;
           head=head->A[(s[j]-'0'+1)%2];
           cout<<(s[j]-'0'+1)%2<<" ";
         }
        else if(head->A[s[j]-'0']!=NULL){
          ans= ans*2+(s[j]-'0');
          head=head->A[s[j]-'0'];
          cout<<(s[j]-'0')<<" ";
        }
        else{ head= NULL; }
        j++;
     }
}

void addNewNode(struct TrieNode* head, string s){
    ll j=0;
    while(j<s.length()){
       if(head->A[s[j]-'0']!=NULL){
          head=head->A[s[j]-'0'];
          cout<<(s[i]-'0')<<" ";
       }
       else{ 
         struct TrieNode* newnode= createnewNode();
         head->A[s[j]-'0']=newnode;
         head= head->A[s[j]-'0'];
         cout<<(s[i]-'0')<<" after"
       }
       j++;
    }
}

string makeString(ll n){
   string s;
   ll j=0;
   while(j<30){
     if(n%2==0){ s='0'+s; }
     else{ s='1'+s;}
     n=n/2;
     j++;
   }
   return s;
}


int main()
{
   struct TrieNode* head= createnewNode();
   ll n;
   cin>>n;
   for (int i = 0; i < n; i++)
   {
       ll x;
       cin>>x;
       string s=makeString(x);
       cout<<s<<" ";
       addNewNode(head,s);
       ans=0;
       findMaxXor(s,head);
       cout<<ans<<endl;
   }

   
 return 0;
}*/