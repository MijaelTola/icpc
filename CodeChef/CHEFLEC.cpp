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
ll v[100010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll ans = 0;
        string s;
        cin >> s;
        for (int i = 0; i < n; ++i) cin >> v[i];
        int pos = 0;
        bool flag;
        if(s[0] == '0') flag = true;
        else flag = false;
        for (int i = 1; i < (int)s.size(); ++i){
            if(flag){
                if(s[i] == '1'){
                    ans += v[i] - v[pos];
                    flag = false;
                    pos = i;
                }
            }else{
                if(s[i] == '0'){
                    pos = i;
                    flag = true;
                }
            }
        }
        if(flag){
            ans += v[n-1] - v[pos-1];
            //cout << pos << " " << v[pos-1] << " " << v[n-1] << endl;
        }
        cout << ans << "\n";
    }
    return 0;
}

