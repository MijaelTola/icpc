#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

stack<long long> s;

long long getN(string s) {
    long long ans = 0;
    for (char x: s)
        ans = ans * 10 + (x - '0');
    return ans;
}

int main() {
    int n;
    cin >> n;
    int c = 0;
    long long y = 0;

    while(n--) {
        string x;
        cin >> x;
        y %= mod;
        if(x == "(") {
            c++;
            s.push(y);
            if(c & 1) y = 1;
            else y = 0;
            continue;
        } else if(x == ")") {
            c--;
            long long val = s.top();
            s.pop();
            if(c % 2 == 0) {
                val += y;
                y = val;
                y %= mod;
            } else {
                val *= y;
                y = val;
                y %= mod;
            }
            continue;
        }
        long long cur = getN(x);
        if(c % 2 == 0) y += cur;
        else y *= cur;
        y %= mod;
    }
    cout << y % mod<< "\n";
    return 0;
}

