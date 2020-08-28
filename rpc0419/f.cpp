#include <bits/stdc++.h>

using namespace std;

int n,x,y;
unsigned long long m;
vector<pair<long long, long long> > v;

bool ver(unsigned long long days) {
    unsigned long long win = 0;
    for (int i = 0; i < n; ++i) {
        long long won = days * v[i].first - v[i].second;
        if(won > 0) win += won;
        if(win >= m) return 1;
    }
    return win >= m;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) 
        cin >> x >> y, v.push_back({x,y});

    long long a = -1;
    unsigned long long b = 1e10 + 2;
    
    while(b - a > 1) {
        unsigned long long mid = (a + b) / 2;
        if(ver(mid)) b = mid;
        else a = mid;
    }
    cout << b << "\n";
    return 0;
}

