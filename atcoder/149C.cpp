#include <bits/stdc++.h>

using namespace std;

int p[1000010];
vector<int> v;

int main() {
    
    for (int i = 2; i * i < 1000000; ++i) 
        for (int j = i + i; j < 1000000; j += i)
            p[j] = 1;

    for (int i = 2; i < 1000000; ++i)
        if(!p[i]) v.push_back(i);

    int x;
    cin >> x;
    
    int pos = lower_bound(v.begin(), v.end(), x) - v.begin();
    cout << v[pos] << "\n";
    return 0;
}

