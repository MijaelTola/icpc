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

long long hsh[100010];
long long hsh1[100010];
long long p = 67280421310721LL;
long long x = 31;
void h(string &s){
    hsh[s.size()-1] = hsh1[0] = 0;
    for (int i = (int)s.size()-1; i >= 0; --i)
        hsh[i] = (((hsh[i+1]*x+s[i])%p)+p)%p;
    
    for (int i = 0; i < (int)s.size(); ++i)
        hsh1[i] = (((hsh1[i-1]*x+s[i])%p)+p)%p;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,q,l;
    while(cin >> n >> q >> l){
        map<pair<pair<long long,long long>, long long >, int > hashing;
        for (int i = 0; i < n; ++i){
            string s; cin >> s;
            h(s);
            for (int j = 0; j < (int)s.size(); ++j){
                long long da = INT_MIN;
                long long db = INT_MIN;
                if(j > 0) da = hsh1[j-1];
                if(j < (int)s.size()-1) db = hsh[j+1];
                hashing[make_pair(make_pair(da,db),j)]++;
            }
        } 
        while(q--){
            int ans = 0;
            string s; cin >> s;
            h(s);
            for (int j = 0; j < (int)s.size(); ++j){
                long long da = INT_MIN;
                long long db = INT_MIN;
                if(j > 0) da = hsh1[j-1];
                if(j < (int)s.size()-1) db = hsh[j+1];
                ans += hashing[make_pair(make_pair(da,db),j)];
            }
            cout << ans << "\n";
        }
    }
    return 0;
}

