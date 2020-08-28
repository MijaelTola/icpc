#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        string s;
        cin >> s;
        queue<int> a1,a2;
        for (char x: s) {
            if(x != '4') {
                a1.push(x - '0');
                a2.push(0);
            } else {
                a1.push(2);
                a2.push(2);
            }
        }
        
        while(a1.front() == 0 and a1.size() > 1) a1.pop();
        while(a2.front() == 0 and a2.size() > 1) a2.pop();
        cout << "Case #" << i << ": ";
        while(!a1.empty()) {
            cout << a1.front();
            a1.pop();
        }
        cout << " ";

        while(!a2.empty()) {
            cout << a2.front();
            a2.pop();
        }
        cout << "\n";
    }
    return 0;
}

