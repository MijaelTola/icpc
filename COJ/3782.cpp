#include <bits/stdc++.h>

using namespace std;

int v[5];
int main(){
    
    int t; 
    scanf("%d",&t);
    while(t--){
        for (int i = 0; i < 5; ++i)
            scanf("%d",v + i);
    
        bool flag = true;
        for (int i = 1; i < 5; ++i)
            if(v[i] != v[i-1] + 1) flag = false;
        if(flag) puts("Y");
        else puts("N");
    }
    return 0;
}

