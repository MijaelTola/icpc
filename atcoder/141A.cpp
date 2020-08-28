#include <bits/stdc++.h>

using namespace std;

string v[] = {"Sunny", "Cloudy", "Rainy"};

int main() {
    string x;
    cin >> x;

    int p = 0;
    while(v[p] != x) p++;

    cout << v[(p + 1) % 3] << "\n";
    return 0;
}

