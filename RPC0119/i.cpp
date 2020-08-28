#include <bits/stdc++.h>

using namespace std;

int n,k;
bool cnt[100000010];
int a[1000100];
int s[1000100];
vector<pair<int,int> > v;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(b.second == a.second) return a.first < b.first;
    if(b.second > a.second) return 0;
    return 1;
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        cnt[a[i]] = 1;
    }

    for (int i = 0; i < k; ++i) 
        scanf("%d", s + i);

    sort(a, a + n);
    
    for (int i = 0; i < k; ++i) {
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if(a[j] >= s[i]) break;
            int dif = abs(a[j] - s[i]);
            if(dif == a[j] or dif > 100000000) continue;
            ans += cnt[dif];
        }
        v.push_back(make_pair(s[i], ans / 2));
    }
    sort(v.begin(), v.end(), cmp);
    for (pair<int,int> p: v)
        cout << p.first << " " << p.second << "\n";

    return 0;
}

