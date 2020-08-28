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
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;

long double tableu[110][110];
long double systems[110][110];
long double x[110];
int n,m;
const long double EPS = 1.0e-15;
int equal(long double a, long double b){
    return fabs(a-b)<EPS;
}
void getSlack(){
    for (int i = 0; i <= n; ++i)
        tableu[i][i+m+1] = 1;
}

int pivotCol(){
    long double mn = tableu[0][1];
    int id = 1;
    for (int i = 1; i <= m; ++i){
        if(tableu[n][i] < mn){
            id = i;
            mn = tableu[n][i];
        }
    }
    if(mn >= 0.0) return -1;
    return id;
}

int pivotRow(int col){
    long double mn = -1;
    int id = 0;
    bool flag = false;
    for (int i = 0; i < n; ++i){
        long double ratio = tableu[i][0]/tableu[i][col];
        if(tableu[i][col] > 0) flag = true;
        if((ratio >= 0 and ratio < mn) or mn < 0){
            id = i;
            mn = tableu[i][0]/tableu[i][col];
        }
    }
    if(!flag) return -2;
    if(mn == -1.0) return -1;
    return id;
}

void pivot(int row, int col){
    long double pi = tableu[row][col];
    for (int i = 0; i <= m+n+1; ++i)
        tableu[row][i] /= pi;

    for (int i = 0; i <= n; ++i){
        long double mul = tableu[i][col];
        if(i == row) continue;
        for (int j = 0; j <= n+m; ++j)
            tableu[i][j] -= mul*tableu[row][j];
    }
}

int basic(int col){
    int xi = -1;
    for (int i = 0; i < n; ++i){
        if(equal(tableu[i][col],(long double)1.0)){
            if(xi == -1) xi = i;
            else return -1;
        }else if(!equal(tableu[i][col],0)) return -1;
    }
    return xi;
}
void find(){
    for (int i = 1; i <= m; ++i){
        int xi = basic(i);
        if(xi != -1) x[i] = tableu[xi][0];
        else x[i] = 0;
    }
}
void print(){
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= n+m+1; ++j)
            cout << tableu[i][j] << " ";
        cout << endl;
    }
}
bool verifySolution(){
    for (int i = 0; i < n; ++i){
        long double ans = 0;
        for (int j = 1; j <= m+n; ++j)
            ans += systems[i][j]*x[j];
        if(ans > systems[i][0]) return false;
    }
    return true;
}
int simplex(){
    getSlack();
    //print();
    while(true){
        int col = pivotCol();
        if(col == -1) break; //gotten optimized solution
        int row = pivotRow(col);
        if(row == -1) return 0; // no solution
        if(row == -2) return -1; //infinity
        pivot(row,col);
    }
    find();
    //if(!verifySolution()) return 0;
   return 1;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 1; j <= m; ++j){
            cin >> tableu[i][j];
            systems[i][j] = tableu[i][j];
        }
    
    for (int i = 0; i < n; ++i){
        cin >> tableu[i][0];
        systems[i][0] = tableu[i][0];
    }

    for (int i = 1; i <= m; ++i) {
        cin >> tableu[n][i];
        tableu[n][i] *= -1;
    }
    //print();
    int ans = simplex();
    if(ans == 1){
        cout << "Bounded solution\n";
        cout.precision(15);
        for (int i = 1; i <= m; ++i) cout<<fixed << x[i] << " ";
        cout << "\n";
    }else if(ans == -1) cout << "Infinity\n";
    else cout << "No solution\n";
    return 0;
}

