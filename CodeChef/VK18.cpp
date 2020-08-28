#include <bits/stdc++.h>

using namespace std;


int getD(int x){
    int a = 0, b = 0;
    while(x > 0){
        int d = x % 10;
        x /= 10;
        if(d & 1) a+=d;
        else b+=d;
    }
    return abs(a - b);
}
long long v[10000100];
int main(){
    int cur = 0;
    long long ans = 0;
    for (int i = 2; i < 10000100; ++i){
        cur += getD(i);
        ans += cur;
        v[i] = ans;
    }
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", & n);
        int limit = 2 * n;
        printf("%lld\n",(long long)(v[limit] - 2*v[limit - n] ));
    }
    return 0;
}
// 2 3 3 4 4 4 5 5 5 5 6 6 6 6 6 7 7 7 7 8 8 8 9 9 10
// n = 7
// 2 3 4 5 6 7 8
// 3 4 5 6 7 8
// 4 5 6 7 8
// 5 6 7 8
// 6 7 8
// 7 8
// 8

// 9
// 10 9
// 11 10 9
// 12 11 10 9
// 13 12 11 10 9
// 14 13 12 11 10 9
//
//12 36 40 141 196 249 306 373 467

