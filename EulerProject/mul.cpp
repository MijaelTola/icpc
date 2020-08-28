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

bool ver(int x){
    int t = x;
    int y = 0;
    while(x>0){
        y+=x%10;
        x/=10;
        if(x)y*=10;
    }
    return y == t;
}
int main(){
    int p = 1;
    bool flag = false;
    while(!flag){
        flag = true;
        for (int i = 1; i <= 20; ++i)
            if(p%i != 0){flag = 0; break;}
        if(!flag)p++;
    }
    cout << p << endl;
    /*int n; cin >> n; ver(n);
    int ans = 0;
    for (int i = 100; i < 1000; ++i){
        for (int j = 100; j < 1000; ++j){
            int p = i*j;
            if(ver(p)) ans = max(ans,p);
        }
    }
    cout << "asfasdfasdf" << endl;
    cout << ans << endl;*/
    /*long long sum = 0;
    long long a = 0; long long b = 1;
    ll c= 0;
    for (;c < 4000000 ;){
        c  = a + b;
        if(c%2==0) sum += c; 
        a = b; b = c;
    }
    cout << sum << endl;*/
    return 0;
}

