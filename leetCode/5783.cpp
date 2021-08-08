#include <bits/stdc++.h>

using namespace std;

class MovieRentingSystem {

    set<pair<int,int> > mvByShop[10010];
    map<int,int> mvByShopByShop[10010];
    set<tuple<int,int,int> > rented;

    public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        n++;
        for (int i = 0; i < (int)entries.size(); ++i) {
            int sp = entries[i][0];
            int mv = entries[i][1];
            int pr = entries[i][2];
            mvByShop[mv].insert({pr, sp});
            mvByShopByShop[mv][sp] = pr;
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        for (auto [pr, sp]: mvByShop[movie]) {
            if((int)ans.size() < 5) {
                ans.push_back(sp);
            } else break;
        }
        return ans;
    }

    void rent(int shop, int movie) {
        int pr = mvByShopByShop[movie][shop];
        mvByShop[movie].erase({pr, shop});
        rented.insert({pr, shop, movie});
    }

    void drop(int shop, int movie) {
        int pr = mvByShopByShop[movie][shop];
        mvByShop[movie].insert({pr, shop});
        rented.erase({pr, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int> > ans;
        for (auto [pr, shop, mv]: rented) {
            if((int)ans.size() < 5) {
                ans.push_back({shop, mv});
            } else break;
        }
        return ans;
    }
};


int main() {

    return 0;
}

