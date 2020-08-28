#include <bits/stdc++.h>

using namespace std;

class AqaAsadiGroups {
public:
	long long minimumDifference(vector <int>, int);
};

long double dp[510][510];
long double bal = 0;
int n,dk;
vector<int> v;

long double f(int pos, int cur) {
    if(pos == n) {
        int left = max(0,dk - cur);

        return  (bal) * (bal) * left;
        //return 1e15;
    }


    long double &ans = dp[pos][cur];

    if(ans != -1) return ans;
    ans = 1e15;
    long long sum = 0;
    for (int i = pos; i < (int)v.size(); ++i) {
        sum += v[i];
        long double df = (bal - sum) * (bal - sum);
        ans = min(ans, f(i + 1, cur + 1) + df);
    }

    return ans;
}

long long AqaAsadiGroups::minimumDifference(vector <int> Skills, int k) {
	
    for (int i = 0; i < 510; ++i)
        for (int j = 0; j < 510; ++j)
            dp[i][j] = -1;
    int sum = 0;
    dk = k;
    n = Skills.size();
    v = Skills;

    for (int x: Skills)
        sum += x;

    bal = 1.*sum / k;
        
  

    return f(0, 0) * k * k;
}


double test0() {
	int t0[] = {1, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	AqaAsadiGroups * obj = new AqaAsadiGroups();
	clock_t start = clock();
	long long my_answer = obj->minimumDifference(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 2LL;
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
	int t0[] = {1, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	AqaAsadiGroups * obj = new AqaAsadiGroups();
	clock_t start = clock();
	long long my_answer = obj->minimumDifference(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 0LL;
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
	int t0[] = {1, 2, 3, 4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	AqaAsadiGroups * obj = new AqaAsadiGroups();
	clock_t start = clock();
	long long my_answer = obj->minimumDifference(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 8LL;
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
	int t0[] = {1, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 5;
	AqaAsadiGroups * obj = new AqaAsadiGroups();
	clock_t start = clock();
	long long my_answer = obj->minimumDifference(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 80LL;
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

//Powered by [KawigiEdit] 2.0!
