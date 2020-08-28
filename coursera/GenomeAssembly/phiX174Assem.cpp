#include <bits/stdc++.h>

using namespace std;

struct StringReconstruction {

    vector<vector<int> > G;
    vector<int> in, out;
    map<string,int> mp;
    vector<string> reads;
    int k, ini;
    StringReconstruction(int dk) {
        k = dk;
        G.resize(300010);
        in.resize(300010);
        out.resize(300010);
        reads.resize(300010);
    };

    void build(const vector<string> &Reads) {
        int cur = 0;
        for (auto s: Reads) {
            string a = s.substr(0, k - 1);
            string b = s.substr(1, k - 1);
            if(!mp.count(a)) {
                reads[cur] = a;
                mp[a] = cur++;
            }
            if(!mp.count(b)) {
                reads[cur] = b;
                mp[b] = cur++;
            }
            int x = mp[a];
            int y = mp[b];
            G[x].push_back(y);
            in[y]++;
            out[x]++;
        }

        int id1 = 0, id2 = -1;

        for (int i = 0; i < 300010; ++i) {
            if(in[i] != out[i]) {
                if(in[i] < out[i]) id1 = i;
                else id2 = i;
            }
        }
        ini = id1;
        if(id2 != -1)G[id2].push_back(id1);
    }

    vector<int> findCycle() {
        stack<int> s;
        vector<int> cycle;
        s.push(ini);
        int u = ini;
        while(!s.empty()) {
            if(G[u].size()) {
                s.push(u);
                int v = G[u].back();
                G[u].pop_back();
                u = v;
            } else {
                cycle.push_back(u);
                u = s.top();
                s.pop();
            }
        }
        return cycle;
    }
        
    string findGenome() {
        auto genome = findCycle();
        reverse(genome.begin(), genome.end());
        string ans = "";
        ans += reads[genome[0]];
        for (int i = 1; i <= (int)genome.size() - k; ++i)
            ans += reads[genome[i]].back();
        return ans;
    }

};

int main() {

    int k = 0;
    vector<string> v;
    string s;
    while(cin >> s) {
        k = s.size();
        v.push_back(s);
    }
    StringReconstruction r(k);
    
    r.build(v);

    cout << r.findGenome() << "\n";

    

    return 0;
}

