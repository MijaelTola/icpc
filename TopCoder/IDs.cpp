#include <bits/stdc++.h>


using namespace std;

class IDs {
public:
	double collisionProbability(int, vector <int>);
};

int n;
long long x;
vector<int> v;

long long dp[50][100];
long long f(int pos, int k) {
    if(pos == n) {
        if(k >= 2) return 1;
        return 0;
    }

    long long &ans = dp[pos][k];
    if(ans != -1) return ans;
    ans = 0;
    for (int i = 1; i <= v[pos]; ++i) {
        ans += f(pos + 1, min(2,k + i)) + ((x - i));
    }
    
    return ans;
}

double IDs::collisionProbability(int num, vector <int> counts) {
	x = num;
    n = counts.size();
    v = counts;
    
    memset(dp, -1, sizeof dp);
    double y = 1;

    for (int i = 0; i < (int)v.size(); ++i) {
        y += x;
    }
    cout << y << "g\n";

    return min(1. * f(0, 0) / y, 1.);
}


double test0() {
	int p0 = 1000;
	int t1[] = {1,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	IDs * obj = new IDs();
	clock_t start = clock();
	double my_answer = obj->collisionProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.002998000000000056;
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
	int p0 = 1000;
	int t1[] = {234,543,640};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	IDs * obj = new IDs();
	clock_t start = clock();
	double my_answer = obj->collisionProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 1.0;
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
	int p0 = 2000000000;
	int t1[] = {100,150,482,71,349,57,751,673,761,942};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	IDs * obj = new IDs();
	clock_t start = clock();
	double my_answer = obj->collisionProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.004688119695273496;
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
	int p0 = 200000000;
	int t1[] = {100,150,482,71,349,57,751,673,761,942};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	IDs * obj = new IDs();
	clock_t start = clock();
	double my_answer = obj->collisionProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.04590472119127553;
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
double test4() {
	int p0 = 4756;
	int t1[] = {0,1,0,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	IDs * obj = new IDs();
	clock_t start = clock();
	double my_answer = obj->collisionProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.0;
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
	int time;
	bool errors = false;
	
    cout << fixed;
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
