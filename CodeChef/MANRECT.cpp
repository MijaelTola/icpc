#include <bits/stdc++.h>

using namespace std;

int lim = 1000000000;
int tl, tr, br, bl, z;

int query(int x, int y) {
    printf("Q %d %d\n", x, y);
    fflush(stdout);
    scanf("%d", &z);
    assert(z >= 0);
    return z;
}

int manhattan(pair<int,int> a, pair<int,int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int ans(pair<int,int> a, pair<int,int> b) {
    if(manhattan(a,{0,0}) > manhattan(b,{0,0})) swap(a,b);
    printf("A %d %d %d %d\n", a.first, a.second, b.first, b.second);
    fflush(stdout);
    scanf("%d", &z);
    assert(z >= 0);
    return z;
}

int main() {
    
    int t;
    scanf("%d", &t);
    while(t--) {
        bl = query(0,0);
        br = query(lim,0);
        tr = query(lim, lim);
        tl = query(0,lim);
        int h = lim - br;
        int mn = min(h, bl);
        int mx = max(bl, h);
        int y = query((mn + mx) / 2, 0);
        h = lim - tl;
        mn = min(h, bl);
        mx = max(h, bl);
        int x = query(0, (mx + mn) / 2);
        assert(manhattan({0,0}, {x,y}) == bl);
        int y1 = y;
        int x1 = lim - (br - y1);
        int x2 = x;
        int y2 = lim - (tl - x2);
        ans({x,y},{x1,y2});
    }
    return 0;
}

