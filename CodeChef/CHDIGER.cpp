#include <bits/stdc++.h>

using namespace std;

int d,t;
string n;
int mn[20];

int main() {
    cin >> t;
    while(t--) {
        for (int i = 0; i < 20; ++i)
            mn[i] = 1e9;
        cin >> n >> d;
        int cur = 1e9;
        for (int i = n.size() - 1; i >= 0; i--) {
            if(n[i] != '0') cur = min(cur, min(n[i] - '0',d));
            mn[i] = cur;
        }
        
        int cnt = 0;
        for (int i = 0; i < (int)n.size(); ++i) {
            if(n[i] - '0' <= mn[i]) cout << n[i];
            else cnt++;
        }
        while(cnt--) cout << d;
        cout << "\n";
     
    }   
    return 0;
}

