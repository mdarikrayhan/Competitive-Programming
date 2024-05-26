#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N = 200200;
vector<int> tmp[N],pfsum[N];
int m[N] , k[N] , pfscore[N];
vector<pair<int,int>> score;
vector<int> unq;
int n;
map<int,int> mp;

bool is_greater( pair<int,int>  a, pair<int,int> b  ){
	if(a.first*b.second >= b.first*a.second)
		return true;
	return false;
}

void solve(){
	cin>>n;
	for (int i = 0; i < n; ++i){
		cin>>m[i]>>k[i];
		unq.push_back(m[i]);
	}
	sort(unq.begin() , unq.end());
	unq.resize( unique( unq.begin() , unq.end() ) - unq.begin() );
	for (int i = 0; i < unq.size(); ++i)
		mp[unq[i]] = i;
	int sz = unq.size();
	for (int i = 0; i < n; ++i)
		tmp[mp[m[i]]].push_back(k[i]);
	for (int i = 0; i < sz; ++i)
		sort(tmp[i].begin() , tmp[i].end());
	for (int i = 0; i < sz; ++i)
	{
		pfsum[i].resize(tmp[i].size(),0);
		pfsum[i][0] = tmp[i][0];
		for (int j = 1; j < tmp[i].size(); ++j)
			pfsum[i][j] = pfsum[i][j-1] + tmp[i][j];
	}
	score.resize(sz);
	for (int i = 0; i < sz; ++i)
	{
		score[i] = {0,i};
		for(int x: tmp[i])
			score[i].first += x;
	}
	sort(score.begin(),score.end(),greater<pair<int,int>>());
	pfscore[0] = score[0].first;
	for (int i = 0; i < sz; ++i)
		pfscore[i] = pfscore[i-1] + score[i].first;
	int ans = 0;
	pair<int,int> val = {0,1};
	for (int t = 1; t <=sz ; ++t)
	{
		if(t<=20){
			int sc = 0;
			vector<int> ar;
			for (int i = 0; i < sz; ++i)
			{
				sc = 0;
				int pos = upper_bound(tmp[i].begin() , tmp[i].end() , t) - tmp[i].begin();
				if(pos>0)
					sc += pfsum[i][pos-1];
				sc += (tmp[i].size()-pos)*t;
				ar.push_back(sc);
			}
			sort(ar.begin(),ar.end());
			sc = 0;
			for (int i = 0; i < t; ++i){
				sc += ar.back();
				ar.pop_back();
			}
			if(is_greater({sc,t} , val )){
				ans = t;
				val = {sc,t};
			}
		}
		else{
			int sc = pfscore[t-1];
			if(is_greater({sc,t} , val )){
				ans = t;
				val = {sc,t};
			}
		}
	}
	cout<<ans<<'\n';
	if(ans>20){
		for (int i = 0; i < ans; ++i)
		{
			cout<<unq[score[i].second]<<" ";
		}
	}
	else{
		vector<pair<int,int>> ar;
		for (int i = 0; i < sz; ++i)
		{
			int sc = 0;
			for(int x: tmp[i]){
				if(x >= ans) sc += ans;
				else sc += x;
			}
			ar.push_back( {sc , i} );
		}
		sort(ar.begin(),ar.end());
		for (int i = 0; i < ans; ++i)
		{
			cout<<unq[ar.back().second]<<" ";
			ar.pop_back();
		}
	}

}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}