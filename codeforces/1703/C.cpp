#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> finalSequence(n);
        for (int i = 0; i < n; ++i)
            cin >> finalSequence[i];

        vector<int> initialSequence(n, 0);

        for (int i = 0; i < n; ++i) {
            int moves;
            cin >> moves;
            string actions;
            cin >> actions;
            reverse(actions.begin(),actions.end());
            for (char action : actions) {
                if (action == 'U') {
                    finalSequence[i] -=1;
                } else {
                    finalSequence[i] += 1;
                }
            }
            finalSequence[i] = (finalSequence[i] + 10) % 10; // To handle negative values
        }

        for (int i = 0; i < n; ++i) {
            cout << finalSequence[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
