#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    string s;
    cin >> n >> s;

    if(n & 1) return puts("No"),0;
    
    auto a = s.substr(0, n / 2);
    auto b = s.substr(n / 2, n);

    puts(a == b ? "Yes": "No");
    return 0;
}

