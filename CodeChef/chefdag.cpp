#include <bits/stdc++.h>

using namespace std;

int t,n,k,x;
vector<int> v[110], G[110];
int dp[1 << 21];

//5 6
//5 3 2 1 4
//5 2 3 1 4
//5 1 2 3 4
//5 3 1 2 4
//5 2 1 3 4
//5 1 3 2 4

int main() {
    

    scanf("%d", &t);

    while(t--) {
        
        
        scanf("%d %d", &n, &k);

        for (int i = 0; i < k; ++i) 
            v[i].clear();

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &x);
                x--;
                v[i].push_back(x);
            }
        }
        
    }

    return 0;
}

