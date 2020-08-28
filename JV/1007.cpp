#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        cin.ignore();
        int ans = -1;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            string s;
            getline(cin, s);
            string cur = "";
            vector<int> a(30);

            for (char x: s) {
                if(x != ' ') cur += x;
                else {
                    a[cur[0] - 'a']++;
                    cur = "";
                }
            }

            a[cur[0] - 'a']++;
            int b = 0;

            for (int i = 0; i < 30; ++i) 
                b = max(b, a[i]);

            if(b > mx) {
                mx = b;
                ans = i;
            }
        }
        cout << "El ganador es " << ans + 1 << "\n";
    }
    return 0;
}

