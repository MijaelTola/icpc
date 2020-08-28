#include <bits/stdc++.h>

using namespace std;

int dp[500010];
int main(){
    
    for (int i = 2; i < 500010; ++i){
        for (int j = i; j < 500010; j += i)
            dp[j]++;
    }
    
    int x;
    while(scanf("%d",&x) and x) printf("%d\n",dp[x] + 1);
    return 0;
}

