#include <bits/stdc++.h>
  
using namespace std;
  
int sset(int n, int ans) {
    while(n > 0) {
        if(ans & (1 << (n % 10))) return -1e9;
        ans |= (1 <<(n % 10));
        n /= 10;
    }
    return ans;
}
  
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    int a1 = 1023;
    int a2 = 1022;
    while(cin >> n) {
        vector<pair <int,int> > ans;
        bool sw = 0;
        for (int i = 1000; i < 99999; ++i) {
            int den = i * n;
            int mk = 0;
            mk |= sset(den,0);
            mk |= sset(i,mk);
            mk |= 1;
            if(den == (int)den and den < 100000 and den >= 1000 
                    and (mk == a1 or mk == a2)) {
                sw = 1;
                ans.push_back({den, i});
            }
        }
        if(!sw){
            cout << "No hay soluciones para " << n << "\n";
        } else {
            sort(ans.begin(), ans.end());
            for (pair<int,int> p: ans)
                cout << p.first << " / " << p.second << " " <<  n<< "\n";
        }
    }
    return 0;
}
