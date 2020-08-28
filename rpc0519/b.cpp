#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1,0,1,1,0,-1};
int dy[] = {1,2,1,-1,-2,-1};
bool vis[2010][2010];
string s[2010];
vector<int> b;
int n,m;
bool ver(int x, int y) {
    return x >= 0 and x < n and y >= 0 
        and y < (int)s[x].size() and s[x][y] == '.' and !vis[x][y];
}
int bfs(int a, int b) {
    queue<pair<int,int> > q;
    q.push({a,b});
    int cnt = 0;
    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        if(vis[xx][yy]) continue;
        vis[xx][yy] = 1;
        cnt++;
        for (int i = 0; i < 6; ++i) {
            int u = dx[i] + xx;
            int v = dy[i] + yy;
            if(ver(u,v)) q.push({u,v});
        }
    }
    return cnt;
}

int main() {

    int x;
    cin >> x >> n >> m;

    cin.ignore();

    for (int i = 0; i < n; ++i) {
        getline(cin, s[i]);
        //if(i & 1) s[i] = " " + s[i];
    }
   
    vector<int> b;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < (int)s[i].size(); ++j) 
            if(ver(i,j)) 
                b.push_back(bfs(i,j));
            
    sort(b.rbegin(), b.rend());
    int ans = 0;
    int sum = 0;
    for (auto p: b) {
        if(sum < x) {
            sum += p;
            ans++;
        } else break;
    }
    cout << ans << "\n";
  
    return 0;
}

