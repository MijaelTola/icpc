#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int t;
    cin >> t;
    
    bool flag = 0;

    deque<char> q;
    
    for (char x: s)
        q.push_back(x);

    while(t--) {
        int c;
        cin >> c;
        if(c == 1) flag = !flag;
        else {
            int x;
            char y;
            cin >> x >> y;
            if(x == 1) {
                if(!flag) q.push_front(y);
                else q.push_back(y);
            } else {
                if(flag) q.push_front(y);
                else q.push_back(y);
            }
        }
    }

    string ans = "";

    while(!q.empty()) {
        ans += q.front();
        q.pop_front();
    }

    if(flag) reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    return 0;
}

