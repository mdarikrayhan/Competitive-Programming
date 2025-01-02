#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string.h>

using namespace std;  
using ll = long long;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ve vector

const int N = 1e5 + 10;

struct Node {
  int pre, nxt;
  int l, r;
} nodes[N];

int id = -1;
int head = -1, tail = -1;

void add(int pnode, int cnode) {
  int nxtnode = nodes[pnode].nxt;
  nodes[cnode].nxt = nxtnode;
  nodes[nxtnode].pre = cnode;
  nodes[pnode].nxt = cnode;
  nodes[cnode].pre = pnode;
}

void del(int cnode) {
  int pnode = nodes[cnode].pre;
  int nxtnode = nodes[cnode].nxt;
  nodes[pnode].nxt = nxtnode;
  nodes[nxtnode].pre = pnode;
}

void print(vector<int>& a) {
    cout << "[";
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << "]" << endl;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int count = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    count += a[i];
  }

  //0 0 0 => 0 0 0
  //1 1 1 => 1 1 1
  //1 1 0 => 0 0 0
  //1 0 0 => 1 1 1
  if(count % 2 == 1) {
    cout << "NO" << endl;
    return;
  }

  
  head = 0, tail = 1;
  id = 2;
  nodes[head] = {-1, tail, -1, -1};
  nodes[tail] = {head, -1, -1, -1};
  
  for(int i = 0; i < n; i++) {
    if(a[i] == 0) continue;
    int j = i;
    int cnt = 0;
    while(j < n && a[j]) {
      cnt++;
      j++;
    }
    nodes[id] = {-1, -1, i, j - 1};
    add(nodes[tail].pre, id);
    id++;
    i = j - 1;
  }
  

  vector<int> ans;
  int cur = nodes[head].nxt;
  while(cur != tail && nodes[cur].nxt != tail) {
    int l = nodes[cur].l, r = nodes[cur].r;
    if(r - l + 1 == 0) {
        int nxt = nodes[cur].nxt;
        del(cur);
        cur = nxt;
        continue;
    }
    
    if((r - l + 1) % 2 == 0) {
      cur = nodes[cur].nxt;
      continue;
    }
    int nxt = nodes[cur].nxt;
    if((nodes[nxt].l - r - 1) % 2 == 0) {
      del(cur);
      for(int i = r; i < nodes[nxt].l - 1; i += 2) {
        ans.push_back(i);
        a[i + 1] = a[i + 2] = 1;
      }
      nodes[nxt].l = nodes[cur].l;
      cur = nxt;
    } else {
      for(int i = r; i < nodes[nxt].l - 2; i += 2) {
        ans.push_back(i);
        a[i + 1] = a[i + 2] = 1;
      }
      int i = nodes[nxt].l - 2;
      ans.push_back(i);
      a[i] = a[i + 1] = a[i + 2] = 0;
      nodes[cur].r = i - 1;
      if(nodes[cur].r - nodes[cur].l + 1 == 0) {
          del(cur);
      }
      nodes[nxt].l++;
      cur = nxt;
    }
  }
  
  /*int c = nodes[head].nxt;
  while(c != tail) {
      cout << nodes[c].l << " " << nodes[c].r << " " << nodes[c].nxt << endl;
      c = nodes[c].nxt;
  }*/
  
  cur = nodes[head].nxt;
  while(cur != tail) {
    int l = nodes[cur].l, r = nodes[cur].r;
    if(l == 0 && r == n - 1) {
      cout << "NO" << endl;
      return;
    }
    if(l - 1 >= 0) {
      for(int i = l - 1; i < r; i += 2) {
        ans.push_back(i);
        a[i] = a[i + 1] = a[i + 2] = 0;
      }
      cur = nodes[cur].nxt;
      continue;
    }
    if(r + 1 < n) {
      for(int i = r - 1; i >= l; i -= 2) {
        ans.push_back(i);
        a[i] = a[i + 1] = a[i + 2] = 0;
      }
      cur = nodes[cur].nxt;
      continue;
    }
  }

  cout << "YES" << endl;
  cout << ans.size() << endl;
  for(int x : ans) cout << x + 1 << " ";
  cout << endl;
}
  

int main(){
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
