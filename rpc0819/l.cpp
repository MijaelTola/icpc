#include <bits/stdc++.h> 

using namespace std; 

int v[100010];

int main() { 
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[x] = i;
    }
    
    int ans = 1;
    int c = 1;
    for (int i = 2; i <= n; ++i) {
        if(v[i - 1] < v[i]) c++;
        else c = 1;
        ans = max(ans, c);
    }
    cout << n - ans << "\n";
	return 0; 
} 


