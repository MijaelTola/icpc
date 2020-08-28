#include <bits/stdc++.h>

using namespace std;

int n;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    priority_queue<int> a,b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push(x);
        b.push(-x);
        cout << a.top() - b.top() << "\n";
    }
    return 0;
}

