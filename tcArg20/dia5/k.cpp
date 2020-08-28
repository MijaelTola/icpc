#include <bits/stdc++.h>

using namespace std;

int  main() {

    long long  n,m;
    cin >> n >> m;

    vector<pair<long long, long long> > seg(n);
    vector<pair<pair<long long, long long>, long long > > v;
    vector<pair<pair<long long, long long>, pair<long long, long long> > > b;
    vector<long long> a(m);

    for (auto &p: seg)
        cin >> p.first >> p.second;

    for (auto &x: a)
        cin >> x;

    multiset<pair<long long,long long> > h;
    for (long long  i = 0; i < m; ++i)
        h.insert({a[i], i});

    sort(a.begin(), a.end());
    
    for (long long  i = 1; i < (long long)seg.size(); ++i) 
        v.push_back({{seg[i].first - seg[i - 1].second, seg[i].second - seg[i - 1].first}, i});
    
    sort(v.begin(), v.end());
    for (auto p: v) {
        long long l = p.first.first;
        long long r = p.first.second;
        b.push_back({{l, r}, {r, p.second}});
    }

    sort(b.begin(), b.end());
    
    vector<pair<long long ,long long > > ans;

    for (auto p: b) {
        long long l = p.first.first;
        long long r = p.first.second;
        long long id = p.second.second;
        auto t = *h.lower_bound(make_pair(l, 0));
        long long sz = t.first;
        long long id2 = t.second;
        if(sz <= r) {
            ans.push_back({id, id2 + 1});
            h.erase(h.lower_bound(t));
        }
    }

    if((long long )ans.size() != n - 1) return cout << "No\n", 0;
    
    cout << "Yes\n";
    sort(ans.begin(), ans.end());
    for (auto x: ans)
        cout << x.second << " ";
    cout << "\n";
    return 0;
}

