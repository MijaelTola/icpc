#include <bits/stdc++.h>

using namespace std;

int n,m,x,y;
int vis[100010];
vector<pair<int,int> > v;

int main() {
    scanf("%d %d", &n, &m);

    int l = 1, r = n;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        l = max(l, x);
        r = min(r, y);
    }
    
    printf("%d\n", max(0,r - l + 1));
    return 0;
}

