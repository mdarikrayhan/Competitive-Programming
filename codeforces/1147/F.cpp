#include<bits/stdc++.h>
using namespace std;
const int N=100+10;
int n,a[N][N];
int l[N][N];
int matchx[N],matchy[N];

void match(){
	queue<int> q;
	for(int i=1;i<=n;i++) q.push(i);
	while(!q.empty()){
		int u=q.front();
		matchx[u]++;
		int x=l[u][matchx[u]];
		if(matchy[x]){
			int y=matchy[x];
			if(a[u][x]<a[y][x]) continue;
			matchy[x]=u;
			q.pop();
			q.push(y);
		}else{
			matchy[x]=u;
			q.pop();
		}
	}
	
	for(int i=1;i<=n;i++){
		matchx[i]=l[i][matchx[i]];
	}
	
	//for(int i=1;i<=n;i++) cout<<matchx[i]<<" "<<matchy[i]<<endl;
}
int _pos=0;
bool cmp(int x,int y){
	return a[_pos][x]<a[_pos][y];
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			l[i][j]=j;
		}
	}
	for(int i=1;i<=n;i++) matchx[i]=matchy[i]=0;
	cout<<"B"<<endl;
	char opt;
	int u;
	cin>>opt>>u;
	if(opt=='D'){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=-a[i][j];
			}
		}
	}
	bool ok=0;
	if(u>n){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				swap(a[i][j],a[j][i]);
			}
		}
		ok=1;
	}
	
	for(int i=1;i<=n;i++){
		_pos=i;
		sort(l[i]+1,l[i]+n+1,cmp);
	}
	match();
	
	while(1){
		if(u==-1){
			break;
		}
		if(u==-2){
			break;
		}
		if(ok){
			if(u>n) u-=n;
			else u+=n;
		}
		if(u<=n){
			cout<<matchx[u]+n-ok*n<<endl;	
		}
		else{
			cout<<matchy[u-n]+ok*n<<endl;
		}
		cin>>u;
	}
}
int main(){
	int _=1;
	cin>>_;
	while(_--) solve();
	return 0;
}

/*
1
3
3 1 9
2 5 7
6 4 8

1
3
3 1 7
6 4 2
5 9 8

1
2
1 2
3 4

*/