#include <bits/stdc++.h>

using namespace std;

    int dis[110][110];

int dx[] = {1,-1, 0,0};
int dy[] = {0,0, 1,-1};
class Solution {
public:

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

    queue<pair<int,int> > q;
    q.push({entrance[0], entrance[1]});
    
    int n = maze.size();
    int m = maze[0].size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            dis[i][j] = -1;
    }
    
    
    dis[entrance[0]][entrance[1]] = 0;

    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        if((x == 0 or x == n or
           y == 0 or y == m) and dis[x][y] > 0) {
            return dis[x][y];
        }
        
        for (int i = 0; i < 4; ++i) {
            int u = dx[i] + x;
            int v = dy[i] + y;
            if(u >= 0 and u < n and v >= 0 and v < m
                    and maze[u][v] == '.' and dis[u][v] == -1) {
                dis[u][v] = dis[x][y] + 1;
                q.push({u,v});
            }
        }
    }
    return -1;
}
};

int main() {

    
    Solution s;

    vector<vector<char> >a = {{"+","+","+"},{".",".","."},{"+","+","+"}};
    auto b = {1,0};
    cout << s.nearestExit(a, b);
    return 0;
}

