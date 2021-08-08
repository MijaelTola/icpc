#include <bits/stdc++.h>

using namespace std;

class FiveRooks {
    public:
        vector <int> find(vector <string>);
};

int dp[65][1 << 8][1 << 8][5];
vector<pair<int,int> > p;
vector <string> bb;

int f(int pos, int mask, int mask2, int k) {
    if(pos == (int)p.size()) {
        return k == 5;
    }
    
    if(k > 5) return 0;
    
    int &ans = dp[pos][mask][mask][k];

    if(ans != -1) return ans;
    ans = 0;

    int a = p[pos].first;
    int b = p[pos].second;

    ans |= f(pos + 1, mask, mask2, k);

    if(!(mask & (1 << a)) and !(mask2 & (1 << b)) and bb[a][b] == 'R') {
        ans |= f(pos + 1, mask | (1 << a), mask2 | (1 << b), k + 1);
    }

    return ans;
}

vector<int> aa;
void r(int pos, int mask, int mask2, int k) {
    if(pos == (int)p.size()) 
        return;
    
    if(k > 5) return;

    int a = p[pos].first;
    int b = p[pos].second;

    if(f(pos + 1, mask, mask2, k)) {
        r(pos + 1, mask, mask2, k);
        return ;
    }

    if(!(mask & (1 << a)) and !(mask2 & (1 << b)) and bb[a][b] == 'R') {
        if(f(pos + 1, mask | (1 << a), mask2 | (1 << b), k + 1)) {
            aa.push_back(a);
            aa.push_back(b);
            r(pos + 1, mask | (1 << a), mask2 | (1 << b), k + 1);
        }
    }
}



vector <int> FiveRooks::find(vector <string> board) {
    memset(dp, -1, sizeof dp);
    bb = board;
    aa.clear();
    p.clear();
    for (int i = 0; i < 8; ++i) 
        for (int j = 0; j < 8; ++j)
            p.push_back({i,j});


    sort(p.begin(), p.end());
    f(0,0,0,0);
    r(0,0,0,0);

    return aa;
}


double test0() {
    string t0[] = {
        "RRRRRRRR",
        "RRRRRRRR",
        "RRRRRRRR",
        "RRRRRRRR",
        "R.......",
        "........",
        "........",
        "........"
    };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    FiveRooks * obj = new FiveRooks();
    clock_t start = clock();
    vector <int> my_answer = obj->find(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t1[] = {0, 7, 1, 3, 2, 4, 3, 6, 4, 0 };
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p1.size() > 0) {
        cout <<p1[0];
        for (int i=1; i<(int)p1.size(); i++)
            cout <<", " <<p1[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<my_answer[0];
        for (int i=1; i<(int)my_answer.size(); i++)
            cout <<", " <<my_answer[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p1) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    string t0[] = {
        "R.R.R.R.",
        ".R.R.R.R",
        "R.R.R.R.",
        ".R.RRR.R",
        "R.R.R.R.",
        ".R.R.R.R",
        "R.R.R.R.",
        ".R.R.R.R"
    };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    FiveRooks * obj = new FiveRooks();
    clock_t start = clock();
    vector <int> my_answer = obj->find(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t1[] = {0, 0, 1, 7, 2, 6, 3, 5, 4, 4 };
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p1.size() > 0) {
        cout <<p1[0];
        for (int i=1; i<(int)p1.size(); i++)
            cout <<", " <<p1[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<my_answer[0];
        for (int i=1; i<(int)my_answer.size(); i++)
            cout <<", " <<my_answer[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p1) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    string t0[] = {
        "RRRRRRRR",
        "RRRRRRRR",
        "RRRRRRRR",
        "RRRRRRRR",
        "RRRRRRRR",
        "RRRRRRRR",
        "RRRRRRRR",
        "RRRRRRRR"
    };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    FiveRooks * obj = new FiveRooks();
    clock_t start = clock();
    vector <int> my_answer = obj->find(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t1[] = {0, 7, 1, 3, 2, 4, 3, 6, 4, 0 };
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p1.size() > 0) {
        cout <<p1[0];
        for (int i=1; i<(int)p1.size(); i++)
            cout <<", " <<p1[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<my_answer[0];
        for (int i=1; i<(int)my_answer.size(); i++)
            cout <<", " <<my_answer[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p1) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    string t0[] = {
        ".RRRRRR.",
        "RRRRRRRR",
        "....RRRR",
        "...RRRR.",
        "..RRRR..",
        ".RRRR...",
        "RRRR....",
        "RRR....."
    }
    ;
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    FiveRooks * obj = new FiveRooks();
    clock_t start = clock();
    vector <int> my_answer = obj->find(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t1[] = {1, 7, 2, 6, 3, 5, 4, 4, 5, 3 };
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p1.size() > 0) {
        cout <<p1[0];
        for (int i=1; i<(int)p1.size(); i++)
            cout <<", " <<p1[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<my_answer[0];
        for (int i=1; i<(int)my_answer.size(); i++)
            cout <<", " <<my_answer[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p1) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4() {
    string t0[] = {
        ".RRRRRR.",
        "RRRRRRRR",
        "....RRRR",
        "...RRRR.",
        "..RRRR..",
        ".RRRR...",
        "RRRRRRRR",
        ".RRRRRR."
    };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    FiveRooks * obj = new FiveRooks();
    clock_t start = clock();
    vector <int> my_answer = obj->find(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t1[] = {1, 7, 2, 6, 3, 5, 4, 4, 5, 3 };
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p1.size() > 0) {
        cout <<p1[0];
        for (int i=1; i<(int)p1.size(); i++)
            cout <<", " <<p1[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<my_answer[0];
        for (int i=1; i<(int)my_answer.size(); i++)
            cout <<", " <<my_answer[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p1) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test5() {
    string t0[] = 
    {
        ".RRRRRR.",
        "RRRRRRRR",
        ".RRRR...",
        "..RRRR..",
        "...RRRR.",
        "....RRRR",
        "RRRRRRRR",
        ".RRRRRR."
    };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    FiveRooks * obj = new FiveRooks();
    clock_t start = clock();
    vector <int> my_answer = obj->find(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t1[] = {1, 7, 3, 5, 4, 4, 6, 2, 7, 1 };
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p1.size() > 0) {
        cout <<p1[0];
        for (int i=1; i<(int)p1.size(); i++)
            cout <<", " <<p1[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<my_answer[0];
        for (int i=1; i<(int)my_answer.size(); i++)
            cout <<", " <<my_answer[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p1) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}

int main() {
    int time;
    bool errors = false;

    time = test0();
    if (time < 0)
        errors = true;

    time = test1();
    if (time < 0)
        errors = true;

    time = test2();
    if (time < 0)
        errors = true;

    time = test3();
    if (time < 0)
        errors = true;

    time = test4();
    if (time < 0)
        errors = true;

    time = test5();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
