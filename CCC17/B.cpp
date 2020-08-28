#include <bits/stdc++.h>

using namespace std;

vector<int> f;
int v[10000010];
int main(){

    int a = 1, b = 1, c = 1;
    while(c < 10000010){
        c = a + b;
        f.push_back(c);
        a = b;
        b = c;
    }

    for (int i = 1; i < 10000010; ++i)
        v[i] = 1;
    for (int i = 0; i < (int)f.size(); ++i){
        int cur = f[i];
        while(cur < 10000010){
            v[cur] = 0;
            cur += f[i];
        }
    }
    
    for (int i = 1; i < 10000010; ++i)
        v[i] += v[i - 1];
    int x,y;
    scanf("%d %d", &x, &y);
    printf("%d\n", (v[y] - v[x - 1]));
    return 0;
}

