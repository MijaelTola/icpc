#include <bits/stdc++.h>

using namespace std;

int p[1000010];
int factors[1000010];
vector<int> primes;

vector<int> factor(int n){
	int index = 0;
	int pf = primes[0];
    vector<int> ans;
	while(pf*pf <= n){
        int cnt = 0;
		while(n%pf==0){
            cnt++;
			n /= pf;
		}
        
        if(cnt > 0) factors[pf]++;
		pf = primes[++index];
	}
	if(n != 1) {
        ans.push_back(n);
        factors[n]++;
    }
    return ans;
}

int main() {

    for (int i = 2; i * i < 1000010; ++i) {
        for (int j = i + i; j < 1000010; j += i)
            p[j] = 1;
    }

    for (int i = 2; i < 1000010; ++i)
        if(!p[i]) primes.push_back(i);

    int n;
    cin >> n;
    vector<int> v(n);
    
    for (auto &x: v) {
        cin >> x;
        factor(x);
    }


    bool flag = 1;
    int gcd = v[0];

    for (int i = 0; i < n; ++i)
        gcd = __gcd(gcd, v[i]);

    for (int x: primes) {
        flag &= factors[x] <= 1;
    }

    if(flag) return cout << "pairwise coprime\n", 0;
    if(gcd == 1) return cout << "setwise coprime\n", 0;
    cout << "not coprime\n";
    return 0;
}

