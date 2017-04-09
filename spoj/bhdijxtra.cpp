#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <functional>
using namespace std;

#define inf 1000000000

int SP[3003];

vector< vector< pair<int, int> > > X(3003);
priority_queue<pair<int, int> ,vector< pair<int, int> > ,greater< pair<int, int> > > Q;

void relax(int u, int v, int w)
{
    if(SP[v]>SP[u]+w)
    {
        SP[v] = SP[u] + w;
        Q.push(pair<int, int>(SP[v], v));
    }
}

int main() {
    
    int T;
    scanf("%d", &T);
    
    while(T--)
    {
        int N, M;
        scanf("%d %d", &N, &M);
        
        for(int i=1; i<=N; i++)
        {
            SP[i] = inf;
            X[i].clear();
        }
        
        while(M--)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            
            X[a].push_back(make_pair(b, c));
            X[b].push_back(make_pair(a, c));
        }
        
        int S;
        scanf("%d", &S);
        
        SP[S] = 0;
        Q.push(pair<int, int>(SP[S], S));
        
        while(!Q.empty())
        {
            pair<int, int> x = Q.top();
            int indx = x.second, dist = x.first;
            
            Q.pop();
              cout<<dist<<endl;
            if(SP[indx]<=dist)
            {
                for(vector< pair<int, int> >::iterator it=X[indx].begin(); it!=X[indx].end(); it++)
                    relax(indx, it->first, it->second);
            }
        }
        
        for(int i=1; i<=N; i++)
        {
            if(i==S)
                continue;
            
            if(SP[i]==inf)
                printf("-1 ");
            else
                printf("%d ", SP[i]);
        }
        
        printf("\n");
    }
    
    return 0;
}