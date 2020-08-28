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
#include <cstdlib>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
    while(cin >> n and n){
        double sum = 0;
        if(n%2 == 0){
            for (int i = 0; i <= n/2-1; i ++){
                double p = i*2+1;
                sum += p*p;
            }
        }else{
            for (int i = 1; i <= n/2; i++){
                double p = i*2;
                sum += p*p;
            }
        }
		double ans = double(sqrt((sum*2)/(n-1)));
        cout.precision(6);
		cout << fixed << ans << "\n";
    }
    return 0;
}

