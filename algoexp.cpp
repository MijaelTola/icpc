#include <bits/stdc++.h>

using namespace std;

int is[200010];

struct SegmentTreeMx {
    int n;
    vector<int> st;
    
    SegmentTreeMx() {}
    void build(int _) {
        st.resize(3 * _);
        n = _;
    }
    int op(int a, int b) {
        return max(a,b);
    }
    void update(int pos,int value){
        for (st[pos += n]= value; pos > 1; pos>>=1)
            st[pos>>1] = op(st[pos], st[pos ^ 1]);
    }

    int query(int l,int r){
        int ans = -1e9;
        r++;
        for (l += n,r += n;l < r;l >>= 1,r >>= 1){
            if(l & 1) ans = op(ans, st[l++]);
            if(r & 1) ans = op(ans, st[--r]);
        }
        return ans;
    }
};

struct SegmentTreeMn {
    int n;
    vector<int> st;
    
    SegmentTreeMn() {}
    void build(int _) {
        st.resize(3 * _, 1e9);
        n = _;
    }
    int op(int a, int b) {
        return min(a,b);
    }
    void update(int pos,int value){
        for (st[pos += n]= value; pos > 1; pos>>=1)
            st[pos>>1] = op(st[pos], st[pos ^ 1]);
    }
    // interval[l,r)
    int query(int l,int r){
        int ans = 1e9;
        r++;
        for (l += n,r += n;l < r;l >>= 1,r >>= 1){
            if(l & 1) ans = op(ans, st[l++]);
            if(r & 1) ans = op(ans, st[--r]);
        }
        return ans;
    }
};


SegmentTreeMx smx;
SegmentTreeMn smn;
vector<int> f(vector<int> v) {
    int n = v.size();
    bool flag = 1;
    is[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        flag &= v[i] <= v[i + 1];
        if(!flag) break;
        is[i] = flag;
    }
    
    if(flag) return {-1, -1};
    smx.build(n);
    smn.build(n);

    for (int i = 0; i < n; ++i) {
        smx.update(i, v[i]);
        smn.update(i, v[i]);
    }

    auto check = [&] (int l, int r) {
        if(!is[r] and r < n) return 0;
        int mx = smx.query(l + 1, r - 1);
        int mn = smn.query(l + 1, r - 1);
        int val = v[l];
        int val2 = v[r];
        if(val <= mn and mx <=  val2) {
            return 1;
        }
        return 0;
    };


    int ans = 1e9;
    int x = -1, y = -1;
    flag = 1;
    for (int i = 0; i < n; ++i) {
        if(i) flag &= v[i] >= v[i - 1];
        if(!flag) break;
        int a = i, b = n - 1;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(check(i, mid)) b = mid;
            else a = mid;
        }
        cout << i << ": " << b << " " << check(i, b) << "\n";
        if(check(i, b)) {
            int df = b - i;
            if(df < ans) {
                ans = df;
                x = i;
                y = b;
            }
        }
    }
    return {x, y};
}


int main() {

    vector<int> v = {1, 2, 4, 7, 10, 11, 7, 12, 6 , 7, 16, 18, 19};

    //vector<int> v = {1, 2, 4, 3, 7};
    auto ans = f(v);
    cout << ans[0] << " " << ans[1] << "\n";
    return 0;
}

