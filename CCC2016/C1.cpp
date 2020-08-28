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

vector<int> r;
vector<int> b;
int num[200010];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    assert(n >= 2 and n <= 1000000);
    for (int i = 0; i < n; ++i){
        int x; scanf("%d",&x);
        assert(abs(x) <= 100000);
        if(x < 0) b.push_back(-x);
        else r.push_back(x);
    }
    
    for (int i = 0; i < (int)r.size(); ++i)
        for (int j = 0; j < (int)b.size(); ++j)
            if(r[i]+b[j] <= 200000)num[r[i]+b[j]]++;

    int q; scanf("%d",&q);
    assert(q <= 1000000);
    while(q--){
        int x; scanf("%d",&x);
        assert(x >= 1 && x <= 200000);
        if(num[x] >= k) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
