#include <bits/stdc++.h>

using namespace std;

struct GenomeAssembly {

    const int error = 2;
    int mer;
    vector<string> reads;
    GenomeAssembly(int k) {
        mer = k;
    }
    int overlap(string a, string b, int mer) {
        for (int i = 0, n = 1 + a.size() - mer; i < n; ++i) {
            int errors = 0;
            for(int j = 0, s = a.size() - i; j < s && errors <= error; ++j)
                if(a[i+j] != b[j]) ++errors;

            if(errors <= error) return a.size() - i;
        }
        return 0;
    }

    string build(vector<string> Reads) {
        reads = Reads;
        string gnome = "";
        gnome += reads[0];
        string g = reads[0];
        string cur = "";
        int cnt = 0;

        while(reads.size() > 1) {
            cur = reads[cnt];
            reads.erase(reads.begin() + cnt);
            int mx = -1e9;
            for (int i = 0; i < (int)reads.size(); ++i) {
                int val = overlap(cur, reads[i], mer);
                if(val > mx) {
                    mx = val;
                    cnt = i;
                }
            }
            gnome += reads[cnt].substr(mx);
        }
        gnome.erase(0, overlap(reads[0], g, mer));
        return gnome;
    }
};

int main() {

    string s;
    vector<string> v;

    while(cin >> s)
        v.push_back(s);

    GenomeAssembly G(12);
    cout << G.build(v) << "\n";
    return 0;
}

