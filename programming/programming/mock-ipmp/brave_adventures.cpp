#include <bits/stdc++.h>
using namespace std;


int par[100005];
int sz[100005];

int findPar(int u){
  if(par[u] == u)return u;
  return par[u] = findPar(par[u]);
}

void connect(int u, int v){
  u = findPar(u);
  v = findPar(v);
  if(v == u)return;
  
  if(sz[u] > sz[v]){
    par[v] = u;
    sz[u] += sz[v];
  }else{
    par[u] = v;
    sz[v] += sz[u];
  }
}


void solve(int n, vector<vector<int>> edges)
{

sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b){
    return a[0] < b[0];
  });
  
  //create the dsu;
  for(int i=0; i<=n; i++){
    par[i] = i;
    sz[i] = 1;
  }
  
  long long ans = 0;
  for(auto ed : edges){
    int w = ed[0], u = ed[1], v = ed[2];
      if(findPar(u) == findPar(v))continue;
      ans += 1LL*w*sz[findPar(u)]*sz[findPar(v)];
      connect(u, v);
    
  }
  
  cout<<ans<<endl;
}

int main() {
  int n;cin>>n;
  vector<vector<int>> edges;
  for(int i=0; i<n-1; i++){
    int u, v, w;
    cin>>u>>v>>w;
    edges.push_back({w, u, v});
  }
  
  solve(n,edges);

  return 0;
}

/*
  *6    1    *7
*2    2    4   *4
    3        5
*/
