#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    deque<int> q;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        q.push_back(x);
    }

    int a = 0, b = 0, turn = 1;

    while(!q.empty()) {
        int val = -1;
        if(q.front() > q.back()) {
            val = q.front();
            q.pop_front();
        } else {
            val = q.back();
            q.pop_back();
        }

        if(turn) a += val;
        else b += val;
        turn = 1 - turn;
    }

    cout << a << " " << b << "\n";
    return 0;
}

