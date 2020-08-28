#include <bits/stdc++.h>

using namespace std;

int v[10000010];

void f(int n) {
  int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int c = 0;
        for (int j = 1; j <= i; j++) {
            if(i % j == 0) c++;
        }
        if(c == 2) cnt++;
    }
    cout << cnt << "\n";
   
}

void criba(int n) {
    memset(v, 0, sizeof v);
    for (int i = 2; i * i <= n; ++i) {
        for (int j = i + i; j <= n; j += i) {
            v[j] = 1;       
        }
    }
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if(!v[i]) cnt++;
    }
    cout << cnt << "\n";
}
int main() {
    
    int n = 1000000;
    /*cout << "forma 2\n";
    criba(n);*/
    cout << "forma 1\n";
    f(n);
   return 0;
}

