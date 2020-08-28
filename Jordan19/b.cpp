#include <bits/stdc++.h>

using namespace std;

int p[10000100];
vector<int> pr;

void init() {
    p[0] = p[1] = 1;
    for (int i = 2; i * i < 10000010; ++i) 
        for (int j = i + i; j < 10000010; j += i) 
            p[j] = 1;

    for (int i = 2; i < 10000010; ++i)
        if(!p[i]) pr.push_back(i);
}

int main() {
    init();

    int n;
    cin >> n;
    

    for (int x: pr) {
        if(x > n) break;
        int y = abs(n - x);
        if(!p[y]) 
            return cout << x << " " << y << "\n", 0;
    }

    puts("-1");
    return 0;
}

