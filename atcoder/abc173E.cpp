#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {

    int n,k;
    cin >> n >> k;
    priority_queue<int> a,b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x < 0) b.push(-x);
        else a.push(x);
    }

    long long ans = 1;

    if(k > (int)a.size() and (int)a.size()) {
        int left = k - a.size();
        if(left & 1) {
            while(k > 0 and b.size() >= 2 and !a.empty()) {
                long long x = -b.top();
                b.pop();
                long long y = -b.top();
                b.pop();
                k -= 2;
                ans *= (x * y) % mod;
                ans %= mod;
            }
            
            while(k and !a.empty()) {
                k--;
                ans *= a.top();
                ans %= mod;
                a.pop();
            }

            priority_queue<int> bb;

            while(!b.empty()) {
                bb.push(-b.top());
                b.pop();
            }


            while(k and !bb.empty()) {
                k--;
                ans *= bb.top();
                ans += mod;
                ans %= mod;
                bb.pop();
            }

            cout << (ans + mod) % mod<< "\n";
            return 0;
        }

    }
    while(k and !a.empty() and b.size() >= 2) {
        if(b.size() >= 2 and k >= 2) {
            long long x = -b.top();
            b.pop();
            long long y = -b.top();
            b.pop();
            if(x * y >= a.top()) {
                k -= 2;
                ans *= (x * y) % mod;
                ans %= mod;
            } else {
                b.push(x);
                b.push(y);
                k--;
                ans *= a.top();
                a.pop();
                ans %= mod;
            }

        } else {
            ans *= a.top();
            ans %= mod;
            k--;
        }
    }

    while(k and !a.empty()) {
        k--;
        ans *= a.top();
        ans %= mod;
        a.pop();
    }

    priority_queue<int> bb;

    while(!b.empty()) {
        bb.push(-b.top());
        b.pop();
    }


    while(k and !bb.empty()) {
        k--;
        ans *= bb.top();
        ans += mod;
        ans %= mod;
        bb.pop();
    }

    cout << ans << "\n";

    return 0;
}

