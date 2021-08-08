#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        auto check = [&] (long long n) {
            return n*(n+1)*(n+2)/2 >= neededApples;
        };
        
        long long a = -1, b = 1e5;
        while(b - a > 1) {
            long long mid = (a + b) / 2;
            if(check(mid)) b = mid;
            else a = mid;
        }
        
        return (b + 1) / 2 + 1;
    }
};

int main() {

    
    return 0;
}

