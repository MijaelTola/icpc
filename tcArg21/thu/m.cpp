#include<bits/stdc++.h>

using namespace std;

long long phi[1000001];
long long sum[1000001];
long long f[1000001];

void init(int N, int k) {
	for (int i = 1; i <= N; ++i)
        phi[i] = i;
 
	for(int i = 2;i <= N; i++)
	if(phi[i] == i) {
		for(int j = i; j <= N; j += i)
		    phi[j] /= i , phi[j] *= (i - 1);
	}
 
	for(int i = 1; i <= N; i++) {
		for(int j = i; j <= N; j += i) {
			f[j] += (i * phi[j / i]);
		}
	}
 
    for (int i = 1; i <= N; ++i) 
	    sum[i] = sum[i - 1] + f[i] - i;
 
}
 
int main() {

    int n,k;
    cin >> n >> k;
	init(1000000, k);

    long long ans = 0;

    for (int i = 1; i <= n; ++i) 
        ans += pow(i,k);
    cout << ans + 2 * sum[n] << "\n";

        

    return 0;
}

