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

int n;
long double sx,sy,ex,ey;
vector<pair<int,long double> > G[110];
long double d[110];

struct point{
    long double x; long double y;
    long double w;
    point(long double _x, long double _y, long double _w){
        x = _x;
        y = _y;
        w = _w;
    }
};
vector<point> v;
long double dis(long double a,long double b, long double x, long double y){
    return sqrt((a-x)*(a-x)+(b-y)*(b-y));
}
void Dijkstra(int ini){
    for(int i = 0; i < 110; i++) d[i] = LLONG_MAX;
    priority_queue<pair<long double,int>, vector<pair<long double,int> >, greater<pair<long double,int> > > q;
    d[ini] = 0.0;
    q.push({0.0,ini});
    while(!q.empty()){
        pair<long double,int> top = q.top(); q.pop();
        int u = top.second; 
        for (int i = 0; i < (int)G[u].size(); i++){
            int v = G[u][i].first;
            long double w = G[u][i].second; 
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> sx >> sy >> ex >> ey and n != -1 and sx != -1 and sy != -1 and ex != -1 and ey != -1){
		for (int i = 0; i < 110; ++i) G[i].clear();
        v.clear();
        v.push_back(point(sx,sy,0.0));
		for (int i = 0; i < n; ++i){
			long double x,y,w; cin >> x >> y >> w;
			v.push_back(point(x,y,w));
		}
		v.push_back(point(ex,ey,0.0));
		n+=2;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if(i == j) continue;
				long double d = dis(v[i].x,v[i].y,v[j].x,v[j].y);
				G[i].push_back({j,d});
			}
		}

		for (int i = 1; i < n-1; ++i){
			for (int j = 0; j < n; ++j){
				if(i == j) continue;
				long double d = dis(v[i].x,v[i].y,v[j].x,v[j].y);
				d = abs(d-v[i].w);
				G[i].push_back({j,d});
			}
		}
		Dijkstra(0);
		cout.precision(2);
		cout<<fixed << d[n-1]<< "\n";
	}
    return 0;
}

