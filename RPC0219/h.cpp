#include <bits/stdc++.h>

using namespace std;

int n;
bool can[20];
vector<string> v[20];

bool ver(string t, string s) {
    if(t.size() > s.size()) return 0;
    for (int i = t.size() - 1, p = s.size() - 1; i >= 0 and p >= 0; i--, p--) 
        if(t[i] != s[p]) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string p; 
        getline(cin, p);
        string cur = "";
        for (char x: p) {
            if(x != ' ') cur += x;
            else {
                can[i] |= ver(cur, s);
                v[i].push_back(cur);
                cur = "";
            }
        }
        can[i] |= ver(cur, s);
        v[i].push_back(cur);
    }
    
    int t; cin >> t;
    cin.ignore();
test:
    while(t--) {
        string p; 
        getline(cin, p);
        string cur = "";
        string last = "";
        for (char x: p) 
            if(x != ' ') cur += x;
            else {
                if(cur != "") last = cur;
                cur = "";
            }
        if(cur != "") last = cur;
        cur = last;
        for (int i = 0; i < n; ++i) {
            for (string x: v[i]) {
                if(ver(x,cur) and can[i]) {
                    cout << "YES\n";
                    goto test;
                }
            }
        }
        cout << "NO\n";
    }
    return 0;
}

