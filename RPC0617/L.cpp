#include <bits/stdc++.h>

using namespace std;

string s;
int v[] = {16,56,96,36,76};
int main(){
    
    int t;
    scanf("%d",&t);
    while(t--){
        cin >> s;
        int sz = s.size();
        if(sz == 1){
            if(s[0] == '1'){
                puts("66");
                continue;
            }
            if(s[0] == '0'){
                puts("1"); continue;
            }
        }
        int mod = 0;
        for (int i = 0; i < sz; ++i)
            mod = (mod*10 + (int)(s[i] - '0'))%5;
        printf("%d\n",v[(mod + 5 - 1)%5]);
    }
    return 0;
}

