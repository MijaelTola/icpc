#include <bits/stdc++.h>

using namespace std;

stack<int> a,b;
vector<int> v;

int main() {

    int n;
    cin >> n;


    for (int i = 0; i < 2 * n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = v.size() - 1; i >= 0; --i)
        a.push(v[i]);

    int ans = 0;


    while(!a.empty()) {

        while(!a.empty() and !b.empty() and a.top() == b.top()) {
            a.pop();
            b.pop();
            ans++;
        }
        if(a.empty()) break;
        ans++;
        b.push(a.top());
        a.pop();
    }

    if(a.size() or b.size()) return cout << "impossible\n", 0;
    cout << ans << "\n";
    return 0;
}

