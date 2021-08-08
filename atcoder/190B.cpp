#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,s,d;
    cin >> n >> s >> d;


    bool flag = 0;
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        flag |= (x < s and y > d);
    }

    if(flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

