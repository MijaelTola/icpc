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

using namespace std;

typedef long long ll;

vector<pair<double,double> > coordinates;

struct edges{
    int source;
    int sink;
    double weight;
    edges(){}
    edges(int source,int sink,double weight): 
        source(source), sink(sink), weight(weight){}
    bool operator < (const edges &e){
        return e.weight > weight;
    }
};
int parent[210];

void init(){
    for (int i = 0; i < 210; ++i) parent[i] = i;
}

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void Union(int x,int y){
    int px = find(x);
    int py = find(y);
    parent[px] = py;
}
vector<edges> e;

double kruskal(){
    double ans = 0.0;
    for(int i = 0; i < (int)e.size(); ++i){
        int source = e[i].source;
        int sink = e[i].sink;
        double w = e[i].weight;
        if(find(source) == find(sink)) continue;
        Union(source,sink);
        ans += w;
    }
    return ans;
}
int main(){
    memset(parent,0,sizeof parent);
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        double x,y; cin >> x >> y;
        coordinates.push_back({x,y});
    }

    for (int i = 0; i < (int)coordinates.size(); ++i){
        double x1 = coordinates[i].first;
        double y1 = coordinates[i].second;
        for (int j = i+1; j < (int) coordinates.size(); ++j){
            double x2 = coordinates[j].first;
            double y2 = coordinates[j].second;
            double dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
            e.push_back(edges(i,j,dist));
        }
    }
    sort(e.begin(),e.end());
    init();
    cout.precision(9);
    cout << fixed <<  kruskal() << endl;
    return 0;
}

