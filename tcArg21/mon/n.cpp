#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;

    unordered_map<string, vector<int>> mp;

    for (int i = 0; i < (int)s.size(); ++i) {
        string cur = "";
        for (int j = i; j < i + 4; ++j) {
            cur += s[j];
            mp[cur].push_back(i);
        }
    }
    return 0;
}

