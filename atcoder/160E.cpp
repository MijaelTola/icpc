#include <bits/stdc++.h>

using namespace std;

int main() {

    int l,r,a,b,c;
    cin >> l >> r >> a >> b >> c;

    priority_queue<int> da, db,dc;

    for (int i = 0; i < a; ++i) {
        int x;
        cin >> x;
        da.push(-x);
    }

    for (int i = 0; i < b; ++i) {
        int x;
        cin >> x;
        db.push(-x);
    }

    for (int i = 0; i < c; ++i) {
        int x;
        cin >> x;
        dc.push(-x);
    }

    while((int)da.size() > l) da.pop();
    while((int)db.size() > r) db.pop();

    while(!dc.empty()) {
        if(-dc.top() <= -db.top() and -dc.top() <= -da.top()) {
            dc.pop();
            continue;
        }

        if(-dc.top() > -db.top() and -dc.top() > -da.top()) {
            if(-db.top() < -da.top()) {
                db.pop();
                db.push(dc.top());
                dc.pop();
            } else {
                da.pop();
                da.push(dc.top());
                dc.pop();
            }
            continue;
        }

        if(-dc.top() > -db.top()) {
            db.pop();
            db.push(dc.top());
            dc.pop();
            continue;
        }

        if(-dc.top() > -da.top()) {
            da.pop();
            da.push(dc.top());
            dc.pop();
        }
    }

    long long ans = 0;

    while(!da.empty()) {
        ans += -da.top();
        da.pop();
    }

    while(!db.empty()) {
        ans += -db.top();
        db.pop();
    }
    cout << ans << "\n";
    return 0;
}

