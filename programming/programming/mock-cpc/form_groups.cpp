#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int>parent,size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    void merge(int u,int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(size[ulp_u] <= size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int solve(vector<string>&arr){
    int n = arr.size();
    DSU ds(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            string s = arr[i];
            string t = arr[j];
            int count = 0;
            for(int k=0;k<s.size();k++){
                if(s[k] != t[k]){
                    count++;
                }
            }
            if(count <= 2){
                ds.merge(i,j);
            }
        }
    }
    set<int>st;
    for(int i=0;i<n;i++){
        st.insert(ds.find(i));
    }
    return st.size();
}

int main(){
    int k;
    cin>>k;
    int n;
    cin>>n;
    vector<string>arr(n);
    for(auto &i : arr)cin>>i;
    cout<<solve(arr);
    return 0;
}
