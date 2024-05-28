#include<bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'
#define TEST_CASE false

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

// merge y into x
// template<typename T = priority_queue<int>>
// void small_to_large(T& x, T& y) {
// 	if (x.size() <= y.size()) {
// 		while (!x.empty()) {
// 			y.push(x.top());
// 			x.pop();
// 		}
// 		x.swap(y);
// 	}
// 	else {
// 		while (!y.empty()) {
// 			x.push(y.top());
// 			y.pop();
// 		}
// 	}
// }

// merge y into x
template<typename T = priority_queue<int>>
void small_to_large(T& x, T& y) {
	if (x.size() < y.size())
		x.swap(y);
	while (!y.empty()) {
		x.push(y.top());
		y.pop();
	}
	// y.clear();
}

struct vertex {
	bool exist;
	vector<int> child;
	int freq;

	vertex() {
		exist = false;
		freq = 0;
		child.assign(26, -1);
	}
};

struct Trie {

	int root, next;
	vector<vertex> TRIE;

	Trie() : Trie(0) {}
	Trie(int n) {
		TRIE.resize(n + 1);
		root = 0;
		next = 1;
	}

	void ADD_VERTEX() {
		TRIE.push_back(vertex());
	}

	void insert(string word) {
		int cur = root;
		int d = 1;
		for (char c : word) {
			int alphabet_num = tolower(c) - 'a'; // Convert to lowercase
			if (TRIE[cur].child[alphabet_num] == -1) {
				if (next >= int(TRIE.size())) {   // Out of range add new vertex
					ADD_VERTEX();
				}
				TRIE[cur].child[alphabet_num] = next++;
			}
			cur = TRIE[cur].child[alphabet_num];
			TRIE[cur].freq = d; d++;
		}
		// TRIE[cur].freq++;
		TRIE[cur].exist = true;
	}

	// Erase a string from trie
	void erase(string word) {
		int cur = root;
		for (auto c : word) {
			int alphabet_num = tolower(c) - 'a';
			if (TRIE[cur].child[alphabet_num] == -1)
				return;
			cur = TRIE[cur].child[alphabet_num];
		}
		TRIE[cur].freq--;
		if (TRIE[cur].freq == 0)
			TRIE[cur].exist = false;
	}

	// Searches if word present in trie
	// Freq for frequency count
	bool search(string word) {
		int cur = root;
		for (auto c : word) {
			int alphabet_num = tolower(c) - 'a';
			if (TRIE[cur].child[alphabet_num] == -1)
				return false;
			cur = TRIE[cur].child[alphabet_num];
		}
		return TRIE[cur].exist;
	}

	// Return LCP sizes
	// change int to long long
	int LCP(string prefix) {
		int cur = root;
		int lcp_cnt = 0;
		for (auto c : prefix) {
			int alphabet_num = tolower(c) - 'a';
			if (TRIE[cur].child[alphabet_num] == -1) {
				break;
			}
			cur = TRIE[cur].child[alphabet_num];
			lcp_cnt++;
			// lcp_cnt += TRIE[cur].freq++;
		}
		return lcp_cnt;
	}
};

Trie tr;

void dfs(int cur, priority_queue<int>& pq) {
	for (int i = 0; i < 26; i++) {
		if (tr.TRIE[cur].child[i] == -1)
			continue;
		priority_queue<int> qp;
		dfs(tr.TRIE[cur].child[i], qp);
		small_to_large(pq, qp);
	}

	if (!tr.TRIE[cur].exist and !pq.empty()) pq.pop();
	pq.push(tr.TRIE[cur].freq);
};

void solution() {

	int n;
	cin >> n;

	tr = Trie(0);
	while (n--) {
		string s;
		cin >> s;
		tr.insert(s);
	}

	intll ans = 0;
	for (int i = 0; i < 26; i++) {
		if (tr.TRIE[0].child[i] == -1)
			continue;
		priority_queue<int> pq;
		dfs(tr.TRIE[0].child[i], pq);
		while (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans << endl;
}

int32_t main() {

	ios::sync_with_stdio(false) ; cin.tie(0) ;

	int t_c = 1, tt_c = 1;
	if (TEST_CASE) cin >> t_c;

	while (t_c--) {
		// cout << "Case " << tt_c++ << ": ";
		solution();
		// if (t_c) cout << '\n';
	}

	return 0;
}