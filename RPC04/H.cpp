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

long long f(long long n){
    long long p = 1;
    while(n > p){
        n-=p;
        p*=2LL;
    }
    return 2LL*n-1LL;
}
int main(){
    long long n;
    while(scanf("%lld",&n) == 1 and n != 0)
        printf("%lld\n",f(n));
    return 0;
}

