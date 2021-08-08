#include <bits/stdc++.h>

using namespace std;

char c [] = {'Q','W','E'};

int main() {
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                vector<char> v = {c[i], c[j], c[k]};
                sort(v.begin(), v.end());
                do {

                } while(next_permutation(v.begin(), v.end()));
            }
        }
    }
    return 0;
}

