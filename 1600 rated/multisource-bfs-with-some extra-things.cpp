// https://codeforces.com/problemset/problem/1593/E

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#define trace1(x) cerr<<#x<<x<<endl
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
#define all(x) (x).begin(),(x).end()
#define int long long int
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define F first
#define S second
#define inf 1e18
#define vi vector<int>
#define Point complex<int>
#define X real()
#define Y imag()
#define pii pair<int,int>
#define num0Beg(x) __builtin_clz(x) // no. of zero in beginning of bit representation
#define num0end(x) __builtin_ctz(x) // no. of zero in the end
#define numOf1(x) __builtin_popcount(x) // no. of ones in bit rep.
#define parity(x) __builtin_parity(x) // parity of 1
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
const int N = 4e5 + 5; 
vector<int> adj[N];
int rem[N],tim[N];
int32_t main()
{
    FAST
    int tt=1;
    cin >> tt;
    while(tt--)
    {         
      int n,k;
      cin>>n>>k;
      for(int i=0;i<=n;i++)
        adj[i].clear(),rem[i]=0,tim[i]=0;
      for(int i=0;i<n-1;i++)
      {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        rem[u]++;
        rem[v]++;         
      }
      queue<int> q;
      for(int i=1;i<=n;i++)
        if(rem[i]==1)
          tim[i]=1,q.push(i); 
      while(!q.empty())
      {
        int x=q.front();
        q.pop();
        for(int to: adj[x])
        {
          if(rem[to]!=1)
          {
            rem[to]--;
            if(rem[to]==1)
            {
              tim[to]=tim[x]+1;  
              q.push(to);  
            }  
          }  
        }         
      }
      int ans=0;
      for(int i=1;i<=n;i++)
      {
        if(tim[i]>k)
          ans++;  
      }
      cout<<ans<<"\n";
    }
    return 0;
}
