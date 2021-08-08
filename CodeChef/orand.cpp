#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> a,b;
set<int> ans;
int AND[1000010];
int XOR[1000010];
int vis[1000010];
int INV[1000010];

void f(int num) {
    if(ans.count(num)) return;
    ans.insert(num);
    for (int i = 0; i < 31; ++i) {
        if(num & (1 << i) and AND[num & (1 << i)]) {
            f(num ^ (1 << i));
        }
    }

    int dnum = num;
    for (int i = 0; i < 32; ++i) 
        dnum = (dnum ^ (1 << i));
}


void gen(int num) {
    if(XOR[num]) return;
    XOR[num] = 1;
    for (int i = 31; i >= 0; --i) {
        if(num & (1 << i))
            gen(num ^ (1 << i));
    }
}

int main() {

    int x = 31;

    while(x > 0) {
        cout << bitset<6> (x) << "\n";
        x -= (x & -x);
    }

    exit(0);
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m;
        a.clear();
        b.clear();

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
            gen(x);
        }

        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            b.push_back(x);
            AND[x] = 1;
        }

        for (int i = 0; i < n; ++i) {
            f(a[i]);
        }
        ans.insert(0);
        cout << ans.size() << "\n";
    }
    return 0;
}

