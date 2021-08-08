#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int dp[(1 << 24) + 10];
int can[(1 << 24) + 10];

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

int main() {
    
    int n = in();

    vector<int> v(n);

    for (auto &x: v) 
        x = in();

    int t = in();

    vector<int> b;

    for (int i = 0; i < t; ++i) {
        int x = in();
        b.push_back(x);
    }

    auto is = [&] (int x) {
        for (int y: b)
            if(x == y) return 1;
        return 0;
    };
    
    dp[(1 << n) - 1] = 1;

    for (int i = (1 << n) - 2; i >= 0; i--) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if(!(i & (1 << j))) {
                sum += v[j];
                dp[i] += dp[i | (1 << j)];
                dp[i] %= mod;
            }
        }
        if(is(sum)) dp[i] = 0;
    }

    printf("%d\n", dp[0]);
    return 0;
}


