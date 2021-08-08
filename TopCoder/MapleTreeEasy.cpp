#include<bits/stdc++.h>

using namespace std;

class MapleTreeEasy {
public:
	long long count(vector <int>);
};

int n;
vector<int> G[60];
int vis[60];
int f(int a, int b) {
    for (int i = 0; i <= n + 1; ++i) {
        vis[i] = -1;
    }

    queue<int> q;
    q.push(a);
    vis[a] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(u == b) return vis[u];
        for (int i = 0; i < (int) G[u].size(); ++i) {
            int v = G[u][i];
            if(vis[v] == -1) {
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
    }
    return vis[b];
}

long long MapleTreeEasy::count(vector <int> p) {
	for (int i = 0; i < 60; ++i)
        G[i].clear();

    n = p.size() + 1;
    for (int i = 0; i < (int) p.size(); ++i) {
        G[i + 1].push_back(p[i]);
        G[p[i]].push_back(i + 1);
    }
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long nodos = f(i, j) + 1;
            nodos -= 2;
            ans += (1LL << nodos);
        }
    }

    return ans + n;
}


double test0() {
	int t0[] = {0, 1, 2, 3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MapleTreeEasy * obj = new MapleTreeEasy();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 31LL;
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
	int t0[] = {0, 1, 0, 3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MapleTreeEasy * obj = new MapleTreeEasy();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 31LL;
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
	int t0[] = {0, 0, 0, 0, 0, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MapleTreeEasy * obj = new MapleTreeEasy();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 43LL;
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
	int t0[] = {0, 0, 1, 1, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MapleTreeEasy * obj = new MapleTreeEasy();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 49LL;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
