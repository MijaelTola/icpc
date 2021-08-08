#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
int ans[(2 << 16) + 10];
int id[(2 << 16) + 10];

void find(int node, int l, int r) {
    if(l == r) {
        ans[node] = a[l];
        id[node] = l + 1;
        return;
    }

    int mid = (l + r) / 2;
    find(2 * node, l, mid);
    find(2 * node + 1, mid + 1, r);

    if(ans[2 * node + 1] > ans[2 * node]) {
        ans[node] = ans[2 * node + 1];
        id[node] = id[2 * node + 1];
    } else {
        ans[node] = ans[2 * node];
        id[node] = id[2 * node];
    }
}

int main() {
    
    cin >> n;
    
    for (int i = 0; i < (1 << n) ; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }


    find(1, 0, (1 << n) - 1);

    if(ans[2] < ans[3]) cout << id[2] << "\n";
    else cout << id[3] << "\n";
    
    return 0;
}

