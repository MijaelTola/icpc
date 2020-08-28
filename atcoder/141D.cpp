#include <bits/stdc++.h>

using namespace std;

int n,m;

int main() {
    cin >> n >> m;
    
    priority_queue<int> q;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        q.push(x);
    }
    
    while(m--) {
        int u = q.top();
        q.pop();
        q.push(u / 2);
    }
    
    long long ans = 0;
    while(!q.empty()) {
        ans += q.top();
        q.pop();
    }
    cout << ans << "\n";
    return 0;
}

