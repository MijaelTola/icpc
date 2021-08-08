
#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
 
// edge
struct Edge{
    long long from, to, f, w;
}E[1000005];
long long Hed[100005], Nex[1000005], ct=1, Cur[100005];
void addedge (long long a, long long b, long long f, long long w) {// bordered
    E[++ct].from=a, E[ct].to=b, E[ct].f=f, E[ct].w=w, Nex[ct]=Hed[a], Hed[a]=ct;
    E[++ct].from=b, E[ct].to=a, E[ct].f=0, E[ct].w=-w, Nex[ct]=Hed[b], Hed[b]=ct;
}
 
// mincostmaxflow
long long n, m, s, t, maxflow, Dis[100005], F[100005];
long long mincost;

bool SPFA () {// shortest stratification, from the sink to the source stratification can guarantee DFS is the shortest path to go, do not waste time going the wrong way
    queue<long long> Q; Q.push(s);
    memset(Dis, INF, sizeof Dis);
    for (int i = 0; i < 100005; ++i)
        Dis[i] = INF;
    Dis[s] = 0; long long k;
    while(!Q.empty()){
        k = Q.front(); Q.pop();
        F[k] = 0;
        for(long long i=Hed[k]; i; i=Nex[i]){
            if(E[i].f && Dis[k]+E[i].w<Dis[E[i].to]){
                Dis[E[i].to] = Dis[k]+E[i].w;
                if(!F[E[i].to])
                    Q.push(E[i].to), F[E[i].to] = 1;
            }
        }
    }
    return Dis[t] != INF;
}
long long DFS(long long k, long long flow){
    if (k == t) {maxflow += flow; return flow;} // Update sink reach Maximum Flow
    long long sum = 0; F [k] = 1; // F [] to ensure that the case when there is the cost of the edge does not occur 0 run back and forth between two polong longs
    for(long long i=Cur[k]; i; i=Nex[i]){
        if(!F[E[i].to] && E[i].f  && Dis[E[i].to]==Dis[k]+E[i].w){
            Cur [k] = i; // current arc Optimization
            long long p = DFS(E[i].to, min(flow-sum, E[i].f));
            sum += p, E [i] .f -= p, E [i ^ 1] .f += p, mincost += p * E [i] .w; // Update cost
            if(sum == flow) break;
        }
    }
    F[k] = 0;
    return sum;
}
void Dinic(){
    while(SPFA()){
        memcpy(Cur, Hed, sizeof Hed);
        DFS(s, INF);
    } 
}

long long prep[2500], pront[2500];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    long long k;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
        cin >> prep[i];
    }
    for (long long i = 1; i <= n; i++) {
        cin >> pront[i];
    }
    s = 0;
    t = n + 5;
    for (long long i = 1; i <= n; i++) {
        addedge(s, i, 1, prep[i]);
        addedge(i, t - 1 , 1, pront[i]);
        if (i != n)addedge(i, i + 1, k, 0);
    }
    addedge(t - 1, t, k, 0);
    Dinic();
    cout << mincost << "\n";

    return 0;
}

