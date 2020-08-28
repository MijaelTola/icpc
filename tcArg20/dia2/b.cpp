#include <bits/stdc++.h>

using namespace std;

int is[5000000];
int main() {

    for (int i = 2; i * i < 5000000; ++i)
        for (int j = i + i; j < 5000000; j += i)
            is[j] = 1;
    is[0] = is[1] = 1;
    int n;
    cin >> n;

    for (int i = 1; i <= 1000; ++i) {
        if(is[i * n + 1]) 
            return cout << i << "\n", 0;
    }



    return 0;
}

