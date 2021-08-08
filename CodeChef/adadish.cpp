#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> v(n);

        for (int &x: v)
            cin >> x;

        sort(v.rbegin(), v.rend());
        
        priority_queue<int> q;
        int pos = 0;
        int ans = 0;
        for (int time = 0; time <= 100; ++time) {
            while(!q.empty() and -q.top() <= time) q.pop();

            while(q.size() < 2 and pos < n) {
                //cout << time << " " << v[pos] << endl;
                q.push(-(time + v[pos]));
                ans = max(ans, time + v[pos]);
                pos++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

