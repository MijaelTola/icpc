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

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);   
    int t; cin >> t;

    while(t--){
        long double n; cin >> n;
        long double ans = 0.0;
        bool flag = false;
        for (int i = 0; i < n; ++i){
            long double x; cin >> x;
            ans += x;
            if(x == 5) flag = true;
        }
        if(!flag)  cout << "No";
        else if(ans/n >= 4.0) cout << "Yes";
        else cout << "No";
        cout << "\n";
    }
    return 0;
}

