#include <bits/stdc++.h>

using namespace std;

int a[110];
int main() {
    int n,m;
    cin >> n;
    vector<pair<int,int> > v(n);
   
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v.push_back(make_pair(a[i],-i));
    }
    cin >> m;
    sort(v.rbegin(), v.rend());

    auto res = [&v] (int k, int posicion) {
        vector<int> b;
        for (int i = 0; i < k; ++i)  {
            b.push_back(-v[i].second);
        }
        
        sort(b.begin(), b.end());


        return a[b[posicion - 1]];
    };

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        cout << res(x,y) << endl;
    }
    return 0;
}

