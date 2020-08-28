#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;

int n,m;
int mat[110][110];
int dp[110][110][110];

// fila columna

int f(int row, int pos,int num){
	if(pos == n+1 or row == m) return 0;
	if(dp[row][pos][num] != -1) return dp[row][pos][num];
	int ans = 0;
	ans = max(ans,f(row,pos+1,num));
	ans = max(ans,f(row+1,pos,num));
	if(num-pos>=0)ans = max(ans,f(row+1,0,num-pos)+mat[row][pos]);
	return dp[row][pos][num] = ans;
}
int main(){
	memset(dp,-1,sizeof dp);
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> mat[i][j];
	cout << f(0,0,n) << "\n";
	return 0;
}

/*
5 3
1 4 10 1 1
1 1 8 1 1
1 1 9 1 1
*/
