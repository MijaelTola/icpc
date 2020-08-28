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

set<pair<int,int> > s;
int main(){
    
    int n,m; 
    double k;
    n = 100000;//rand()%100000;
    m = 100000;//rand()%100000;
    k = rand()%5;
    cout << n << " " << m << " " << k << endl;
    int i = 0;
    while(i < n){
        int x = rand()%1000000000;
        int y = rand()%1000000000;
        if(s.count({x,y})) continue;
        cout << x << " " << y << endl;
        s.insert({x,y});
        i++;
    }
    i = 0;
    while(i < m){
        int x = rand()%1000000000;
        int y = rand()%1000000000;
        if(s.count({x,y})) continue;
        cout << x << " " << y << endl;
        s.insert({x,y});
        i++;
    }
    
    int q; q =100000;
    cout << q << endl;
    while(q--){
        int x;
        int y;
        x = rand()%1000000000;
        y = rand()%1000000000;
        cout << x << " " << y << endl;
    }
    return 0;
}

