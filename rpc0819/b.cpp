#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        string x;
        cin >> x;
        if(x != "mumble") {
            int y = 0;
            for (int j = 0; j < (int)x.size(); ++j) 
                y = y * 10 + (int)(x[j] - '0');
            if(y != i) return cout << "something is fishy\n",0;
        }
    }
    cout << "makes sense\n";
    return 0;
}

