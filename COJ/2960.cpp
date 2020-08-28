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

int a[28];
int main(){
    a['B'-'A'] = 2;
    a['A'-'A'] = 1;
    a['P'-'A'] = 1;
    a['D'- 'A'] = 1;
    a['O' - 'A'] = 1;
    a['Q' - 'A'] = 1;
    a['R' - 'A'] = 1;
    a['P' - 'A'] = 1;
    string x; cin >> x; 
    int ans = 0;
    for (int i = 0; i < (int)x.size(); ++i) ans += a[x[i]-'A'];
    cout << ans << endl;
    return 0;
}

