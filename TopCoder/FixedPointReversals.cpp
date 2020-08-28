#include <bits/stdc++.h>

using namespace std;

class FixedPointReversals {
    public:
        vector <int> sort(vector <int>, int);
};

bool check(vector<int> A, int pos) {
    vector<int> b = A;
    sort(b.begin(), b.end());
    return b[pos] == A[pos];
}

vector <int> FixedPointReversals::sort(vector <int> A, int fixed) {
    if(!check(A, fixed)) return {-1};
    vector<pair<int,int> > dans;
    bool flag = 1;
    while(flag) {
        flag = 0;
        for (int i = 0; i < fixed; ++i) {
            for (int j = A.size() - 1; j >= fixed + 1; --j) {
                if(i == fixed or j == fixed) continue;
                if(A[i] >= A[fixed] and A[j] <= A[fixed] and A[fixed] != A[i] and A[fixed] != A[j]) {
                    flag = 1;
                    if(abs(i - fixed) == abs(fixed - j)) {
                        dans.push_back({i, j + 1});
                        reverse(A.begin() + i, A.begin() + j + 1);
                        continue;
                    }
                    if(i + 1 != fixed )dans.push_back({i, fixed});
                    reverse(A.begin() + i, A.begin() + fixed);
                    if(fixed + 1 != j)dans.push_back({fixed + 1, j + 1});
                    reverse(A.begin() + fixed + 1, A.begin() + j + 1);
                    if(A[fixed - 1] != A[fixed + 1])dans.push_back({fixed - 1, fixed + 2});
                    reverse(A.begin() + fixed - 1, A.begin() + fixed + 2);
                }
            }
        }
    }

    for (int i = 0; i < fixed; ++i) {
        int id = i;
        int mn = A[i];
        for (int j = i + 1; j < fixed; ++j) {
            if(A[j] < mn) {
                mn = A[j];
                id = j;
            }
        }
        if(i == id) continue;
        dans.push_back({i, id + 1});
        reverse(A.begin() + i, A.begin() + id + 1);
    }

    for (int i = fixed + 1; i < (int)A.size(); ++i) {
        int id = i;
        int mn = A[i];
        for (int j = i + 1; j < (int)A.size(); ++j) {
            if(A[j] < mn) {
                mn = A[j];
                id = j;
            }
        }
        if(i == id) continue;
        dans.push_back({i, id + 1});
        reverse(A.begin() + i, A.begin() + id + 1);
    }

    vector<int> ans;
    for (auto p: dans) {
        ans.push_back(p.first);
        ans.push_back(p.second);
    }

    return ans;
}


double test0() {
    int t0[] = {10, 20, 30, 40, 50};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 2;
    FixedPointReversals * obj = new FixedPointReversals();
    clock_t start = clock();
    vector <int> my_answer = obj->sort(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    vector <int> p2;
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<p2[0];
        for (int i=1; i<(int)p2.size(); i++)
            cout <<", " <<p2[i];
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
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    int t0[] = {10, 20, 40, 30, 50};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 2;
    FixedPointReversals * obj = new FixedPointReversals();
    clock_t start = clock();
    vector <int> my_answer = obj->sort(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t2[] = {-1 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<p2[0];
        for (int i=1; i<(int)p2.size(); i++)
            cout <<", " <<p2[i];
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
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    int t0[] = {20, 10, 10, 10, 10, 10};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 4;
    FixedPointReversals * obj = new FixedPointReversals();
    clock_t start = clock();
    vector <int> my_answer = obj->sort(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t2[] = {0, 6 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<p2[0];
        for (int i=1; i<(int)p2.size(); i++)
            cout <<", " <<p2[i];
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
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    int t0[] = {1, 50, 40, 30, 20, 10};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 0;
    FixedPointReversals * obj = new FixedPointReversals();
    clock_t start = clock();
    vector <int> my_answer = obj->sort(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t2[] = {1, 6 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<p2[0];
        for (int i=1; i<(int)p2.size(); i++)
            cout <<", " <<p2[i];
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
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}

double test4() {
    int t0[] = {20, 10, 30, 50, 40};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 2;
    FixedPointReversals * obj = new FixedPointReversals();
    clock_t start = clock();
    vector <int> my_answer = obj->sort(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t2[] = {0, 2, 3, 5 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<p2[0];
        for (int i=1; i<(int)p2.size(); i++)
            cout <<", " <<p2[i];
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
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}

double test5() {
    int t0[] = {4, 24, 48, 42, 39, 17, 41, 12, 34, 41, 11, 13, 40, 2, 35, 49, 30, 15, 17, 27, 31, 1, 49, 42, 4, 22, 40, 27, 6, 5, 40, 22, 14, 17, 22, 45, 8, 40, 10, 39, 29, 25, 38, 22, 13, 17, 18, 44, 30, 16};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 27;
    FixedPointReversals * obj = new FixedPointReversals();
    clock_t start = clock();
    vector <int> my_answer = obj->sort(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t2[] = {0, 2, 3, 5 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<p2[0];
        for (int i=1; i<(int)p2.size(); i++)
            cout <<", " <<p2[i];
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
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}

double test6() {
    int t0[] = {1,1,1,1,1,1,1};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 3;
    FixedPointReversals * obj = new FixedPointReversals();
    clock_t start = clock();
    vector <int> my_answer = obj->sort(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t2[] = {0, 6 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<p2[0];
        for (int i=1; i<(int)p2.size(); i++)
            cout <<", " <<p2[i];
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
    if (my_answer != p2) {
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
