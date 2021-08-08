#include <bits/stdc++.h>

using namespace std;

int main() {

    long double k;
    string s,t;
    cin >> k >> s >> t;

    vector<long double> a(15, 0),b(15,0), tot(15,k);

    for (int i = 0; i < 4; ++i) {
        a[s[i] - '0']++;
        tot[s[i] - '0']--;
    }

    for (int i = 0; i < 4; ++i) {
        b[t[i] - '0']++;
        tot[t[i] - '0']--;
    }
 
    long double total = 0;


    for (int i = 1; i <= 9; ++i)
        total += tot[i];

    total = (total * (total - 1)) / 2;

    
    auto getA = [&] () {
        long double ca = 0;
        for (int i = 1; i <= 9; ++i) {
            long double p = 1;
            for (int j = 0; j < a[i]; ++j)
                p *= 10;
            ca += i * p;
        }
        return ca;
    };


    auto getB = [&]() {
        long double cb = 0;
        for (int i = 1; i <= 9; ++i) {
            long double p = 1;
            for (int j = 0; j < b[i]; ++j)
                p *= 10;
            cb += i * p;
        }
        return cb;
    };

    long double f = 0;

    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            if(tot[i] > 0) {
                tot[i]--;
                a[i]++;
                if(tot[j] > 0) {
                    tot[j]--;
                    b[j]++;
                    if(getA() > getB()) {
                        if(i != j) {
                            long double da = (tot[i] + 1);
                            long double db = (tot[j] + 1);
                            f += (da * db) / 2;
                        } else {
                            long double l = (tot[i] + 2);
                            f += (l * (l - 1)) / 2;
                        }
                    }
                    tot[j]++;
                    b[j]--;
                }
                a[i]--;
                tot[i]++;
            }
        }
    }
    cout.precision(12);
    cout << fixed << 1. * f / total  << "\n";
    return 0;
}

