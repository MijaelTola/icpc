#include <bits/stdc++.h>

using namespace std;

class TheTilesDivTwo {
public:
	int find(vector <string>);
};

vector<string> v;
int n,m;

int dp[50][50][1 << 4][1 << 4][1 << 4];

bool check(int mask, int x, int y) {
    return y >= 0 and y < m and x >= 0 and x < n and mask & (1 << x);
}
bool ver(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < m and v[x][y] == '.';
}

int f(int x, int y, int last, int cur, int next) {
    if(y == m) return 0;
    if(x == n) return f(0, y + 1, cur, next, 0);
    int &ans = dp[x][y][last][cur][next];
    if(ans != -1) return ans;
    ans = 0;
    if((x + y) % 2 == 0 and !check(cur, x, y) and ver(x,y)) {
        if(!check(last, x, y - 1) and ver(x, y - 1) and !check(cur, x + 1, y) and ver(x + 1,y))
            ans = max(ans, f(x + 1, y, last | (1 << x), cur | (1 << x) | (1 << (x + 1)), next) + 1);

        if(!check(last, x, y - 1) and ver(x, y - 1) and !check(cur, x - 1, y) and ver(x - 1,y))
            ans = max(ans, f(x + 1, y, last | (1 << x), cur | (1 << x) | (1 << (x - 1)), next) + 1);

        if(!check(next, x, y + 1) and ver(x, y + 1) and !check(cur, x + 1, y) and ver(x + 1,y))
            ans = max(ans, f(x + 1, y, last, cur | (1 << x) | (1 << (x + 1)), next | (1 << x)) + 1);

        if(!check(next, x, y + 1) and ver(x, y + 1) and !check(cur, x - 1, y) and ver(x - 1,y))
            ans = max(ans, f(x + 1, y, last, cur | (1 << x) | (1 << (x - 1)), next | (1 << x)) + 1);
    }
    
    ans = max(ans, f(x + 1, y, last, cur, next));
    ans = max(ans, f(x, y + 1, last, cur, next));
    return ans;
}


int TheTilesDivTwo::find(vector <string> b) {
    n = b.size();
    m = b[0].size();
    v = b;
    memset(dp, -1, sizeof dp);
    //cout << m << " lim\n";
	return f(0, 0, 0, 0, 0);
}


double test0() {
	string t0[] = {"X.X",
 "...",
 "X.X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheTilesDivTwo * obj = new TheTilesDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
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
	string t0[] = {"...",
 "...",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheTilesDivTwo * obj = new TheTilesDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
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
double test2() {
	string t0[] = {"......X.X.XXX.X.XX."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheTilesDivTwo * obj = new TheTilesDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
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
double test3() {
	string t0[] = {"X.....XXX.XX..XXXXXXXXX...X.XX.XX....X",
 ".XXXX..X..XXXXXXXX....XX.X.X.X.....XXX",
 "....XX....X.XX..X.X...XX.X..XXXXXXX..X",
 "XX.XXXXX.X.X..X..XX.XXX..XX...XXX.X..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheTilesDivTwo * obj = new TheTilesDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 13;
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
	string t0[] = {
        "....",
        "...."
    };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheTilesDivTwo * obj = new TheTilesDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
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
	
    test4();
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
