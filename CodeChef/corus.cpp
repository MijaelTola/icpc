#include <bits/stdc++.h>

using namespace std;

char s[100010];

int main() {
    
    int t;
    scanf("%d", &t);

    while(t--) {
        int n,q;
        scanf("%d %d %s", &n, &q, s);
        vector<int> a(26);

        for (int i = 0; i < n; ++i)
            a[s[i] - 'a']++;

        while(q--) {
            int c;
            scanf("%d", &c);

            int ans = 0;

            for (int i = 0; i < 26; ++i) {
                ans += max(0, a[i] - c);
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}

