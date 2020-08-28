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

string m[4000];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--){
        vector<pair<int,int> > s;
        int n,k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i){
            int y;
            cin >> m[i] >> y;
            int p = y;
            while(p <= 1e4){
                s.push_back({p,i});
                p += y;
            }
        }
        sort(s.begin(),s.end());   
        for (int i = 0; i < k; ++i)
            cout << s[i].first << " " << m[s[i].second] << "\n";
    }
    return 0;
}

