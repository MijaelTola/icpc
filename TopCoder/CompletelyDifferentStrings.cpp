#include <bits/stdc++.h>

using namespace std;

class CompletelyDifferentStrings {
public:
	int count(int, vector <string>);
};

int dp[1010];
int CompletelyDifferentStrings::count(int S, vector <string> forbidden) {
    int n = forbidden[0].size();
    dp[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < S; ++j) {
            char c = j + 'a';
            bool flag = 1;
            for (int k = 0; k < (int)forbidden.size(); ++k) 
                flag &= forbidden[k][i] != c;

            if(flag) dp[i] += dp[i + 1];
        }
    }
    return dp[0];
}


double test0() {
	int p0 = 3;
	string t1[] = {"ab"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CompletelyDifferentStrings * obj = new CompletelyDifferentStrings();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 1;
	string t1[] = {"aaaaa", "aaaaa"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CompletelyDifferentStrings * obj = new CompletelyDifferentStrings();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 7;
	string t1[] = {"baba", "babe", "cage", "cafe", "feed", "deed", "deaf", "dead"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CompletelyDifferentStrings * obj = new CompletelyDifferentStrings();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 90;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 3;
	string t1[] = {"abacaa", "abacaa", "acabab"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CompletelyDifferentStrings * obj = new CompletelyDifferentStrings();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 8;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	test2();
    return 0;
}
/*
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
*/

//Powered by [KawigiEdit] 2.0!
