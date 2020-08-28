#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

int m[30][30];
int a[30][30];
int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j){
                cin >> m[i][j];
                a[i][j] = m[i][j];
                if(i > 0) m[i][j] += m[i-1][j];
                if(j > 0) m[i][j] += m[i][j-1];
                if(i > 0 and j > 0) m[i][j] -= m[i-1][j-1];
            }

        bool flag = true;
        int sq = sqrt(n);
        int total = (n*(n+1))/2;
        //cout << total << endl;
        for (int i = 0; i < n; i+=sq){
            for (int j = 0; j < n; j += sq){
                int disx = i+sq-1;
                int disy = j+sq-1;
                int sum = m[disx][disy];
                sum -= m[i-1][disy];
                sum -= m[disx][j-1];
                sum += m[i-1][j-1];
        //        cout << i << " " << j << " " << disx << " " << disy << " "<< sum<< endl;
                if(sum != total){
                    flag = false; break;
                }
            }
            if(!flag) break;
        }
        if(flag){
            for (int i = 0; i < n; ++i){
                int row = 0;
                int column = 0;
                for (int j = 0; j < n; ++j){
                    row += a[i][j];
                    column += a[j][i];
                }
                if(row != total or column != total){
               //     cout << "entra " << i << " "  << row << " " << column << " " << total << endl;
                    flag = false; break;
                }
            }
        }
        if(flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}

