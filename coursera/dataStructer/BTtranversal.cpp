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

int n;
vector<ll> in;
vector<ll> pre;
vector<ll> post;
vector<int> T[100010];
ll key[100010];
void dfs(int u){
    if(u == -1) return;
    pre.push_back(key[u]);
    dfs(T[u][0]);
    in.push_back(key[u]);
    dfs(T[u][1]);
    post.push_back(key[u]);

}
int main(){
    
    cin >> n;
    for (int i = 0; i < n; ++i){
        ll k; int right,left;
        cin >> k >> left >> right;
        key[i] = k;
        T[i].push_back(left);
        T[i].push_back(right);
    }
    dfs(0);

    for (int i = 0; i < (int)in.size(); ++i) cout << in[i] << " "; cout << "\n";
    for (int i = 0; i < (int)pre.size(); ++i) cout << pre[i] << " "; cout <<"\n";
    for (int i = 0; i < (int)post.size(); ++i) cout << post[i] << " "; cout << "\n";
    return 0;
}

