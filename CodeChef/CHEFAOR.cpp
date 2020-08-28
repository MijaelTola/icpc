#include <bits/stdc++.h>

using namespace std;

long long dp[5010][5010];
int val[5010][5010];
int v[5010];

int cost(int l, int r) {
    return val[l][r];
}

void f(int g, int i, int j, int l, int r) {
    if(i > j) return;

    int mid = (i + j) / 2;
    int bestIndex = l;

    for (int k = l; k <= min(r, mid); ++k) {
        long long val = dp[k - 1][g - 1] + cost(k, mid);
        if(val > dp[mid][g]) {
            dp[mid][g] = val;
            bestIndex = k;
        }
    }
    
    f(g,i, mid - 1, l, bestIndex);
    f(g, mid + 1, j, bestIndex, r);
}

int in () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int t,n,k,x;

int main() {
    
    t = in();
    while(t--) {
    
        n = in();
        k = in();

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= k; ++j)
                dp[i][j] = 0;

        for (int i = 1; i <= n; ++i) 
            v[i] = in();
        
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j) {
                val[i][j] = v[j];
                val[i][j] |= val[i][j - 1];
            }
    
        dp[0][0] = 0;

        for (int i = 1; i <= k; ++i)
            f(i, 1, n, 1, n);

        printf("%lld\n", dp[n][k]);
    }
    return 0;
}

