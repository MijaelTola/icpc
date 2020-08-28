#include <bits/stdc++.h>

using namespace std;

bool prime[10000010];
void criba() {
    memset(prime,false,sizeof prime);
    prime[0] = 1;
    prime[1] = 1;
    for (int i = 2; i * i < 10000010; ++i) {
        int c = i + i;
        while(c < 10000010) {
            prime[c] = 1;
            c += i;
        }
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int k; 
    string x;
    criba();
    while(cin >> k >> x) {
        int num = 0;
        bool flag = 1;
        int c = 0;
        for (int i = 0; i < (int)x.size(); ++i) {
            if(c < k ) {
                 num = num * 10 + (x[i] - '0');   
                 c++;
            }else {
                if(prime[num]) {
                    flag= 0 ;
                    break;
                }
                num = x[i] - '0';
                c = 1;
            }
        }

        if(c and prime[num]) flag = 0;
        if(flag) cout << ":)\n";
        else cout << ":(\n";
    }
    return 0;
}

