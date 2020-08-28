#include <bits/stdc++.h>

using namespace std;
string s[3];
long long n;

long long dp[200010][10];
long long f(long long pos, long long mask) {
	if(pos == n) return 1;
	if(dp[pos][mask] != -1) return dp[pos][mask];
	long long &ans = dp[pos][mask];
	ans = 0;
	if(s[0][pos] != s[1][pos] and s[1][pos] != s[2][pos] 
            and s[0][pos] != s[2][pos]) {
		//cout << pos << " here 3\n";
		//a tiene la razon
		long long mk = 0;
		mk |= (1 << 1); mk |= (1 << 2);
		if(!(mask & (1 << 1)) and !(mask & (1 << 2)))
			ans += f(pos + 1, mask | mk);
		//b tiene la razon
		mk = 0;
		mk |= (1 << 0); mk |= (1 << 2);
		if(!(mask & (1 << 0)) and !(mask & (1 << 2)))
			ans += f(pos + 1, mask | mk);
		//c tiene la razon
		mk = 0;
		mk |= (1 << 0); mk |= (1 << 1);
		if(!(mask & (1 << 0)) and !(mask & (1 << 1)))
			ans += f(pos + 1, mask | mk);
		return ans;
	}
	// 0 1
	if(s[0][pos] == s[1][pos] and s[1][pos] != s[2][pos]) {
		//cout << "here 1\n";
		//0 y 1 tienen la razon
		long long mk = 0;
		mk |= (1 << 2);
		if(!(mask & (1 << 2))) ans += f(pos + 1, mask | mk);
		mk = 0;
		//2 tiene la razon
		mk |= (1 << 0); mk |= (1 << 1);
		if(!(mask & (1 << 0)) and !(mask & (1 << 1)))
            ans += f(pos + 1, mask | mk);
		return ans;
	}
	//0 2
	if(s[0][pos] == s[2][pos] and s[1][pos] != s[0][pos]) {
		//0 y 2 tienen la razon
		//cout << "here 2\n";
		long long mk = 0;
		mk |= (1 << 1);
		if(!(mask & (1 << 1))) ans += f(pos + 1, mask | mk);
		mk = 0;
		//1 tiene la razon
		mk |= (1 << 0); mk |= (1 << 2);
		if(!(mask & (1 << 0)) and !(mask & (1 << 2))) 
            ans += f(pos + 1, mask | mk);
		return ans;
	}
	//CONTINUEAS ACA
	//1 2
	if(s[1][pos] == s[2][pos] and s[1][pos] != s[0][pos]) {
	//	cout << "final\n";
		//1 y 2 tienen la razon
		long long mk = 0;
		mk |= (1 << 0);
		if(!(mask & (1 << 0))) ans += f(pos + 1, mask | mk);
		mk = 0;
		//0 tiene la razon
		mk |= (1 << 1); mk |= (1 << 2);
		if(!(mask & (1 << 1)) and !(mask & (1 << 2))) 
            ans += f(pos + 1, mask | mk);
		return ans;
	}
	// todos van bien
	ans += f(pos + 1, mask);
	
	// todos la cagaron
	long long mk = 0;
	mk |= (1 << 0);
	mk |= (1 << 1);
	mk |= (1 << 2);
	if(!(mask & (1 << 1)) and !(mask & (1 << 2)) and !(mask & (1 << 0))) 
        ans += f(pos + 1, mask | mk);
	return ans;	
}

