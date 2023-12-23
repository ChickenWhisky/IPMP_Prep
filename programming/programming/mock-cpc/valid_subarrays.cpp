#include <bits/stdc++.h>
using namespace std;

bool chk[1000005];
int a[1000005];

int main() {
    int mx = -1;
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (chk[i])
            continue;
        int cnt = 1;
        int j = i - 1;
        int left = i;
        while (j >= 0 && a[j] % a[i] == 0)
        {
            left = j;
            j--;
            cnt++;
        }
        j = i + 1;
        while (j < n && a[j] % a[i] == 0)
        {
            chk[j] = 1;
            cnt++;
            j++;
        }
        if (cnt - 1 > mx)
        {
            mx = cnt - 1;
            v.clear();
            v.push_back(left+1);
        }
        else if (cnt - 1 == mx)
        {
            if(v[v.size()-1] != left + 1)
                v.push_back(left+1);
        }
    }
    
    cout << v.size() << " " << mx << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}
