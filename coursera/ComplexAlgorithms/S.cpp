#include <bits/stdc++.h>

using namespace std;

long double tableu[110][110];
int n,m;

void print(){
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= 2*m+2; ++j)
            printf("%d ",(int)tableu[i][j]);
        puts("");
    }
}

int colPivot(){
    long double mn = 1e9;
    int id = -1;
    for (int i = 1; i <= m; ++i){
        if(tableu[0][i] < mn and tableu[0][i] < 0){
            mn = tableu[0][i];
            id = i;
        }
    }
    return id;
}

int rowPivot(int col){
    long double mn = 1e9;
    int id = -1;
    for (int i = 1; i <= n; ++i){
        long double cur = tableu[i][2*m+2] / tableu[i][col];
        if(cur < mn and cur >= 0){
            mn = cur;
            id = i;
        }
    }
    return id;
}

void pivot(int x, int y){
    long double pi = tableu[x][y];
    for (int i = 0; i <= 2 * m + 2; ++i)
        tableu[x][i] /= pi;
    for (int i = 0; i <= n; ++i){
        if(i == x) continue;
        long double cur = tableu[i][y];
        for (int j = 0; j <= 2 * m + 2; ++j){
            long double mul = cur * tableu[x][j];
            tableu[i][j] -= mul;
        }
    }
}

int simplex(){
    while(true){
        int y = colPivot();
        if(y == -1) return true;
        int x = rowPivot(y);
        if(y == -1) return 0;
        pivot(x,y);
    }
}

int basic(int col){
    int xi = -1;
    for (int i = 0; i <= n; ++i){
        if(tableu[i][col] == 1.0){
            if(xi == -1) xi = i;
            else return -1;
        }else if(tableu[i][col] != 0.0) return -1;
    }
    return xi;
}
void find(){
    long double z = 0;
    for (int i = 1; i <= m; ++i){
        int xi = basic(i);
        if(xi != -1) printf("%Lf ",tableu[xi][2 * m + 2]);
        else printf("%Lf ",z);
    }
    puts("");
}
int main(){
    scanf("%d %d",&n,&m);
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%Lf",&tableu[i][j]);
    
    for (int i = 1; i <= n; ++i){
        scanf("%Lf",&tableu[i][2*m+2]);
        tableu[i][m+i] = 1;   
    }

    for (int i = 1; i <= m; ++i){
        long double a;
        scanf("%Lf",&a);
        tableu[0][i] = -a;
    }
    tableu[0][0] = 1.0;
    print();
    simplex();
    print();
    find();
    return 0;
}

