#include<bits/stdc++.h>
using namespace std;
int n,m,q,tp[1005];
string s[1005],t[1005];
vector<int> v[1005];
int gett(char c){
	if(c=='i') return 1;
	if(c=='s') return 2;
	if(c=='d') return 3;
	return 0;
}
int getv(string x){
	for(int i=1;i<=n;++i)if(t[i]==x) return tp[i];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		char c=getchar();
		int cnt=0;
		while(c!='('){
			if(c>' '){
				++cnt;
				if(cnt>4)s[i]+=c;
			}
			c=getchar();
		}
		c=getchar();
		string tmp="";
		while(c!=')'){
			if(c==','){
				v[i].push_back(gett(tmp[0]));
				tmp="";
			}
			else if(c>' ')tmp+=c;
			c=getchar();
		}
		v[i].push_back(gett(tmp[0]));
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		string tmp;
		cin>>tmp>>t[i];
		tp[i]=gett(tmp[0]);
	}
	cin>>q;
	while(q--){
		vector<int> V;
		string sq="";
		char c=getchar();
		while(c!='('){
			if(c>' ') sq+=c;
			c=getchar();
		}
		c=getchar();
		string tmp="";
		while(c!=')'){
			if(c==','){
				V.push_back(getv(tmp));
				tmp="";
			}
			else if(c>' ')tmp+=c;
			c=getchar();
		}
		V.push_back(getv(tmp));
		int ans=0;
		for(int i=1;i<=n;++i){
			if(s[i]!=sq) continue;
			if(v[i].size()!=V.size()) continue;
			bool ok=1;
			for(int j=0;j<V.size();++j)if(v[i][j]>0&&v[i][j]!=V[j])ok=0;
			if(ok)++ans;
		}
		cout<<ans<<'\n';
	}
    return 0;
}
