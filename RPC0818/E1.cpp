
#include <bits/stdc++.h>

using namespace std;

int b, n, c, total;
int in1[10010];
int price[10010];
int prestige[10010];
pair<int,int>  dp[10010][10010];
map<string,int> mp;
vector<pair<int,pair<int,int> > > G[10010];

void dijkstra(int ini) {
    priority_queue<pair<pair<int,int> , int > > q;
    price[ini] = prestige[ini] = 0;
    q.push({{0,0},ini});
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        for (pair<int,pair<int,int> > p: G[u]) {
            int node = p.first;
            int pri = p.second.first;
            int pre = p.second.second;
            int co = price[u] + pri;
            int np = prestige[u] + pre;
            if(co < price[node]) {
                price[node] = co;
                prestige[node] = np;
                q.push({{-co, np},node});
            }
            else if(co == price[node] and np > prestige[node]) {
                prestige[node] = np;
                price[node] = co;
                q.push({{-co, np}, node});
            }
            
        }
    }
}

pair<int,int> f(int pos, int budget) {
    if(pos == c) return {0,0};
    if(dp[pos][budget].first != -1) return dp[pos][budget];

    pair<int,int> ans1 = {0,0};
    pair<int,int> ans2 = {0,0};

    if(budget - price[pos] >= 0) {
        ans1 = f(pos + 1, budget - price[pos]);
        ans1.first += prestige[pos];
        ans1.second += price[pos];
    }

    ans2 = f(pos + 1, budget);
    if(ans2.first > ans1.first) ans1 = ans2;
    return dp[pos][budget] = ans1;
}

int main(){
    memset(in1,0,sizeof in1);
    memset(dp, -1, sizeof dp);
    cin >> b >> n;   
    c = total = 0;

    for (int i = 0; i < n; ++i) {
        string p1,p2,in;
        int cost,pres;
        cin >> p1 >> p2 >> in >> cost >> pres;
        if(!mp.count(p1)) mp[p1] = c++;
        if(!mp.count(p2)) mp[p2] = c++;
        G[mp[p2]].push_back({mp[p1], {cost, pres}});
        in1[mp[p1]]++;
    }
    for (int i = 0; i < n; ++i) price[i] = prestige[i] = 1e9;
    for (int i = 0; i < n; ++i) if(in1[i] == 0) dijkstra(i);
    pair<int,int> ans = f(0,b);
    cout << ans.first << "\n";
    cout << ans.second << "\n";
    return 0;
}


