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
typedef long double ld;
vector<pair<int,int> > v;
vector<pair<int,ld> > G[5000];

ll distance(int a,int b, int x,int y){
    return (a-x)*(a-x)+(b-y)*(b-y);
}
int main(){
    int n,e,s;
    cin >> n >> e >> s;

    for (int i = 1; i <= n; ++i){
        int x,y; cin >> x >> y;
        v.push_back({x,y});
    }
    int start,end;
    for (int i = 0; i < (int)v.size(); ++i){
        for (int j = 0; j < (int) v.size(); ++i){
            int dis = distance(v[i].first,v[i].second,v[j].first,v[j].second);
            G[i].push_back({j,dis});
            G[j].push_back({i,dis});
        }
    }


    return 0;
}

