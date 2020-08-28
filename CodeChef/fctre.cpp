#include <bits/stdc++.h>

using namespace std;

int sieve[1000100];
vector<int> primes;
int mx = 0;
void factor(int n){
    int index = 0;
    int pf = primes[0];
    while(pf*pf <= n){
        while(n%pf==0){
            mx = max(pf, mx);
            n /= pf;
        }
        pf = primes[++index];
    }
    if(n != 1) {
    }
}

int main() {

    memset(sieve,false,sizeof sieve);	

    for (int i = 2; i*i < 1000100; ++i){
        int c = i + i;
        while(c < 1000100){
            sieve[c] = true;
            c += i;
        }
    }

    for (int i = 2; i < 1000100; ++i)
        if(!sieve[i])	primes.push_back(i);

    for (int i = 2; i <= 1000000; ++i)
        factor(i);
    cout<<mx << "\n";


    return 0;
}

