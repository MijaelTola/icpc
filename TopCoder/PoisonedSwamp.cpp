#include <bits/stdc++.h>

using namespace std;

class PoisonedSwamp {
public:
	string cross(vector <string>);
};

int dis[30][30];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

//..11111111111111111.
//#######.###S#######.

string PoisonedSwamp::cross(vector <string> swamp) {


    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j)
            dis[i][j] = 1e9;
    }


	priority_queue<pair<int, pair<int,int> > > q;
    q.push(make_pair(0, make_pair(0,0)));
    dis[0][0] = 0;
    
    while(!q.empty()) {
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();

        if(-dis[x][y] >= 10) continue;

        if(x == (int)swamp.size() - 1 and y == (int)swamp[0].size() - 1) return "possible";
        
        for (int i = 0; i < 4; ++i) {
            int u = dx[i] + x;
            int v = dy[i] + y;


            if(u >= 0 and v >= 0 and u < (int)swamp.size() and v < (int)swamp[0].size() and swamp[u][v] != '#') {
                if(swamp[u][v] != 'S') {
                    int lvl = 0;
                    if('1' <= swamp[u][v] and swamp[u][v] <= '9') 
                        lvl = swamp[u][v] - '0';
                    if(dis[x][y] + lvl < dis[u][v] and dis[x][y] + lvl < 10) {
                        dis[u][v] = dis[x][y] + lvl;
                        q.push(make_pair(-dis[u][v], make_pair(u,v)));
                    }
                } else {
                    if(dis[u][v] > 0) {
                        dis[u][v] = 0; 
                        q.push(make_pair(-dis[u][v], make_pair(u,v)));
                    }
                }
            }

        }
    }


    return "impossible";

}


double test0() {
    string t0[] = {"..11111111111111111.", "#######.###S#######."};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    PoisonedSwamp * obj = new PoisonedSwamp();
    clock_t start = clock();
    string my_answer = obj->cross(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "possible";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string t0[] = {".....",
        "####.",
        "97...",
        "9#2##",
        "97..."};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    PoisonedSwamp * obj = new PoisonedSwamp();
    clock_t start = clock();
    string my_answer = obj->cross(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "possible";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string t0[] = {".111111111.",
        ".#########.",
        "..22222...."};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    PoisonedSwamp * obj = new PoisonedSwamp();
    clock_t start = clock();
    string my_answer = obj->cross(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "possible";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string t0[] = {".#222#111",
        "4#S#2#1#S",
        "4#3#S#1#9",
        "S33#111#."};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    PoisonedSwamp * obj = new PoisonedSwamp();
    clock_t start = clock();
    string my_answer = obj->cross(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "possible";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string t0[] = {"..111111111111..",
        "###############."};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    PoisonedSwamp * obj = new PoisonedSwamp();
    clock_t start = clock();
    string my_answer = obj->cross(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "impossible";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string t0[] = {"..111111111111..",
        "#######S#######."};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    PoisonedSwamp * obj = new PoisonedSwamp();
    clock_t start = clock();
    string my_answer = obj->cross(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "possible";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string t0[] = {"..#.#.",
        "..#.#.",
        "#5#.5.",
        "....#."};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    PoisonedSwamp * obj = new PoisonedSwamp();
    clock_t start = clock();
    string my_answer = obj->cross(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "impossible";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string t0[] = {".1.#.",
        ".9.#.",
        ".###.",
        "2#.1.",
        ".#.7."};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    PoisonedSwamp * obj = new PoisonedSwamp();
    clock_t start = clock();
    string my_answer = obj->cross(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "impossible";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    exit(0);
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
