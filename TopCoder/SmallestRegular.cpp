#include <bits/stdc++.h>

using namespace std;

class SmallestRegular {
    public:
        vector <int> findLexSmallest(string);
};

vector <int> SmallestRegular::findLexSmallest(string s) {
    int n = s.size();

    vector<int> ans;

    int p = 0;
    int cnt = 0;

    while(s[p] != ')') cnt++,p++;
    vector<int> op;

    for (int i = p; i < n; ++i)
        if(s[i] == '(') op.push_back(i);


    for (int x: op) {
        ans.push_back(0);
        ans.push_back(x - 1);
        ans.push_back(x);
        p++;
    }

    return ans;
}


double test0() {
    string p0 = "(())";
    SmallestRegular * obj = new SmallestRegular();
    clock_t start = clock();
    vector <int> my_answer = obj->findLexSmallest(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    vector <int> p1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p1.size() > 0) {
        cout <<p1[0];
        for (int i=1; i<p1.size(); i++)
            cout <<", " <<p1[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<my_answer[0];
        for (int i=1; i<my_answer.size(); i++)
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
    string p0 = "(()())";
    SmallestRegular * obj = new SmallestRegular();
    clock_t start = clock();
    vector <int> my_answer = obj->findLexSmallest(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t1[] = {1, 2, 3 };
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p1.size() > 0) {
        cout <<p1[0];
        for (int i=1; i<p1.size(); i++)
            cout <<", " <<p1[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<my_answer[0];
        for (int i=1; i<my_answer.size(); i++)
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
    string p0 = "()()()()";
    SmallestRegular * obj = new SmallestRegular();
    clock_t start = clock();
    vector <int> my_answer = obj->findLexSmallest(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t1[] = {2, 3, 6, 2, 3, 5, 0, 1, 4 };
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p1.size() > 0) {
        cout <<p1[0];
        for (int i=1; i<p1.size(); i++)
            cout <<", " <<p1[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<my_answer[0];
        for (int i=1; i<my_answer.size(); i++)
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
