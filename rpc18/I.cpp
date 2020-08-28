#include <bits/stdc++.h>

using namespace std;

string names[510];
map<string,int> val;
vector<int> G[510];
vector<int> ans;
int way[510];
bool vis[510];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
        val[names[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        string name;
        int c;
        cin >> name >> c;
        int u = val[name];
        cin.ignore();
        bool first = 0;
        while(c--) {
            string command;
            getline(cin,command);
            string curn = "";
            for (int j = 0; j < (int)command.size(); ++j) {
                if(command[j] != ' ' and command[j] != ','){
                    curn += command[j];
                }else {
                    if(first)assert(curn == "import");
                    first = 0;
                    if(curn == "" or curn == "import") {
                        curn = "";
                        continue;
                    }
                    int v = val[curn];
                    G[u].push_back(v);
                    curn = "";
                }
            }
            
            if(curn != "" and curn != "import") {
                int v = val[curn];
                G[u].push_back(v);

            }
        }
    }
    
    int a = INT_MAX;
    for (int i = 0; i < n; ++i) {
        queue<pair<int,int> > q;
        q.push(make_pair(i,0));
        memset(way,-1,sizeof way);
        memset(vis,0,sizeof vis);
        way[i] = i;
        while(!q.empty()) {
            int u = q.front().first;
            int c = q.front().second;
            q.pop();
            if(u == i and c > 0) {
                if(c >= a) continue;
                a = c;
                ans.clear();
                int cur = way[u];
                while(cur != u) {
                    ans.push_back(cur);
                    cur = way[cur];
                }
                ans.push_back(u);
                break;
            }
            if(vis[u]) continue;
            vis[u] = 1;
            for (int v: G[u]) {
                way[v] = u;
                q.push(make_pair(v,c + 1));
            }
        }
    }
    if(ans.size() == 0) return cout << "SHIP IT\n",0;
    for (int i = ans.size() - 1; i >= 0; --i) 
        cout << names[ans[i]] << " ";
    cout << "\n";
   return 0;
}

