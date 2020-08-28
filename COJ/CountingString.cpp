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

const ll MODULO = 1000000000+7;
int n,k;

ll f(int pos, int c){
    if(pos == n) return c == k;
    ll ans = 0;
    ans += f(pos+1,c+1);
    ans += f(pos+1,c);
    return ans;
}
int main(){
    cin >> n >> k;
    cout << f(0,0)<< " " << f(0,0) << endl;
    return 0;
}

