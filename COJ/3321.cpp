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

int v[1000010];
bool s[1000010];
vector<ll> a;
vector<int> p;
ll mod = 10000000000;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    memset(s,false,sizeof s);
    for (int i = 2; i*i <= 1000010; ++i){
        int c = i+i;
        while(c <= 1000010){
            s[c] = true; c += i;
        }
    }
    ll f = 1;
    for (int i = 2; i <= 1000000; ++i){
        if(!s[i]){
            f = (f*i)%mod;
            a.push_back(f);
            p.push_back(i);
        }
    }
    int n; 
    int t; cin >> t;
    while(t--) {
        cin >> n;
        int low = 0; int b = p.size();
        while(b-low>1){
            int mid = (low+b)>>1;
            if(p[mid]>=n) b = mid;
            else low = mid;
        }
        cout << a[low] << "\n";
    }
    return 0;
}

