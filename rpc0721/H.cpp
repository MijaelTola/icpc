#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,m;
    cin >> n >> m;

    priority_queue<int> si,no;
    for (int i = 0; i < m; ++i) {
        int a;
        char b;
        cin >> a >> b;
        if(b == 'y') si.push(-a);
        else no.push(-a);
    }


    for (int i = 1; i < 1000000; ++i) {
        int cnt = 0;

        while(cnt < n - 1 and !no.empty() and -no.top() >= i) {
            cnt++;
            no.pop();
        }
        if(!si.empty()) {
            if(-si.top() >= i) {
                si.pop();
            } 
        } else {
            if(!no.empty()) {
                if(-no.top() >= i) {
                    no.pop();
                } 
            } 
        }
    }

    if(no.empty() and si.empty()) cout << "Yes\n";
    else cout << "No\n";


    return 0;
}
