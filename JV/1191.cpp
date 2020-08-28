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

int v[10010];
int main(){
   // ios::sync_with_stdio(false); cin.tie(0);
    int n;
    while(scanf("%d",&n)!=EOF){
        for (int i = 0; i < n; ++i) scanf("%d",&v[i]);
        int p; scanf("%d",&p);
        int mx = -1;
        int mn = 1e9;
        bool flag = false;
        sort(v,v+n);
        for (int i = 0; i < n; ++i){
            for (int j = i+1; j < n; ++j){
                if(v[i] + v[j] > p) break;
                if(v[i] + v[j] == p){
                    flag = true;
                    int a = min(v[i],v[j]);
                    int b = max(v[i],v[j]);
                    if(a < mn and b > mx){
                        mn = a;
                        mx = b;
                    }
                }
            }
        }
        if(!flag) printf("-1\n");
        else printf("%d %d\n",mn,mx);
    }
    return 0;
}

