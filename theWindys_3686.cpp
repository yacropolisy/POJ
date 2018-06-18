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

// min_cost_flow O(FE log V)  F : Flow
// 1. set V
// 2. min_cost_flow(source, destination, flow)


const int MAX_V = 100000;

struct edge{int to, cap, cost, rev;};

int V;
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, int cost){
  G[from].push_back((edge){to, cap, cost, int(G[to].size())});
  G[to].push_back((edge){from, 0, -cost, int(G[from].size())});
}

int min_cost_flow(int s, int t, int f){
  int res = 0;
  fill(h, h+V, 0);
  while(f > 0) {
    priority_queue<pi, vector<pi>, greater<pi>  > que;
    fill(dist, dist + V, INFi);
    dist[s] = 0;
    que.push(pi(0,s));

    while(!que.empty()){
      pi p = que.top(); que.pop();
      int v = p.second;
      if(dist[v] < p.first) continue;
      for(int i = 0; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          prevv[e.to] = v;
          preve[e.to] = i;
          que.push(pi(dist[e.to], e.to));
        }
      }
    }
    if(dist[t] == INFi){
      return -1;
    }
    REP(v, V) h[v] += dist[v];

    int d = f;
    for(int v = t; v != s; v = prevv[v]){
      d = min(d, G[prevv[v]][preve[v]].cap);
    }
    f -= d;
    res += d * h[t];
    for(int v = t; v != s; v = prevv[v]){
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  return res;
}

int main(){
  int r;
  cin >> r;
  double ans[r];
  REP(l, r){
    REP(i,MAX_V) G[i].clear();
    int n, m;
    cin >> n >> m;
    int z[n][m];
    REP(i,n)REP(j,m)cin >> z[i][j];
    V = n*(m+1)+2;
    int s = V - 2;
    int t = V - 1;
    REP(i,n){
      add_edge(s, i, 1, 0);
    }
    REP(i, n){
      REP(j, m){
        add_edge(n+i*m+j, t, 1, 0);
        REP(k, n){
          add_edge(k, n+i*m+j, 1, (i+1) * z[k][j]);
        }
      }
    }
    ans[l] = double(min_cost_flow(s,t,n)) / n;
  }

  REP(l,r) cout << ans[l] << endl;


  return 0;
}
