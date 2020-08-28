#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin.ignore();
    while(getline(cin,s)){
        int ans = 0;
        for (int i = 0; i < (int)s.size(); ++i){
            if(s[i] == ' ') continue;
            ans += (i + 1) * (s[i] - 'A');
        }
        cout << ans << "\n";
    }
    return 0;
}

