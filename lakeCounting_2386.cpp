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

const int MAX_N = 100;
const int MAX_M = 100;


int n, m;
string s[MAX_N];
bool used[MAX_N][MAX_M];
void dfs(int x, int y){
  used[x][y] = true;
  REP(i,8){
    int tx = x + dirx[i];
    int ty = y + diry[i];
    if(tx >= 0 && tx < n && ty >= 0 && ty < m && !used[tx][ty] && s[tx][ty] == 'W') dfs(tx,ty);
  }
}

int main(){
  cin >> n >> m;
  REP(i, n){
    cin >> s[i];
  }
  int ans = 0;

  REP(x,n)REP(y,m)used[x][y] = false;

  REP(x,n){
    REP(y,m){
      if(!used[x][y] && s[x][y] == 'W'){
        dfs(x,y);
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
