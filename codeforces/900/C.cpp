#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <numeric>
#include <climits>
using namespace std;

int arr[1 << 17];
int con[1 << 17];
int n;

void yrlpSolve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int ma1 = -1, ma2 = -1;
    for (int i = 1; i <= n; i++) {
        if (arr[i] > ma1) {
            con[arr[i]] -= 1;
            ma2 = ma1;
            ma1 = arr[i];
        } else if (arr[i] > ma2) {
            con[ma1] += 1;
            ma2 = arr[i];
        }
    }

    int ma = 1;
    for (int i = 2; i <= n; i++) {
        if (con[arr[i]] > con[arr[ma]]) {
            ma = i;
        } else if (con[arr[i]] == con[arr[ma]] && arr[i] < arr[ma]) {
            ma = i;
        }
    }
    cout << arr[ma];
    return; 
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
