#include <bits/stdc++.h>

using namespace std;

int n,p;
string s;

int modpow(int a, int b, int n){
    long long x = 1, y = a; 
    while (b > 0) {
        if (b % 2 == 1) x = (x * y) % n; 
        y = (y * y) % n; 
        b /= 2;
    }
    return x % n;
}

int main() {

    cin >> n >> p >> s;

    int cur = 0;
    int ans = 0;
    map<int,int> mp;
    for (int i =  n - 1; i >= 0; --i) {
        int d = s[i] - '0';
        cur = (d * 10 + cur) % p;
        ans += cur == 0;
        mp[cur]++;
    }
    
    ans += mp[0];
    
    int pp = 1;

    for (int i = 0; i < n - 1; ++i)
        pp = (pp * 10) % p;

    for (int i = 0; i < n; i++) {
        int d = s[i] - '0';
        int dv = (d * pp) % p;
        map<int,int> mp2;

        mp = mp2;
        ans += mp[0];
        pp = (pp * 10) % p;
    }
   
    cout << ans << "\n";
    return 0;
}

