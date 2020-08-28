#include <bits/stdc++.h>

using namespace std;

char s[100010];
char ds[100010];
int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        scanf("%s",s);
        int sz = strlen(s);
        int a,b;
        a = b = 0;
        char cur = 'C';
        for (int i = 0; i < sz; ++i)
            ds[i] = s[i];
        for (int i = 0; i < sz; ++i){
            if(s[i] == '.') s[i] = cur;
            if(s[i] == 'A') cur = 'A';
            if(s[i] == 'B') cur = 'B';
        }
        cur = 'C';
        for (int i = sz - 1; i >= 0; --i){
            if(ds[i] == '.') ds[i] = cur;
            if(ds[i] == 'A') cur  = 'A';
            if(ds[i] == 'B') cur = 'B';
        }

        for (int i = 0; i < sz; ++i){
            if(ds[i] == s[i] and s[i] == 'A') a++;
            if(ds[i] == s[i] and s[i] == 'B') b++;
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}

