#include <bits/stdc++.h>

using namespace std;

int b,n;
vector<pair<pair<int, int> , pair<int,bool> > > v;
bool mk[110][110];
int cnt[21];
bool check[30];
int val[21];
int main() {
    cin >> b;

    int sum = 0;
    for (int i = 0; i < b; ++i) {
       int x; cin >> x;
       if(x == 0) continue;
       val[i] = x;
       sum += x;
       v.push_back({{x,0},{i,0}});
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        for (int j = 0; j < x; ++j) {
            int p; cin >> p;
            p--;
            cnt[p]++;
            mk[i][p] = 1;
        }
    }
    
    for (int i = 0; i < (int)v.size(); ++i) {
        v[i].first.second = -cnt[v[i].second.first];
    }

    while(1) {
        sort(v.begin(), v.end());
        int id = 0;
        int pp = 0;
        while(check[v[id].second.first] and id < b) id++;
        id = v[id].second.first;
        bool flag = 0;
        for (int j = 0; j < (int)v.size(); ++j) {
            if(v[j].second.second) continue;
            if(mk[v[j].second.first][id]) {
                v[j].second.second = 1;
                for (int i = 0; i < 20; i++)
                    cnt[i] -= mk[j][i];
                flag = 1;
            }
        }
        
        for (int j = 0; j < (int)v.size(); ++j) {
            v[j].first.second = -cnt[v[j].second.first];
        }
        if(flag) sum -= val[id];
        else break;
        check[id] = 1;
    }
    cout << sum << "\n";
    return 0;
}

