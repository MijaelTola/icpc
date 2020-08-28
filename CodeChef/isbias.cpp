#include <bits/stdc++.h>

using namespace std;

int n,q;
int v[100010];

int main() {

    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    int p1 = 1;
    int p2 = 1;
    vector<pair<int,int> > in, de;

    for (int i = 1; i <= n; ++i) {
        if(v[i] > v[i - 1]) {}
        else {
            if(p1 != i - 1)in.emplace_back(p1, i - 1);
            p1 = i;
        }
        if(i - 1 == 0) v[i - 1] = 1e9;
        if(v[i] < v[i - 1]) {}
        else {
            if(p2 != i - 1)de.emplace_back(p2, i - 1);
            p2 = i;
        }
    }
    if(p1 != n) in.emplace_back(p1, n);
    if(p2 != n) de.emplace_back(p2, n);
    
    while(q--) {
        int l,r;
        cin >> l >> r;
        p1 = lower_bound(in.begin(), in.end(), make_pair(l, 0)) - in.begin();
        p2 = lower_bound(in.begin(), in.end(), make_pair(r, 0)) - in.begin();
        if(p1 and in[p1 - 1].second > l) p1--; 
        int a1 = p2 - p1;
        if(p2 == (int)in.size())p2--;
        p1 = lower_bound(de.begin(), de.end(), make_pair(l, 0)) - de.begin();
        p2 = lower_bound(de.begin(), de.end(), make_pair(r, 0)) - de.begin();

        if(p1 and de[p1 - 1].second > l) p1--; 
        int a2 = p2 - p1;
        if(p2 == (int)de.size())p2--;
        puts(a1 == a2 ? "YES" : "NO");
    }
   
    return 0;
}

