#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef long double ld;

template <typename A, typename B = less<A>> using ordered_set = tree<A, null_type, B, rb_tree_tag, tree_order_statistics_node_update>;
template <typename A, typename B, typename C = less<A>> using ordered_map = tree<A, B, C, rb_tree_tag, tree_order_statistics_node_update>;

void prep();
void solve(const int curt);

const int dx4[4] = {0, 0, 1, -1}, dy4[4] = {1, -1, 0, 0};
const int dx8[8] = {0, 0, 1, 1, 1, -1, -1, -1}, dy8[8] = {1, -1, 1, 0, -1, 1, 0, -1};
const bool isT = false;

constexpr const double EPS = 1e-9;
const int GLMOD = 998'244'353;
// const int GLMOD = 1'000'000'007;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prep();

	int t = 1; if(isT)cin >> t;
	for(int i = 1; i <= t; ++i)solve(i);
}


namespace dbg {

	string to_string(const string s);
	string to_string(const char* c);
	string to_string(const bool& b);
	string to_string(const char& c);
	template<typename A> string to_string(A x);
	template<typename A> string to_string(const vector<A> &V);
	template<typename A> string to_string(const stack<A> &S);
	template<typename A> string to_string(const deque<A> &V);
	template<typename A> string to_string(const set<A> &S);
	template<typename A> string to_string(const unordered_set<A> &S);
	template<typename A> string to_string(const queue<A> &Q);
	template<typename A> string to_string(const std::priority_queue<A> &Q);
	template<typename A, size_t sz > string to_string(const array<A, sz> &V);
	template<typename A, typename B> string to_string(const pair<A, B> &p);
	template<typename A, typename B> string to_string(const set<A, B> &S);
	template<typename A, typename B> string to_string(const unordered_set<A, B> &S);
	template<typename A, typename B> string to_string(const map<A, B> &M);
	template<typename A, typename B> string to_string(const unordered_map<A, B> &M);
	template<typename A, typename B> string to_string(const queue<A, B> &Q);
	template<typename A, typename B> string to_string(const std::priority_queue<A, B> &Q);
	template<typename A, typename B> string to_string(tree<A, null_type, B, rb_tree_tag, tree_order_statistics_node_update> &T);
	template<typename A, typename B, typename C> string to_string(const set<A, B, C> &S);
	template<typename A, typename B, typename C> string to_string(const unordered_set<A, B, C> &S);
	template<typename A, typename B, typename C> string to_string(const map<A, B, C> &M);
	template<typename A, typename B, typename C> string to_string(const unordered_map<A, B, C> &M);
	template<typename A, typename B, typename C> string to_string(const std::priority_queue<A, B, C> &Q);
	template<typename A, typename B, typename C> string to_string(tree<A, B, C, rb_tree_tag, tree_order_statistics_node_update> &T);

	string to_string(const string s) {
		return '"' + s + '"';
	}

	string to_string(const char* s) {
		return to_string((string)s);
	}

	string to_string(const bool& b) {
		return b ? "True" : "False";
	}

	string to_string(const char& c) {
		return (string)"'" + c + "'";
	}

	template<typename A> string to_string(A x) {
		stringstream s;
		s << fixed << setprecision(4) << x;
		return s.str();
	}

	template<typename A> string to_string(const vector<A> &V) {
		if(V.empty()){
			return "{ }";
		}
		string ret = "{";
		for(auto it = V.begin(); it != V.end(); ++it){
			ret += to_string(*it) + (next(it) == V.end() ? "}" : ", ");
		}
		return ret;
	}

	template<typename A> string to_string(const stack<A> &S) {
		if(S.empty()){
			return "{ }";
		}
		string ret = "{";
		for(auto it = S.begin(); it != S.end(); ++it){
			ret += to_string(*it) + (next(it) == S.end() ? "}" : ", ");
		}
		return ret;

	}

	template<typename A> string to_string(const deque<A> &V){
		if(V.empty()){
			return "{ }";
		}
		string ret = "{";
		for(auto it = V.begin(); it != V.end(); ++it){
			ret += to_string(*it) + (next(it) == V.end() ? "}" : ", ");
		}
		return ret;
	}

