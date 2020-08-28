#include <bits/stdc++.h>

using namespace std;

class ArpaAsDevotee {
public:
	vector <string> solve(int, int, vector <int>, vector <int>, vector <int>);
};

vector <string> ArpaAsDevotee::solve(int n, int q, vector <int> a, vector <int> lastSeen, vector <int> t) {
    
    vector<string> ans;
    map<int,int> mp;
    int mx = 0;
	for (int i = 0; i < n; ++i) {
        if(a[i] < lastSeen[i]) return {};
        if(a[i] < mx) return {};
        mx = max(a[i], mx);
        if(!mp.count(a[i])) {
            mp[a[i]] = lastSeen[i];
            continue;
        }
        if(mp[a[i]] != lastSeen[i]) return {};
    }
    
    vector<pair<int,int> > b;

    for (int i = 0; i < n; ++i)
        b.push_back({a[i], lastSeen[i]});
    sort(b.begin(), b.end());
    for (int i = 0; i < q; ++i) {
        int x = t[i];
        int l = -1, r = n;
        while(r - l > 1) {
            int mid = (r + l) / 2;
            if(b[mid].first >= x) r = mid;
            else l = mid;
        }
        int pos = r;
        if(b[pos].first < x) {
            ans.push_back("Not Sure");
            continue;
        }
        if(b[pos].second == x) ans.push_back("Yes");
        if(b[pos].second < x) ans.push_back("No");
        if(b[pos].second > x) ans.push_back("Not Sure");
    }
    return ans;
}


double test0() {
	int p0 = 5;
	int p1 = 7;
	int t2[] = {11, 13, 17, 25, 29};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {11, 13, 15, 15, 29};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {11, 12, 13, 14, 15, 16, 17};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	ArpaAsDevotee * obj = new ArpaAsDevotee();
	clock_t start = clock();
	vector <string> my_answer = obj->solve(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t5[] = {"Yes", "Not Sure", "Yes", "Not Sure", "Yes", "No", "No" };
	vector <string> p5(t5, t5+sizeof(t5)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p5.size() > 0) {
		cout <<"\""<<p5[0]<<"\"";
		for (int i=1; i<(int)p5.size(); i++)
			cout <<", \"" <<p5[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if ((int)my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<(int)my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p5) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 2;
	int p1 = 1;
	int t2[] = {1, 10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {5, 3};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {6};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	ArpaAsDevotee * obj = new ArpaAsDevotee();
	clock_t start = clock();
	vector <string> my_answer = obj->solve(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <string> p5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p5.size() > 0) {
		cout <<"\""<<p5[0]<<"\"";
		for (int i=1; i<(int)p5.size(); i++)
			cout <<", \"" <<p5[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<(int)my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p5) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 3;
	int p1 = 1;
	int t2[] = {7, 7, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {3, 5, 1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {4};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	ArpaAsDevotee * obj = new ArpaAsDevotee();
	clock_t start = clock();
	vector <string> my_answer = obj->solve(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <string> p5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p5.size() > 0) {
		cout <<"\""<<p5[0]<<"\"";
		for (int i=1; i<(int)p5.size(); i++)
			cout <<", \"" <<p5[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<(int)my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p5) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 2;
	int p1 = 3;
	int t2[] = {5, 5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {2, 2};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {1, 2, 3};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	ArpaAsDevotee * obj = new ArpaAsDevotee();
	clock_t start = clock();
	vector <string> my_answer = obj->solve(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t5[] = {"Not Sure", "Yes", "No" };
	vector <string> p5(t5, t5+sizeof(t5)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p5.size() > 0) {
		cout <<"\""<<p5[0]<<"\"";
		for (int i=1; i<(int)p5.size(); i++)
			cout <<", \"" <<p5[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<(int)my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p5) {
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
