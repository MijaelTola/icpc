#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    for (int i = 1; i <= 9; ++i)
        if(n % i == 0 and n / i <= 9) return puts("Yes"),0;

    puts("No");
    return 0;
}

