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

vector<pair<string,int> > v;
int main(){
    string x; cin >> x;
    for (int init = 0; init < (int)x.size(); ++init){
        string p = "";
        for (int i = init; i < (int)x.size(); ++i)
            p += x[i];
        string t = "";
        for (int i = 0; i < init; ++i) t += x[i];
        v.push_back({p+t,init});
    }
    sort(v.begin(),v.end());

    for (int i = 0; i < (int)v.size(); ++i) cout << v[i].second << " ";
    return 0;
}

