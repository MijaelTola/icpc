#include <bits/stdc++.h>

using namespace std;

int m[110][110];
int main() {
    
    int t;
    scanf("%d", &t);

    int k = 1;
    while(t--) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &m[i][j]);

        int sum = 0;

        for (int i = 0; i < n; ++i)
            sum += m[i][i];
        
        int r = 0, c = 0;
        for (int i = 0; i < n; ++i) {
            set<int> s;

            for (int j = 0; j < n; ++j)
                s.insert(m[i][j]);

            if((int)s.size() != n) r++;
            s.clear();

            for (int j = 0; j < n; ++j)
                s.insert(m[j][i]);

            if((int)s.size() != n) c++;
        }
        
        printf("Case #%d: %d %d %d\n", k++, sum, r, c);

    }
    return 0;
}

