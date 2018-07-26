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

// Strongly Connected Component : O(V+E)
// 1. set V
// 2. scc() return number of component
// 3. cmp[v]: component number of node v

const int MAX_V = 1000000;

int V;
vi G[MAX_V];
vi rG[MAX_V];
vi vs;
bool used[MAX_V];
int cmp[MAX_V];

void add_edge(int from, int to){
  G[from].push_back(to);
  rG[to].push_back(from);
}

void scc_dfs(int v){
  used[v] = true;
  REP(i, G[v].size()){
    if(!used[G[v][i]]) scc_dfs(G[v][i]);
  }
  vs.push_back(v);
}

void scc_rdfs(int v, int k){
  used[v] = true;
  cmp[v] = k;
  REP(i, rG[v].size()){
    if(!used[rG[v][i]]) scc_rdfs(rG[v][i], k);
  }
}

int scc(){
  memset(used, 0, sizeof(used));
  vs.clear();
  REP(v, V){
    if(!used[v]) scc_dfs(v);
  }
  memset(used, 0, sizeof(used));
  int k = 0;
  for(int i = vs.size() - 1; i >= 0; i--){
    if(!used[vs[i]]) scc_rdfs(vs[i], k++);
  }
  return k;
}


int main(){
  int n, m;
  cin >> n >> m;
  V = n;
  int a, b;
  REP(i, m) {
    cin >> a >> b;
    add_edge(a - 1, b - 1);
  }

  int k = scc();
  int ans = 0;
  int u = 0;
  REP(i, n) {
    if(cmp[i] == k - 1) {
      ans++;
      u = i;
    }
  }

  REP(i, n) used[i] = false;
  scc_rdfs(u, k - 1);
  REP(i, n) if(!used[i]) {
    cout << 0 << endl;
    return 0;
  }

  cout << ans << endl;

  return 0;
}
