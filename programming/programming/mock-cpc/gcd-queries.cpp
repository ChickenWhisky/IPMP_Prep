#include <bits/stdc++.h>
#define int long long
#define gcd __gcd
#define mod 1000000007
#define endl '\n' 
using namespace std;

class node{
    public:
        int parent,gcd_value;
        node()
        {
            parent = -1;
            gcd_value = 0;
        }
        node(int parent,int gcd_value)
        {
            this->parent = parent;
            this->gcd_value = gcd_value;
        }
};

void dfs(int ver,int parent,vector<int> adj[],vector<vector<node>>&par,int val[],int dis[])
{
    par[ver][0] = {parent, gcd(val[ver],(parent==-1? 0 : val[parent]))};
    if(parent!=-1)
    {
        dis[ver] = 1 + dis[parent];
    }
    for(int i : adj[ver])
    {
        if(i!=parent)
        {
            dfs(i,ver,adj,par,val,dis);
        }
    }
}

int find_ans(int a,int b,vector<vector<node>>&par,int dis[],int val[])
{
    if(dis[a]<dis[b])
    {
        swap(a,b);
    }
    int diff = dis[a] - dis[b];
    int bit = 0,ans = 0;
    while(diff)
    {
        if(diff&1)
        {
            ans = gcd(ans,par[a][bit].gcd_value);
            a = par[a][bit].parent;
        }
        bit++;
        diff >>= 1;
    }
    if(a==b)
    {
        return ans;
    }
    for(int i = 31;i>=0;i--)
    {
        if(par[a][i].parent!=par[b][i].parent)
        {
            ans = gcd(ans,gcd(par[a][i].gcd_value,par[b][i].gcd_value));
            a = par[a][i].parent;
            b = par[b][i].parent;
        }
    }
    return gcd(ans,val[par[a][0].parent]);
}

void solve()
{
    int n,q;
    cin>>n>>q;
    int val[n],dis[n];
    for(int i = 0;i<n;i++)
    {
        cin>>val[i];
    }
    vector<int> adj[n];
    for(int i = 0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<node>> par(n,vector<node>(32));
    dis[0] = 0;
    dfs(0,-1,adj,par,val,dis);
    for(int dis = 1;dis<32;dis++)
    {
        for(int i = 0;i<n;i++)
        {
            if(par[i][dis-1].parent!=-1)
            {
                par[i][dis] = { par[par[i][dis-1].parent][dis-1].parent,
                                gcd(par[i][dis-1].gcd_value, par[par[i][dis-1].parent][dis-1].gcd_value)};
            }
        }
    }

    while(q--)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        cout<<find_ans(a,b,par,dis,val)<<endl;
    }
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
} 

