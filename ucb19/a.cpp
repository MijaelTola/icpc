#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int v[110];

bool cmp(int a, int b) {
    return n % a < n % b;
}

int main() {
        
    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 0; i < m; ++i)
            cin >> v[i];

        sort(v, v + m, cmp);

        for (int i = 0; i < m; ++i)
            cout << v[i] << " ";
        cout << "\n";

        int ans = 0;
        for (int i = 0; i < k; ++i) {
            if(n % v[i] != 0) {
                ans += n % v[i];
                n -= (n % v[i]);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

