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

set<ll> s;
vector<ll> p;
int main(){
    
    for (ll i = 2LL; i*i < 5000000000LL; ++i){
        ll c = i + i;
        while(c < 5000000000LL){
            s.insert(c);
            c += i;
        }
    }
    for (ll i = 2LL; i < 5000000000LL; ++i){
        if(!s.count(i)) p.push_back(i);
    }
    cout << "ASDFASDF" << endl;
    return 0;
}

