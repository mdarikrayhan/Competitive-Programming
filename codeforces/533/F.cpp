#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define FOR(i, to) for (int i = 0; i < (to); ++i)
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpi;
typedef pair<ll,ll> pll;
typedef vector<pair<ll, ll> > vpl;
typedef vector<string> vs;
char en = '\n';
int N,M,K,P;
#define MOD 1000000007
#define B 1000

class RabinKarp {
public:
  int num = 2;
  vvi nr, pw;
  vi p{47, 149} , MD{666013, 991777};

  RabinKarp(string &s, int rem) {
    int N = sz(s);
    nr.resize(num);
    pw.resize(num);
    FOR(k,num) {
      nr[k].resize(N+1);
      pw[k].resize(N+1);
      pw[k][0] = 1;
      nr[k][0] = 0;
    }
    for(int i=1;i<=N;++i) {
      int val = (s[i-1]);
      if (rem) {
        val = (s[i-1]-'0');
      }
      FOR(k,num) {
        pw[k][i] = (1LL*pw[k][i-1] * p[k]) % MD[k];
        nr[k][i] = (1LL*nr[k][i-1] * p[k] + val) % MD[k];
      }
    }
  }
  int eq(int x, int y, int x1, int y1) {
    if(y-x != y1-x1) return 0;
    ++x, ++y, ++x1, ++y1;
    FOR(k, num) {
      int sol1 = (1LL*nr[k][y] - (1LL*pw[k][y-x+1]*nr[k][x-1]) % MD[k] + MD[k]) % MD[k];
      int sol2 = (1LL*nr[k][y1] - (1LL*pw[k][y1-x1+1]*nr[k][x1-1]) % MD[k] + MD[k]) % MD[k];
      if(sol1 != sol2) return 0;
    }
    return 1;
  }
  pll geth(int x, int y) {
    ++x, ++y;
    pll ret = {-1,-1};
    FOR(k, num) {
      int sol1 = (1LL*nr[k][y] - (1LL*pw[k][y-x+1]*nr[k][x-1]) % MD[k] + MD[k]) % MD[k];
      if(ret.fs == -1) ret.fs = sol1;
      else ret.sc = sol1;
    }
    return ret;
  }
};

string gets(string &s, char x) {
  string ret;
  for(auto y : s) {
    if (x == y) {
      ret += '1';
    } else {
      ret += '0';
    }
  }
  return ret;
}

string sr[26];
vector<RabinKarp> rk;
vector<int> cpos[26];
int main() {
  int N,M;
  cin >> N >> M;
  string s,t;
  cin >> s >> t;
  FOR(i, 26) {
    sr[i] = gets(s, 'a'+i);
    rk.pb(RabinKarp(sr[i], 1));
  }
  RabinKarp qr(t, 0);
  pll good = qr.geth(0, sz(t)-1);
  FOR(i, sz(s)) {
    cpos[s[i]-'a'].pb(i);
  }
  vi ret;
  for(int i=0;i<sz(s);++i) {
    if (i + sz(t) > sz(s)) {
      break;
    }
    pll ch = {0,0};
    int h[26]; FOR(kk, 26) h[kk] = -1;
    FOR(cc, 26) {
      auto it = lower_bound(all(cpos[cc]), i);

      int ps = lower_bound(all(cpos[cc]), i) - cpos[cc].begin();
      int nc = 1;
      
      if (it != cpos[cc].end() && cpos[cc][ps] < i+sz(t)) {
        int tpos = cpos[cc][ps] - i;
        nc = t[tpos];
        
        if (h[nc-'a'] != -1) {
          if (h[nc-'a'] != cc) {
            ch = {-1,-1}; break;
          }
        }
        if (h[cc] != -1) {
          if (h[cc] != nc - 'a') {
            ch = {-1,-1}; break;
          }
        }
        h[cc] = nc-'a';
        h[nc-'a'] = cc; 
         
      }

      pll nh = rk[cc].geth(i, i + sz(t)-1);
      ch.fs += (nh.fs * (nc));
      ch.sc += (nh.sc * (nc));
      ch.fs %= qr.MD[0];
      ch.sc %= qr.MD[1];
    }
    if (ch == good) {
      ret.pb(i);
    }
  }
  cout << sz(ret) << endl;
  for (auto x : ret) {
    cout << x + 1 << " ";
  }
  cout << endl;

  return 0;
}