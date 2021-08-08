#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> v, ac;
int dp[110][400][400];
int dp2[110][4000];

int f(int pos, int da, int db) {
    if(pos == n) {
        if(da >= k and db >= k) return 0;
        return 1e9;
    }

    int &ans = dp[pos][da][db];

    if(ans != -1) return ans;
    ans = 1e9;

    if(da < k) ans = min(ans, f(pos + 1, da + v[pos], db) + 1);
    if(db < k) ans = min(ans, f(pos + 1, da, db + v[pos]) + 1);
    ans = min(ans, f(pos + 1, da, db));
    return ans;

}

int r(int pos, int sum) {
    if(pos == n) {
        int sum2 = ac[pos - 1] - sum;
        if(sum >= k and sum2 >=k) return 0;
        return 1e9;
    }

    int sum2 = ac[pos - 1] - sum;
    //cout << pos << " - " << v[pos] << ": " << sum << " " << sum2 << endl;
    if(sum >= k and sum2 >= k) {
        return 0;
    }

    int &ans = dp2[pos][sum];
    if(ans != -1) return ans;
    ans = 1e9;

    if(sum < k) 
        ans = min(ans, r(pos + 1,sum + v[pos]) + 1);
    ans = min(ans, r(pos + 1, sum) + 1);
    return ans;
}

int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    //int t;
    //cin >> t;

    //while(t--) {
    //

    int cnt = 0;
    while(1) {
        cnt++;
        memset(dp, -1, sizeof dp);
        memset(dp2, -1, sizeof dp2);
        //cin >> n >> k;

        n = 10;
        k = rand() % 100 + 1;
        v.clear();
        ac.clear();

        for (int i = 0; i < n; ++i) {
            int r = rand() % 100 + 1;
            //r = min(r, k);
            v.push_back(r);
            ac.push_back(r);
        }


        sort(v.rbegin(), v.rend());
        sort(ac.rbegin(), ac.rend());

        for (int i = 1; i < (int)ac.size(); ++i)
            ac[i] += ac[i - 1];

        int res = f(0,0,0);
        if(f(0,0,0) == 1e9) res = -1;
        
        int res2 = r(0,0);
        if(res2 == 1e9) res2 = -1;

        if(res2 != res) {
            cout << cnt << ":\n";
            cout << n << " " << k << "\n";
            
            for (auto x: v)
                cout << x << " ";
            cout << "\n";
            cout << res << " " << res2 << endl;
            exit(0);

        }
        //exit(0);
        continue;

        long long ans = -1;

        for (int i = 0; i < n; ++i) {

            long long a = 0, b = 0;

            for (int j = 0; j <= i; ++j) {
                a += v[j];
            }

            for (int j = 0; j <= i and b < k and a >= k; ++j) {
                if(a - v[j] >= k) {
                    if(b + v[j] >= k) {
                        a -= v[j];
                        b += v[j];
                    } else {
                        if(a - v[j] - v[i] >= k) {
                            a -= v[j];
                            b += v[j];
                        }
                    }
                }

            }

            if(a >= k and b >= k) {
                //cout << a << " " << b << endl;
                ans = i + 1;
                break;
            }
        }

        if(res != ans) {

            cout << cnt << ":\n";
            cout << n << " " << k << endl;

            for (auto x: v)
                cout <<  x << " ";
            cout << "\n";
            cout << res << " " << ans << "\n";
            exit(0);
        }
    }

    //}



    return 0;
}

