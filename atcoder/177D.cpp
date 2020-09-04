#include <bits/stdc++.h>

using namespace std;

int n,m;
int p[200010];
int c[200010];
void init() {for (int i = 0; i < 200010; ++i) p[i] = i;}
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]);}
void merge(int x,int y) {p[find(y)] = find(x);}

int main() {
    
    init();

    cin >> n >> m;


    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        merge(a,b);
    }
    

    for (int i = 1; i <= n; ++i) {
        c[find(i)]++;
    }

    int ans = 0;

    for (int i = 1; i <= n ;++i)
        ans = max(c[i], ans);

    cout << ans << "\n";


    return 0;
}

