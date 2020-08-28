#include <bits/stdc++.h>

using namespace std;
int t,n,k;
int v[2010];
int st[4*2010];
int val[2010];
vector<int> oc[2010];

long long findM(int d) {
    long long a = -1, b = 1e9;
    while(b - a > 1) {
        long long mid = (a + b) / 2;
        if((long long)mid * d >= k) b = mid;
        else a = mid;
    }
    return b;
}

long long findK(int sz, int m) {
    long long a = 0, b = sz;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(mid * m <= k) b = mid; 
        else a = mid;
    }
    return b;
}

void update(int pos, int value){
    for (st[pos+=n]= value; pos > 1; pos>>=1)
        st[pos>>1] = st[pos] + st[pos^1]; 
}

int query(int l,int r){
    int ans = 0; r++;
    for (l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) ans += st[l++];
        if(r&1) ans += st[--r];
    }
    return ans;
}

long long f(int dk) {
    int a = 0, b = n;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(query(1, mid) >= dk) b = mid;
        else a = mid;
    }
    return b;
}

bool solve(int i, int j) {
    int sz = (j - i + 1);
    long long m = findM(sz);
    long long dk = findK(sz, m);
    int pos = f(dk);
    int l = lower_bound(oc[pos].begin(), oc[pos].end(), i) - oc[pos].begin();
    int r = upper_bound(oc[pos].begin(), oc[pos].end(), j) - oc[pos].begin(); 
    r--;
    int f = r - l + 1;
    int dl = lower_bound(oc[f].begin(), oc[f].end(), i) - oc[f].begin();
    int dr = upper_bound(oc[f].begin(), oc[f].end(), j) - oc[f].begin(); 
    return dr - dl > 0;
}

int main() {

    scanf("%d", &t);

    while(t--) {
        for (int i = 0; i < 2010; ++i) {
            oc[i].clear();
            st[i] = val[i] = 0;
        }

        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", v + i);
            oc[v[i]].push_back(i);
        }
        bool flag = 1;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            if(i) {
                val[v[i - 1]]--;
                update(v[i - 1], val[v[i - 1]]);
            }
            if(flag) {
                for (int j = i; j < n; ++j) {
                    val[v[j]]++;
                    update(v[j], val[v[j]]);
                    ans += solve(i,j);
                }
            } else {
                for (int j = n - 1; j >= i; j--) {
                    if(j + 1 < n) {
                        val[v[j + 1]]--;
                        update(v[j + 1], val[v[j + 1]]);
                    }
                    ans += solve(i, j);
                }
            }
            flag = !flag;
        }
        assert(ans >= n);
        printf("%lld\n", ans);
    }
    return 0;
}

