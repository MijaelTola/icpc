#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    cin >> s;

    stack<char> st;

    for (auto c: s) {
        if(st.empty()) st.push(c);
        else if(c == st.top()) st.pop();
        else st.push(c);
    }

    if(st.empty()) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

