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

int v[1010],n,k;

int f(int pos,int where, bool flag){
    if(pos == n) return 0;
    int ans = 1e8;
    if(flag){
        for (int i = v[pos]; i >= where; --i)
            ans = max(ans,f(pos+1,i,false)+1);
    }else{
        for (int i = v[pos]; i < where+k; ++i){
            if(i+1<where+k) ans = min(ans,f(pos+1,i,false)+1);
            else ans = min(ans,f(pos+1,i,true)+1);
        }
    }
    return ans;
}
int main(){
    cin >> n >> k;
    v[0] = 0;
    for (int i = 1; i < n; ++i){
        int x; cin >> x;
        v[i] = x + v[i]-1;
    }
    cout << "ASDFASDF" << endl;
    cout << f(0,0,false);
    cout << "ASDFASDF" << endl;
    return 0;
}

