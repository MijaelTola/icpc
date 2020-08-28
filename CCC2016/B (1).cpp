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

using namespace std;

typedef long long ll;

vector<pair<int,int>> v;
int dp[10010],n;
struct kmp{
    string t,p;
    int n,m;
    int b[10010];
    kmp(string &t):t(t){n = t.size();}
    void pre(string &pattern){
        p = pattern;
        m = p.size();
        int i = 0,j = -1; b[0] = -1;
        while(i < m){
            while(j >= 0 and p[i] != p[j]) j = b[j];
            i++; j++;
            b[i] = j;
        }
    }
    void find(int num,int w){
        int i = 0, j = 0;
        while(i < n){
            while(j >= 0 and t[i] != p[j]) j = b[j];
            i++; j++;
            if(j == m){
                int x = i-j;
                v.push_back({num,w});
                dp[x+w] = v.size()-1;
                j = b[j];
            }
        }
    }
};
int main(){
   // ios::sync_with_stdio(false); cin.tie(0);
    memset(dp,-1,sizeof dp);
    string x; cin >> x;
    n = x.size();
    kmp K(x);
    int q; cin >> q;
    dp[0] = 0;
    for (int i = 1; i <= q; ++i){
        string s; cin >> s;
        K.pre(s);
        K.find(i,s.size());
    }
    if(dp[n] != -1){
        int r = n;
        int s = 0;
        int ans = 0;
        while(r > 0){
            ans++;
            if(dp[r] == -1) break;
            s += v[dp[r]].second;
            int w = v[dp[r]].second;
            v[dp[r]].second = -4;
            r -= w;
        }
        if(s == n){
            cout << "ES SPAM\n";
            cout << ans << "\n";
            for (int i = 1; i <= n; ++i)
                if(v[dp[i]].second == -4)cout <<  v[dp[i]].first<< " ";
        }else cout << "NO ES SPAM\n";
    }else cout << "NO ES SPAM\n";
    return 0;
}
