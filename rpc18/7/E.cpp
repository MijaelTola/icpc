#include <bits/stdc++.h>

using namespace std;

priority_queue<int> q;
int main(){
    
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        q.push(x);
    }
    
    int da = 0;int db = 0;
    bool flag = 1;
    while(!q.empty()) {
        if(flag) {
            da += q.top();
        }else {
            db += q.top();
        }
        q.pop();
        flag = !flag;
    }

    cout << da << " " << db << "\n";
    
    return 0;
}

