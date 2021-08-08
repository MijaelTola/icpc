#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int q;
        cin >> q;
        multiset<int> s;
        stack<int> st;

        while(q--) {
            int a;
            cin >> a;
            if(a == 1) {
                int x;
                cin >> x;
                st.push(x);
                s.insert(x);
            }

            if(a == 2) {
                if(st.empty()) continue;
                s.erase(s.lower_bound(st.top()));
                st.pop();
            }

            if(a == 3) {
                if(st.empty()) cout << "Empty!\n";
                else cout << *s.rbegin() - *s.begin() << "\n";
            } 
            //cout << st.size() << "\n";
        }
    }

    return 0;
}

