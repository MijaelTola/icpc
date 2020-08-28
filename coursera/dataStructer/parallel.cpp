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

using namespace std;

typedef long long ll;
struct cmp{
    bool operator () (const pair<int,ll> a, const pair<int,ll> b){
        if(a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
};
int main(){
    priority_queue<pair<int,ll>,vector<pair<int,ll> >, cmp> q;      
    int n,m; cin >> n >> m;

    for (int i = 0; i < n; ++i) q.push({i,0});
    for (int i = 0; i < m; ++i){
        ll x; cin >> x;
        ll time = q.top().second;
        int node = q.top().first;
        q.pop();
        cout << node << " " << time << endl;
        time += x;
        q.push({node,time});
    }
    return 0;
}

