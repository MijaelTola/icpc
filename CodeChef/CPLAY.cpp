#include <bits/stdc++.h>

using namespace std;

string s;
void f(int da, int db, int a,int b, int cur){
    if(cur == (int)s.size()){
        if(a > b) cout << "TEAM-A " << da + db << "\n";
        else if(b > a) cout << "TEAM-B " << da + db << "\n";
        else cout << "TIE\n";
        return;
    }
    if(cur < 10){
        if(a > b and abs(a - b) > 5 - db){
            cout << "TEAM-A " << da + db << "\n";
            return;
        }

        if(b > a and abs(a - b) > 5 - da){
            cout << "TEAM-B " << da + db<< "\n";
            return;
        }
        if(cur % 2 == 0){
            if(s[cur] == '1') f(da + 1, db, a + 1, b, cur + 1);
            else f(da + 1,db,a, b, cur + 1);
        }else {
            if(s[cur] == '1') f(da, db + 1, a, b + 1, cur + 1);
            else f(da,db + 1, a, b, cur + 1);
        }
    }else {
        if(cur % 2 == 0){
            if(a > b){
                cout << "TEAM-A " << da + db<< "\n";
                return;
            }
            if(b > a){
                cout << "TEAM-B " << da + db<< "\n";
                return;
            }
        }
        if(cur % 2 == 0){
            if(s[cur] == '1') f(da + 1, db, a + 1, b, cur + 1);
            else f(da + 1,db, a, b, cur + 1);
        }else {
            if(s[cur] == '1') f(da, db + 1, a, b + 1, cur + 1);
            else f(da,db + 1, a, b, cur + 1);
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> s) f(0,0,0,0,0);
    return 0;
}


