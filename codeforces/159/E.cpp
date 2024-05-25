#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;

struct block{
	int c;
	ll s;
	int i;
	bool operator<(block b){
		return tie(c, s) < tie(b.c, b.s);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<block> blocks;
	rep(i,0,n){
		int ci, si;
		cin >> ci >> si;
		blocks.emplace_back(ci, si, i+1);
	}
	// Group by colour
	sort(all(blocks));
	vector<vector<block>> cols;
	int st = 0, en = 0;
	while(en<blocks.size()){
		// Find a block of one colour
		while(en<blocks.size() && blocks[en].c == blocks[st].c){
			en++;
		}
		cols.push_back(vector<block>(blocks.begin()+st, blocks.begin()+en));
		sort(all(cols.back()));
		reverse(all(cols.back()));
		st = en;
	}
	// for(auto &col: cols){
	// 	for(auto &b: col){
	// 		cout << b.c << " " << b.s << " " << b.i << endl;
	// 	}
	// 	cout << endl;
	// }

	// Do some magic greedy with replacement
	ll max_h = 0;
	int c1 = 0, c2 = 0;
	vector<block> max_tow(n+7, {-1, -(1LL<<60), 0});
	for(int c=0; c<cols.size(); ++c){
		auto& col = cols[c];
		// Try all best towers to combine with this colour
		ll cur = 0;
		rep(i,0,sz(col)){
			cur += col[i].s;
			// cout << c << " " << cur << endl;
			rep(j, i, i+3){
				if (cur + max_tow[j].s > max_h){
					max_h = cur + max_tow[j].s;
					c1 = c;
					c2 = max_tow[j].c;
				}
			}
		}
		// See if this makes the basis for any new towers
		cur = 0;
		rep(i,0,sz(col)){
			cur += col[i].s;
			if (cur > max_tow[i+1].s){
				max_tow[i+1].s = cur;
				max_tow[i+1].c = c;
			}
		}
	}

	// Print the best tower
	cout << max_h << endl;
	if (cols[c2].size() > cols[c1].size()){
		swap(c1, c2);
	}
	vector<int> idx;
	rep(i,0,sz(cols[c1])){
		idx.push_back(cols[c1][i].i);
		if (i < cols[c2].size()){
			idx.push_back(cols[c2][i].i);
		} else {
			break;
		}
	}
	cout << sz(idx) << endl;
	for(auto a: idx){
		cout << a << " ";
	}
	cout << endl;


	
}
		 	  		   						 	 		    			 	