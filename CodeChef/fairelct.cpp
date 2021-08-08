#include <bits/stdc++.h>

using namespace std;

int main() {
        
    int t;
    cin >> t;

    while(t--) {
        int n,m;
        cin >> n >> m;

        priority_queue<int> a,b;

        long long da = 0, db = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            da += x;
            a.push(-x);
        }

        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            db += x;
            b.push(x);
        }
        
        int ans = 0;
        while(da <= db and -a.top() < b.top()) {
            ans++;
            int aa = -a.top();
            int bb = b.top();
            a.pop();
            b.pop();
            da -= aa; da += bb;
            db += aa; db -= bb;
            a.push(-bb);
            b.push(aa);
        }
        if(da > db) cout << ans << "\n";
        else cout << "-1\n";
    }
    return 0;
}

