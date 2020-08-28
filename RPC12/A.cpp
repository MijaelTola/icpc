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

int main(){
    string x; cin >> x;
    bool flag = false;
    for (int i = 0; i < (int)x.size(); ++i)
        if(x[i] == 'i'){
            flag = true;
            break;
        }
    if(flag) cout << "N";
    else cout << "S";
    cout <<  "\n";
    return 0;
}

