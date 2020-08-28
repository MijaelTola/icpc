#include <bits/stdc++.h>

using namespace std;

struct node {
    long long sum;
    long long mps;
};

int n,m;
node st[4000010];
int val[1000010];
int v[1000010];
int curp[1000010];
vector<int> vpos[1000010];

void update(int nd, int left, int right, int pos, int value) {
    if(left == right) {
        st[nd].sum = value;
        st[nd].mps = value;
        return;
    }

    int mid = (left + right) / 2;
    if(pos <= mid) update(2 * nd, left, mid, pos, value);
    else update(2 * nd + 1, mid + 1, right, pos, value);
    st[nd].sum = st[2 * nd].sum + st[2 * nd + 1].sum;
    st[nd].mps = max(st[2 * nd].mps, st[2 * nd].sum + st[2 * nd + 1].mps);
}   

int main() {
    
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        vpos[v[i]].push_back(i);
    }

    for (int i = 1; i <= m; ++i) {
        cin >> val[i];
        if(vpos[i].size()) update(1,0,n,vpos[i][0], val[i]);
        if(vpos[i].size() >= 2) update(1, 0, n, vpos[i][1], -val[i]);
    }

    long long ans = st[1].mps;
    for (int i = 1; i < n; ++i) {
        int id = v[i - 1];
        int curPos = vpos[id][curp[id]];
        update(1, 0, n, curPos, 0);
        curp[id]++;
        if(curp[id] < (int)vpos[id].size()) {
            curPos = vpos[id][curp[id]];
            update(1, 0, n, curPos, val[id]);
        }

        if(curp[id] + 1 < (int)vpos[id].size()) 
            update(1, 0, n, vpos[id][curp[id]+ 1], -val[id]);
        
        ans = max(ans, st[1].mps);
    }
    cout << ans << "\n";
    return 0;
}

