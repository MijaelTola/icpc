#include <bits/stdc++.h>

using namespace std;

int a[100010];
int main(){
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        priority_queue<int> mx;
        priority_queue<int> mn;
        for (int i = 0; i < n; ++i) {
            int x; cin >>  x;
            mx.push(x);
            mn.push(-x);
            a[x]++;
        }
        int q; cin >> q;
        while(q--) {
            int p,y;
            cin >> p >> y;
            if(p == 1) {
                int a = -mn.top();
                int b = mx.top();
                if(a < y) cout << a << " ";
                else cout << "-1 ";
                if(b > y) cout << b << "\n";
                else cout << 100001 << "\n";
            }
            if(p == 2) {
                mx.push(y);
                mn.push(-y);
                a[y]++;
            }
            if(p == 3) {
                a[y]--;
                while(!a[mx.top()]) mx.pop();
                while(!a[-mn.top()]) mn.pop();
            }
        }
    }
    return 0;
}


