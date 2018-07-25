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

void solve(int n, vi pv) {
  if(n % 2 == 0) {
    int a = 0;
    REP(i, 2/n) {
      a ^= (pv[2 * i + 1] - pv[2 * i]);
    }
    if(a == 0) cout << "Georgia will win" << endl;
    else cout << "Bob will win" << endl;
  } else {
    int a = pv[0];
    REP(i, 2/n) {
      a ^= (pv[2 * i + 2] - pv[2 * i + 1]);
    }
    if(a == 0) cout << "Georgia will win" << endl;
    else cout << "Bob will win" << endl;
  }
}


int main(){
  int R;
  cin >> R;
  vi nv;
  vvi pvv;
  REP(r, R) {
    int n;
    cin >> n;
    nv.push_back(n);
    vi pv;
    int p;
    REP(i, n){
      cin >> p;
      pv.push_back(p);
    }
    pvv.push_back(pv);
  }

  REP(r, R) {
    solve(nv[r], pvv[r]);
  }

  return 0;

}
