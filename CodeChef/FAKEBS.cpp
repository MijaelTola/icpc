#include <bits/stdc++.h>

using namespace std;

int v[100010];
int b[100010];
int n,q;

int bs(pair<int,int> p) {
    int x = p.first;
    int low = 0;
    int high = n - 1;
    int mid = -1;
    int M = 0;
    int m = 0;

    while(low <= high) {
        mid = (low + high) / 2;
        if(mid == x) break;
        else if(mid < x) {
            if(v[mid] > v[x]) M++;
            low = mid + 1;
        } else {
            if(v[mid] < v[x]) m++;
            high = mid - 1;
        }
    }

    int big = n - p.second - 1 - M;
    int small = p.second - m;
    int rest = min(M,m);
    int ans = rest;
    M -= rest;
    m -= rest;
    if(M and M > small) return -1;
    if(m and m > big) return -1;
    ans += m;
    ans += M;
    return ans;   
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> q;
        map<int,pair<int,int> > mp;
        for (int i = 0; i < n; ++i)  {
            cin >> v[i];
            mp[v[i]].first = i;
            b[i] = v[i];
        }
        sort(b,b + n);

        for (int i = 0; i < n; ++i) 
            mp[b[i]].second = i;
        
        while(q--) {
            int x; cin >> x;
            pair<int,int> p = mp[x];
            if(n != 2) {
                cout << bs(p) << "\n";
            }else {
                if(x == v[0]) cout << "0\n";
                else cout << "1\n";
            }
        }
    }
    return 0;
}

