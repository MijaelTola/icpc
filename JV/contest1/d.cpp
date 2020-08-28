#include <bits/stdc++.h>

using namespace std;

int v[110];
int n;

bool puede(int k) {
    int carvajal = 0;
    int osito = 0;
    for (int i = 0; i < n; ++i) {
        carvajal += v[i];
        osito += k - v[i];
        if(k < k - v[i] or k < v[i]) return 0;
    }
    return osito > carvajal;
}
int main() {

    while(cin >> n) {
        for (int i = 0; i < n; ++i) 
            cin >> v[i];

        int a = -1; 
        int b = 10010;

        while(b - a > 1) {
            int medio = (a + b) / 2;
            if(puede(medio)) b = medio;
            else a = medio;
        }
        cout << b << "\n";
    }
    return 0;
}

