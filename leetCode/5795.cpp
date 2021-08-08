#include <bits/stdc++.h>

using namespace std;

vector<int> G[1010];
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        
        for (int i = 0; i < (int)passingFees.size(); ++i)
            G[i].clear();

        for (auto edge: edges) {
            int x,y,w;
            x = edge[0];
            y = edge[1];
            w = edge[2];
            G[x].push_back({y, w});
            G[y].push_back({x, w});
        }

        priority_queue<tuple<int,int> > q;
        q.push({0, 0});

    }
};

int main() {

    return 0;
}

