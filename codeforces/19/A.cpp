// LUOGU_RID: 160150175
#include<bits/stdc++.h>
using namespace std;
const int N = 55;
struct Team{
	string name;
	int score;
	int net_balls;
	int balls;
}t[N];
int n;
map<string, int> mp;
bool cmp1(Team a, Team b){
	if(a.score > b.score) return true;
	else if(a.score == b.score){
		if(a.net_balls > b.net_balls) return true;
		else if(a.net_balls == b.net_balls){
			return a.balls > b.balls;
		}
		else return false;
	}
	else return false;
}
bool cmp2(Team a, Team b){
	return a.name < b.name;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> t[i].name;
		mp[t[i].name] = i;
	}
	for(int i = 1; i <= n * (n - 1) / 2; i ++){
		string a, b;
		cin >> a >> b;
		int k = a.find('-');
		string team1 = a.substr(0, k);
		string team2 = a.substr(k + 1);
		k = b.find(':');
		int s1 = stoi(b.substr(0, k));
		int s2 = stoi(b.substr(k + 1));
		if(s1 > s2) t[mp[team1]].score += 3;
		else if(s1 == s2) t[mp[team1]].score += 1, t[mp[team2]].score += 1;
		else t[mp[team2]].score += 3;
		t[mp[team1]].net_balls += s1 - s2;
		t[mp[team2]].net_balls += s2 - s1;
		t[mp[team1]].balls += s1;
		t[mp[team2]].balls += s2;
	}
	sort(t + 1, t + 1 + n, cmp1);
	sort(t + 1, t + 1 + n / 2, cmp2);
	for(int i = 1; i <= n / 2; i ++) cout << t[i].name << '\n';

	return 0;
}