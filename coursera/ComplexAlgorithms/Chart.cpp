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

int n,k;
int c[110][30];
vector<int> G[200];
int match[200];
int vis[200];
int Aug(int l){
    if(vis[l]) return false;
    vis[l] = true;
    for (int j: G[l]){
        if(match[j] == -1 or Aug(match[j])){
            match[j] = l; return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j)
            cin >> c[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            if(i == j) continue;
            bool flag = true;
            for (int l = 0; l < k; ++l)
                flag &= (c[i][l] < c[j][l]);
            if(flag) G[i].push_back(j);
        }
    memset(match,-1,sizeof match);
    int mcbm = 0;
    for (int i = 0; i < n; ++i){
        memset(vis,false,sizeof vis);
        mcbm += Aug(i);
    }
    cout << n - mcbm << "\n";
    return 0;
}

