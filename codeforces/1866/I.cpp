// LUOGU_RID: 160223831
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
const int N=5e5+5;
int in[N];
struct no{
	int x,y;
}a[N];
bool operator <(no n1,no n2){
	return n1.x==n2.x? n1.y>n2.y: n1.x>n2.x;
}
void solve(){
	int p=1;
	int y=m;
	for(int i=n;i>=1;i--){
		int mx=0;
		while(in[y]) y--;
		bool f0=1;
		while(a[p].x==i&&p<=k){
			int yy=a[p].y;
			if(yy>=y) f0=0;
			in[yy]=1;
			p++;
		}
		if(y==0){ cout<<"Chaneka";return;}
		if(f0) in[y]=1;
	}
	if(y!=1) cout<<"Chaneka";
	else cout<<"Bhinneka";
}
signed main(){
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i].x>>a[i].y;
		if(a[i].x==1){ cout<<"Chaneka";return 0;}
	}
	a[++k]=no{n,m};
	sort(a+1,a+1+k);
	solve();
	return 0;
}