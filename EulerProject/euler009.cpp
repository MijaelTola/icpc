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

int ans[5000];
int main(){
    memset(ans,-1,sizeof ans);
    for (int a = 1; a < 2000; ++a){
        for (int b = a+1; b < 2000; ++b){
            for (int c = b+1; c < 2000; ++c){
                if(c*c == a*a+b*b){
                    //cout << a+b+c << endl;
                    if(a+b+c <= 3000){
                        int sum = a*b*c;
                        ans[a+b+c] = sum;
                    }
                }
            }
        }
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << ans[n] << "\n";
    }
    return 0;
}

