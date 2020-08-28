#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;

vector<pair<int,int> > G[5010];
int d[5010][3];
struct cmp{
    bool operator()(const pair<int,int> &A, pair<int,int> &B){
        return A.second > B.second;
    }
};

void Dijkstra(int x, int flag){
    priority_queue<pair<int,int>, vector<pair<int,int> >, cmp> q;
    q.push({x,0});
    d[x][flag] = 0;
    while(!q.empty()){
        int u = q.top().first;
        q.pop();
        for (pair<int,int> i: G[u]){
            int v = i.first;
            int w = i.second;
            if(d[u][flag] + w < d[v][flag]){
                d[v][flag] = d[u][flag] + w;
                q.push({v,d[v][flag]});
            }
        }
    }
}
int main(){
    //ios::sync_with_stdio(false); cin.tie(0);
    int j,b,c,n,s;
    while(/*cin >> j >> b >> c >> n >> s*/ scanf("%d %d %d %d %d",&j,&b,&c,&n,&s) and j != -1 and b != -1 and c != -1 and n != -1 and s != -1){
        for (int i = 0; i < 5010; ++i){
            G[i].clear();
            d[i][0] = INT_MAX;
            d[i][1] = INT_MAX;
            d[i][2] = INT_MAX;
        }
        for (int i = 0; i < s; ++i){
            int x,y,w; 
            //cin >> x >> y >> w;
            scanf("%d %d %d",&x,&y,&w);
            G[x].push_back({y,w});
            G[y].push_back({x,w});
        }

        Dijkstra(b,0);
        Dijkstra(c,1);
        Dijkstra(n,2);
        
        int mx = INT_MAX;
        int id = -1;
        for (int i = 1; i <= j; ++i){
            if(d[i][0] == INT_MAX or d[i][1] == INT_MAX or d[i][2] == INT_MAX) continue;
            if(d[i][0]+d[i][1]+d[i][2] < mx){
                id = i;
                mx = d[i][0]+d[i][1]+d[i][2];
            }
        }
        //cout << mx-d[id][1] - d[id][2] << " "<< d[id][1] << " " << d[id][2] << "\n";
        printf("%d %d %d\n", d[id][0],d[id][1],d[id][2]);
    }
    return 0;
}
