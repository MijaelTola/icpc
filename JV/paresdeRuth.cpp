#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool sieve[1000100];
vector<int> primes;
vector<pair<int,int> >v;

int factorizar(int n){
	int index = 0;
	int pf = primes[0];
	int ans = 0;
	while(pf*pf <= n){
		bool flag = false;
		while(n%pf == 0){
			if(!flag) ans += pf;
			flag = true;
			n/=pf;
	//		cout << pf << endl;
		}
		pf = primes[++index];
	}
	if(n != 1) ans += n;
	return ans;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	for (int i = 2; i*i < 1000100; ++i){
                int c = i+i;
                while(c < 1000100){
                        sieve[c] = -1;
                        c+= i;
                }
        }
        for (int i = 2; i < 1000100; ++i)
                if(sieve[i] == 0)  primes.push_back(i);
	int last = factorizar(1);
	for (int i = 2; i < 1000100; ++i){
		int b = factorizar(i);
		if(last == b) v.push_back({i-1,i});
		last = b;
	}
	
	int n, m;
	while( cin >> n >> m){
		for (int i = 0; i < v.size(); ++i){
			if(v[i].first >= n and v[i].second <= m)
				cout << v[i].first << " " << v[i].second << "\n";
		}
	}
	for (int i = 0; i < n; ++i){
		int	
		}
	return 0;
}
