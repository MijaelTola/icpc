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

int match[40][2];
int main(){
    
    int n,m,g; 
    while(cin >> n >> m >> g and n and m and g){
    memset(match,0,sizeof match);
    int total = m*2;
    for (int i = 0; i < g; ++i){
        int x,y; char c;
        cin >> x >> c >> y;
        if(c == '>') match[x][0] += 2;
        if(c == '<') match[y][0] += 2;
        if(c == '=') match[x][0]++,match[y][0]++;
        match[x][1]++;
        match[y][1]++;
    }

    for (int i = 0; i < n; ++i){
        int rest = total - match[i][1];
        int point = rest*2;
        match[i][0] += point;
    }
    
    int mx = match[0][0];
    bool flag = true;
    for (int i = 1; i < n; ++i){
        cout << mx << " " << match[i][0] << endl;
        if(mx <= match[i][0]){
            flag = false;
            break;
        }
    }
    if(flag) cout << "Y" << endl;
    else cout << "N" << endl;
    }
    return 0;
}

