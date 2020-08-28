#include <bits/stdc++.h>

using namespace std;

long double A[110][110];
long double b[110],c[110];

long double x[110];
const long double EPS = 1e-9;
struct simplex{
    int m,n;
    int B[110],N[110];
    long double D[110][110];

    simplex(int _n, int _m){
        m = _n;
        n = _m;
        for(int i = 0; i < m;i++)
            for(int j = 0; j < n;j++)
                D[i][j] = A[i][j];
        for(int i  = 0; i < m;i++){
            B[i] = n + i;D[i][n] = -1, D[i][n + 1] = b[i];
        }
        for(int i = 0; i < n;i++){ N[i] = i; D[m][i] = -c[i]; }
        N[n] = -1; D[m + 1][n] = 1;
    }

    void pivot(int r, int s){
        double inv = 1.0 / D[r][s];
        for(int i = 0; i < m + 2;i++)
            if(i != r)
                for(int j = 0; j < n + 2;j++)
                    if(j != s)
                        D[i][j] -= D[r][j] * D[i][s] * inv;
        for(int j = 0; j < n + 2;j++)
            if(j != s)
                D[r][j] *= inv;
        for(int i = 0; i < m + 2;i++)
            if(i != r)
                D[i][s] *= -inv;
        D[r][s] = inv;
        swap(B[r],N[s]);
    }

    bool simplex1(int phase){
        int x = phase == 1? m + 1:m;
        while(true){
            int s = -1;
            for(int j = 0; j <= n;j++){
                if(phase == 2 && N[j] == -1)continue;
                if(s == -1 or D[x][j] < D[x][s] or D[x][j] == D[x][s] and N[j] < N[s])s = j;
            }
            if(D[x][s] > -EPS)return true;
            int r = -1;

            for(int i = 0; i < m;i++){
                if(D[i][s] < EPS)continue;
                if(r == -1 or D[i][n + 1] / D[i][s] < D[r][n + 1] / D[r][s] or (D[i][n + 1] / D[i][s]) == (D[r][n + 1] / D[r][s]) and B[i] < B[r])
                    r = i;
            }
            if(r == -1)return false;
            pivot(r,s);
        }
    }

    int solve(){
        int r = 0;
        for(int i = 1; i < m;i++)
            if(D[i][n + 1] < D[r][n + 1]) r = i;
        if(D[r][n + 1] < -EPS){
            pivot(r,n);
            if(!simplex1(1) or D[m + 1][n + 1] < -EPS)return -1;
            for(int i = 0; i < m;i++)
                if(B[i] == -1){
                    int s = -1;
                    for(int j = 0; j <= n;j++)
                        if(s == -1 or D[i][j] < D[i][s] or D[i][j] == D[i][s] and N[j] < N[s]) s = j;
                    pivot(i,s);
                }
        }
        if(!simplex1(2))return 1;
        for(int i = 0; i < m;i++)
            if(B[i] < n)
                x[B[i]] = D[i][n + 1];
        return 0;
    }
};
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    //cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) //cin >> M[i][j];
    scanf("%Lf",&A[i][j]);
    for (int i = 0; i < n; ++i) //cin >> b[i];
    scanf("%Lf",&b[i]);

    for (int i = 0; i < m; ++i) //cin >> c[i];
    scanf("%Lf",&c[i]);
    simplex S(n,m);
    int cur = S.solve();
    if(cur == 0){
        puts("Bounded solution");
        for (int i = 0; i < m; ++i)
            printf("%.20Lf ",x[i]);
        puts("");
    }
    if(cur == -1) puts("No solution");
    if(cur == 1) puts("Infinity");
    return 0;
}

