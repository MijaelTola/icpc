#include <bits/stdc++.h>

using namespace std;

int v[1000010];
int n;

int f(int cur) {
    int last = cur;
    int mn = cur;
    for (int i = 0; i < n; ++i) {
        int dif = v[i] - last;
        mn = min(dif, mn);
        last = dif;
    }
    return mn;
}

int f2(int cur) {
    int last = cur;
    int mn = cur;
    for (int i = 0; i < n; ++i) {
        int dif = abs(v[i] - last);
        cout << dif << "lol\n";
        mn = min(dif, mn);
        last = dif;
    }
    return mn;
}
int main() {
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    int a1 = f(0);
    cout << a1 << "\n";
    cout << max(f2(abs(a1)) + 1, 0) << "\n";
    return 0;
}

