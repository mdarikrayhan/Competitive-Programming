#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// if you end up using long double, you need to set the floating point notation to fixed, and set the percision to be very high
typedef long double ld;

// contrsuct umaps like this, unordered_map<long long, int, custom_hash> safe_map;
// FIXED_RANDOM is static so it doesn not get redeclared between function calls
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
		
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


#define INF 2001001001
#define INF2 2e18
#define MOD 1000000007

#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for(long long a = b; a < c; a++)
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define pb push_back 
#define pf push_front
#define f first
#define s second
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define tp make_tuple

// first four are north, west, east ,south
int dir1[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dir2[] = {0, 1, 0, -1, 1, -1, 1, -1};

int main() {
	// apparently this does fast i/o
	cin.tie(0) , ios::sync_with_stdio(0);
	
	// use this if you read in from a file
	/*
	freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	*/
	
	stringstream ss;
	
	// Do it once. Do it right.
	// Read the problem statement carefully
	// Plan out the steps in words on a piece of paper before implementing
	// after RTE(obviously) but also WA, run valgrind!!!
	
	//cout << fixed << setprecision(12);
	// if you use ld, use the above and don't use string stream
	
	// use instead of ceil(a, b) if a and b are positive
	// (a + b - 1) / b
	
	int t;
	cin >> t;
	while(t > 0){
		t--;
		int n;
		cin >> n;
		string str;
		cin >> str;
		set<string> oset;
		
		bool works = false;
		int ind_add = 0;
		int ind_check = 1;
		while(ind_check+1 < n){
			if(oset.count(str.substr(ind_check, 2))) works = true;
			oset.insert(str.substr(ind_add, 2));
			ind_add++;
			ind_check++;
		}
		if(works){
			ss << "YES" << endl;
		}else{
			ss << "NO" << endl;
		}
		
	}
	cout << ss.str();
	return 0;
}
