#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

ll minOperations(vector<ll>& v, ll x) {
    sort(v.begin(),v.end());

    //for (auto &val : nums) cout << val << " ";

    int m = v[v.size() / 2], ans = 0;

    for(int i : v) {
        if(abs(i - m) % x) return -1;
        ans += abs(i - m);
    }
    return ans / x;
}

int main() {
    ll n, m;
    cin >> n >> m;
    
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    
    cout << minOperations(a,m) << endl;
    return 0;
}
