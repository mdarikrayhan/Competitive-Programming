// LUOGU_RID: 159212858
#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;

map<int,int> mm;
array<int,2> cnt[N];
int sum[N];
int* ans[N];

void llz(){
	int n;
	cin>>n;	
	for(int i=1;i<=n;++i){
		int a;
		cin>>a;
		mm[a]++;
	}
	int tot=0;
	for(auto v:mm){
		cnt[++tot]={v.second,v.first};
	}
	sort(cnt+1,cnt+1+tot);
	int p=1;
	for(int i=1;i<=tot;++i)sum[i]=sum[i-1]+cnt[i][0];
	int mx=0,fr=0,fc=0;
	for(int c=1;c*c<=n;++c){
		while(p<=tot&&cnt[p][0]<=c)++p;
		int res=sum[p-1]+(tot-p+1)*c;
		int r=res/c;
		if(r<c)break;
		res=r*c;
		if(res>mx)mx=res,fr=r,fc=c;
	}
	cout<<mx<<"\n";
	cout<<fr<<" "<<fc<<"\n";
	for(int i=1;i<=fr;++i)ans[i]=new int[fc+1];
	int id=tot,now=0;
	for(int s=1;s<=fr;++s){
		int x=s,y=1;
		for(;y<=fc;x++,y++){
			int tx,ty=y;
			if(x>fr)tx=x-fr;
			else tx=x;
			ans[tx][ty]=cnt[id][1];
			now++;
			if(now>=fc||now>=cnt[id][0])now=0,id--;
		}
	}
	for(int i=1;i<=fr;++i){
		for(int j=1;j<=fc;++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;	
	while(T--)llz();
	return 0;
}