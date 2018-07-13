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

vvi solve(vvi su, int m){
  if(su[0][0] == -1) return su;

  while(m < 81 && su[m/9][m%9] != 0 )m++;
  if(m >= 81) return su;
  int x = m / 9;
  int y = m % 9;
  bool a[10];
  REP(i,10) a[i] = true;



  int bx = x / 3 * 3;
  int by = y / 3 * 3;
  REP(i,9){
    if(su[x][i]!=0) a[su[x][i]] = false;
    if(su[i][y]!=0) a[su[i][y]] = false;
    if(su[bx+i/3][by+i%3]!=0) a[su[bx+i/3][by+i%3]] = false;
  }

  REP(i,9){
    if(a[i+1] == true){
      vvi tmp = su;
      tmp[x][y] = i+1;
      vvi res = solve(tmp, m+1);
      if(res[0][0] != -1) return res;
    }
  }
  su[0][0] = -1;
  return su;

}

int main(){
  int n;
  cin >> n;
  REP(i,n){
    vvi su(9,vi(9,0));
    string in;
    REP(j,9){
      cin >> in;
      REP(l,9)su[j][l] = (in[l]) - '0';
    }
    su = solve(su, 0);
    REP(j,9){
      REP(l,9) cout << su[j][l];
      cout << endl;
    }
  }

  return 0;
}
