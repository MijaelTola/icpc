#include <bits/stdc++.h>

using namespace std;

int t,n,q;
int v[100010];
int st[300010];

void update(int pos,int value){
	for (st[pos+=n]= value; pos > 1; pos>>=1)
		st[pos>>1] = st[pos] + st[pos^1]; 
}

// interval[l,r)
int query(int l,int r){
	int ans = 0;
	r++;
	for (l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1) ans += st[l++];
		if(r&1) ans += st[--r];
	}
	return ans;
}

int main() {
    
    scanf("%d", &t);

    while(t--) {
        memset(st, 0, sizeof st);
        memset(v, 0, sizeof v);
        scanf("%d %d", &n, &q);

        for (int i = 0; i < n; ++i) 
            scanf("%d", v + i);

        vector<pair<pair<int,int>, pair<int,int> > > queries, lines;

        for (int i = 0; i < q; ++i) {
            int l,r,h;
            scanf("%d %d %d", &l, &r, &h);
            queries.push_back({{h, i}, {l, r}});
        }

        for (int i = 1; i < n; ++i) 
            lines.push_back({{min(v[i], v[i - 1]), max(v[i], v[i - 1])}, {i - 1, i}});

        sort(lines.begin(), lines.end());
        sort(queries.begin(), queries.end());

        
        set<pair<int,int> > s;
        vector<pair<int,int> > ans;
        int pos = 0;
        for (auto p: queries) {
            while(lines[pos].first.first <= p.first.first and pos < n - 1) {
                s.insert({lines[pos].first.second, lines[pos].second.second});
                update(lines[pos].second.second, 1);
                pos++;
            }

            while(s.size() and (*s.begin()).first < p.first.first) {
                update((*s.begin()).second, 0);
                s.erase(*s.begin());
            }
            ans.push_back({p.first.second, query(p.second.first, p.second.second - 1)});
        }
        
        sort(ans.begin(), ans.end());

        for (auto p: ans)
            printf("%d\n", p.second);

    }
    return 0;
}

