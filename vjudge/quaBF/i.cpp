#include <bits/stdc++.h>

using namespace std;

int main() {

    int a,b,c,d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    deque<int> ans;
    int mn = min(a,b);
    for (int i = 0; i < mn; ++i) {
        ans.push_back(0);
        ans.push_back(1);
    }

   



    return 0;
}

