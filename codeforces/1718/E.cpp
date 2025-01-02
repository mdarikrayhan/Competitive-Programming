#include<cstdio>
#include<map>
using namespace std;
#define SIZE 201000
#define INF 1000000000
typedef pair<int, int> pii;
typedef map<int,int> mii;
typedef mii::iterator mii_it;
int n,m;
int ia[SIZE], ib[SIZE];
int ta[SIZE], tb[SIZE];
mii ca[SIZE], ra[SIZE];
mii cb[SIZE], rb[SIZE];
int mca[SIZE], mra[SIZE];
int mcb[SIZE], mrb[SIZE];

inline int a(int x, int y) {
  return ia[x*m+y];
}
inline int b(int x, int y) {
  return ib[x*m+y];
}

bool matchr(int u, int v);
bool matchc(int u, int v);
int tmca[SIZE], tmra[SIZE];
int tmcb[SIZE], tmrb[SIZE];
bool matchr(int u, int v) {
  if (ra[u].size() != rb[v].size()) {
    return false;
  }
  mii_it ita, itb;
  ita = ra[u].begin();
  itb = rb[v].begin();
  while(ita != ra[u].end() && itb != rb[v].end()) {
    if (ita->first != itb->first) return false;
    if (tmca[ita->second] != INF) {
      if (tmca[ita->second] != itb->second) return false;
    }
    if (tmcb[itb->second] != INF) {
      if (tmcb[itb->second] != ita->second) return false;
    }
    ita++; itb++;
  }

  tmra[u] = v;
  tmrb[v] = u;
  ita = ra[u].begin();
  itb = rb[v].begin();
  while(ita != ra[u].end() && itb != rb[v].end()) {
    if (tmca[ita->second] == INF && tmcb[itb->second] == INF) {
      // printf("call matchc(%d, %d)\n", ita->second, itb->second);
      bool res = matchc(ita->second, itb->second);
      
      if (!res) return false;
    }
    ita++; itb++;
  }
  return true;
}

bool matchc(int u, int v) {
  if (ca[u].size() != cb[v].size()) {
    return false;
  }
  mii_it ita, itb;
  ita = ca[u].begin();
  itb = cb[v].begin();
  while(ita != ca[u].end() && itb != cb[v].end()) {
    if (ita->first != itb->first) return false;
    if (tmra[ita->second] != INF) {
      if (tmra[ita->second] != itb->second) return false;
    }
    if (tmrb[itb->second] != INF) {
      if (tmrb[itb->second] != ita->second) return false;
    }
    ita++; itb++;
  }

  tmca[u] = v;
  tmcb[v] = u;
  ita = ca[u].begin();
  itb = cb[v].begin();
  while(ita != ca[u].end() && itb != cb[v].end()) {
    if (tmra[ita->second] == INF && tmrb[itb->second] == INF) {
      bool res = matchr(ita->second, itb->second);

      if (!res) return false;
    }
    ita++; itb++;
  }
  return true;
}

int main() {
  int rowc = 1, colc = 2;
  scanf("%d%d",&n,&m);
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ;j < m ; j++) {
      scanf("%d",&ta[i*m+j]);
    }
  }
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ;j < m ; j++) {
      scanf("%d",&tb[i*m+j]);
    }
  }
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ;j < m ; j++) {
      if (n > m) {
        ia[j*n+i] = ta[i*m+j];
        ib[j*n+i] = tb[i*m+j];
      } else {
        ia[i*m+j] = ta[i*m+j];
        ib[i*m+j] = tb[i*m+j];
      }
    }
  }
  if (n > m) {
    int t = n; n = m; m = t;
    int cc = rowc; rowc = colc; colc = cc;
  }
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      if (a(i,j) != 0) {
        ra[i].insert(pii(a(i,j), j));
        ca[j].insert(pii(a(i,j), i));
      }

      if (b(i,j) != 0) {
        rb[i].insert(pii(b(i,j), j));
        cb[j].insert(pii(b(i,j), i));
      }
    }
  }
  for(int i = 0 ; i < n ; i++) mra[i] = mrb[i] = INF;
  for(int i = 0 ; i < m ; i++) mca[i] = mcb[i] = INF;

  for(int u = 0 ; u < n ; u++) {
    if (mra[u] != INF) continue;
    for(int v = 0 ; v < n ; v++) {
      if (mrb[v] != INF) continue;
      for(int i = 0 ; i < n ; i++) {
        tmra[i] = mra[i];
        tmrb[i] = mrb[i];
      }
      for(int i = 0 ; i < m ; i++) {
        tmca[i] = mca[i];
        tmcb[i] = mcb[i];
      }

      if (matchr(u,v)) {
    
        for(int i = 0 ; i < n ; i++) 
        {
          mra[i] = tmra[i];
          mrb[i] = tmrb[i];
        }
        for(int i = 0 ; i < m ; i++) {
          mca[i] = tmca[i];
          mcb[i] = tmcb[i];
        }
        break;
      }
    }
  }
  for(int i = 0 ; i < n ; i++) {
    if (mra[i] == INF) {
      printf("-1\n");
      return 0;
    }
  }
  int xb = 0;
  for(int i = 0 ; i < m ; i++) {
    if (mca[i] == INF) {
      while(mcb[xb] != INF) xb++;
      mca[i] = xb;
      mcb[xb] = i;
      xb++;
    }
  }
  int count = 0;
  for(int i = 0 ; i < n ; i++) {
    tmra[i] = mra[i];
    tmrb[i] = mrb[i];
  }
  for(int i = 0 ; i < m ; i++) {
    tmca[i] = mca[i];
    tmcb[i] = mcb[i];
  }
  for(int i = 0 ; i < n ; i++) {
    if (tmrb[i] != i) {
      count++;
      int u = tmrb[i], v = tmra[i];
      tmra[i] = i;
      tmrb[i] = i;
      tmra[u] = v;
      tmrb[v] = u;
    }
  }
  for(int i = 0 ; i < m ; i++) {
    if (tmcb[i] != i) {
      count++;
      int u = tmcb[i], v = tmca[i];
      tmca[i] = i;
      tmcb[i] = i;
      tmca[u] = v;
      tmcb[v] = u;
    }
  }

  printf("%d\n",count);
  for(int i = 0 ; i < n ; i++) {
    if (mrb[i] != i) {
      printf("%d %d %d\n", rowc, i+1, mrb[i]+1);
      int u = mrb[i], v = mra[i];
      mra[i] = i;
      mrb[i] = i;
      mra[u] = v;
      mrb[v] = u;
    }
  }
  
  for(int i = 0 ; i < m ; i++) {
    if (mcb[i] != i) {
      printf("%d %d %d\n", colc, i+1, mcb[i]+1);
      int u = mcb[i], v = mca[i];
      mca[i] = i;
      mcb[i] = i;
      mca[u] = v;
      mcb[v] = u;
    }
  }
}
