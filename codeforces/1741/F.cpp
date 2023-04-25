#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+50;
const int inf = 2e9;
signed main(void){
	ios::sync_with_stdio(false);cin.tie(0);
	int T;cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<array<int,5> >v(n<<1);
		for(int i=0;i<n;i++){
			int l,r,c;
			cin>>l>>r>>c;
			v[i<<1]={l,r,c,i,0};
			v[i<<1|1]={r,l,c,i,1};
		} 
		sort(v.begin(),v.end());
		vector<int>res(n,inf);
		for(int k=0;k<2;k++){
			array<int,2>f[2];
        	f[0]=f[1]={-inf,-1};
        	for(auto [l,r,c,i,o]:v)
	        	if(o){
					for(auto [ll,cc]:f)
						if(cc!=c) res[i]=min(res[i],max(0LL,r-ll));
				}
				else{
					array<int,2>g={r,c};
					if(g>f[0]) swap(g,f[0]);
					if((g>f[1]&&g[1]!=f[0][1])||f[0][1]==f[1][1]) f[1]=g;
				}
			reverse(v.begin(),v.end());
			for(auto &[l,r,c,i,o]:v){
				l=-l;
				r=-r;
				o^=1;
			}
		}
		for(auto it:res) cout<<it<<" ";cout<<"\n";
	}
	return 0;
} 