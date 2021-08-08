#include <bits/stdc++.h>

using namespace std;

int main() {


    auto get = [&] (vector<int> v, int n) {
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int mn = 1e9;
            int id = -1;

            for (int j = i; j < n; ++j) {
                if(v[j] < mn) {
                    id = j;
                    mn = v[j];
                }
            }

            reverse(v.begin() + i, v.begin() + id + 1);
            ans += (id - i + 1);

        }

            return ans - 1;
    };

    int t;
    cin >> t;

    int k = 1;
    while(t--) {
        int n,c;
        cin >> n >> c;

        vector<int> v;

        for (int i = 1; i <= n; ++i) {
            v.push_back(i);
        }

        int flag = 0;
        do {
            if(get(v, n) == c) {
                flag = 1;
                break;
            }

        } while(next_permutation(v.begin(), v.end()));


        printf("Case #%d: ",k++);

        if(flag) {
            for (auto x: v)
                printf("%d ", x);
            puts("");
        } else {
            puts("IMPOSSIBLE");
        }
            
    }
    return 0;
}

