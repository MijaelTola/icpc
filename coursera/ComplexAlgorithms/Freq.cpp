#include <bits/stdc++.h>

using namespace std;

vector<int> G[510];
vector<pair<int,int> > p;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    for (int i = 0; i < m; ++i){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
    }
    
    for (int i = 1; i <= n; ++i){
        for (int k = 1; k <= 3; ++k){
            int icur = (i - 1) * 3 + k;
            for (int j = 0; j < (int)G[i].size(); ++j){
                int jcur = (G[i][j] - 1) * 3 + k;
                p.push_back(make_pair(-icur,-jcur));
            }
        }
    }
    
    for (int i = 0; i < n; ++i){
        p.push_back(make_pair(-(i*3 + 1), -(i * 3 + 2))); // 1 2
        p.push_back(make_pair(-(i*3 + 1), -(i * 3 + 3))); // 1 3
        p.push_back(make_pair(-(i*3 + 2), -(i * 3 + 3)));
    }
    //printf("p cnf %d %d\n",n * 3,(int)p.size() + n);
    printf("%d %d\n",(int)p.size() + n, n * 3);
    for (int i = 0; i < (int)p.size(); ++i){
        printf("%d %d 0\n",p[i].first,p[i].second);
    }    
    for (int i = 0; i < n; ++i)
        printf("%d %d %d 0\n",i * 3 + 1, i * 3 + 2, i * 3 + 3);
    return 0;
}

