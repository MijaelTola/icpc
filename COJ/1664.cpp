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

bool B[110];
bool A[110];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    while(n--){
        int da,db;cin >> da >> db;
        A[da] = B[db] = true;
        int ans = 1e9;
        for (int i = 1; i <= 100; ++i){
            int sum = 0;
            if(!A[i]) continue;
            for (int j = 1; j <= 100; ++j){
                if(i == j) continue;
                if(B[j]) sum = max(sum,i+j);
            }
            ans = min(ans,sum);
        }
        cout << ans << "\n";
    }
    return 0;
}

