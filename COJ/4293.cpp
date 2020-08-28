#include <bits/stdc++.h>

using namespace std;

int v[1000010];
long long ans;
vector<int> f(int l, int r) {
    if(l > r) return {};
    if(l == r) return {v[r]};
    int mid = (l + r) / 2;
    vector<int> left = f(l, mid);
    vector<int> right = f(mid + 1, r);
    int a = 0;
    int b = 0;
    vector<int> c;
    while(a < (int)left.size() and b < (int)right.size()) {
        if(left[a] <= right[b]) c.push_back(left[a++]);
        else {
            ans += left.size() - a;
            c.push_back(right[b++]);
        }
    }

    if(a < (int)left.size()) {
        while(a < int(left.size())) 
            c.push_back(left[a++]);
    }
    if(b < (int)right.size()) {
        while(b < int(right.size())) 
            c.push_back(right[b++]);
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n and n) {
        ans = 0;
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        vector<int> l = f(0, n - 1);
        cout << ans << "\n";
    }
    return 0;
}

