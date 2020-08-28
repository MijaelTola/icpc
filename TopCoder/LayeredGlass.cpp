#include <bits/stdc++.h>

using namespace std;

class LayeredGlass {
public:
	int minDefects(vector <string>, vector <string>);
};


int check(vector<string> a, vector<string> b) {
    int ans = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        for (int j = 0; j < (int)a[i].size(); ++j) {
            ans += a[i][j] == 'X' or b[i][j] == 'X';
        }
    }
    return ans;
}

vector<string> rotate(vector<string> a) {
    int n = a.size();
    vector<string> b;
    for (int i = 0; i < n; ++i) {
        string x = "";
        for (int j = n - 1; j >= 0; --j) 
            x += a[j][i];
        b.push_back(x);
        //cout << x << " gg\n";
    }
    return b;
}

int LayeredGlass::minDefects(vector <string> a, vector <string> b) {
    int da = a.size(), db = b.size();
    return da + db;
}


double test0() {
	string t0[] = {"X.",
 ".."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"..",
 ".X"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	LayeredGlass * obj = new LayeredGlass();
	clock_t start = clock();
	int my_answer = obj->minDefects(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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
	string t0[] = {"...",
 "..X",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"X..",
 "...",
 "..."};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	LayeredGlass * obj = new LayeredGlass();
	clock_t start = clock();
	int my_answer = obj->minDefects(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	string t0[] = {"...",
 "...",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"...",
 ".XX",
 "..."};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	LayeredGlass * obj = new LayeredGlass();
	clock_t start = clock();
	int my_answer = obj->minDefects(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	string t0[] = {".XX",
 "...",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"X..",
 "...",
 "X.."};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	LayeredGlass * obj = new LayeredGlass();
	clock_t start = clock();
	int my_answer = obj->minDefects(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	string t0[] = {"XX..",
 "X...",
 "XX..",
 "X..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"XXXX",
 "X.X.",
 "....",
 "...."};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	LayeredGlass * obj = new LayeredGlass();
	clock_t start = clock();
	int my_answer = obj->minDefects(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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

    test4();
    return 0;
}

int man() {
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
    return 0;
}

//Powered by [KawigiEdit] 2.0!
