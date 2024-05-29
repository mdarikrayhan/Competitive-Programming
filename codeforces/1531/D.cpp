#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
vector<string> s;
set<int> a;
set<int> b;

void Update(int i) {
  a.erase(i);
  if (i + 1 < n && s[i] == "unlock" && s[i + 1] != "unlock" && s[i + 1] != "lock") {
    a.insert(i);
  }
  b.erase(i);
  if (s[i] == "unlock" || s[i] == "lock") {
    b.insert(i);
  }
}

string GetResult() {
  int p = *prev(a.end());
  int q = *next(b.find(p));
  return s[q - 1];
}

int main() {
  cin >> n;
  n += 3;
  s.resize(n);
  s[0] = "unlock";
  s[1] = "blue";
  for (int i = 2; i < n - 1; i++) {
    cin >> s[i];
  }
  s[n - 1] = "lock";
  for (int i = 0; i < n; i++) {
    Update(i);
  }
  cout << GetResult() << endl;
  int tt;
  cin >> tt;
  for (int i = 0; i < tt; i++) {
    int id;
    cin >> id;
    id += 1;
    cin >> s[id];
    Update(id - 1);
    Update(id);
    cout << GetResult() << endl;
  }
  return 0;
}