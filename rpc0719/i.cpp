#include <bits/stdc++.h>

using namespace std;

int n;
int h[1010];
int v[1010];

bool ver(int k) {
    for (int i = 0; i < n; ++i) 
        if(h[i] + k > v[i]) return 1;
        else if(h[i] + k < v[i]) return 0;
    return 1;
    
}
int main() {
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> h[i];

    for (int i = 0; i < n; ++i)
        cin >> v[i];


    int a = -1, b = 1000;

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) b = mid;
        else a = mid;
    }
    cout << b << "\n";
    return 0;
}

