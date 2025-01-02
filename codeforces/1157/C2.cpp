#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 2e5 + 10;

int a[kMaxN], n;
vector<int> q;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int k = n - 1, s = -1;
  for (int i = 0; i < n;) {
    if (a[i] < a[k] && s < a[i]) {
      q.push_back(1), s = a[i], i++;
    } else if (a[i] == a[k] && s < a[k]) {
      int ans1 = 0, ans2 = 0;
      for (int j = i + 1; j <= k; j++) {
        if (a[j - 1] < a[j]) {
          ans1++;
        } else {
          break;
        }
      }
      for (int j = k - 1; j >= i; j--) {
        if (a[j + 1] < a[j]) {
          ans2++;
        } else {
          break;
        }
      }
      if (ans1 < ans2) {
        s = a[k - ans2];
        for (int j = 0; j <= ans2; j++) {
          q.push_back(0), k--;
        }
      } else if (ans1 == ans2) {
        if (a[i + ans1] > a[k - ans2]) {
          s = a[k - ans2];
          for (int j = 0; j <= ans2; j++) {
            q.push_back(0), k--;
          }
        } else {
          s = a[i + ans1];
          for (int j = 0; j <= ans1; j++) {
            q.push_back(1), i++;
          }
        }
      } else {
        s = a[i + ans1];
        for (int j = 0; j <= ans1; j++) {
          q.push_back(1), i++;
        }
      }
    } else if (a[i] > a[k] && s < a[k]) {
      q.push_back(0), k--, s = a[k + 1];
    } else {
      if (s < a[i]) {
        q.push_back(1), s = a[i], i++;
      } else if (s < a[k]) {
        q.push_back(0), s = a[k], k--;
      } else {
        break;
      }
    }
    if (i > k) {
      break;
    }
  }
  cout << q.size() << '\n';
  for (int i = 0; i < q.size(); i++) {
    cout << (q[i] ? "L" : "R");
  }
  return 0;
}
    	 		 	 				  			 	 	  	  	