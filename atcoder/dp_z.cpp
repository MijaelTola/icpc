#include <bits/stdc++.h>

using namespace std;

struct line {
    long long m,b;
    line() {}
    line(long long _, long long __) {
        m = _, b = __;
    }
    long long get(long long x) {
        return m * x + b;
    }
};
 
struct cht {
    vector<line> trick;
    int pos;
    cht() { pos = 0;}
    bool irrelevant(line l1, line l2, line l3) {
        return (double)(l3.b - (double)l1.b) * (double)(l1.m - l2.m) <= (double)(l2.b - l1.b) * ((double)l1.m - l3.m);
    }
    
    void add(line l) {
        while(trick.size() >= 2 
          and irrelevant(trick[trick.size() - 2], trick[trick.size() - 1], l))
            trick.pop_back();
        trick.push_back(l);
    }
 
    long long query(long long x) {
        if(pos >= (int)trick.size()) pos = trick.size() - 1;
        while(pos + 1 < (int)trick.size() and trick[pos + 1].get(x) < trick[pos].get(x))
            pos++;
        return trick[pos].get(x);
    }
};
  
int n;
long long c;
long long h[1000010];

int main() {
    scanf("%d %lld", &n, &c);

    for (int i = 0; i < n; ++i)
        scanf("%lld", h + i);
    
    cht dp;
    
    dp.add(line(-2 * h[0], h[0] * h[0]));

    long long cur = 0;
    for (int i = 1; i < n; ++i) {
        cur = dp.query(h[i]) + h[i] * h[i] + c;
        dp.add(line(-2*h[i], h[i] * h[i] + cur));
    }
    cout << cur << "\n";

    return 0;
}

