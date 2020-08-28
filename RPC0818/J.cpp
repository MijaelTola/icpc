#include <bits/stdc++.h>

using namespace std;

int a[100010];
int b[100010];
long long da[3];
long long db[3];

int n;

int main() {
    
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int i = 0; i < n; ++i) {
        da[i % 3] += a[i];
        db[i % 3] += b[i];
    }
    
    long long ans1 = db[1] * da[0] + db[2] * da[2] + db[0] * da[1];
    long long ans2 = db[2] * da[0] + db[1] * da[1] + db[0] * da[2];
    long long ans3 = db[0] * da[0] + db[1] * da[2] + db[2] * da[1];
    cout << ans1 << " " << ans2 << " " << ans3 << "\n";
    return 0;
}

