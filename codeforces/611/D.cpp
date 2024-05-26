#include<bits/stdc++.h>

using namespace std;

const int MAX = 5e3+5;
const int MOD = 1e9+7;

int z[MAX][MAX];
int id;
void zalgo(string &s){
	int L = 0, R = 0, n = s.size();
	for(int i = 1; i<n; ++i){
		if(i>R){
			L = R = i;
			while(R<n && s[R-L]==s[R])++R;
			z[id][i] = R-L, --R;
		}
		else {
			int k = i-L;
			if(z[id][k] < R-i+1)z[id][i] = z[id][k];
			else {
				L = i;
				while(R<n && s[R-L]==s[R])++R;
				z[id][i] = R-L, --R;
			}
		}
	}
}

int n,dp[MAX][MAX];
string s,t;

int f(int nw,int k){
	if(nw+k > n)return 0;
	int &ret = dp[nw][k];
	if(ret!=-1)return ret;
	if(nw+k == n)return ret = 1;
	ret = f(nw, k+1);
	if(nw+k+k > n)return ret;
	if(s[nw+k]!='0'){
		if(z[nw][k]>=k)ret+= f(nw+k, k+1);
		else ret+= f(nw+k, k+(s[nw+z[nw][k]]>s[nw+k+z[nw][k]]));
		ret%= MOD;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>s;
	t = s;
	for(int i = 0; i<n; ++i){
		id = i;
		zalgo(s);
		s = s.substr(1, s.size()-1);
	}
	memset(dp, -1, sizeof dp);
	s = t;
	cout<<f(0,1)<<endl;
	return 0;
}