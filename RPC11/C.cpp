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
#include <unordered_map>
using namespace std;

typedef long long ll;


struct cmp{
    bool operator()(const pair<vector<vector<int> >,int > a, const pair<vector<vector<int> >,int > b){
        return a.second > b.second;
    }
};
vector<vector<int> > v(2);
vector<vector<int> > v1(2);
map<vector<vector<int> >,int > dis;
priority_queue<pair<vector<vector<int> >,int >,vector<pair<vector<vector<int> >,int > >, cmp > q;

const int maxn = 1e8;

int main(){
  //  ios::sync_with_stdio(false); cin.tie(0);
    for(int i = 0; i < 2; ++i)
        for (int j = 0; j < 4; ++j){
            int x;
            //cin >> x;
            scanf("%d",&x);
            v[i].push_back(x);
        }

    for(int i = 0; i < 2; ++i)
        for (int j = 0; j < 4; ++j){
            int x; //cin >> x;a
            scanf("%d",&x);
            v1[i].push_back(x);
        }
    q.push({v,1});
    dis[v] = 1;
    while(!q.empty()){
        vector<vector<int> > p = q.top().first;
        q.pop();
        int w = dis[p];
        for (int i = 1; i < 4; ++i){
            swap(p[0][i],p[0][i-1]);
            //show(p);
            if(dis[p] == 0) dis[p] = maxn;
            if(w+p[0][i]+p[0][i-1] < dis[p]){
                dis[p] = w + p[0][i]+p[0][i-1];
                q.push({p,dis[p]});
            }
            //cout << endl;
            swap(p[0][i],p[0][i-1]);
            swap(p[1][i],p[1][i-1]);
           // show(p);
            if(dis[p] == 0) dis[p] = maxn;
            if(w + p[1][i]+p[1][i-1] < dis[p]){
                dis[p] = w + p[1][i] + p[1][i-1];
                q.push({p,dis[p]});
            }
            swap(p[1][i],p[1][i-1]);
            //cout << endl;
        }   
        for (int i = 0; i < 4; ++i){
            swap(p[0][i],p[1][i]);
           // show(p);
            //cout << endl;
            if(dis[p] == 0) dis[p] = maxn;
            if(w + p[0][i] + p[1][i] < dis[p]){
                dis[p] = w + p[0][i]+p[1][i];
                q.push({p,dis[p]});
            }
            swap(p[0][i],p[1][i]);
        }
    }
    //cout << dis[v1]-1 << "\n";
    printf("%d\n",dis[v1]-1);
    return 0;
}

