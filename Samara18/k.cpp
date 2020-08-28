#include <bits/stdc++.h>

using namespace std;

int n,m;
int v[200010];
bool ver(int x) {
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if(cur >= v[i]) cur++;
        else if(x) cur++,x--;
    }
    return cur >= m;
}
int main() {

    scanf("%d%d",&n,&m);

    for (int i = 0; i < n; ++i) 
        scanf("%d", v + i);
    
    int a = -1;
    int b = n;

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) b = mid;
        else a = mid;
    }

    printf("%d\n",b);

    return 0;
}