	template<typename A> string to_string(const set<A> &S){
		if(S.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = S.begin(); it != S.end(); ++it){
			ret += to_string(*it) + (next(it) == S.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A> string to_string(const unordered_set<A> &S){
		if(S.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = S.begin(); it != S.end(); ++it){
			ret += to_string(*it) + (next(it) == S.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A> string to_string(const queue<A> &Q){
		if(Q.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = Q.begin(); it != Q.end(); ++it){
			ret += to_string(*it) + (next(it) == Q.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A> string to_string(const std::priority_queue<A> &Q){
		if(Q.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = Q.begin(); it != Q.end(); ++it){
			ret += to_string(*it) + (next(it) == Q.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A, size_t sz>  string to_string(const array<A, sz> &V){
		if(V.empty()){
			return "{ }";
		}
		string ret = "{";
		for(size_t i = 0; i < sz; ++i){
			ret += to_string(V[i]) + (i + size_t(1) == sz ? "}" : ", ");
		}
		return ret;
	}

	template<typename A, typename B> string to_string(const pair<A, B> &p){
		return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
	}

	template<typename A, typename B> string to_string(const set<A, B> &S){
		if(S.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = S.begin(); it != S.end(); ++it){
			ret += to_string(*it) + (next(it) == S.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A, typename B> string to_string(const unordered_set<A, B> &S){
		if(S.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = S.begin(); it != S.end(); ++it){
			ret += to_string(*it) + (next(it) == S.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A, typename B> string to_string(const map<A, B> &M){
		if(M.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = M.begin(); it != M.end(); ++it){
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == M.end() ? ")]" : "), ");
		}
		return ret;
	}

	template<typename A, typename B> string to_string(const unordered_map<A, B> &M){
		if(M.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = M.begin(); it != M.end(); ++it){
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == M.end() ? ")]" : "), ");
		}
		return ret;
	}

	template<typename A, typename B> string to_string(const queue<A, B> &Q){
		if(Q.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = Q.begin(); it != Q.end(); ++it){
			ret += to_string(*it) + (next(it) == Q.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A, typename B> string to_string(const std::priority_queue<A, B> &Q){
		if(Q.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = Q.begin(); it != Q.end(); ++it){
			ret += to_string(*it) + (next(it) == Q.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A, typename B> string to_string(tree<A, null_type, B, rb_tree_tag, tree_order_statistics_node_update> &S){
		if(S.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = S.begin(); it != S.end(); ++it){
			ret += to_string(*it) + (next(it) == S.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A, typename B, typename C> string to_string(const set<A, B, C> &S){
		if(S.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = S.begin(); it != S.end(); ++it){
			ret += to_string(*it) + (next(it) == S.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A, typename B, typename C> string to_string(const unordered_set<A, B, C> &S){
		if(S.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = S.begin(); it != S.end(); ++it){
			ret += to_string(*it) + (next(it) == S.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A, typename B, typename C> string to_string(const map<A, B, C> &M){
		if(M.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = M.begin(); it != M.end(); ++it){
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == M.end() ? ")]" : "), ");
		}
		return ret;
	}

	template<typename A, typename B, typename C> string to_string(const unordered_map<A, B, C> &M){
		if(M.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = M.begin(); it != M.end(); ++it){
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == M.end() ? ")]" : "), ");
		}
		return ret;
	}

	template<typename A, typename B, typename C> string to_string(const std::priority_queue<A, B, C> &Q){
		if(Q.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = Q.begin(); it != Q.end(); ++it){
			ret += to_string(*it) + (next(it) == Q.end() ? "]" : ", ");
		}
		return ret;
	}
	template<typename A, typename B, typename C> string to_string(tree<A, B, C, rb_tree_tag, tree_order_statistics_node_update> &M){
		if(M.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = M.begin(); it != M.end(); ++it){
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == M.end() ? ")]" : "), ");
		}
		return ret;
	}

	void dbg_out() {
		cerr << endl;
	}

	template<typename A, typename... B> void dbg_out(A a, B... b){
		std::cerr << "\033[96m " << to_string(a) << "\033[0m";
		dbg_out(b...);
	}

	void dbm_tab(const int cnt = 1) {
		cerr << string(cnt,' ');
	}

	template<typename A> void dbm_out(A a){
		for(auto it = a.begin(); it != a.end(); ++it){
			dbm_tab(1);
			std::cerr << "\033[96m[ " << to_string(*it) << " ]\033[0m" << endl;
		}
	}
}

#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << "\033[94m[" << #__VA_ARGS__ << "]:\033[0m", dbg::dbg_out(__VA_ARGS__)
#define debum(...) std::cerr << "\033[94m[" << #__VA_ARGS__ << "]:\033[0m\n", dbg::dbm_out(__VA_ARGS__)
#else
#define debug(...)
#define debum(...)
#endif


void prep(){

}

int n, k, eps;

bool f(double r2, vector<int> &dis){
	vector<vector<double>> dp(n + 1, vector<double> (k + 1, 0));
	for(int i = 0; i <= n; ++i){
		dp[i][0] = 1;
	}
	for(int i = 1; i <= k; ++i){
		for(int j = n - 1; ~j; --j){
			dp[j][i] = dp[j + 1][i - 1] * min(1.0, exp(1 - dis[j] / r2)) + dp[j + 1][i] * (1.0 - min(1.0, exp(1 - dis[j] / r2)));
		}
	}
	return dp[0][k] * 1000 + eps >= 1000;
}

void solve(const int curt){
	cin >> n >> k >> eps;
	int x0, y0; cin >> x0 >> y0;
	vector<int> dis;
	for(int i = 0; i < n; ++i){
		int x, y; cin >> x >> y;
		dis.push_back((x - x0) * (x - x0) + (y - y0) * (y - y0));
	}
	double l = 0, r = 10000000;
	while(r - l > EPS){
		double m = (l + r) / 2;
		if(f(m, dis)){
			r = m;
		}
		else l = m;
	}
	printf("%.8f\n", sqrt(l));
}

