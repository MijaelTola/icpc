#include <bits/stdc++.h>

using namespace std;

bool v[210];
vector<int> p;
void criba(){
    memset(v,0,sizeof v);
    for (int i = 2; i*i <= 200; ++i){
        int c = i + i;
        while(c < 200){
            v[c] = 1;
            c += i;
        }
    }
    for (int i = 2; i <= 200; ++i){
        if(!v[i]) p.push_back(i);
    }
}
int main(){

    criba();
    int n,x;
    while(cin >> n >> x){
        int a = 1, b = 0;

        double ans = 0.0;
        for (int i = 0; i < n; ++i){
            double c = a + b;
            a = b;
            b = c;
            ans = ans + (double)(c / ((double)p[i] * x));
        }
        cout.precision(2);
        cout  << fixed << ans << "\n";
    }
    return 0;
}

