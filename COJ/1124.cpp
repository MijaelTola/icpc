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

int main(){
    ll n;
    while(scanf("%llu",&n)){
        if(n == 0LL) break;
        printf("%llu = %llu + %llu\n",n,n-1LL,1LL);
    }
    return 0;
}

