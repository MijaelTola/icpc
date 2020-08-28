#include <bits/stdc++.h>

using namespace std;

int n;
int v[110];
int b[110];
void print() {
    for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;

    while(getline(cin, s)) {
        vector<int> ans;
        n = 0;
        int cur = 0;
        for (char x: s) {
            if(x != ' ') cur = cur * 10 + (int)(x - '0');
            else {
                v[n] = cur;
                b[n++] = cur;
                cur = 0;
            }
        }
        if(cur) {
            v[n] = cur;
            b[n++] = cur;
        }
        print();
        sort(b, b + n);
        reverse(b, b + n);
        
        int to = n - 1;
        for (int i = 0; i < n; ++i) {
            int c = b[i];
            int id = 0;
            while(v[id] != c) id++;
            if(id == to) {
                to--;
                continue;
            }
            if(id == 0) {
                reverse(v, v + to + 1);
                ans.push_back(to);
                to--;
                continue;
            }
            ans.push_back(id);
            ans.push_back(to);
            reverse(v, v + id + 1);
            reverse(v, v + to + 1);
            to--;
        }
        for (int x: ans)
            cout << n - x  << " ";
        cout << "0\n";
    }

    return 0;
}

