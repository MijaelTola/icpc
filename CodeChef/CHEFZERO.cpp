#include <bits/stdc++.h>

using namespace std;

int n,m,k;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int a[1010][1010];
int v[1010][1010];

priority_queue<pair<int, pair<int,int> > > s;
queue<pair<int, pair<int,int> > > q[1010];
priority_queue<pair<long long,int> > teams;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(a, -1, sizeof a);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
            s.push(make_pair(v[i][j],make_pair(i,j)));
        }
    
    
    for (int i = 0; i < k; ++i) {
        long long val = s.top().first;
        int x = s.top().second.first;
        int y = s.top().second.second;
        s.pop();
        q[i].push(make_pair(-val, make_pair(x,y)));
        teams.push(make_pair(0,i));
    }
    
   
    while(k) {
        int cteam = teams.top().second;
        long long curVal = -teams.top().first;
        teams.pop();
        bool flag = 0;
        while(!q[cteam].empty() and !flag) {
            int val = -q[cteam].front().first;
            int x = q[cteam].front().second.first;
            int y = q[cteam].front().second.second;
            q[cteam].pop();
            if(a[x][y] == -1) {
                a[x][y] = cteam;
                curVal += (long long)v[x][y];
                for (int i = 0; i < 4; ++i) {
                    int u = dx[i] + x;
                    int vv = dy[i] + y;
                    if(u >= 0 and u < n and vv >= 0 and vv < m) 
                        q[cteam].push(make_pair(-v[u][vv],make_pair(u,vv)));
                }
                flag = 1;
            }
        }
        if(flag) teams.push(make_pair(-curVal, cteam));
        else k--;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) 
            cout << a[i][j] + 1 << " ";
        cout << "\n";
    }
        
    return 0;
}

