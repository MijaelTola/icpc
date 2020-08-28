#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,x;
    cin >> n;

    priority_queue<int> q;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        q.push(-x);
    }
    int ans = 0;
    int k = 1;
    while(!q.empty()) {
        if(-q.top() >= k) {
            k++;
            ans++;
        }
        q.pop();
    }

    cout << ans << "\n";
    return 0;
}

