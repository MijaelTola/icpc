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

int v[11];

priority_queue<int> q;

int main(){
    int n; cin >> n;
    for (int i = 0; i < n; ++i){ 
        cin >> v[i];
        q.push(v[i]);
    }
    return 0;
}

