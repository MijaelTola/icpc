#include <iostream>
#include <cstring>
using namespace std;

int m[110][110];
int main(){
    
    int n; 
    while(cin >> n){
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
                cin >> m[i][j];
        
        int ans = -1;
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                int sum = 0;
                for (int k = 0; k < n; ++k){
                    sum += m[i][k];
                }
                for (int k = 0; k < n; ++k)
                        sum += m[k][j];
                sum -= m[i][j];
                ans = max(ans,sum);
            }
        }
        cout <<ans << endl;
    }
    return 0;
}
