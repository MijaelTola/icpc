#include <bits/stdc++.h>

using namespace std;


double v[100010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n and n) {
        for (int i = 0; i < n; ++i) 
            cin >> v[i];
        sort(v,v + n);
        int mid = n / 2;
        cout.precision(1);
        cout << fixed;
        if(n & 1) {
            cout << (double)v[mid] << "\n";
        }else {
            cout << (double)(v[mid] + v[mid - 1]) / 2.0 << "\n";
        }

    }
    return 0;
}

