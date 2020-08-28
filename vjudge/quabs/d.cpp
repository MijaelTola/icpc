#include <bits/stdc++.h>

using namespace std;

int n,s;
int v[100001];

long long f(int k) {
    priority_queue<long long> q;
    for (int i = 0; i < n; ++i)
        q.push(-(v[i] + 1ll*(i + 1) * k));
    
    long long sum = 0;

    while(k--) {
        sum += -q.top();
        q.pop();
    }
    return sum;
}

int main() {
    
    cin >> n >> s;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int a = 0, b = n + 1;

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(f(mid) <= s) a = mid;
        else b = mid;
    }

    cout << a << " " << f(a) << "\n";
    return 0;
}

