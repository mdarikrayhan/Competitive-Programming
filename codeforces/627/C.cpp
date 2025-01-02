// LUOGU_RID: 159572667
#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,p;
}a[200002];
stack<int>st;
int ne[200002];
bool cmp(node q,node p){
	return q.x<p.x;
}
int max(int a,int b){
	return a>b?a:b;
}
void solve(){
	int d,n,m;
	cin>>d>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].p;
	} 
	sort(a+1,a+m+1,cmp);
	a[m+1]=(node){d,0};
	st.push(m+1);
	for(int i=m;i>=1;i--){
		while(st.size()&&a[st.top()].p>a[i].p)st.pop();
		ne[i]=st.top();
		st.push(i);
	}
	int ans=0,now=n;
	for(int i=0;i<=m;i++){
		int dis=max(0,min(a[ne[i]].x-a[i].x,n)-now);
		ans+=dis*a[i].p;
		now-=a[i+1].x-a[i].x-dis;
		if(now<0){
			cout<<"-1"<<endl;
			return ;
		}
	}
	cout<<ans<<endl;
	
}
signed main(){
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}