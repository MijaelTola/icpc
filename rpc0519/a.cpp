#include <bits/stdc++.h>

using namespace std;

bool b[110];
bool g[110];

int h,w;
int main() {
    cin >> h >> w;

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j) {
            char x; cin >> x;
            b[j] |= x != '.';
            if(i == h - 1) g[j] |= (x != '.');
        }
    ;
    int l = 0, r = w - 1;
    while(!g[l]) l++;
    while(!g[r]) r--;
    int cur = r - l + 1;
    int dl = 0, dr = 0;
    l = 0, r = w - 1;
    while(!g[l]) dl += b[l], l++;
    while(!g[r]) dr += b[r], r--;
    if(dl > cur) cout << "left\n";
    else if(dr > cur) cout << "right\n";
    else cout << "balanced\n";
    return 0;
}

