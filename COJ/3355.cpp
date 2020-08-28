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
#include <bitset>

using namespace std;

typedef long long ll;

bool s[3010];
vector<int> prime;

int primefact(int n){
    int pfid = 0,pf = prime[0];
    set<int> p;
    while(pf*pf<= n){
        while(n%pf==0){
            n /= pf;
            p.insert(pf);
        }
        pf = prime[++pfid];
    }
    if(n != 1) p.insert(n);
    return p.size();
}
int main(){
    memset(s,false,sizeof s);
    for (int i = 2; i*i < 3010; ++i){
        int c = i+i;
        while(c < 3010){
            s[c] = true;
            c += i;
        }
    }

    for (int i = 2; i < 3010; ++i) 
        if(!s[i]) prime.push_back(i);
    
    int n; cin >> n;
    int ans = 0;
    //cout << primefact(n)<< endl;
    for (int i = 1; i <= n; ++i)
        if(primefact(i) == 2) ans++;
       // cout << primefact(i) << " " << i << endl;

    cout << ans << endl;
    return 0;
}

