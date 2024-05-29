#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

int dp[2][25][25][25][25];

void solve(int test_ind){
    for (int i1=0;i1<2;++i1)
    for (int i2=0;i2<25;++i2)
    for (int i3=0;i3<25;++i3)
    for (int i4=0;i4<25;++i4)
    for (int i5=0;i5<25;++i5)
    dp[i1][i2][i3][i4][i5] = -1;

    map<char, int> mp1;
    mp1['C'] = 0;
    mp1['D'] = 1;
    mp1['S'] = 2;
    mp1['H'] = 3;
    map<char, int> mp2;
    mp2['6'] = 0;
    mp2['7'] = 1;
    mp2['8'] = 2;
    mp2['9'] = 3; // start
    mp2['T'] = 4;
    mp2['J'] = 5;
    mp2['Q'] = 6;
    mp2['K'] = 7;
    mp2['A'] = 8;

    auto mp = [&](int ind) -> pair<int, int> { 
        if (ind == 0) return {-1, -1};
        ind--;
        return {3 - (ind&3), (ind>>2) + 3};
    };
    map<pair<int, int>, int> mpind;
    for (int i=0;i<25;++i) mpind[mp(i)] = i;

    vector<vector<bool> > alice(4, vector<bool>(9, false));
    for (int i=0;i<18;++i) {
        string s;
        cin >> s;
        alice[mp1[s[1]]][mp2[s[0]]] = true;
    }
    for (int i=0;i<18;++i) {
        string s;
        cin >> s;
    }
    int wind = mpind[{0, 8}];
    function<bool(int, vector<int>, int, int)> get_winner = [&](int player, vector<int> x, int c1, int c2) -> bool {
        if (c2 == 18) return false;
        if (dp[player][x[0]][x[1]][x[2]][x[3]] != -1) return dp[player][x[0]][x[1]][x[2]][x[3]];
        auto ret = [&](bool val) {
            // cerr << player;
            // auto prnt = [&](int ind) {
            //     auto p = mp(ind);
            //     cerr << " {" << p.first << " " << p.second << "}";
            // };
            // prnt(x[0]);
            // prnt(x[1]);
            // prnt(x[2]);
            // prnt(x[3]);
            // cerr << " : " << val << endl;
            return dp[player][x[0]][x[1]][x[2]][x[3]] = val;
        };
        // alice
        bool turn = false;
        for (int ind=0;ind<4;++ind){
            int px = x[ind];
            pair<int, int> p = mp(x[ind]);
            if (p.first == -1) {
                if (alice[ind][3] == player) {
                    turn = true;
                    x[ind] = mpind[{3, 3}];
                    if (!get_winner(1-player, x, c2, c1+1)){
                        x[ind] = px;
                        return ret(true);
                    }
                }
            } else {
                if (p.first != 0 && alice[ind][p.first - 1] == player) {
                    turn = true;
                    x[ind] = mpind[{p.first-1, p.second}];
                    if (!get_winner(1-player, x, c2, c1+1)){
                        x[ind] = px;
                        return ret(true);
                    }
                }
                if (p.second != 8 && alice[ind][p.second + 1] == player) {
                    turn = true;
                    x[ind] = mpind[{p.first, 1+p.second}];
                    if (!get_winner(1-player, x, c2, c1+1)){
                        x[ind] = px;
                        return ret(true);
                    }
                }
            }
            x[ind] = px;
        }
        if (!turn) return ret(!get_winner(1-player, x, c2, c1));
        return ret(false);
    };

    if (get_winner(1, {0, 0, 0, 0}, 0, 0)) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}
