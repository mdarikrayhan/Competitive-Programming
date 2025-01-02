// LUOGU_RID: 160212494
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int trie[N][2];
int val[N];
struct node{
	int val,id;
	bool operator <(node other){
		return val<other.val;
	}
}a[N];
int cnt,flag;
deque<int>q[1001];
void dfs(int u,int step,int fnl,int id){
	if(val[u]==1) return;
	if(step==fnl){
		val[u]|=1; flag=1;
		return;
	}
	for(int i=0;i<2;i++){
		if(!trie[u][i]) trie[u][i]=++cnt;
		q[id].push_front(i);
		dfs(trie[u][i],step+1,fnl,id);
		if(flag==1) break;
		q[id].pop_front();
	}
}

void solve(){
	int n; 
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].val,a[i].id=i;
	sort(a+1,a+n+1);
	int u=0;
	for(int i=1;i<=n;i++){
		flag=0;
		dfs(0,0,a[i].val,a[i].id);
		if(flag==0){
			cout<<"NO\n"; return;
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++){
		while(!q[i].empty()){
			cout<<q[i].back(); q[i].pop_back();
		}
		cout<<"\n";
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	solve(); 
}

