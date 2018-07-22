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

const int MAX_N = 100000;
const int MAX_R = 100000;


int n[MAX_R], S[MAX_R];
int a[MAX_R][MAX_N];

int main(){
  int R;
  cin >> R;
  REP(r, R){
    cin >> n[r] >> S[r];
    REP(i, n[r]){
      cin >> a[r][i];
    }
  }
  REP(r, R){
    int sum = a[r][0];
    int ans = INFi;
    int i1 = 0, i2 = 0;

    while(i2 < n[r]){
      while(i2 < n[r] && sum < S[r]) {
        sum += a[r][++i2];
      }
      while(sum >= S[r]){
        ans = min(i2 - i1 + 1, ans);
        sum -= a[r][i1++];
      }
    }

    if(ans == INFi) cout << 0 << endl;
    else cout << ans << endl;
  }

  return 0;
}
