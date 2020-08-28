#include <bits/stdc++.h>

using namespace std;

int cnt[1000010];
int v[1000010][50];
int ans[1000010];
int f(int x) {
    string number = "";
    int y = x;
    int p = 0;
    int nd = log10(x) + 1;
    for (int i = 0; i < nd; ++i) {
        int d = y % 10;
        p = p * 10 + d;
        y /= 10;
    }
    for (int i = 0; i < nd; ++i) {
        int d = p %10;
        char z = (char)(d + '0');
        number += z;
        p /= 10;
    }
    
    while(number.size() < 6) number = "0" + number;
    int a = 0;
    for (int i = 0; i < 3; ++i) 
        a += (int)(number[i] - '0');
    for (int i = 3; i < 6; ++i)
        a -= (int)(number[i] - '0');
    return abs(a);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for (int i = 0; i <= 1000000; ++i)
        v[i][cnt[i] = f(i)] = 1;

    for (int i = 1; i <= 1000000; ++i) 
        for (int j = 0; j < 37; ++j) 
            v[i][j] += v[i - 1][j];

    for (int i = 0; i <= 1000000; ++i) 
        for (int j = cnt[i] - 1; j >= 0; j--)
            ans[i] += v[i][j];
    
    int q;
    cin >> q;
    while(q--) {
        int x; 
        cin >> x;
        cout << ans[x] << "\n";
    }
    return 0;
}
