#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    string s;
    cin >> n >> s;

    if((int)s.size() > 26) return cout << "-1\n", 0;
    
    set<char> st;

    for (auto x: s)
        st.insert(x);
    cout << s.size() - st.size() << "\n";
    return 0;
}

