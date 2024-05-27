// LUOGU_RID: 159135802
//   you're already the best
//             _
//   ^ ^      //
// >(O_O)<___//
//   \ __ __  \
//    \\ \\ \\\\
//
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100010;

int n,m;
int f[N],g[N];
int pre[N][5];
vector<int> v[5];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=3;i++) v[i].clear();
	for(int i=1;i<=n;i++){
		int w,c;
		cin>>w>>c;
		v[w].push_back(c);
	}
	
	for(int i=1;i<=3;i++){
		sort(v[i].begin(),v[i].end(),
		[&](int x,int y){return x>y;});
		
		for(int j=1;j<=v[i].size();j++) pre[j][i]=pre[j-1][i]+v[i][j-1];
	} 

	if(m>=v[1].size()+v[2].size()*2+v[3].size()*3){
		cout<<pre[v[1].size()][1]+pre[v[2].size()][2]+pre[v[3].size()][3]<<endl;
		return;
	}
	
	
	
	// 你先暴力枚举1，2怎么选 
	int maxn=0,ans=0;
	int cnt1=0,cnt2=0; 
	for(int i=0;i<=v[2].size();i++){
		int t=m-i*2;
		t=min(t,(int)v[1].size()); // t代表 1 选择了几个
		
		if(t<0) break; // 1 难选上，那就别选了 掀桌(╯‵□′)╯︵┻━┻ 
		
		int sum=pre[i][2]+pre[t][1]; // 我肯定贪心的选两个最大的
		
		if(sum>maxn){
			maxn=sum;
			cnt1=t;
			cnt2=i;
		}
	}
	
	ans=maxn;
	// 接着你考虑把 3 放进去换出来 1, 2
	// 这个过程有点像反悔贪心
	
	for(int i=1;i<=v[3].size();i++){
		maxn=0;
		int tt1=cnt1,tt2=cnt2;
		
		for(int d=-5;d<=5;d++){ // 这里是说我 2 往出拿几个，不用拿太多因为波动很小 
			int t2=cnt2+d,t1=m-i*3-t2*2;
			t2=min(t2,(int)v[2].size()),t1=min(t1,(int)v[1].size());
			
			if(t2<0||t1<0) continue; //(╯‵□′)╯︵┻━┻
			
			int sum=pre[i][3]+pre[t2][2]+pre[t1][1];
			if(sum>maxn){
				maxn=sum;
				tt1=t1;
				tt2=t2;
			} 
		}
		
		if(ans<maxn){
			ans=maxn;
			cnt1=tt1;
			cnt2=tt2;
		}
	} 
	
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return (0-0);
}
