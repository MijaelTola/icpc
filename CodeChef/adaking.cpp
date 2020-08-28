#include <bits/stdc++.h>

using namespace std;

int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,-1,-1,-1,0,1,1,1};

int main() {

    int t;
    cin >> t;

    while(t--) {
        int k;
        cin >> k;
        set<pair<int,int> > s;
        queue<pair<int,int> > q;
        q.push({0,0});

        while(!q.empty() and (int)s.size() < k) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();
            if(s.count({u,v})) continue;
            s.insert({u,v});

            for (int i = 0; i < 8; ++i) {
                int x = dx[i] + u;
                int y = dy[i] + v;
                if(x >= 0 and x < 8 and y >= 0 and y < 8)
                    q.push({x,y});
            }
        }
        
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if(i == 0 and j == 0) {
                    cout << "O";
                    continue;
                }
                if(s.count({i,j})) cout << ".";
                else cout << "X";
            }
            cout << "\n";
        }
    }
    return 0;
}

