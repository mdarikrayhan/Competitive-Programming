#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int o=2e5+10,O=3e6;
int n,m,k,p[o],hd[o],ans[o],vis[o],cnt;char s[9];bool a[o][8],b[O];priority_queue<int> S[o];
vector<int> vec[o],z[8],nxt;vector<pair<int,int> > Vec;
inline void ins(int x,int d){
	d=(d-1)%7+1;
	for(int i=1;i<8;++i) if(a[x][i]){
		if(i==d) nxt.push_back(x);
		else z[i].push_back(x);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,t;i<=n;++i) for(scanf("%d",&t);t--;){
		scanf("%s",s);
		if(s[0]=='M') a[i][1]=1;
		else if(s[0]=='T'&&s[1]=='u') a[i][2]=1;
		else if(s[0]=='W') a[i][3]=1;
		else if(s[0]=='T'&&s[1]=='h') a[i][4]=1;
		else if(s[0]=='F') a[i][5]=1;
		else if(s[0]=='S'&&s[1]=='a') a[i][6]=1;
		else a[i][7]=1;
	}
	for(int h;m--;){scanf("%d",&h);if(h<O) b[h]=1;}
	for(int i=1;i<=k;S[vec[i][0]].push(-i),++i){
		scanf("%d",&p[i]);vec[i].resize(p[i]);
		for(int j=0;j<p[i];++j) scanf("%d",&vec[i][j]);
	}
	for(int i=1;i<=n;++i) if(!S[i].empty()) for(int j=1;j<8;++j) if(a[i][j]) z[j].push_back(i);
	for(int d=1;1;++d) if(!b[d]){
		Vec.clear();nxt.clear();
		for(int id=(d-1)%7+1,i=z[id].size(),t;i--;) if(vis[z[id][i]]-d&&!S[z[id][i]].empty()){
			t=-S[z[id][i]].top();S[z[id][i]].pop();vis[z[id][i]]=d;
			if(!S[z[id][i]].empty()) ins(z[id][i],d);
			if(p[t]==++hd[t]) ++cnt,ans[t]=d;
			else Vec.push_back(make_pair(vec[t][hd[t]],t));
		}
		if(cnt==k) break;
		for(int i=Vec.size();i--;){
			if(S[Vec[i].first].empty()) ins(Vec[i].first,d);
			S[Vec[i].first].push(-Vec[i].second);
		}
		z[(d-1)%7+1]=nxt;
	}
	for(int i=1;i<=k;++i) printf("%d ",ans[i]);
	return 0;
}
