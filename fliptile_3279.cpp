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



int main(){
  int m, n;
  cin >> m >> n;
  bool masu[m][n];

  int t;
  REP(i, m) REP(j, n){
    cin >> t;
    if(t == 1) masu[i][j] = false;
    else masu[i][j] = true;
  }

  bool memo[m][n];
  int ans[m][n];
  REP(k, 1 << n) {
    REP(i, m) REP(j, n) memo[i][j] = masu[i][j];
    REP(i, m) REP(j, n) ans[i][j] = 0;

    REP(j, n) if(k & 1 << j) {
      int i = 0;
      ans[i][j] = 1;
      memo[i][j] = !memo[i][j];
      REP(d, 4) {
        int di = i + dirx[d];
        int dj = j + diry[d];
        if(di >= 0 && di < m && dj >= 0 && dj < n ) memo[di][dj] = ! memo[di][dj];
      }
    }

    for(int i = 1; i < m; i++) {
      REP(j, n) {
        if(!memo[i-1][j]) {
          ans[i][j] = 1;
          memo[i][j] = !memo[i][j];
          REP(d, 4) {
            int di = i + dirx[d];
            int dj = j + diry[d];
            if(di >= 0 && di < m && dj >= 0 && dj < n ) memo[di][dj] = ! memo[di][dj];
          }
        }
      }
    }

    bool flag = true;
    REP(j, n) {
      if(!memo[m - 1][j]){
        flag = false;
        break;
      }
    }
    if(flag){
      REP(i, m) {
        REP(j, n) {
          cout << ans[i][j];
          if(j != n - 1) cout << " ";
          else cout << endl;
        }
      }
      return 0;
    }
  }

  cout << "IMPOSSIBLE" << endl;


  return 0;

}
