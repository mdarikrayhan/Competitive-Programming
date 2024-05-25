// LUOGU_RID: 160145852
#include <bits/stdc++.h>
using namespace std;
#define int long long
static const int maxl=5e5+5;
int a[15][maxl];
int num[maxl];
struct Trie{
	int cnt;
	Trie():cnt(0){}
	size_t turn(char x){
		return x;
	}
	void clear(){
		for(int i=0;i<15;i++)fill(a[i],a[i]+cnt+1,0);
		fill(num,num+cnt+1,0);
		cnt=0;
	}
	void insert(string &s){
		int now=0;
		for(int i=0;i<s.size();i++){
			if(!a[turn(s[i])][now]){
				a[turn(s[i])][now]=++cnt;
			}
			now=a[turn(s[i])][now];
			num[now]++;
		}
	}
	int check(string &s){
		int now=0;
		int len=0;
		for(int i=0;i<s.size();i++){
			if(!a[turn(s[i])][now])return len;
			if(!num[now]&&i)return len;
			now=a[turn(s[i])][now];
			len++;
		}
		return len;
	}
}trie;
inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
void solve(){
	int n,m;
	cin>>n>>m;
	trie.clear();
	vector<pair<int,int> >t;
	vector<vector<int> >a,b;
	for(int i=0;i<n;i++){
		a.push_back(vector<int>());
		b.push_back(vector<int>());
		t.clear();
		for(int j=0;j<m;j++){
			t.push_back({read(),j+1});
		}
		for(auto &j:t){
			b.back().push_back(j.first);
		}
		sort(t.begin(),t.end());
		for(auto &j:t){
			a.back().push_back(j.second);
		}
		
		string s="";
		for(int j=0;j<m;j++)
			s+=a.back()[j];
		trie.insert(s);
	}
	for(int i=0;i<n;i++){
		string s="";
		for(int j=0;j<m;j++)s+=b[i][j];
		cout<<trie.check(s)<<" ";
	}cout<<"\n";
	return;
}

signed main(){
	int ____=1;
	cin>>____;
	while(____--)solve();
	return 0;
}