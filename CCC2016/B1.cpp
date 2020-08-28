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
    void find(int num){
        int i = 0, j = 0;
        while(i < n){
            while(j >= 0 and t[i] != p[j]) j = b[j];
            i++; j++;
            if(j == m){
                v.push_back({i-j,num});
                j = b[j];
            }
        }
    }
};
int dp[10010],n;
int sz[10010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp,-1,sizeof dp);
    string x; cin >> x;
    n = x.size();
    kmp K(x);
    int q; cin >> q;
    for (int i = 1; i <= q; ++i){
        string x; cin >> x;
        K.pre(x);
        K.find(i);
        sz[i] = x.size();
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); ++i) cout << v[i].first << " " << v[i].second << endl;
    dp[0] = 0;
    for (int i = 0; i < (int)v.size(); ++i){
        int x = v[i].first;
        int w = sz[v[i].second];
        //cout << x << endl;
        if(dp[x] != -1){
          //  cout << "entra\n";
            dp[x+w] = i;
        }
    }
    vector<int> a;
    if(dp[n] != -1){
        cout << "ES SPAM\n";
        int r = n;
        while(r != 0){
            assert(a.size() < 10010);
            a.push_back(v[dp[r]].second);
            r-=sz[v[dp[r]].second];
        }
        cout << a.size() << "\n";
        for (int i = a.size()-1; i >= 0; --i)
           cout <<  a[i] << " ";
    }else cout << "NO ES SPAM\n";
    return 0;
}
