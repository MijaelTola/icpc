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

using namespace std;

typedef long long ll;

bool sieve[1010000];
vector<int> ans;
int main(){
    memset(sieve,false,sizeof sieve);
    for (int i = 2; i*i< 1010000; ++i){
        int c = i+i;
        while(c < 1010000){
            sieve[c] = true;
            c += i;
        }
    }
    for (int i = 2; i < 1010000; ++i){
        if(!sieve[i]) ans.push_back(i);
    }
    cout << ans[10001-1] << endl;
    return 0;
}

