#include <bits/stdc++.h>

using namespace std;

map<string,int> mp;
map<int,string> mv;
queue<int> q;
int b[2];
int w[2];
queue<pair<int,int> > A[100];
int main(){
    int n; cin >> n;

    for (int i = 0; i < n; ++i){
        string x; cin >> x;
        mp[x] = i;
        mv[i] = x;
        q.push(i);
    }

    w[1] = q.front(); q.pop();
    b[1] = q.front(); q.pop();
    w[0] = q.front(); q.pop();
    b[0] = q.front(); q.pop();
    string x; cin >> x;

    int cur = 0;
    int win = -1;
    int ans = 0;
    for (int i = 0; i < (int)x.size(); ++i){
        if(x[i] == 'W'){
            if(win == 0 or win== -1){}
            else{
                ans = max(ans,cur);
                A[cur].push({b[0],b[1]});
                //cout << mv[b[0]] << " " << mv[b[1]] << " " << cur <<  "\n";
                cur = 0;
            }
            q.push(b[0]);
            b[0] = b[1];
            b[1] = q.front();
            q.pop();
            swap(w[0],w[1]);
            win = 0;
            cur++;
        }else{
            if(win == 1 or win == -1){}
            else{
                //cout << mv[w[0]] << " " << mv[w[1]] << " " << cur << "\n";
                ans = max(ans,cur);
                A[cur].push({w[0],w[1]});
                cur = 0;
            }
            win = 1;
            q.push(w[0]);
            w[0] = w[1];
            w[1] = q.front();
            q.pop();
            swap(b[0],b[1]);
            cur++;
        }
        cout << cur << " asdf\n";
    }
    if(win == 0) A[ans].push({w[0],w[1]});
    else A[ans].push({b[0],b[1]});
    while(!A[ans].empty()){
        cout << mv[A[ans].front().first] << " " << mv[A[ans].front().second] << "\n";
        A[ans].pop();
    }
    return 0;
}

