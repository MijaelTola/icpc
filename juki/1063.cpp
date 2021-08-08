#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e15 + 318157;

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(__int128 x, __int128 y) { return x > y; }

int main() {
    
    int n;
    cin >> n;

    priority_queue<__int128> q;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        q.push(x);
    }

    while(q.size() > 2) {
        auto a = q.top();
        q.pop();
        auto b = q.top();
        q.pop();
        q.push(((a * b) % mod - (a - 1) - (b - 1) + mod) % mod);
    }

    print(q.top());
    puts("");
    return 0;
}

