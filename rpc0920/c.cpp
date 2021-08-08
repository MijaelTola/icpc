#include <bits/stdc++.h>

using namespace std;

template <typename T, int MAX_N>
struct Hash {

    T p,x,n;    
    vector<T> h,h1,vpow;

    Hash(T dx, T dp) {
        h.resize(MAX_N);
        h1.resize(MAX_N);
        vpow.resize(MAX_N);

        x = dx, p = dp;
        vpow[0] = 1;
        for (int i = 1; i < MAX_N; ++i)
            vpow[i] = ((T) mul(vpow[i - 1], (T) x)) % p;
    }

    void build(const vector<int> &v) {
        T hash = 0;
        n = v.size();
        
        for (int i = 0; i < (int)v.size() + 2; ++i) {
            h[i] = 0;
            h1[i] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            hash = ((((T) mul(hash, x) + v[i]) % p) + p) % p;
            h[i] = hash % p;
        }
        hash = 0;
        for (int i = 0; i < n; ++i) {
            hash = ((((T) mul(hash, x) + v[i]) % p) + p) % p;
            h1[i] = hash % p;
        }
    }

    T mul(T a, T b) {
        return (a * b)%p;
    }

    T getH(int i, int j) {
        int sz = j - i + 1;
        return ((h[i] - mul(h[j + 1], vpow[sz]) % p) + p) % p;
    }

    T getRh(int i, int j) {
        int sz = j - i + 1;
        return ((h1[j] - mul(h1[i - 1], vpow[sz] % p)) + p) % p;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int d;
    cin >> d;

    Hash<long long, 100> h(33, INT_MAX);

    set<int> noChanges;
    map<long long, vector<pair<int,int>> > withChanges;
    map<long long, string> saved;
    vector<long long> v;

    int hcurrent = -1;

    auto removeLetter = [&] (const string &current, int id) {
        vector<int> b;
        b.clear();
        string s = "";
        for (int i = 0; i < (int)current.size(); ++i) {
            if(i != id) s += current[i];
        }

        for (auto x: s) {
            b.push_back(x - 'a' + 1);
        }
        h.build(b);
        withChanges[h.getH(0, b.size() - 1)].push_back({0, hcurrent});
    };

    auto addLetter = [&] (const string &current, int id) {
        for (int i = 0; i < 26; ++i) {
            vector<int> b;
            for (int j = 0; j < (int)current.size(); ++j) {
                if(j == id) b.push_back(i + 1);
                b.push_back(current[j] - 'a' + 1);
            }
            h.build(b);
            withChanges[h.getH(0, b.size() - 1)].push_back({1, hcurrent});

            string ns = current + (char)(i + 'a');

            b.clear();

            for(char c: ns)
                b.push_back(c - 'a' + 1);
            h.build(b);
            withChanges[h.getH(0, b.size() - 1)].push_back({1, hcurrent});
        }
    };

    auto diffLetter = [&] (const string &current, int id) {
        for (int i = 0; i < 26; ++i) {
            vector<int> b;
            for (int j = 0; j < (int)current.size(); ++j) {
                if(id == j) b.push_back(i + 1);
                else b.push_back(current[j] - 'a' + 1);
            }
            h.build(b);
            withChanges[h.getH(0, b.size() - 1)].push_back({2, hcurrent});
        }
    };

    auto swapLetter = [&](const string &current, int id) {
        if(id + 1 == (int)current.size()) return;
        vector<int> b;
        string copy = current;
        swap(copy[id], copy[id + 1]);
        b.clear();

        for (char c: copy) {
            b.push_back(c - 'a' + 1);
        }

        h.build(b);
        withChanges[h.getH(0, b.size() - 1)].push_back({3, hcurrent});
    };


    for (int i = 0; i < d; ++i) {
        string s;
        cin >> s;
        
        vector<int> b;
        for (auto x: s) {
            b.push_back(x - 'a' + 1);
        }
        h.build(b);
        hcurrent = h.getH(0, (int)s.size() - 1);
        noChanges.insert(h.getH(0, (int)s.size() - 1));
        saved[hcurrent] = s;
        v.push_back(hcurrent);

        for (int j = 0; j < (int)s.size(); ++j) {
            addLetter(s, j);
            diffLetter(s, j);
            removeLetter(s, j);
            swapLetter(s, j);
        }
    }

    int q;
    cin >> q;

    while(q--) {
        string s;
        cin >> s;

        vector<int> b;

        for (char c: s) {
            b.push_back(c - 'a' + 1);
        }
        
        h.build(b);

        int hsh = h.getH(0, b.size() - 1);
        if(noChanges.count(hsh)) {
            cout << s << "\n";
            cout << "CORRECT\n";
        } else if(withChanges.count(hsh)) {
            map<long long, int> val;

            for (auto p: withChanges[hsh]) {
                val[p.second] = p.first;
            }
            
            cout << s << "\n";

            for (auto x: v) {
                if(val.count(x) and val[x] == 0) cout << "ONE LETTER OMITTED FROM " << saved[x] << "\n";
                if(val.count(x) and val[x] == 1) cout << "ONE LETTER ADDED TO " << saved[x] << "\n";
                if(val.count(x) and val[x] == 2) cout << "ONE LETTER DIFFERENT FROM " << saved[x] << "\n";
                if(val.count(x) and val[x] == 3) cout << "TWO LETTERS TRANSPOSED IN " << saved[x] << "\n";
            
            }
        } else {
            cout << s << "\n";
            cout << "UNKNOWN\n";
        }
        cout << "\n";
    }
    return 0;
}
