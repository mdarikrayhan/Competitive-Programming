#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long 
#define t ll t; cin >> t; while(t--)
#define ln ll n; cin >> n;
#define lnm ll n,m; cin >> n >> m;
#define st string s; cin >> s;
#define lan ll arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
#define lbn ll brr[n]; for(int i = 0; i < n; i++) cin >> brr[i];
#define f(i,a,n) for(ll i = 0; i < n; i++)
#define lnk ll n,k; cin >> n >> k;
#define labc ll a,b,c; cin >> a >> b >> c;
#define lk ll k; cin >> k;
#define ld ll d; cin >> d;
#define lnmk ll n,m,k; cin >> n >> m >> k;

bool sortcol(const vector<ll>& v1, const vector<ll>& v2) {
    return v1[0] < v2[0];
}


const int N = (int)(1e5+5);

vector<int> tree[N]; 


void dfs(int s, int p){
	cout<<s<<" ";
	for(int v: tree[s]){
		if(v != p){
			dfs(v, s);
		}
	}
}

void bfs(int root){
	queue<int> q;
	q.push(root);
	vector<bool> visited(N, false);

	visited[root] = true;

	cout<<"Running BFS---\n";

	while(!q.empty()){
		int u = q.front();
		cout<<u<<" ";
		q.pop();

		for(int v: tree[u]){
			if(!visited[v]){
				visited[v] = true;
				q.push(v);
			}
		}
	}
	cout<<endl;

}

class DSU{
	vector<int> parent;
	vector<int> subtree_size;
	int N;
public:

	DSU(int n){
		N = n;
		parent = vector<int>(n+1, 0);
		subtree_size = vector<int>(n+1, 1);

		for(int i=1; i<=n; i++) parent[i] = i;
	}

	int findRoot(int u){
		while(u != parent[u]){
			parent[u] = parent[parent[u]]; //Path compression
			u = parent[u];
		}

		return u;
	}


	void combine(int u, int v){
		int ru = findRoot(u);
		int rv = findRoot(v);

		if(ru == rv) return;

		if(subtree_size[ru] > subtree_size[rv]){
			parent[rv] = ru;
			subtree_size[ru] += subtree_size[rv];
		} else{
			parent[ru] = rv;
			subtree_size[rv] += subtree_size[ru];
		}

	}

};
ll pow1(ll k ){
if(k==0){return 1;}
ll p=pow1(k/2);
p%=1000000007;
if(k%2==0){
	
	return  (p*p);
}else{
return  (2*p*p);
}
}





ll SubarrayWithMaxSum(vector<ll>& nums)
{
	ll endIndex, currMax = nums[0];
	ll globalMax = nums[0];

	
	for (int i = 1; i < nums.size(); ++i) {

		
		currMax = max(nums[i],
					nums[i] + currMax);

		
		if (currMax > globalMax) {
			globalMax = currMax;
			endIndex = i;
		}
	}

	ll startIndex = endIndex;

	
	while (startIndex >= 0) {

		globalMax -= nums[startIndex];

		if (globalMax == 0)
			break;

		startIndex--;
	}
ll ans=0;
		for (int i = startIndex;
		i <= endIndex; ++i) {
if(ans<nums[i])ans=nums[i];
	}
	return ans;
}
bool check(ll n){
	if(n<10){
		if(n%10 ==0 ||n%10==1){
			return 1;
		}else{
			return 0;
		}
	}
	if(n%10 ==0 ||n%10==1){
			return check(n/10);
		}else{
			return 0;
		}
}


const int mod = 1e9+7;

ll fact(ll n){
	ll res = 1;

	for(int i=1;i<=n;i++) res = (res * i) % mod;

	return res;
}

ll power(ll a , ll n){
	ll res = 1;

	while(n){
		if(n & 1) res = (res * a) % mod;

		n >>= 1;
		a = (a * a) % mod;
	}

	return res;
}

ll modInv(ll n){
	return power(n , mod-2);
}



int main() {
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//n=n k=r
lnm

ll p=__gcd(n,m);

ll q=n/p;
ll r=m/p;
ll ans=0,w=0;

while(q>1){
if(q%2!=0 && q%3!=0 && q%5!=0){
	w=1;break;
}
if(q%2==0){
	ans++;
	q/=2;
}
if(q%3==0){
	ans++;
	q/=3;
}if(q%5==0){
	ans++;
	q/=5;
}

}
while(r>1){
if(r%2!=0 && r%3!=0 && r%5!=0){
	w=1;break;
}
if(r%2==0){
	ans++;
	r/=2;
}
if(r%3==0){
	ans++;
	r/=3;
}if(r%5==0){
	ans++;
	r/=5;
}

}

if(w){
	cout<<-1<<endl;
}else{
	cout<<ans<<endl;
}



}