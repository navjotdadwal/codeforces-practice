// https://codeforces.com/problemset/problem/1594/D

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
 
const int N = 5e5 + 5;
vector<pii> adj[N];
vector<int> color(N);
int col[2];
void dfs(int v,int p,bool &ok,int x)
{
  color[v]=x;
  col[x]++;
  for(auto it: adj[v])
  {
    int to=it.F,val=it.S;
    if(color[to]==-1)
    {
      dfs(to,v,ok,x^val);  
    }  
    else 
    {
      if(color[to]==color[v] && val==1)
        ok=false;
      else if(color[to]!=color[v] && val==0)
        ok=false;  
    }
  }
}
int32_t main()
{
    FAST
    int tt=1;
    cin >> tt;
    while(tt--)
    {         
      int n,m;
      cin>>n>>m;
      col[0]=col[1]=0;
      for(int i=0;i<=n;i++)
        adj[i].clear(),color[i]=-1;
      for(int i=0;i<m;i++)
      {
        int u,v;
        string s;
        cin>>u>>v>>s;
        if(s=="imposter")
        {
          adj[u].pb({v,1});
          adj[v].pb({u,1});
        }  
        else 
        {
          adj[u].pb({v,0});
          adj[v].pb({u,0});
        }
      }             
      bool ok=true;
      int ans=0;
      for(int i=1;i<=n;i++)
      {
        if(color[i]==-1)
        {
          col[0]=col[1]=0;
          dfs(i,0,ok,0);
          ans+=max(col[0],col[1]);  
        }  
      }
      if(!ok)
        cout<<"-1\n";
      else 
        cout<<ans<<"\n";
    }
    return 0;
}
