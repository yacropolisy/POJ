#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

// Dinic O(EV^2)
// maximum flow problem
// 1. init G[V] by add_edge
// 2. max_flow(s, t) return the max flow

const int MAX_V = 20002;

struct edge{int to, cap, rev;};

vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

void add_edge(int from, int to, int cap){
  G[from].push_back((edge){to, cap, int(G[to].size())});
  G[to].push_back((edge){from, 0, int(G[from].size() -1)});
}

void bfs(int s){
  memset(level, -1, sizeof(level));
  queue<int> que;
  level[s] = 0;
  que.push(s);
  while(!que.empty()){
    int v = que.front(); que.pop();
    REP(i,G[v].size()){
      edge &e = G[v][i];
      if (e.cap > 0 && level[e.to] < 0){
        level[e.to] = level[v] + 1;
        que.push(e.to);
      }
    }
  }
}

int dfs(int v, int t, int f){
  if(v == t) return f;
  for (int &i = iter[v]; i < G[v].size(); i++){
    edge &e = G[v][i];
    if(e.cap > 0 && level[v] < level[e.to]){
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0){
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s, int t){
  int flow = 0;
  for(;;){
    bfs(s);
    if(level[t] < 0) return flow;
    int f;
    while((f = dfs(s, t, INFi)) > 0){
      flow += f;
    }

  }
}

int main(){
  int n, m;
  cin >> n >> m;
  int a[n],b[n];
  REP(i,n){
    cin >> a[i] >> b[i];
    add_edge(i, n+1, a[i]);
    add_edge(n, i, b[i]);
  }
  int ta, tb, tw;
  REP(i,m){
    cin >> ta >> tb >> tw;
    add_edge(ta, tb, tw);
    add_edge(tb, ta, tw);
  }

  cout << max_flow(n, n+1) << endl;


  return 0;
}
