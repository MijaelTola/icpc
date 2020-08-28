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

int v[100];
int main(){
    
    int n;
    while(cin >> n){
        int total = 0;
        for (int i = 0; i < n; ++i){
            cin >> v[i];
            total += v[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if((total - v[i])%2==0) ans++;
        cout << ans << "\n";
    }
    return 0;
}

