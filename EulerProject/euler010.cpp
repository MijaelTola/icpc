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

bool p[10000100];
vector<int> prime;
ll sum[10000100];
void criba(){
    memset(p,false,sizeof p);
    for(int i = 2; i*i <= 10000100; ++i){
        int c = i + i;
        while(c < 10000100){
            p[c] = true;
            c +=i;
        }
    }
    for (int i = 2; i < 10000100; ++i){
        if(!p[i]) prime.push_back(i);
    }
    sum[0] = prime[0];

    for (int i = 1; i < (int)prime.size(); ++i)
        sum[i] = prime[i]+ sum[i-1];
}

int bs(int x){
    int a = -1; int b = prime.size();
    while(b-a>1){
        int mid = (a+b)>>1;
        if(prime[mid] > x) b = mid;
        else a = mid;
    }
    return a;
}
int main(){
    
    criba();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int pos = bs(n);
        cout << sum[pos] << endl;
    }
    return 0;
}

