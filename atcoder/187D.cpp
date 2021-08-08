#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> v[200010];

int main() {
 
    for (int i = 0; i < 200010; ++i)
        v[i].first = v[i].second = 0;
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        long long x,y;
        cin >> x >> y;
        v[i].first = x + y;
        v[i].second = x;
    }

    sort(v, v + n);
    reverse(v, v + n);

    for (int i = n - 1; i >= 0; i--) 
        v[i].second += v[i + 1].second;

    for (int i = 0; i < n; i++) 
        v[i].first += v[i - 1].first;

    for (int i = 0; i < n; ++i) {
        if(v[i].first > abs(v[i + 1].second)) {
            return cout << i + 1 << "\n", 0;
        }
    }

    assert(1);
    return 0;
}

