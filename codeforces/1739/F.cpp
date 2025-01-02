#include<bits/stdc++.h>
using namespace std;
const int M = 12;
const int inf = 1000000005;
int dp[(1<<M)+5][4005],pre[(1<<M)+5][4005],ppre[(1<<M)+5][4005];
int n;
int c[4005];string s[4005];
vector<int>p[4005];
int fail[4005],trie[4005][15],sum[4005];int nw;
string nows;
void dfs(int now,int fa){
	nows+=(char)('a'+now);
	for(int x:p[now]){
		if(x == fa)continue;dfs(x,now);
	}
}
void ins(string s,int val){int now = 0;
	for(int i =0;i<s.size();i++){
		if(!trie[now][s[i]-'a'])trie[now][s[i]-'a'] = ++nw;
		now = trie[now][s[i]-'a'];
	}sum[now]+=val;
}
void build(){
	queue<int>q;
	for(int i = 0;i<M;i++)if(trie[0][i])q.push(trie[0][i]);
	while(!q.empty()){
		int now = q.front();q.pop();
		for(int i = 0;i<M;i++){
			if(trie[now][i]){
				fail[trie[now][i]] =trie[fail[now]][i];q.push(trie[now][i]);
			}else{
				trie[now][i] = trie[fail[now]][i];
			}
		}
	}for(int i = 1;i<=nw;i++)p[fail[i]].push_back(i);
}
void dfss(int now,int fa){
	sum[now]+=sum[fa];
	for(int x:p[now]){
		if(x == fa)continue;dfss(x,now);
	}
}
signed main(){
	cin >> n;
	for(int i = 1;i<=n;i++)cin >> c[i] >> s[i];
	for(int i = 1;i<=n;i++){
		for(int j =0;j<M;j++){
			p[j].clear();			
		}for(int j = 0;j+1<s[i].size();j++){
			p[s[i][j]-'a'].push_back(s[i][j+1]-'a');
			p[s[i][j+1]-'a'].push_back(s[i][j]-'a');
		}for(int j =0 ;j<M;j++){
			sort(p[j].begin(),p[j].end());
			p[j].erase(unique(p[j].begin(),p[j].end()),p[j].end());
		}int cc =0,pos=  0,ok = 1;
		for(int j=0;j<M;j++){
			if(p[j].size()>2)ok = 0;
			if(p[j].size() ==1)cc++,pos = j;
		}
		nows.clear();
		if(cc != 2 or ok == 0)continue;dfs(pos,pos);
	//	cout << ' ' << nows << endl;
		ins(nows,c[i]);
		reverse(nows.begin(),nows.end());
	//	cout << "  " << nows << endl;
		ins(nows,c[i]);
	}for(int j =0;j<M;j++)p[j].clear();build();dfss(0,0);
	for(int i =0;i<(1<<M);i++)for(int j =0;j<=nw;j++)dp[i][j] =-inf;
	//cout << ' ' << nw << endl;
	//for(int i = 0;i<=nw;i++)cout << fail[i] << " ";cout << endl;
	//for(int i =0;i<=nw;i++)cout << sum[i] << " ";cout << endl;
	dp[0][0] = 0;
	for(int i =0 ;i<(1<<M);i++){
	//	cout << i << endl;
		for(int j = 0;j<=nw;j++){
			if(dp[i][j] == -inf)continue;
			for(int k =0;k<M;k++){
				if(i>>k&1)continue;
				if(dp[i|(1<<k)][trie[j][k]]<dp[i][j]+sum[trie[j][k]]){
					dp[i|(1<<k)][trie[j][k]]=dp[i][j]+sum[trie[j][k]];
					pre[i|(1<<k)][trie[j][k]] = k;
					ppre[i|(1<<k)][trie[j][k]] = j;
				}
			}
		}//cout << " "<< i << endl;
		///for(int j =0;j<=nw;j++)cout << dp[i][j] << " ";cout << endl;
	}
	int ans = 0,pos = 0;
//	cout << 111 << endl;
	for(int i = 0;i<=nw;i++){
		if(dp[(1<<M)-1][i]>ans){
			ans = dp[(1<<M)-1][i];pos = i;
		}
	}
//	cout << ans << endl;
	int S = (1<<M)-1;string res; 
	for(int i = 0;i<M;i++){
		int pp = pre[S][pos];
	//	cout << " " << S << " " << pos<< " " << pp << endl;
		res+=(char)(pp+'a');
		pos = ppre[S][pos];S^=(1<<pp);
	}
	reverse(res.begin(),res.end());
	cout << res <<endl;
	return 0;
}/*
3
7 abacaba
10 cba
4 db
*/