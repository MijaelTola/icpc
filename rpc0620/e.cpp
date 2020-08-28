#include <bits/stdc++.h>

using namespace std;

vector<string> ans[2];
int main() {

    string s;
    getline(cin, s);

    int k = 1;

    for (int i = 0; i < (int)s.size(); ++i)
        if(s[i] == ' ') k++;


    int n;
    cin >> n;
    
    queue<string> q;
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        q.push(x);
    }
    
    bool turn = 0;
    while(!q.empty()) {
        for (int i = 0; i < k - 1; ++i) {
            q.push(q.front());
            q.pop();
        }

        ans[turn].push_back(q.front());
        q.pop();
        turn = 1 - turn;
    }

    for (int i = 0; i < 2; ++i) {
        cout << ans[i].size() << "\n";
        for (auto x: ans[i]) 
            cout << x << "\n";
    }
    return 0;
}

