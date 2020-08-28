#include <bits/stdc++.h>

using namespace std;

char m[110][110];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int r,c;
        cin >> r >> c;

        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j){
                cin >> m[i][j];
            }

        int ans = 0;

        for (int i = 0; i < r; ++i){
            for (int j = 0; j < c; ++j){
                if(i % 2 ==0){
                    if(j % 2 == 0){
                        if(m[i][j] == 'R'){
                            ans += 5;
                        }
                    }else{
                        if(m[i][j] == 'G'){
                            ans += 3;
                        }
                    }
                }else{
                    if(j % 2 == 0){
                        if(m[i][j] == 'G'){
                            ans += 3;
                        }
                    }else{
                        if(m[i][j] == 'R'){
                            ans += 5;
                        }
                    }
                }
            }
        }


        int ans2 = 0;

        for (int i = 0; i < r; ++i){
            for (int j = 0; j < c; ++j){
                if(i % 2 ==0){
                    if(j % 2 == 0){
                        if(m[i][j] == 'G'){
                            ans2 += 3;
                        }
                    }else{
                        if(m[i][j] == 'R'){
                            ans2 += 5;
                        }
                    }
                }else{
                    if(j % 2 == 0){
                       if(m[i][j] == 'R'){
                            ans2 += 5;
                        }
                    }else{
                        if(m[i][j] == 'G'){
                            ans2 += 3;
                        }
                    }
                }
            }
        }
        cout << min(ans,ans2) << "\n";
    }
    return 0;
}

