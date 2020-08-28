#include <bits/stdc++.h>

using namespace std;

int main(){
    int w,n;
    cin >> w >> n;
    int t = 0;
    for (int i = 0; i < n; ++i) {
        int dw,dl; cin >> dw >> dl;
        t += (dw * dl);
    }
    cout << t / w << "\n";
    return 0;
}

