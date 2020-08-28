#include <bits/stdc++.h>

using namespace std;

int main() {

    int m, n;
    cin >> m >> n;
    vector<int> a(m), b(n);
    
    for (int &x: a) 
        cin >> x;

    for (int &x: b)
        cin >> x;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long sa = accumulate(a.begin(), a.end(), 0LL), sb = accumulate(b.begin(), b.end(), 0LL);
    long long a1 = sa, a2 = sb;

    for (int i = 0; i < n - 1; ++i) 
        a1 += min(sa, 1LL*b[i]);	

    for (int i = 0; i < m - 1; ++i) 
        a2 += min(sb, 1LL*a[i]);

    cout << min(a1, a2) << endl;

    return 0;
}

