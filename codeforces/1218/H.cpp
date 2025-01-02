#include <bits/stdc++.h>

#define int long long
#define ll long long

#define endl '\n'

#define debug(u) cerr<<(u == inf ? "inf" : to_string(u))<<endl



using namespace std;
using namespace chrono;


const int mxn = 2e5 + 5;

const int LOG = 17;

const int inf = 1e9 + 7;

const int mod = 1e9 + 7;

int n;
int A[mxn];

vector<pair<int,int> > qs[mxn];

int res[mxn];

int vis[mxn];

vector<int> gr[mxn];

vector<int> dfs(int v){
	vector<int> vec;
	vec.push_back(1);

	for(auto u : gr[v]){
		auto upd = dfs(u);
		upd.push_back(0);

		if(upd.size() > vec.size())swap(upd,vec);

		for(int i = 0;i<upd.size();i++){
			vec[vec.size() - 1 - i] += upd[upd.size() - 1 - i];
		}

	}

	if(vis[v] == 1){
		for(auto t : qs[v]){
			int x = t.first;
			if(x >= vec.size()){
				res[t.second] = 0;
			}else{
				res[t.second] = vec[vec.size() - 1 - x];
			}
		}
	}
	return vec;
}

void solve(int T){
    

	cin>>n;

	int pos[n];
	int num[n];
	for(int i = 0;i<n;i++){
		cin>>A[i];
		A[i]--;
		pos[i] = -1;
		num[i] = -1;
	}

	vector<vector<int> > cycles;

	for(int i = 0;i<n;i++){
		if(vis[i])continue;

		vector<int> vec;
		int v = i;
		while(!vis[v]){
			vis[v] = 1;
			vec.push_back(v);
			v = A[v];
		}

		vector<int> cycle;

		while(vec.size() && vec.back() != v){
			cycle.push_back(vec.back());
			vec.pop_back();
		}

		if(!vec.size())continue;

		cycle.push_back(vec.back());

		reverse(cycle.begin(), cycle.end() );
		cycles.push_back(cycle);

		for(int j = 0;j<cycle.size();j++){
			int v = cycle[j];
			vis[v] = 2;
			num[v] = cycles.size() - 1;
			pos[v] = j;
		}
	}

	int q;
	cin>>q;
	for(int i = 0;i<q;i++){
		int m;
		cin>>m;
		int v;
		cin>>v;
		v--;
		if(vis[v] == 1){
			qs[v].push_back({m,i});
		}else{
			auto &cycle = cycles[num[v]];
			int posv = pos[v];
			int sz = cycle.size();
			int sh = m % sz;
			int pos = (posv - sh + sz) % sz;
			int nxt = cycle[pos];
			qs[nxt].push_back({m,i});
		}
	}
			
	
	for(int i = 0;i<n;i++){
		if(vis[i] == 1){
			gr[A[i]].push_back(i);
		}
	}


    vector<pair<int,int> > cnts[n];

	for(int i = 0;i<n;i++){
		if(vis[i] == 2){
			auto t = dfs(i);
			auto &cycle = cycles[num[i]];
			int posi = pos[i];
			int sz = cycle.size();
			for(int dist = 0;dist < t.size();dist++){
				int cnt = t[t.size() - 1 - dist];
				int sh = dist % sz;
				int pos = (posi - sh + sz ) % sz;
				int nxt = cycle[pos];
				cnts[nxt].push_back({dist,cnt});
			}
		}
		
	}
	for(int i = 0;i<n;i++){
		if(vis[i] == 2){
			sort(cnts[i].begin(), cnts[i].end()) ;
			auto pref = cnts[i];
			for(int j = 1;j< pref.size();j++){
				pref[j].second += pref[j-1].second;
			}

			for(auto qt : qs[i]){
				int x = qt.first;
				int id = qt.second;
				int pos = lower_bound(pref.begin(), pref.end(), make_pair((x > inf ? inf : (int) x), inf)) - pref.begin();
				res[id] = pref[pos - 1].second;
			}
		}
	}

	for(int i = 0;i<q;i++){
		cout<<res[i]<<" ";
	}
}   
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin>>t;
	for(int i = 1;i<=t;i++){
		solve(i);
	}
	
}








