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

vector<int> v[110];
int n;
int f(int pos, int col){
    if(pos == n+1) return 0;
    int ans = 0;
    if(col < (int)v[pos].size()) ans = max(ans,f(pos+1,col) + v[pos][col]);
    if(col < (int)v[pos].size()) ans = max(ans,f(pos+1,col+1) + v[pos][col]);
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for (int i = 1; i <= n; ++i){
            v[i].clear();
            for (int j = 1; j <= i; ++j){
                int x; scanf("%d",&x);
                v[i].push_back(x);
            }
        }
        printf("%d\n",f(1,0));
    }
    return 0;
}

