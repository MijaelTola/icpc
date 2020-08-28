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

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    long long s;
    int t; cin >> t;
    while(t--){
        cin >> s;
        long long p = s+1LL;
        cout << (p*p)-1LL << "\n";
    }
    return 0;
}

