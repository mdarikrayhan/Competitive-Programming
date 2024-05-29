#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<int> x(q), y(q);
  for (int i = 0; i < q; i++) {
    cin >> x[i] >> y[i];
    --x[i]; --y[i];
  }
  vector<vector<int>> U(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'X') {
        U[i][j] = i;
      } else {
        U[i][j] = (i == 0 ? -1 : U[i - 1][j]);
      }
    }
  }
  vector<vector<int>> D(n, vector<int>(m));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'X') {
        D[i][j] = i;
      } else {
        D[i][j] = (i == n - 1 ? n : D[i + 1][j]);
      }
    }
  }
  vector<vector<int>> L(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'X') {
        L[i][j] = j;
      } else {
        L[i][j] = (j == 0 ? -1 : L[i][j - 1]);
      }
    }
  }
  vector<vector<int>> R(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = m - 1; j >= 0; j--) {
      if (s[i][j] == 'X') {
        R[i][j] = j;
      } else {
        R[i][j] = (j == m - 1 ? m : R[i][j + 1]);
      }
    }
  }
  vector<int> from(max(n, m)), to(max(n, m));
  vector<int> res(q);
  function<void(int, int, int, int, vector<int>)> Solve = [&](int xl, int xr, int yl, int yr, vector<int> qs) {
    if (xl > xr || yl > yr) {
      return;
    }
    if (xr - xl > yr - yl) {
      int mid = (xl + xr) >> 1;
      for (int i = yl; i <= yr; i++) {
        from[i] = max(xl, U[mid][i] + 1);
        to[i] = min(xr, D[mid][i] - 1);
      }
      for (int i = -1; i < (int) qs.size(); i++) {
        int nxt = (i == (int) qs.size() - 1 ? q - 1 : qs[i + 1] - 1);
        if (i >= 0) {
          int qi = qs[i];
          if (x[qi] <= mid) {
            from[y[qi]] = max(from[y[qi]], x[qi] + 1);
          }
          if (x[qi] >= mid) {
            to[y[qi]] = min(to[y[qi]], x[qi] - 1);
          }
        }
        if (nxt < 0) {
          continue;
        }
        int r = yl - 1;
        deque<pair<int, int>> dq_from, dq_to;
        for (int l = yl; l <= yr; l++) {
          if (from[l] > to[l]) {
            while (!dq_from.empty()) {
              dq_from.pop_back();
            }
            while (!dq_to.empty()) {
              dq_to.pop_back();
            }
            continue;
          }
          r = max(r, l - 1);
          while (r + 1 <= yr) {
            int new_to = to[r + 1];
            if (!dq_to.empty()) {
              new_to = min(new_to, dq_to.front().second);
            }
            int new_from = from[r + 1];
            if (!dq_from.empty()) {
              new_from = max(new_from, dq_from.front().second);
            }
            if ((r + 1 - l + 1) > new_to - new_from + 1) {
              break;
            }
            r += 1;
            while (!dq_to.empty() && dq_to.back().second >= to[r]) {
              dq_to.pop_back();
            }
            dq_to.emplace_back(r, to[r]);
            while (!dq_from.empty() && dq_from.back().second <= from[r]) {
              dq_from.pop_back();
            }
            dq_from.emplace_back(r, from[r]);
          }
          res[nxt] = max(res[nxt], r - l + 1);
          if (!dq_from.empty() && dq_from.front().first == l) {
            dq_from.pop_front();
          }
          if (!dq_to.empty() && dq_to.front().first == l) {
            dq_to.pop_front();
          }
        }
      }
      vector<int> qsL, qsR;
      for (int qi : qs) {
        if (x[qi] < mid) {
          qsL.push_back(qi);
        }
        if (x[qi] > mid) {
          qsR.push_back(qi);
        }
      }
      Solve(xl, mid - 1, yl, yr, qsL);
      Solve(mid + 1, xr, yl, yr, qsR);
    } else {
      int mid = (yl + yr) >> 1;
      for (int i = xl; i <= xr; i++) {
        from[i] = max(yl, L[i][mid] + 1);
        to[i] = min(yr, R[i][mid] - 1);
      }
      for (int i = -1; i < (int) qs.size(); i++) {
        int nxt = (i == (int) qs.size() - 1 ? q - 1 : qs[i + 1] - 1);
        if (i >= 0) {
          int qi = qs[i];
          if (y[qi] <= mid) {
            from[x[qi]] = max(from[x[qi]], y[qi] + 1);
          }
          if (y[qi] >= mid) {
            to[x[qi]] = min(to[x[qi]], y[qi] - 1);
          }
        }
        if (nxt < 0) {
          continue;
        }
        int r = xl - 1;
        deque<pair<int, int>> dq_from, dq_to;
        for (int l = xl; l <= xr; l++) {
          if (from[l] > to[l]) {
            while (!dq_from.empty()) {
              dq_from.pop_back();
            }
            while (!dq_to.empty()) {
              dq_to.pop_back();
            }
            continue;
          }
          r = max(r, l - 1);
          while (r + 1 <= xr) {
            int new_to = to[r + 1];
            if (!dq_to.empty()) {
              new_to = min(new_to, dq_to.front().second);
            }
            int new_from = from[r + 1];
            if (!dq_from.empty()) {
              new_from = max(new_from, dq_from.front().second);
            }
            if ((r + 1 - l + 1) > new_to - new_from + 1) {
              break;
            }
            r += 1;
            while (!dq_to.empty() && dq_to.back().second >= to[r]) {
              dq_to.pop_back();
            }
            dq_to.emplace_back(r, to[r]);
            while (!dq_from.empty() && dq_from.back().second <= from[r]) {
              dq_from.pop_back();
            }
            dq_from.emplace_back(r, from[r]);
          }
          res[nxt] = max(res[nxt], r - l + 1);
          if (!dq_from.empty() && dq_from.front().first == l) {
            dq_from.pop_front();
          }
          if (!dq_to.empty() && dq_to.front().first == l) {
            dq_to.pop_front();
          }
        }
      }
      vector<int> qsL, qsR;
      for (int qi : qs) {
        if (y[qi] < mid) {
          qsL.push_back(qi);
        }
        if (y[qi] > mid) {
          qsR.push_back(qi);
        }
      }
      Solve(xl, xr, yl, mid - 1, qsL);
      Solve(xl, xr, mid + 1, yr, qsR);
    }
  };
  vector<int> v(q);
  iota(v.begin(), v.end(), 0);
  Solve(0, n - 1, 0, m - 1, v);
  for (int i = q - 2; i >= 0; i--) {
    res[i] = max(res[i], res[i + 1]);
  }
  for (int i = 0; i < q; i++) {
    cout << res[i] << '\n';
  }
  return 0;
}