#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int leftMoves = n/2;
    int rightMoves = n-leftMoves;
    int grid[n][3];
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<3; j++) {
            cin >> grid[i][j];
        }
    }
    map<pair<int, int>, pair<int, int>> m;
    for(int i = 0; i<pow(3, leftMoves); i++) {
        vector<int> moves(leftMoves, 0);
        int mask = i;
        int bit = 0;
        while(mask) {
            moves[bit] = mask%3;
            mask/=3;
            bit++;
        }
        int a = 0, b = 0, c = 0;
        for(int j = 0; j<leftMoves; j++) {
            if(moves[j]==0) {
                a+=grid[j][0], b+=grid[j][1];
            } else if(moves[j]==1) {
                a+=grid[j][0], c+=grid[j][2];
            } else {
                b+=grid[j][1], c+=grid[j][2];
            }
        }
        if(!m.count({b-a, c-b})) m[{b-a, c-b}] = {a, i};
        else if(m[{b-a, c-b}].first<a) m[{b-a, c-b}]={a, i};
    }
    int leftMask = -1, rightMask = -1, ans = -1e9;
    for(int i = 0; i<pow(3, rightMoves); i++) {
        vector<int> moves(rightMoves, 0);
        int mask = i;
        int bit = 0;
        while(mask) {
            moves[bit] = mask%3;
            mask/=3;
            bit++;
        }
        int a = 0, b = 0, c = 0;
        for(int j = 0; j<rightMoves; j++) {
            int jj = j+leftMoves;
            if(moves[j]==0) {
                a+=grid[jj][0], b+=grid[jj][1];
            } else if(moves[j]==1) {
                a+=grid[jj][0], c+=grid[jj][2];
            } else {
                b+=grid[jj][1], c+=grid[jj][2];
            }
        }
        // printf("%d %d\n", a, b, c);
        if(m.count({a-b, b-c})) {
            int candidate = m[{a-b, b-c}].first + a;
            if(candidate > ans) {
                ans = candidate;
                leftMask = m[{a-b, b-c}].second;
                rightMask = i;
            }
        }
    }
    if(ans==-1e9) cout << "Impossible" << endl;
    else {
        vector<int> mmoves(leftMoves, 0);
        int bit = 0;
        while(leftMask) {
            mmoves[bit] = leftMask%3;
            leftMask/=3;
            bit++;
        }
        vector<int> moves(rightMoves, 0);
        bit = 0;
        while(rightMask) {
            moves[bit] = rightMask%3;
            rightMask/=3;
            bit++;
        }
        for(auto &num : mmoves) {
            if(num==0) cout << "LM" << endl;
            else if(num==1) cout << "LW" << endl;
            else cout << "MW" << endl;
        }
        for(auto &num : moves) {
            if(num==0) cout << "LM" << endl;
            else if(num==1) cout << "LW" << endl;
            else cout << "MW" << endl;
        }
    }
}