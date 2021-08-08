#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {

        int n;
        cin >> n;

        unordered_map<int,int> mp;

        for (int i =0; i < n; ++i) {
            string s;
            cin >> s;
            for (auto c: s)
                mp[c]++;
        }

        bool flag = 1;
        for (auto [a,b]: mp)
            flag &= b % n == 0;

        puts(flag ? "YES" : "NO");
    }
    return 0;
}

