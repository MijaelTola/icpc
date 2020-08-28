#include <bits/stdc++.h>

using namespace std;

int n;
double ans = 1e9;
vector<double> b;
void f(int pos, vector<double> v) {
    if(pos == n) {
        double sum = 0;   

        for (auto x: v)
            sum += x;

        bool flag = 1;
        for (auto x: v) {
            flag &= x < sum / 2;
        }
        if(!flag) {
            if(sum < ans) {
                ans = sum;
                b = v;
            }
        }
        return;
    }
    
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i);
        f(pos + 1, v);
        v.pop_back();
    }
}

//N = 4
//{1 1 2 2}
int main() {
    
    auto check = [](vector<double> v) {
        double sum = 0;   

        for (auto x: v)
            sum += x;

        bool flag = 1;
        for (auto x: v) {
            flag &= x < sum / 2;
        }
        return flag;
    }
    cin >> n;
    vector<double> 
    for (int i = 0; i < n; ++i)
            
    f(0,{});
    cout << ans << "\n";

    for (auto x: b)
        cout << x << " ";
    cout << "\n";
    return 0;
}

