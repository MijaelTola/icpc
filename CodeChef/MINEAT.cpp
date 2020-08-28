#include <bits/stdc++.h>

using namespace std;

int v[100010];
int n,h;

bool ver(int k) {
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += v[i] / k;
        if(v[i] % k != 0) total++;
    }
    return total <= h;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> h;
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        int a = 0;
        int b = 1e9;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(ver(mid)) b = mid;
            else a = mid;
        }
        cout << b << "\n";
    }
    return 0;
}

