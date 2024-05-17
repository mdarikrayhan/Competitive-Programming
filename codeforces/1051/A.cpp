#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LLMAX (1ll << 60) - 1
#define INTMAX (1 << 30) - 1
#define MOD 1000000007
#define NMAX 1000*100+1

#define numberOfSetBits(S) __builtin_popcount(S) // __builtin_popcountl(S) __builtin_popcountll(S)
#define MSET(x,y) memset(x,y,sizeof(x))
#define gcd(a,b) __gcd(a,b)
#define all(x)  x.begin(),x.end()
#define isOn(S, j) (S & (1 << j))
#define endl '\n'
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define print(x)    for(auto it:x) cout<<it<<' '; cout<<endl;
#define in(x,n)   for(int e=0;e<n;e++){ll y;cin>>y;x.pb(y);}
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = b-1; i >= a; i--)

#define vi vector<ll>
#define vvi vector<vi>
#define ii pair<ll,ll>
#define vii vector<ii>
#define vvii vector<vii>
#define viii vector<array<ll,3>>
#define pb push_back
#define F first
#define S second
#define mp make_pair
// cout << fixed << setprecision(10)

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string) s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}";
	return res;
}

template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cout << " " << to_string(H);
	debug_out(T...);
}

#ifdef VIVEK
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, x, t, m, y, z, k;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		n = s.size();
		auto isOk = [&n](string & foo) {
			vi cnt(3);
			rep(i, 0, n) {
				if (isupper(foo[i])) {
					cnt[0]++;
				}
				else if (islower(foo[i])) {
					cnt[1]++;
				}
				else {
					cnt[2]++;
				}
			}
			return *min_element(all(cnt)) != 0;
		};

		if (isOk(s)) {
			cout << s << endl;
			continue;
		}

		vector<string> candidates = { "a", "A", "1", "1a", "1A", "aA"};
		bool found = false;
		for (auto &it : candidates) {
			rep(j, 0, n - it.size() + 1) {
				string foo = s;
				foo.replace(j, it.size(), it);
				if (isOk(foo)) {
					found = true;
					cout << foo << endl;
					break;
				}
			}
			if (found)break;
		}
	}

	return 0;
}