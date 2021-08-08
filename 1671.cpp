#include <bits/stdc++.h>

using namespace std;

int p[200010];
int can[200010];
void init(){for (int i = 0; i < 200010; ++i) p[i] = i;}
int f(int x) {return x == p[x] ? x : p[x] = f(p[x]);}
void merge(int x, int y) {p[f(x)] = f(y);}

int main() {
    init();
    int n,m;
    cin >> n >> m;
    vector<pair<int,int> > e;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        e.push_back({x,y});
    }


    int k;
    cin >> k;

    vector<int> q;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        x--;
        q.push_back(x);
        can[x] = 1;
    }

    int cur = n;
    for (int i = 0; i < m; ++i) {
        if(!can[i]) {
            if(f(e[i].first) != f(e[i].second)) cur--;
            merge(e[i].first, e[i].second);
        }
    }
    
    vector<int> ans;

    for (int i = q.size() - 1; i >= 0; i--) {
        int x = q[i];
        ans.push_back(cur);
        if(f(e[x].first) != f(e[x].second)) cur--;
        merge(e[x].first, e[x].second);
    }

    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    cout << "\n";


    return 0;
}

