#include <bits/stdc++.h>

using namespace std;

long long m[1010][1010];

int main() {
    
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lld", &m[i][j]);
        }
    }
    vector<long long> ans;
    
    ans.push_back(sqrt((m[0][1] * m[0][2]) / m[1][2]));
    
    for (int i = 1; i < n; ++i) 
        ans.push_back(m[0][i] / ans[0]);

    for (auto x: ans)
        printf("%lld ", x);
    puts("");
    return 0;
}

