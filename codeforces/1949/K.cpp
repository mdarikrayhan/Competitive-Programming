#include<bits/stdc++.h>
using namespace std;

// assume a <= b <= c, x1 <= x2 <= ... <= xn
// conditions: A < B + C, B < A + C, C < A + B
// 1) sum of c smallest numbers < sum / 2
// 2) x[n] + sum of a-1 smallest numbers < sum / 2

// let A has xn and a-1 smallest numbers (A < sum / 2 so A < B + C)
// B has next b smallest numbers, C has c remaining numbers (so B < C)
// swap bi cj until C - B < A (bi < cj)
// or until B has b largest numbers and C has c smallest numbers of list B, C (and C - B still >= A)
// assume C - B >= A, since 0 < bi, cj <= x[n] = A[a], cj - bi < A[n] <= A
// when swap bi with cj, C-B decreases 2(cj - bi) < 2A, so new C-B still > -A (valid since |C - B| still < A if C - B < A)

// if after swap all elements but C - B still >= A: (C >= A + B so B < sum / 2)
// swap ai cj until C - A < B (ai < cj and not swap x[n] in A)
// assume C - A >= B, since 0 < ai, cj <= x[n - 1] = B[b], cj - ai < B[b] <= B
// when swap ai with cj, C-A decreases 2(cj - ai) < 2B, so new C-A still > -B (valid since |C - A| still < B if C - A < B, and new A + C > B as B < sum / 2)
// what if swap until A has a largest numbers and C has c smallest numbers in list A, C but C - A still >= B
// in that case, C >= A + B and C >= sum / 2 (contradicts with (1)) so there is no such case
// so can always swap until -B < C - A < B and A + C > B

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<array<int, 2>> num(4);
        for (int i = 1; i <= 3; i++) {
            cin >> num[i][0];
            num[i][1] = i;
        }

        sort(num.begin() + 1, num.begin() + 3 + 1);

        int a = num[1][0];
        int b = num[2][0];
        int c = num[3][0];

        vector<int> x(n + 1);
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            sum += x[i];
        }

        sort(x.begin() + 1, x.begin() + n + 1);

        long long sumSmallest = 0;
        for (int i = 1; i <= c; i++) {
            sumSmallest += x[i];
        }

        if (sumSmallest * 2 >= sum) {
            cout << "NO\n";
            continue;
        }

        long long sumA = x[n];
        for (int i = 1; i < a; i++) {
            sumA += x[i];
        }

        if (sumA * 2 >= sum) {
            cout << "NO\n";
            continue;
        }

        long long sumB = 0, sumC = 0;

        priority_queue<int, vector<int>, greater<int>> pqB;
        priority_queue<int> pqC;

        for (int i = a; i < n; i++) {
            if (i < a + b) {
                sumB += x[i];
                pqB.push(x[i]);
            }
            else {
                sumC += x[i];
                pqC.push(x[i]);
            }
        }

        for (int i = 1; i <= b; i++) {
            if (sumC - sumB < sumA) break;

            int minB = pqB.top();
            int maxC = pqC.top();

            sumB = sumB - minB + maxC;
            sumC = sumC - maxC + minB;

            pqB.pop();
            pqB.push(maxC);

            pqC.pop();
            pqC.push(minB);
        }

        if (sumC - sumB < sumA) {
            vector<vector<int>> ans(4);

            for (int i = 1; i < a; i++) {
                ans[num[1][1]].push_back(x[i]);
            }
            ans[num[1][1]].push_back(x[n]);

            while (pqB.size()) {
                ans[num[2][1]].push_back(pqB.top());
                pqB.pop();
            }

            while (pqC.size()) {
                ans[num[3][1]].push_back(pqC.top());
                pqC.pop();
            }

            cout << "YES\n";
            for (int i = 1; i <= 3; i++) {
                for (auto s: ans[i]) {
                    cout << s << ' ';
                }
                cout << "\n";
            }

            continue;
        }

        priority_queue<int, vector<int>, greater<int>> pqA;
        for (int i = 1; i < a; i++) {
            pqA.push(x[i]);
        }

        for (int i = 1; i < a; i++) {
            if (sumC - sumA < sumB) break;

            int minA = pqA.top();
            int maxC = pqC.top();

            sumB = sumB - minA + maxC;
            sumC = sumC - maxC + minA;

            pqA.pop();
            pqA.push(maxC);

            pqC.pop();
            pqC.push(minA);
        }

        vector<vector<int>> ans(4);

        while (pqA.size()) {
            ans[num[1][1]].push_back(pqA.top());
            pqA.pop();
        }
        ans[num[1][1]].push_back(x[n]);

        while (pqB.size()) {
            ans[num[2][1]].push_back(pqB.top());
            pqB.pop();
        }

        while (pqC.size()) {
            ans[num[3][1]].push_back(pqC.top());
            pqC.pop();
        }

        cout << "YES\n";
        for (int i = 1; i <= 3; i++) {
            for (auto s: ans[i]) {
                cout << s << ' ';
            }
            cout << "\n";
        }
    }
 
    return 0;
}