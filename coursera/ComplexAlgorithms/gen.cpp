#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n = 500;
    int m = 1000;
    cout << n << " " << m << "\n";
    for (int i = 0; i < m; ++i){
        int x = (random()*random()) % n + 1;
        int y = random() % n + 1;
        cout << x << " " << y << "\n";
    }
    return 0;
}

