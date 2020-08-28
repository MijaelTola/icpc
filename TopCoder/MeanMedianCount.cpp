#include <bits/stdc++.h>

using namespace std;

class MeanMedianCount {
    public:
        int getCount(int, int, int);
};

int n, mean, media;
const int mod = 1e9 + 7;

int dp[50][510][50][50];
int f(int pos, int sum, int l, int e) {
    if(pos == n) {
        if(l < (n + 1) / 2 and l + e >= (n + 1) / 2 and sum / n >= mean) 
            return 1;  
        return 0;
    }
    int &ans = dp[pos][sum][l][e];
    if(ans != -1) return ans;
    ans = 0;
    for (int i = 0; i <= 10; ++i) {
        ans += f(pos + 1, sum + i, l + (i < media), e + (i >= media));
        ans %= mod;
    }
    return ans;
}

int MeanMedianCount::getCount(int N, int needMean, int needMedian) {
    n = N, mean = needMean, media = needMedian;
    memset(dp, -1, sizeof dp);
    return f(0, 0, 0, 0);
}


double test0() {
    int p0 = 3;
    int p1 = 9;
    int p2 = 10;
    MeanMedianCount * obj = new MeanMedianCount();
    clock_t start = clock();
    int my_answer = obj->getCount(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 10;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    int p0 = 3;
    int p1 = 7;
    int p2 = 8;
    MeanMedianCount * obj = new MeanMedianCount();
    clock_t start = clock();
    int my_answer = obj->getCount(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 162;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    int p0 = 5;
    int p1 = 10;
    int p2 = 8;
    MeanMedianCount * obj = new MeanMedianCount();
    clock_t start = clock();
    int my_answer = obj->getCount(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    int p0 = 5;
    int p1 = 7;
    int p2 = 1;
    MeanMedianCount * obj = new MeanMedianCount();
    clock_t start = clock();
    int my_answer = obj->getCount(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 14874;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4() {
    int p0 = 49;
    int p1 = 0;
    int p2 = 0;
    MeanMedianCount * obj = new MeanMedianCount();
    clock_t start = clock();
    int my_answer = obj->getCount(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 21051900;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test5() {
    int p0 = 1;
    int p1 = 4;
    int p2 = 8;
    MeanMedianCount * obj = new MeanMedianCount();
    clock_t start = clock();
    int my_answer = obj->getCount(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 3;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test6() {
    int p0 = 1;
    int p1 = 9;
    int p2 = 5;
    MeanMedianCount * obj = new MeanMedianCount();
    clock_t start = clock();
    int my_answer = obj->getCount(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 2;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
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

       time = test6();
       if (time < 0)
       errors = true;

       if (!errors)
       cout <<"You're a stud (at least on the example cases)!" <<endl;
       else
       cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
