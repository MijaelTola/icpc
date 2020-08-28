#include <bits/stdc++.h>

using namespace std;

string a,b;
int main(){
    
    bool f = 1;
    cin.ignore();
    while(cin >> a){
        if(f != 1) puts("");
        f = 0;
        int n; 
        cin >> n;
        while(n--){
            getline(cin,b);
            int sz = b.size();
            for (int i = 0; i < sz; ++i){
                if(b[i] == ' '){
                    printf(" ");
                    continue;
                }
                for (int j = 0; j < 27; ++j)
                    if(a[j] == b[i]){
                        printf("%c", (char) (j + 'a'));
                        break;
                    }
            }
            puts("");
        }
    }
    return 0;
}

