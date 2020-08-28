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

vector<int> primes;
vector<int> gods;
bool is(int x){
    if(x == 2) return true;
    if(x < 2 or (x & 1) == 0) return false;
    for (int i = 3; i*i <= x; i+=2)
        if(x%i == 0) return false;
    return true;
}
void f(int x, int p){
    if(x > 1e9) return;
    if(is(x) or x == 0){
        if(x > 0)primes.push_back(x);
        for (int i = 1; i < 10; ++i)
            f(i*p+x,p*10);
    }
}

int getrev(int x){
    int ans = 0;
    while(x > 0){
        ans = ans*10 + x%10;
        x/=10;
    }
    return ans;
}
void find(){
    f(0,1);
    sort(primes.begin(),primes.end());
    for (int i = 0; i < (int)primes.size(); ++i){
        int rev = getrev(primes[i]);
        if(binary_search(primes.begin(),primes.end(),rev)) gods.push_back(primes[i]);
    }
}
int main(){
    find();
    int t;
    scanf("%d",&t);
    while(t--){
        int x,y;
        scanf("%d %d",&x, &y);
        int posx = lower_bound(gods.begin(),gods.end(),x)-gods.begin();
        int posy = lower_bound(gods.begin(),gods.end(),y+1)-gods.begin();
        printf("%d\n",posy-posx);
    }
    return 0;
}

