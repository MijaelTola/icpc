
#include <iostream> 
#include <algorithm>

using namespace std; 

const int MAX = 10000001; 

int factor[MAX] = { 0 }; 

void generatePrimeFactors() { 
    factor[1] = 1; 

    for (int i = 2; i < MAX; i++) 
        factor[i] = i; 
    for (int i = 4; i < MAX; i += 2) 
        factor[i] = 2; 

    for (int i = 3; i * i < MAX; i++) { 
        if (factor[i] == i) { 
            for (int j = i * i; j < MAX; j += i) { 
                if (factor[j] == j) 
                    factor[j] = i; 
            } 
        } 
    } 
} 

int calculateNoOFactors(int n) { 
    if (n == 1)  return 1; 
    int ans = 1; 
    int dup = factor[n]; 
    int c = 1; 
    int j = n / factor[n]; 
    while (j != 1) { 
        if (factor[j] == dup) c += 1; 
        else { 
            dup = factor[j]; 
            ans = ans * (c + 1); 
            c = 1; 
        } 
        j = j / factor[j]; 
    } 
    ans = ans * (c + 1); 
    return ans; 
} 

int main() { 
    freopen("input.txt","rt", stdin);
    freopen("output.txt", "wt", stdout);
    
    generatePrimeFactors(); 
    int k; cin >> k;
    int mx = 0;
    int cur = 0;
    for (int i = 2; i <= k; ++i) {
        int x = calculateNoOFactors(i);
        if(x > mx) {
            cur = i;
            mx = x;
        }
    }
    cout << k - cur + 1 << "\n";
    return 0; 
} 
