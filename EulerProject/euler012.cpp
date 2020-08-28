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

bool p[10000000];
vector<int> prime;
ll v[1030];
vector<pair<int,int> > r;
void criba(){
    memset(p,false,sizeof p);
    for (int i = 2; i*i < 1000000; ++i){
        int c = i+i;
        while(c < 1000000){
            p[c] = true;
            c += i;
        }
    }
    for (int i = 2; i < 1000000; ++i)
        if(!p[i])prime.push_back(i);
}

int factor(ll n){
    ll pf = prime[0];
    int id = 0;
    int ans = 1;
    while(pf*pf <= n){
        int c = 0;
        while(n%pf == 0){ n/= pf; c++;}
        ans *= (c+1);
        pf = prime[++id];
    }
    if(n != 1) ans *= 2;
    return ans;
}
int bs(int x){
    int a = 0; int b = r.size();
    while(b-a>1){
        int mid = (a+b)>>1;
        if(r[mid].first > x) b = mid;
        else a = mid;
    }
    return b;
}
int main(){
    memset(v,-1,sizeof v);
    criba();
    for (int i = 1; i < 100000; ++i){
        ll tr = (i*(i+1LL))/2LL;
        int q = factor(tr);
        if(q >= 0 and  v[q] == -1){
            v[q] = tr;
            r.push_back({q,tr});
        }
      //  cout << tr << " " <<  q << endl;
        if(q > 1000) break;
    }
   // sort(r.begin(),r.end());
    /*for (int i = 0; i < (int)r.size(); ++i){
        cout << r[i].first << " " << r[i].second << endl;
    }*/
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        int id = 0;
        while(r[id].first <= x) id++;
        cout << r[id].second << "\n";
    }
    return 0;
}

