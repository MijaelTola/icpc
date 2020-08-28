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

int main(){
    
    ll sum = 0;
    for (int i = 1; i <= 100; ++i) sum+=i*i;
    ll ans = (100*101/2)*(100*101/2); 
    cout << ans-sum << endl;
    return 0;
}

