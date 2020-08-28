#include <bits/stdc++.h>

using namespace std;

int ans[200000];

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    stack<int> st;
    memset(ans, 0,sizeof ans);
    int last = 0;
    int cur = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if(isdigit(s[i])) cur = cur * 10 + (s[i] - '0');
        else {
            if(!st.empty())
                ans[cur] = st.top();
            if(s[i] == '(') {
                if(cur != 0) st.push(cur);
                else st.push(last);
            } else {
                last = st.top();
                st.pop();
            }
            cur = 0;
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}

