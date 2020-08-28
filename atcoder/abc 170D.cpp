#include <bits/stdc++.h>

using namespace std;

int v[1000010];
bool is[100010];

int main() {
    
    int n;
    cin >> n;


    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[x]++;
    }

    for (int i = 2; i * i < 1000010; ++i) {
        if(!v[i]) continue;
        long long cur = 0;
        for (int j = i + i; j < 1000010; ++j) {
            if(v[j]) cur += v[j] * v[i];
        }
    }

    return 0;
}

