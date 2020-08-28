#include <bits/stdc++.h>

using namespace std;

bool is[10000010];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    is[0] = is[1] = 1;
    for (int i = 2; i * i < 10000010; ++i) 
        for (int j = i * i; j < 10000010; j += i)
            is[j] = 1;
    int n;
    string s;
    while(cin >> n >> s) {
        int pos = 0;
        bool flag = 1;
        while(pos < (int)s.size()) {
            int next = pos + n;
            int cur = 0;
            for (; pos < next; pos++) 
                cur = cur * 10 + (int)(s[pos] - '0');
            flag &= !is[cur];
        }
        if(flag) cout << ":)\n";
        else cout << ":(\n";
    }
    return 0;
}

