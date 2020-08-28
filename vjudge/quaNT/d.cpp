#include <bits/stdc++.h>

using namespace std;

bool ok[1010];
vector<int> p;

int main() {
    
    for (int i = 2; i < 1010; ++i) 
        for (int j = i + i; j < 1010; j += i)
            ok[j] = 1;

    for (int i = 2; i < 1010; ++i)
        if(!ok[i]) p.push_back(i);


    int n;
    scanf("%d", &n);

    vector<int> ans;

    for (auto x: p) {
        int cur = x;
        while(cur <= n) {
            ans.push_back(cur);
            cur *= x;
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto x: ans)
        printf("%d ", x);
    puts("");


    return 0;
}

