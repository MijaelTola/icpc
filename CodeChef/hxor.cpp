#include <bits/stdc++.h>

using namespace std;


#include <bits/stdc++.h>

using namespace std;

int a[33];
int b[33];
int current[33];

void f(int n, int k, vector<long long> v) {


    for (int i = 0; i < 33; ++i) 
        a[i] = b[i] = current[i] = 0;


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 32; ++j) {
            if(v[i] & (1 << j)) a[j]++;
            else b[j]++;
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 31; j >= 0; j--) {
            if(v[i] & (1 << j)) {
                if(!current[j]) {
                    if(i + 1 < n and k) {
                        k--;
                        current[j]++;
                    } else continue;
                } else current[j]--;
                v[i] ^= (1 << j);
            }
        }
    }


    for (int i = 31; i >= 0; i--) {
        if(current[i] & 1) {
            v[n - 1] ^= (1 << i);
        }
    }

    for (int i = 31; i >= 0 and k; i--) {
        if(v[n - 1] & (1 << i)) {
            if(a[i] > 1 and b[i]) {
                k--;
                v[n - 1] ^= (1 << i);
            }
        }
    }


    for (int i = 31; i >= 0; i--) {
        if(a[i] > 1 and b[i] and k) {
            k--;
        }
    }


    if(k & 1) {
        v[n - 1] ^= 1;
        v[n - 2] ^= 1;
    }

    for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
    cout << "\n";
}

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<long long> v(n), cnt(33, 0);

        for (auto &x: v) {
            cin >> x;
            for (int i = 0; i < 32; i++) {
                if(x & (1LL << i)) cnt[i]++;
            }
        }

        int tot = 0;

        for (int i = 0; i < 33; ++i) {
            tot += cnt[i] / 2;
            if(tot & 1 && !(v.back() & (1LL << i)))
                tot++;
        }


        if(k >= tot and n > 2) {
            for (int i = 0; i < n - 1; ++i) 
                cout << "0 ";

            long long last = 0;           

            for (int i = 0; i < 33; ++i) 
                if(cnt[i] & 1) last |= (1LL << i);
            cout << last << "\n";

            continue;
        }

        f(n,k,v);

    }
    return 0;
}
