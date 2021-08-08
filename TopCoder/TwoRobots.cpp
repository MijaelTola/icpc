#include <bits/stdc++.h>

using namespace std;

class TwoRobots {
public:
	int move(vector <string>);
};


int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int vis[41][41][41][41];



int TwoRobots::move(vector <string> plan) {
	
    memset(vis, -1, sizeof vis);
    queue<pair<pair<int,int>, pair<int,int> > > q;
    int a = 0,b = 0,x = 0, y = 0;

    int n = plan.size(), m = 0;
    for (int i = 0; i < (int)plan.size(); ++i) {
        for (int j = 0; j < (int)plan[i].size(); ++j) {
            if(plan[i][j] == 'A') {
                x = i;
                y = j;
            }

            if(plan[i][j] == 'B') {
                a = i;
                b = j;
            }
        }
        m = max(m, (int)plan[i].size());
    }
    q.push({{x,y}, {a,b}});
    vis[x][y][a][b] = 0;
    
    while(!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        a = q.front().second.first;
        b = q.front().second.second;
        q.pop();
        if(plan[x][y] == 'a' and plan[a][b] == 'b') return vis[x][y][a][b];
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                int xx = dx[i] + x;
                int yy = dy[i] + y;
                int aa = dx[j] + a;
                int bb = dy[j] + b;

                if(xx >= 0 and xx < n and yy >= 0 and yy < m and plan[xx][yy] != '#' 
                        and aa >= 0 and aa < n and bb >= 0 and bb < m and plan[aa][bb] != '#') {
                    //cout << xx << " " << yy << " " << aa << " " << bb << endl;
                    pair<int,int> pa = {xx,yy};
                    pair<int,int> pb = {aa,bb};
                    pair<int,int> la = {x,y};
                    pair<int,int> lb = {a,b};
                    if(pa == lb and pb == la) continue;
                    if(pa != pb and vis[xx][yy][aa][bb] == - 1) {
                        vis[xx][yy][aa][bb] = vis[x][y][a][b] + 1;
                        q.push({{xx,yy}, {aa,bb}});
                    }
                }
            }
        }
    }
    return -1;
}


double test0() {
	string t0[] = {"Ab.a",
 "...B"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TwoRobots * obj = new TwoRobots();
	clock_t start = clock();
	int my_answer = obj->move(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
	string t0[] = {"#a#",
 "A.b",
 "#B#"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TwoRobots * obj = new TwoRobots();
	clock_t start = clock();
	int my_answer = obj->move(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
	string t0[] = {"#b#",
 "A.a",
 "#B#",
 "#.#"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TwoRobots * obj = new TwoRobots();
	clock_t start = clock();
	int my_answer = obj->move(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
	string t0[] = {"...",
 "#a#",
 "A.b",
 "#B#",
 "#.#"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TwoRobots * obj = new TwoRobots();
	clock_t start = clock();
	int my_answer = obj->move(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
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
	string t0[] = {"AB......ab"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TwoRobots * obj = new TwoRobots();
	clock_t start = clock();
	int my_answer = obj->move(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 8;
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
double test5() {
	string t0[] = {"bA......Ba"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TwoRobots * obj = new TwoRobots();
	clock_t start = clock();
	int my_answer = obj->move(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
double test6() {
	string t0[] = {"bA.......Ba"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TwoRobots * obj = new TwoRobots();
	clock_t start = clock();
	int my_answer = obj->move(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
double test7() {
	string t0[] = {"AB.........",
 "...........",
 "...........",
 "........b.a"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TwoRobots * obj = new TwoRobots();
	clock_t start = clock();
	int my_answer = obj->move(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
double test8() {
	string t0[] = {"...A...",
 ".#####.",
 ".#####b",
 "B#####.",
 ".#####.",
 ".#####.",
 "..a...."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TwoRobots * obj = new TwoRobots();
	clock_t start = clock();
	int my_answer = obj->move(p0);
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
	
	time = test7();
	if (time < 0)
		errors = true;
	
	time = test8();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
