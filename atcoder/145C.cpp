#include <bits/stdc++.h>

using namespace std;

vector<pair<double, double> > v;

int main() {
    
    int n,x,y;
    scanf("%d", &n);
    int f = 1;

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        v.emplace_back(x,y);
        f *= (i + 1);
    }
    
    double ans = 0;

    auto dis = [](int i, int j) {
        return sqrt((v[i].first - v[j].first) * (v[i].first - v[j].first) 
                + (v[i].second - v[j].second) * (v[i].second - v[j].second));
    };
    
    sort(v.begin(), v.end());

    do {
        for (int i = 1; i < (int)v.size(); ++i)
            ans += dis(i, i - 1);
    }while(next_permutation(v.begin(), v.end()));

    
    printf("%.10lf\n", ans / f);
    return 0;
}

