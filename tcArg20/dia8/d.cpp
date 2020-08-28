#include <bits/stdc++.h>

using namespace std;

int p[1000010];
int v[1000010];
priority_queue<int> q[1000010];

void init() {for (int i = 0; i < 1000010; ++i) p[i] = i;}
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]);}
void merge(int x, int y) {p[find(y)] = find(x);}

int main() {

    init();
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        x--, y--;
        if(find(x) != find(y)) {
            merge(x,y);
        }
    }

    for (int i = 0; i < n; ++i) 
        q[find(i)].push(v[i]);

    for (int i = 0; i < n; ++i) {
        cout << q[find(i)].top() << " ";
        q[find(i)].pop();
    }
    
    cout << "\n";

    return 0;
}

