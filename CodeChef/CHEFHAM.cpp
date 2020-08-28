#include <bits/stdc++.h>

using namespace std;

int ans[100010];
int b[100010];
bool vis[100010];
vector<int> v[100010];
int main(){

    int t;
    scanf("%d",&t);

    while(t--){
        memset(vis, false,sizeof vis);
        queue<pair<int,int> > one;
        queue<pair<int,int> > two;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i){
            int x;
            scanf("%d",&x);
            b[i] = x;
            v[x].clear();
            v[x].push_back(i);
        }
        for (int i = 0; i < n; ++i){
            if(v[b[i]].size() == 2 and !vis[b[i]]){
                two.push(make_pair(b[i],v[b[i]][0]));
                two.push(make_pair(b[i],v[b[i]][1]));
                vis[b[i]] = 1;
            }
            else if(v[b[i]].size() == 1) one.push(make_pair(b[i],v[b[i]][0]));
        }

        int answer = 0;
   /*     while(two.size() and one.size()){
            int op = one.front().second;
            int o = one.front().first;
            int tp = two.front().second;
            int t = two.front().first;
            one.pop();
            two.pop();
            ans[op] = t;
            one.push(make_pair(o,tp));
        
        }*/

        while(two.size() >= 2){
            int f = two.front().first;
            int fp = two.front().second;
            two.pop();
            int s = two.front().first;
            int sp = two.front().second;
            if(f == s){
                two.push(make_pair(f,fp));
            }else {
                two.pop();
                ans[fp] = s;
                ans[sp] = f;
            }
        }
   /*     while(two.size()){
            one.push(two.front());
            two.pop();
        }*/
        while(one.size() >= 2){
            int f = one.front().first;
            int fp = one.front().second;
            one.pop();
            int s = one.front().first;
            int sp = one.front().second;
            one.pop();
            ans[fp] = s;
            one.push(make_pair(f,sp));
        }

        /*while(one.size()){
            ans[one.front().second] = one.front().first;
            one.pop();
        }*/
        for (int i = 0; i < n; ++i){
            if(b[i] != ans[i]) answer++;
        }
        printf("%d\n",answer);
        for (int i = 0; i < n; ++i){
            printf("%d ",ans[i]);
        }
        puts("");

    }
    return 0;
}


// 1 2 2 1 3 4 5 6 6
// 2 2 1 1 6 6
// 3 4 5 2 2 1 1 6 6 
// 3 4 5 2 1 1 6 6


