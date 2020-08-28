#include <bits/stdc++.h>

using namespace std;

int R,S,P,L;
long long dp[110][110][110];

long long f(int r, int s, int p) {
    
    if(r and !s and !p and (L == 0 or L == 3)) return 1;
    if(!r and s and !p and (L == 1 or L == 3)) return 1;
    if(!r and !s and p and (L == 2 or L == 3)) return 1;

    long long &ans = dp[r][s][p];
    if(ans != -1) return ans;
    ans = 0;
    if(r) ans += f(r - 1, s, p) * p * r;
    if(s) ans += f(r, s - 1, p) * s * r;
    if(p) ans += f(r, s, p - 1) * s * p;

    return ans;
}

void clear() {
    for (int i = 0; i < 110; ++i)
        for (int j = 0; j < 110; ++j)
            for (int k = 0; k < 110; ++k)
                dp[i][j][k] = -1;
}

int main() {
    
    cin >> R >> S >> P;

    L = 0;
    clear();
    long double dr = f(R, S, P);
    L = 1;
    clear();
    long double ds = f(R, S, P);
    L = 2;
    clear();
    long double de = f(R, S, P);
    L = 3;
    clear();
    long double total = dr + ds + de;
    //cout << dr << " " << ds << " " << de << " " << total << "\n";
    cout << dr / total << " " << ds / total << " " << de / total << "\n";
    return 0;
}

