#include <bits/stdc++.h>

using namespace std;

int main(){
        
    int t; 
    scanf("%d",&t);
    for (int k = 1; k <= t; ++k) {
        int a;
        scanf("%d", &a);
        int i = 3;
        while(true) {
            printf("3 %d\n",i);
            fflush(stdout);
            int x,y;
            scanf("%d %d", &x, &y);
            if(x == 3 and y == i) i++;
            if(x == 0 and y == 0) break;
            if(x == -1 and y == -1) return 0;
        }
    }
    return 0;
}

