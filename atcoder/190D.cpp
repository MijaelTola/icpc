#include <bits/stdc++.h> 
using namespace std; 

long long countConsecutive(long long N) 
{ 
	long long count = 0; 
	for (long long L = 1; L * (L + 1) < 2 * N; L++) 
	{ 
		auto x =  N-(L * (L + 1)) / 2; 
		if (x % (L + 1) == 0) 
			count++;		 
	} 
    
	return count + 1;
} 

int main() 
{ 

    long long n;
    cin >> n;

    cout << countConsecutive(n) * 2;
	return 0; 
} 

