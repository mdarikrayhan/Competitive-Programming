#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"
#define pb push_back
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

const int mod = 1000003;


void solve() {
    int candidates, cities;
    cin >> candidates >> cities;
    
    int votes[cities][candidates];
    short wins[candidates] = {};

    for (int i = 0; i < cities; i++) {
        int maxVotes = 0;
        for (int j = 0; j < candidates; j++) {
            cin >> votes[i][j];
            maxVotes = max(votes[i][j], maxVotes);
        }

        for (int j = 0; j < candidates; j++) {
            if (votes[i][j] == maxVotes) {
                wins[j]++;
                break;
            }
        }
    }

    short maxWins = *max_element(wins, wins + candidates);

    for (int i = 0; i < candidates; i++) {
        if (wins[i] == maxWins) {
            cout << i + 1;
            return;
        }
    }
}

int main() {
    optimize;
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
