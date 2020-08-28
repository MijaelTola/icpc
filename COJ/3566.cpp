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


struct cmp{
    bool operator()(pair<pair<int,int>,pair<int,int>> &a, pair<pair<int,int>, pair<int,int>> &b){
        return a.second.first > b.second.first;
    }
};
char m[2010][2010];
int d[2010][2010];

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int n;
bool ver(int u,int v){
    return u >= 0 and u < n and v >= 0 and v < n;
}
int add(int last){
    if(m[n-1][n-1]=='H'){
        if(last == 0) return 2;
        if(last == 1) return 1;
    }else{
        if(last == 0) return 2;
        if(last == 1) return 3;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n; 
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            cin >> m[i][j];
            d[i][j] = 1e9;
        }
    priority_queue<pair<pair<int,int>,pair<int,int> >, vector<pair<pair<int,int>,pair<int,int> > >,cmp> q;
    // x y time watching 
    q.push({{0,0},{0,0}});
    d[0][0] = 0;
    //int last = 0;
    while(!q.empty()){
        int x = q.top().first.first;
        int y = q.top().first.second;
        int pos = q.top().second.second;
        cout << x << " " << y << " " << q.top().second.first << endl;
        q.pop();
        if(m[x][y] == 'H'){
            int c = 1;
            while(c <= 3){
                pos = (pos+1)%4;
                int u = dx[pos] + x;
                int v = dy[pos] + y;
                if(ver(u,v)){
                    int p = 0;
                    if(u == n-1 and v == n-1)
                        p = add((pos+2)%4);   
                    if(d[x][y]+c+p < d[u][v]){
                        d[u][v] = d[x][y] + c + p;
                        q.push({{u,v},{d[u][v],(pos+2)%4}});
                    }
                }
                c++;
            }
        }else{
            int c = 1;
            while(c <= 3){
                pos = ((pos-1)+4)%4;
                int u = dx[pos] + x;
                int v = dy[pos] + y;
                if(ver(u,v)){
                    int p = 0;
                    if(u == n-1 and v == n-1)
                        p = add((pos+2)%4);
                    if(d[x][y]+c+p <= d[u][v]){
                        d[u][v] = d[x][y]+c+p;
                        q.push({{u,v},{d[u][v],(pos+2)%2}});
                    }
                }
                c++;
            }
        }

    }
    cout << d[n-1][n-1] << "\n";
    return 0;
}

