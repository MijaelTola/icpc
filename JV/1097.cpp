#include <bits/stdc++.h>

using namespace std;

bool p[1000010];
vector<int> primes;
void criba(){
    memset(p,false,sizeof p);
    for (int i = 2; i*i < 1000010; ++i){
        int c = i + i;
        while(c < 1000010){
            p[c] = 1;
            c += i;
        }
    }

    for (int i = 2; i < 1000010; ++i)
        if(!p[i])primes.push_back(i);   
}

int factor(int n){
    int idx = 0;
    int pf = primes[idx];
    int ans = 0;
    while(pf * pf <= n){
        bool f = 0;
        while(n%pf == 0)f = 1, n /= pf;
        if(f) ans += pf;
        pf = primes[++idx];
    }
    if( n != 1) ans += n;
    return ans;
}
int main(){
    criba();
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        cout << factor(x) << "\n";
    }
    return 0;
}

