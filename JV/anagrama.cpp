#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    string x,y;
    cin.ignore();
    while(n--){
        getline(cin,x);
        getline(cin,y);
        //cout << x << " " << y << " asfasdfsadf " << "\n";
        string dx = "",dy = "";
        for (int i = 0; i < (int)x.size(); ++i)
                if(x[i] != ' ') dx += x[i];
        
        for (int i = 0; i < (int)y.size(); ++i)
                if(y[i] != ' ') dy += y[i];
        sort(dx.begin(),dx.end());
        sort(dy.begin(),dy.end());
        //cout << dx << " " << dy << "\n";
        if(dx == dy) cout << "Si" << "\n";
        else cout << "No" << "\n";
    }
    return 0;
}
