#include <bits/stdc++.h>

using namespace std;

class SRMCodingPhase {
public:
	int countScore(vector <int>, vector <int>, int);
};

int SRMCodingPhase::countScore(vector <int> points, vector <int> skills, int luck) {
	vector<int> per = {0, 1, 2};
    vector<int> pen = {2, 4, 8};

    int ans = 0;

    do {
        for (int i = 0; i <= luck; ++i) {
            for (int j = 0; j <= luck; ++j) {
                for (int k = 0; k <= luck; ++k) {
                    if(i + j + k <= luck) {
                        int tm = 0;
                        int cur = 0;
                        vector<int> res = {i, j, k};
                        for (int l = 0; l < 3 and tm < 75; ++l) {
                            int pos = per[l];
                            int ntm = skills[pos] - res[l];
                            if(ntm > 0) {
                                tm += ntm;
                                if(tm <= 75) {
                                    cur += (points[pos] - max(0, pen[pos] * ntm));
                                } else break;
                            }

                        }
                        ans = max(ans, cur);
                    }
                }
            }
        }
    } while(next_permutation(per.begin(), per.end()));

    return ans;
}


double test0() {
	int t0[] = {250, 500, 1000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10, 25, 40};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 0;
	SRMCodingPhase * obj = new SRMCodingPhase();
	clock_t start = clock();
	int my_answer = obj->countScore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1310;
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
	int t0[] = {300, 600, 900};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {30, 65, 90};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 25;
	SRMCodingPhase * obj = new SRMCodingPhase();
	clock_t start = clock();
	int my_answer = obj->countScore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 680;
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
	int t0[] = {250, 550, 950};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10, 25, 40};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 75;
	SRMCodingPhase * obj = new SRMCodingPhase();
	clock_t start = clock();
	int my_answer = obj->countScore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1736;
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
	int t0[] = {256, 512, 1024};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {35, 30, 25};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 0;
	SRMCodingPhase * obj = new SRMCodingPhase();
	clock_t start = clock();
	int my_answer = obj->countScore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1216;
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
	int t0[] = {300, 600, 1100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {80, 90, 100};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 4;
	SRMCodingPhase * obj = new SRMCodingPhase();
	clock_t start = clock();
	int my_answer = obj->countScore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
