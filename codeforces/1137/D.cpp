#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using pll=pair<ll,ll>;
using vll=vector<ll>;
using vpl=vector<pll>;
using vstr=vector<string>;
using sll=set<ll>;
using spl=set<pll>;
using qll=queue<ll>;
ll INF=1e18;
#define PI 3.14159265
ll MOD=1e9+7;



vll move_result(const vll &to_move) {
	cout << "next ";
	for(ll i=0;i<to_move.size()-1;i++){
        cout << to_move[i] << ' ';
    }
	cout << to_move.back() << endl;
	ll group_num;
	cin >> group_num;
	vll groups(10);
	for(ll g=0;g<group_num;g++){
		string group;
		cin >> group;
		for(char i:group){
            groups[i-'0']=g;
        }
	}
	return groups;
}

int main() {
	move_result({0,1});
	vll groups = move_result({1});
	while(groups[0]!=groups[1]){
		move_result({0,1});
		groups=move_result({1});
	}
	while(groups[2]!=groups[1]){
		groups = move_result({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
	}
	cout << "done" << endl;
	fflush(stdout);
	return 0;
}
