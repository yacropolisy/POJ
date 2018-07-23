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

int gcd(int a, int b, int i){
  if(a == 0) return i;
  if(b / a >= 2) return i;
  return gcd(b % a, a, -i);
}

// void solve(int a, int b){
//   if(a > b) swap(a, b);
//   if(gcd(a, b, 1) == 1) cout << "Stan wins" << endl;
//   else cout << "Ollie wins" << endl;
// }

void solve(int a, int b){
  bool f = true;
  for(;;){
    if(a > b) swap(a, b);

    if(b % a == 0) break;

    if(b - a > a) break;

    b -= a;
    f = !f;
  }
  if(f) cout << "Stan wins" << endl;
  else cout << "Ollie wins" << endl;



}

int main(){
  vi va, vb;
  int a, b;
  while(1){
    cin >> a >> b;
    if(a == 0 && b == 0) break;
    va.push_back(a);
    vb.push_back(b);
  }
  REP(i, va.size()){
    solve(va[i], vb[i]);
  }

  return 0;
}
