#include <bits/stdc++.h>

using namespace std;

class MakeSquare {
    public:
        int minChanges(string);
};
int dp[110][110];

int f(string str1, string str2, int m, int n) { 
    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            if (i == 0) dp[i][j] = j; 
            else if (j == 0) dp[i][j] = i; 
            else if (str1[i - 1] == str2[j - 1])  dp[i][j] = dp[i - 1][j - 1]; 
            else dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}); 
        } 
    } 

    return dp[m][n]; 
} 
int MakeSquare::minChanges(string S) {
    int n = S.size();
    int ans = 1e9;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i; j < n - 1; ++j) {
            string cur = "";
            for (int k = i; k <= j; ++k)
                cur += S[k];

            string ds = cur + cur;
            //cout << S << " " << ds << ": " << f(ds, S, ds.size(), S.size()) << "\n";
            ans = min(ans, f(ds, S, ds.size(), S.size()));
        }
    }
    //exit(0);
    return ans;
}


double test0() {
    string p0 = "abcdabgcd";
    MakeSquare * obj = new MakeSquare();
    clock_t start = clock();
    int my_answer = obj->minChanges(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    string p0 = "abcdeabce";
    MakeSquare * obj = new MakeSquare();
    clock_t start = clock();
    int my_answer = obj->minChanges(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    string p0 = "abcdeabxde";
    MakeSquare * obj = new MakeSquare();
    clock_t start = clock();
    int my_answer = obj->minChanges(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    string p0 = "aabcaabc";
    MakeSquare * obj = new MakeSquare();
    clock_t start = clock();
    int my_answer = obj->minChanges(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 0;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4() {
    string p0 = "aaaaabaaaaabaaaaa";
    MakeSquare * obj = new MakeSquare();
    clock_t start = clock();
    int my_answer = obj->minChanges(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 2;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer) {
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