void r(long long pos, long long mask) {
	if(pos == n) return;
	long long ans = 0;
	if(s[0][pos] != s[1][pos] and s[1][pos] != s[2][pos] and s[0][pos] != s[2][pos]) {
		//cout << pos << " here 3\n";
		//a tiene la razon
		long long ans1 = 0;
		long long ans2 = 0;
		long long ans3 = 0;
		long long mk = 0;
		mk |= (1 << 1); mk |= (1 << 2);
		if(!(mask & (1 << 1)) and !(mask & (1 << 2)))
			ans1 = f(pos + 1, mask | mk);
			
		if(ans1 == 1) {
			cout << s[0][pos];
			r(pos + 1, mask | mk);
			return;
		}
		
		//b tiene la razon
		mk = 0;
		mk |= (1 << 0); mk |= (1 << 2);
		if(!(mask & (1 << 0)) and !(mask & (1 << 2)))
			ans2 = f(pos + 1, mask | mk);
		
		if(ans2 == 1) {
			cout << s[1][pos];
			r(pos + 1, mask | mk);
			return;
		}
		
		//c tiene la razon
		mk = 0;
		mk |= (1 << 0); mk |= (1 << 1);
		if(!(mask & (1 << 0)) and !(mask & (1 << 1)))
			ans3 = f(pos + 1, mask | mk);
		
		if(ans3 == 1) {
			cout << s[2][pos];
			r(pos + 1, mask | mk);
			return;
		}
		
		
	}
	// 0 1
	if(s[0][pos] == s[1][pos] and s[1][pos] != s[2][pos]) {
		//cout << "here 1\n";
		//0 y 1 tienen la razon
		long long ans1 = 0;
		long long ans2 = 0;
		long long mk = 0;
		mk |= (1 << 2);
		if(!(mask & (1 << 2))) ans1 = f(pos + 1, mask | mk);
		if(ans1 == 1) {
			cout << s[0][pos];
			r(pos + 1, mask | mk);
			return;
		}
		mk = 0;
		//2 tiene la razon
		mk |= (1 << 0); mk |= (1 << 1);
		if(!(mask & (1 << 0)) and !(mask & (1 << 1))) ans2 = f(pos + 1, mask | mk);
		if(ans2 == 1) {
			cout << s[2][pos];
			r(pos + 1, mask | mk);
			return;
		}
		//return ans;
	}
	//0 2
	if(s[0][pos] == s[2][pos] and s[1][pos] != s[0][pos]) {
		//0 y 2 tienen la razon
		//cout << "here 2\n";
		long long ans1 = 0;
		long long ans2 = 0;
		long long mk = 0;
		mk |= (1 << 1);
		if(!(mask & (1 << 1))) ans1 = f(pos + 1, mask | mk);
		if(ans1 == 1) {
			cout << s[0][pos];
			r(pos + 1, mask | mk);
			return;
		}
		mk = 0;
		//1 tiene la razon
		mk |= (1 << 0); mk |= (1 << 2);
		if(!(mask & (1 << 0)) and !(mask & (1 << 2))) ans2 = f(pos + 1, mask | mk);
		if(ans2 == 1) {
			cout << s[1][pos];
			r(pos + 1, mask | mk);
			return;
		}
		//return ans;
	}
	//CONTINUEAS ACA
	//1 2
	if(s[1][pos] == s[2][pos] and s[1][pos] != s[0][pos]) {
	//	cout << "final\n";
		//1 y 2 tienen la razon
		
		long long ans1 = 0;
		long long ans2 = 0;
		long long mk = 0;
		mk |= (1 << 0);
		if(!(mask & (1 << 0))) ans1 = f(pos + 1, mask | mk);
		if(ans1 == 1) {
			cout << s[1][pos];
			r(pos + 1, mask | mk);
			return;
		}
		mk = 0;
		//0 tiene la razon
		mk |= (1 << 1); mk |= (1 << 2);
		if(!(mask & (1 << 1)) and !(mask & (1 << 2))) ans2 = f(pos + 1, mask | mk);
		
		if(ans2 == 1) {
			cout << s[0][pos];
			r(pos + 1, mask | mk);
			return;
		}
		//return ans;
	}
	
	cout << s[0][pos];
	//ans += f(pos + 1, mask);
	r(pos + 1, mask);
}
int main() {
	
	ios::sync_with_stdio(false); cin.tie(0);
	memset(dp, -1,sizeof dp);
	cin >> s[0] >> s[1] >> s[2];
	n = s[0].size();
	long long ans = f(0,0);
	if(ans == 0) return  cout << "Impossible\n",0;
	if(ans > 1) return cout << "Ambiguous\n",0;
	r(0,0);
	return 0;
}		
