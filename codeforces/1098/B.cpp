#include<bits/stdc++.h>
#include<complex>
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
typedef vector<string> vs;
#define Nmax 300100
#define sq 320
#define MOD 998244353

vector<string> s, rety;
int N, M;

int dist(string t1, string t2, int dir) {
    int ret = 0;
    if(dir == 0) {
        FOR(i, N) {
            string cur = t1;
            if(i%2 == 0) cur = t2;

            int m1 = 0, m2 = 0;
            FOR(j,M) {
                if(s[i][j] != cur[j%2]) ++m1;
                if(s[i][j] != cur[1-j%2]) ++m2;
            }
            ret += min(m1, m2);
        }
    } else {
        FOR(j, M) {
            string cur = t1;
            if(j%2 == 0) cur = t2;

            int m1 = 0, m2 = 0;
            FOR(i,N) {
                if(s[i][j] != cur[i%2]) ++m1;
                if(s[i][j] != cur[1-i%2]) ++m2;
            }
            ret += min(m1, m2);
        }
    }
    return ret;
}

void makesol(string t1, string t2, int dir) {
    if(dir == 0) {
        FOR(i, N) {
            string cur = t1;
            if(i%2 == 0) cur = t2;

            int m1 = 0, m2 = 0;
            FOR(j,M) {
                if(s[i][j] != cur[j%2]) ++m1;
                if(s[i][j] != cur[1-j%2]) ++m2;
            }
            if(m1 < m2) {
                FOR(j,M) rety[i][j] = cur[j%2];
            } else {
                FOR(j,M) rety[i][j] = cur[1-j%2];
            }
        }
    } else {
        FOR(j, M) {
            string cur = t1;
            if(j%2 == 0) cur = t2;

            int m1 = 0, m2 = 0;
            FOR(i,N) {
                if(s[i][j] != cur[i%2]) ++m1;
                if(s[i][j] != cur[1-i%2]) ++m2;
            }
            if(m1 < m2) {
                FOR(i,N) rety[i][j] = cur[i%2];
            } else {
                FOR(i,N) rety[i][j] = cur[1-i%2];
            }
        }
    }
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin>>N>>M;
  s.resize(N); rety.resize(N);
  FOR(i, N) {
    cin>>s[i];
    rety[i].resize(M);
  }

  vector<pair<string, string>> cand;
  cand.pb(mp("AC", "GT"));
  cand.pb(mp("AG", "CT"));
  cand.pb(mp("AT", "CG"));
  cand.pb(mp("CG", "AT"));
  cand.pb(mp("CT", "AG"));
  cand.pb(mp("GT", "AC"));
  
  ll D = N*M;
  int dir;
  pair<string, string> ret; 

  for(auto t: cand) {
    FOR(k, 2) {
        ll d = dist(t.fs, t.sc, k);
        if(d < D) {
            ret = t;
            dir = k;
            D = d;
        }
    }
  }

  makesol(ret.fs, ret.sc, dir);

  FOR(i, N) cout<<rety[i]<<"\n";

  return 0;
}