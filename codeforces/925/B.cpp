#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 #define MAXN 1000007
 
// stores smallest prime factor for every number
int spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
bool sortbyCond(const pair<int, int>& a,
                const pair<int, int>& b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second > b.second);
}
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i < MAXN; i++) {
        // checking if i is prime
        if (spf[i] == i) {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j < MAXN; j += i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
} 

ll fact(ll x){
    ll y=x;
    ll cnt=1;
    while(y--){
        cnt=cnt*x;
       // cnt=cnt%998244353;
        x--;
    }
    return cnt;
}

int n, x, y, pos1 = -1, pos2 = -1;
vector<pair<int, int>> a;
bool f() {
	pos1 = -1, pos2 = -1;
	for (int i = 0; i < n; i++) {
		if ((i + 1) * a[i].first >= x) {
			pos1 = i;
			break;
		}
	}
	if (pos1 == -1) {
		return 0;
	}
	for (int i = pos1 + 1; i < n; i++) {
		if ((i - pos1) * a[i].first >= y) {
			pos2 = i;
			return 1;
		}
	}
	return 0;
}
 /*ifstream inFile;  
    ofstream outFile;
    inFile.open("input.txt");
    outFile.open("output.txt");
    int n;
    inFile >> n;
    outFile<<n;*/
 
void solve() {
  /*   map<int,int>mp;
    for(int i=0;i<n;i++){
    vector<int>v =  getFactorization(a[i]);
    for(int j=0;j<v.size();j++){
        mp[v[j]]++;
    }
    }*/
   cin >> n >> x >> y;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a.push_back({ x, i });
	}
	sort(a.rbegin(), a.rend());
	if (f()) {
		cout << "Yes" << endl;
		cout << pos1 + 1 << ' ' << pos2 - pos1 << endl;
		for (int i = 0; i <= pos1; i++) {
			cout << a[i].second << ' ';
		}
		cout << endl;
		for (int i = pos1 + 1; i <= pos2; i++) {
			cout << a[i].second << ' ';
		}
		cout<<endl;
		return;
	}
	swap(x,y);
	if (f()) {
		cout << "Yes" << endl;
		cout << pos2 - pos1 << ' ' << pos1 + 1 << endl;
		for (int i = pos1 + 1; i <= pos2; i++) {
			cout << a[i].second << ' ';
		}
		cout << endl;
		for (int i = 0; i <= pos1; i++) {
			cout << a[i].second << ' ';
		}
		cout<<endl;
		return;
	}
	cout<<"No"<<endl;

 
    
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t=1;
   // cin >> t;
    while (t--)
        solve();
}