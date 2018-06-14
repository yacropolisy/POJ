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
  int n, m;
  cin >> n >> m;
  int x[n], y[n], b[n];
  REP(i,n){
    cin >> x[i] >> y[i] >> b[i];
  }
  int p[m], q[m], c[m];
  REP(i,m){
    cin >> p[i] >> q[i] >> c[i];
  }
  int cost = 0;
  REP(i,n){
    REP(j,m){
      int t;
      cin >> t;
      cost += t * (abs(x[i] - p[j]) + abs(y[i] - q[j]) + 1);
    }
  }

  REP(i,n){
    REP(j,m){
      add_edge(i, n+j, INFi, abs(x[i] - p[j]) + abs(y[i]- q[j]) + 1);
    }
  }

  int sumb = 0;
  REP(i,n){
    add_edge(n+m, i, b[i], 0);
    sumb += b[i];
  }
  REP(j, m){
    add_edge(n+j, n+m+1, c[j], 0);
  }

  V = n + m + 2;


  int mincost = min_cost_flow(n+m, n+m+1, sumb);

  if(cost == mincost) cout << "OPTIMAL" << endl;
  else{
    cout << "SUBOPTIMAL" << endl;
    REP(i,n){
      REP(j,m){
        cout << G[j+n][i].cap << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
