#include <bits/stdc++.h>

using namespace std;

int n,k;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        printf("%lld\n", (long long)(n - k + 1)*(k + 1)*(k + 1)*(k + 1) - (n - k) * k * k * k);   
    }
    return 0;
}


/*
3 3 3
2 2 2
1 1 1
0 0 0

*/

