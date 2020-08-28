#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > G[50];

struct PowerOutage {


    int dfs(int u, int p) {
        int ans = 0;
        for (auto v: G[u]) {
            if(v.first == p) continue;
            ans += dfs(v.first, u) + 2 * v.second;
        }
        return ans;
    }
    
    int f(int u, int p) {
        int ans = 0;
        for (auto v: G[u]) {
            if (v.first == p) continue;
            ans = max(ans, f(v.first, u) + v.second);
        }
        return ans;
    }

    int estimateTimeOut(vector <int> fromJunction, vector <int> toJunction, vector <int> ductLength) {
        int n = fromJunction.size();
        for (int i = 0; i < n; ++i) {
            G[fromJunction[i]].push_back({toJunction[i], ductLength[i]});
            G[toJunction[i]].push_back({fromJunction[i], ductLength[i]});
        }
        return dfs(0,0) - f(0,0);  
    }
};

void t1() {
    vector<int> a = {0};
    vector<int> b = {1};
    vector<int> c = {10};
    PowerOutage p;
    cout << p.estimateTimeOut(a,b,c) << "\n";
}

void t2() {
    PowerOutage p;
    cout << p.estimateTimeOut({0,1,0}, {1,2,3},{10,10,10}) << "\n";
}

void t3() {
    PowerOutage p;
    cout << p.estimateTimeOut({0,0,0,1,4}, {1,3,4,2,5} ,{10,10,100,10,5}) << "\n";

}

void t4() {
    PowerOutage p;
    cout << p.estimateTimeOut({0,0,0,1,4,4,6,7,7,7,20}, {1,3,4,2,5,6,7,20,9,10,31},
            {10,10,100,10,5,1,1,100,1,1,5}) << "\n";

}

int main() {
    t4();
    return 0;
}

