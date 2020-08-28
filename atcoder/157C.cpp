#include <bits/stdc++.h>

using namespace std;

int d[10];
int main() {
    memset(d, -1, sizeof d);
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int s,c;
        cin >> s >> c;
        s--;
        if(d[s] != -1 and d[s] != c) return puts("-1"), 0;
        d[s] = c;
    }
    
    for (int i = 0; i < 1000000; ++i) {
        string x = to_string(i);
        if(x.size() != n) continue;
        bool flag = 1;
        for (int j = 0; j < (int)x.size(); ++j) 
            flag &= (x[j] == d[j] + '0' or d[j] == -1);
        if(flag) return cout << i << "\n", 0;
    }
    cout << -1 << "\n";
    return 0;
}

