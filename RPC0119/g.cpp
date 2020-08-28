#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s,t;
    int x,y;
    while(cin >> s >> x >> t >> y) {
        if(x == y and s == t) {
            cout << "Draw\n";
            continue;
        }
        
            if(s[0] == 'B' and t[0] == 'D') {
                if(x < y * 2)
                    cout << "Naebbirac\n";
                else  cout << "Tobby\n";
                continue;
            }
            
            if(s[0] == 'D' and t[0] == 'C') {
                if(y < x * 2)
                    cout << "Tobby\n";
                else  
                    cout << "Naebbirac\n";
                continue;
            }

            if(s[0] == 'C' and t[0] == 'B') {
                if(x < y * 2)
                    cout << "Tobby\n";
                else  
                    cout << "Naebbirac\n";
                continue;
            }
            if(s[0] == 'D' and t[0] == 'B') {
                if(x < y * 2)
                    cout << "Naebbirac\n";
                else  cout << "Tobby\n";
                continue;
            }
            
            if(s[0] == 'C' and t[0] == 'D') {
                if(y < x * 2)
                    cout << "Tobby\n";
                else  
                    cout << "Naebbirac\n";
                continue;
            }

            if(s[0] == 'B' and t[0] == 'C') {
                if(x < y * 2)
                    cout << "Tobby\n";
                else  
                    cout << "Naebbirac\n";
                continue;
            }

    }
    return 0;
}

