#include <bits/stdc++.h>

using namespace std;

struct PrimePruning {
    
    string s;
    bool p[2000010];
    vector<int> pr;

    void build() {
        for (int i = 2; i * i < 2000010; ++i)
            for (int j = i + i; j < 200010; j += i)
                p[j] = 1;

        for (int i = 2; i < 2000010; ++i)
            if(!p[i]) pr.push_back(i);
    }
    string maximize(int N, int E) {
        s = "";
        if(N >= 2000000) {
            for (int i = 0; i < N - E; ++i)
                s += 'z';
            return s;
        }
        build();
        for (int i = 0; i < N; ++i) 
            s += (char)(pr[i] % 26 + 'a');
        
        
        return s;
    }
};
int main() {
    PrimePruning p;
    cout << p.maximize(10, 0) << "\n";;
    return 0;
}

