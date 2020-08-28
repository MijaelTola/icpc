#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<int> v[11];

int main() {
    cin >> n >> s;
    
    for (int i = 0; i < n; ++i) 
        v[s[i] - '0'].push_back(i);
    
    int ans = 0;
    for (int i = 0; i < 100; ++i) {
        string x = to_string(i);
        while(x.size() < 2) x = "0" + x;
        int a = 0, b = 0;

        while(a < n and b < (int)x.size()) {
            if(s[a] == x[b]) a++, b++;
            else a++;
        }

        if(a == n) continue;
        
        for (int i = 0; i < 10; ++i) {
            if(!v[i].size()) continue;
            int l = -1, r = v[i].size();
            while(r - l > 1) {
                int mid = (l + r) / 2;
                if(v[i][mid] >= a) r = mid;
                else l = mid;
            }
            ans += (r < (int)v[i].size());
        }
    }
    cout << ans << "\n";
    return 0;
}

