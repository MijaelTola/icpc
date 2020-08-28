#include <bits/stdc++.h>

using namespace std;

vector<long long> v;
int main(){

    long long n;
    int k;
    cin >> n >> k;
    int c = 0;
    for (int i = 0; i < 61; ++i) 
        if(n &  (1LL << i)) c++;

    if(c < k) {
        for (int i = 0; i < 61 and c < k; ++i) {
            if(!(n & (1LL << i))) {
                c++;
                n ^= (1LL << i);
            }
        }
    } else {
        int p = 60;
        while(!(n & (1LL << p))) p--;
        long long ans = 0;
        if(p == c) {
            cout << "lol\n";
            ans = (1 << (p + 1));
            for (int i = 0; i < k - 1; ++i) 
                ans ^= (1LL << i);
        } else {
            cout << "lel\n";
            ans = (1LL << p);
            p--;
            while(!(n & (1LL << p))) p--;
            ans = (1LL << p);
            for (int i = 0; i < k - 2; ++i) 
                ans ^= (1LL << i);
        }
        n = ans;
    }
    cout << n << "\n";
    return 0;
}

