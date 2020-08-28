#include <bits/stdc++.h>

using namespace std;

int n,m;
int G[35][35];
vector<pair<int,int> > p;
int main(){
    memset(G,-1,sizeof G);
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; ++i){
        int x,y;
        scanf("%d%d",&x,&y);
        G[x][y] = 1;
        G[y][x] = 1;
    }
    
    // no j cant appear twice in a path
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < n; ++j){
            int curi = i + j * n;
            for (int k = j + 1; k < n; ++k){
                int curj = i + k * n;
                p.push_back(make_pair(-curi,-curj));
            }
        }
    }

    // no two nodes occup the same positions
    for (int i = 0; i < n; ++i){
        for (int j = 1; j <= n; ++j){
            for (int k = j + 1; k <= n; ++k)
                p.push_back(make_pair(-(j + i * n),-(k + i * n)));
        }
    }

    //nonadjacent nodes i and j cannnot be adjacent in the path
    
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if(G[i][j] == -1 and i != j){
                for (int k = 0; k < n; ++k){
                    int curi = -(i + k * n);
                    int curj = -(j + (k + 1) * n);
                    if(abs(curj) > n*n or abs(curi) > n*n) continue;
                    p.push_back(make_pair(curi,curj));
                }
            }
        }
    }

    printf("%d %d\n",(int)p.size() + 2*n, n * n);
    for(int i = 0; i < (int)p.size(); ++i)
        printf("%d %d 0\n",p[i].first,p[i].second);

    //each node j must appear in the path
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < n; ++j)
            printf("%d ", i + j * n);
        puts("0");
    }

    //every position on the path must be occupied
    for (int i = 0; i < n; ++i){
        for (int j = 1; j <= n; ++j)
            printf("%d ", j + i * n);
        puts("0");
    }
    return 0;
}

