#include "bits/stdc++.h"

using namespace std;

#define ii pair<int,int>

const int inf = 1e9 + 10;
const int ms = 1e5 + 5;

// vou setar minimo

struct Node{
  int cntMx1, mx1, mx2, matchMx1;
  Node(int cntMx1, int mx1, int mx2, int matchMx1) : cntMx1(cntMx1), mx1(mx1), mx2(mx2), matchMx1(matchMx1){}
  Node(){
    cntMx1 = mx1 = mx2 = matchMx1 = 0;
  }
};

struct Beats{
  array<Node, 2> n;
  long long sum;
  Beats(){
    sum = 0;
  }
};

vector<Beats> seg(4*ms);
array<int, 2> lazy[4*ms];

void merge(int idx, int a, int b){
  seg[idx].sum = seg[a].sum + seg[b].sum;
  for(int i=0; i<2; i++){
    Node &now = seg[idx].n[i];
    Node left = seg[a].n[i], right = seg[b].n[i]; 
    if(left.mx1 < right.mx1) swap(left, right);
    now = left;
    if(left.mx1 == right.mx1){
      now.cntMx1 += right.cntMx1;
      now.matchMx1 += right.matchMx1;
      now.mx2 = max(left.mx2, right.mx2);
    }
    else{
      now.mx2 = max(left.mx2, right.mx1);
    }
  }
}

bool tagCondition(int L, int R, int p, int val, int l, int r, int idx){
  if(!(L <= l && r <= R)) return false;
  return ((l == r) || (seg[idx].n[p].mx1 > val && val >= seg[idx].n[p].mx2));
}

bool breakCondition(int L, int R, int p, int val, int l, int r, int idx){
  return ((l > R || r < L) || val >= seg[idx].n[p].mx1);
}

void apply(int idx, int l, int r){
  for(int i=0; i<2; i++){
    if(lazy[idx][i] >= seg[idx].n[i].mx1) continue;
    seg[idx].sum -= 1ll*seg[idx].n[i].mx1*seg[idx].n[i].matchMx1;
    seg[idx].n[i].mx1 = lazy[idx][i];
    seg[idx].sum += 1ll*seg[idx].n[i].mx1*seg[idx].n[i].matchMx1;
    if(l != r){
      lazy[2*idx + 1][i] = min(lazy[idx][i], lazy[2*idx + 1][i]);
      lazy[2*idx + 2][i] = min(lazy[idx][i], lazy[2*idx + 2][i]);
    }
    else{
      if(seg[idx].n[i].matchMx1 == 0 && seg[idx].n[1 - i].mx1 < inf){
        seg[idx].n[i].matchMx1 = 1;
        seg[idx].n[1 - i].matchMx1 = 1;
        seg[idx].sum += seg[idx].n[i].mx1 + seg[idx].n[1 - i].mx1; 
      }
      seg[idx].n[i].mx2 = -1;
    }
  }

  lazy[idx][0] = lazy[idx][1] = inf+5;
}

void build(int l=0, int r=ms-1, int idx=0){
  lazy[idx][0] = lazy[idx][1] = inf + 5;
  if(l == r){
    seg[idx].sum = 0;
    seg[idx].n[0] = seg[idx].n[1] = Node(1, inf+2, inf+1, 0);
    return;
  }
  int m = (l+r)/2;
  build(l, m, 2*idx + 1), build(m+1, r, 2*idx + 2);
  merge(idx, 2*idx +1, 2*idx + 2);
}

void update(int L, int R, int p, int val, int l=0, int r=ms-1, int idx=0){
  apply(idx, l, r);
  if(breakCondition(L, R, p, val, l, r, idx)) return;
  if(tagCondition(L, R, p, val, l, r, idx)){
    lazy[idx][p] = val;
    apply(idx, l, r);
    return;
  }
  int m = (l+r)/2;
  update(L, R, p, val, l, m, 2*idx + 1);
  update(L, R, p, val, m+1, r, 2*idx + 2);
  merge(idx, 2*idx +1, 2*idx +2);
}

long long query(int L, int R, int l=0, int r=ms-1, int idx=0){
  apply(idx, l, r);
  if(r < L || l > R) return 0;
  if(L <= l && r <= R) return seg[idx].sum;
  int m = (l+r)/2;
  long long ret = query(L, R, l, m, 2*idx +1) + query(L, R, m+1, r, 2*idx +2);
  merge(idx, 2*idx +1, 2*idx + 2);
  return ret;
}

signed main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q;
  cin >> q;

  build();

  while(q--){
    int op, l, r;
    cin >> op >> l >> r;
    r--;
    if(op == 1){
      int k; cin >> k;
      update(l, r, (k < 0), abs(k));
    }
    else{
      cout << query(l, r) << '\n';
    }
  }

}
