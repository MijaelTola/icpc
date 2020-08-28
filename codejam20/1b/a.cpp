#include <bits/stdc++.h>

using namespace std;

map<tuple<int,int,int>, int> dp;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
char mv[]= {'E','W','N','S'};
int xx,yy;

tuple<int,int,int> get(int a, int b, int c) {
    return tuple<int,int,int> {a,b,c};
}
bool f(int x, int y, int k) {
    if(x == xx and yy == y) return 1;
    if(dp.count(get(x,y,k))) return dp[get(x,y,k)];
    bool ans = 0;
    for (int i = 0; i < 4; ++i) {
        long long u = dx[i] * (1 << k) + x;
        long long v = dy[i] * (1 << k) + y;
        if(u >= -100 and u <= 100 and v >= -100 and v <= 100) {
            ans |= f(u,v,k +1);
        }
    }
    dp[get(x,y,k)] = ans;
    return ans;
}

void r(int x,int y, int k) {
    if(x == xx and yy == y) return;

    for (int i = 0; i < 4; ++i) {
        long long u = dx[i] * (1 << k) + x;
        long long v = dy[i] * (1 << k) + y;
        if(u >= -100 and u <= 100 and v >= -100 and v <= 100) {
            if(f(u,v,k +1)) {
                cout << mv[i];
                r(u,v,k+1);
                break;
            }
        }
    }
}
int main() {
    

    int t;
    cin >> t;
    while(t--) {
        dp.clear();
        cin >> xx >> yy;
        cout << f(0,0,0) << "\n";
        r(0,0,0);
        cout << "\n";
    }
    return 0;
}

