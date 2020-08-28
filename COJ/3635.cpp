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

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    double xl,yl,xr,yr;
    cout.precision(9);
    while(cin >> xl >> yl >> xr >> yr) cout<< fixed << double((xr-xl)*(xr-xl)+(yr-yl)*(yr-yl))/6 << "\n";
    return 0;
}

