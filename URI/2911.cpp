#include <bits/stdc++.h>

using namespace std;

vector<int> G[100010];
int n;

int f(int u, int level) {
    
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        G[x].push_back(i);
    }
    return 0;
}

