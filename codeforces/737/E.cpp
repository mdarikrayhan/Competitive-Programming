#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500+10;
const int inf=1e15;
int n,m,b;
int P[N],k[N],x[N][N],y[N][N];
int r[N],c[N];
int cpy[N],rev_cpy[N];
int org_m;
int in[N],out[N];

int realin[N],realout[N];
struct Msg{
	int i,j,s,d;
};
vector<Msg> ans;
struct KM{
	int n;
	int matchx[N],matchy[N],pre[N];
	bool visx[N],visy[N];
	int lx[N],ly[N];
	int mp[N][N];
	int slack[N];
	int org_n,org_m;
	
	queue<int> q;
	void init(int _n,int _m,int opt){
		org_n=_n;
		org_m=_m;
		n=_n+_m;
		if(opt) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) mp[i][j]=-1e9;
		for(int i=1;i<=n;i++){
			matchx[i]=matchy[i]=-1;
			pre[i]=visx[i]=visy[i]=0;
			lx[i]=-inf;
			ly[i]=0;
			slack[i]=0;
		}
	}
	
	void add(int u,int v,int w){
		//cout<<u<<" "<<v<<" "<<w<<"\n";
		mp[u][v]=max(mp[u][v],w);
	}
	
	bool check(int u){
		visy[u]=true;
		if(matchy[u]!=-1){
			q.push(matchy[u]);
			visx[matchy[u]]=true;
			return false;
		}
		while(u!=-1){
			matchy[u]=pre[u];
			swap(u,matchx[pre[u]]);
		}
		return true;
	}
	
	void bfs(int x){
		while(!q.empty()) q.pop();
		q.push(x);
		visx[x]=true;
		while(1){
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int v=1;v<=n;v++){
					if(!visy[v]){
						int delta=lx[u]+ly[v]-mp[u][v];
						if(slack[v]>=delta){
							pre[v]=u;
							if(delta) slack[v]=delta;
							else if(check(v)) return;
						}
					}
				}
			}
			int a=inf;
			for(int i=1;i<=n;i++){
				if(!visy[i]) a=min(a,slack[i]);
			}
			for(int i=1;i<=n;i++){
				if(visx[i]) lx[i]-=a;
				if(visy[i]) ly[i]+=a;
				if(!visy[i]) slack[i]-=a;
			}
			for(int i=1;i<=n;i++){
				if(!visy[i]&&slack[i]==0&&check(i)) return;
			}
		}
		return;
	}
	
	int solve(int time){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mp[i][j]==0) mp[i][j]=-1e9;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				lx[i]=max(lx[i],mp[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) slack[j]=inf,visx[j]=visy[j]=false;
			bfs(i);
		}
		int res=1e9;
		for(int i=1;i<=n;i++){
			if(mp[i][matchx[i]]!=-1e9) res=min(res,mp[i][matchx[i]]);
			else{
				cout<<i<<" "<<matchx[i]<<"\n";
				exit(0);
			}
		}
		for(int i=1;i<=n;i++){
			if(mp[i][matchx[i]]){
				mp[i][matchx[i]]-=res;
				if(mp[i][matchx[i]]==0) mp[i][matchx[i]]=-1e9;
			}
		}
		for(int i=1;i<=org_n;i++){
			if(matchx[i]<=org_m){
				int z=matchx[i];
				if(rev_cpy[z]) z=rev_cpy[z];
				ans.push_back({i,z,time,res});
			}
		}
		
		for(int i=1;i<=n;i++){
			realin[i]=realout[i]=0;
		}
		
		//cout<<res<<"\n";
		if(res==0) exit(0);
		
		/*
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mp[i][j]==-1e9){
					cout<<"0 ";
					continue;
				}
				cout<<mp[i][j]<<" ";
				realin[i]+=mp[i][j];
				realout[j]+=mp[i][j];
			}
			cout<<"\n";
		}
		
		
		for(int i=1;i<=n;i++){
			cout<<realin[i]<<" "<<realout[i]<<"\n";
		}
		*/
		return res;
	}
}solver;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>b;
	org_m=m;
	for(int i=1;i<=m;i++) cin>>P[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x[i][j]>>y[i][j];
			r[i]+=y[i][j];
			c[x[i][j]]+=y[i][j];
		}
	}
	priority_queue<pair<int,int>> q;
	for(int i=1;i<=n;i++) q.push({r[i],0});
	for(int i=1;i<=m;i++) q.push({c[i],i});
	while(1){
		auto p=q.top();
		if(p.second==0) break;
		else{
			if(b-P[p.second]<0) break;
			b-=P[p.second];
			q.pop();
			q.push({p.first/2,0});
			q.push({(p.first+1)/2,0});
			cpy[p.second]=++m;
			rev_cpy[m]=p.second;
		}
	}
	int mx=q.top().first;
	solver.init(n,m,1);
	
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=k[i];j++){
			sum+=y[i][j];
			int x1=x[i][j],x2=cpy[x[i][j]];
			if(y[i][j]+out[x1]>mx){
				solver.add(i,x1,mx-out[x1]);
				solver.add(i,x2,y[i][j]-(mx-out[x1]));
				out[x2]+=y[i][j]-(mx-out[x1]);
				out[x1]=mx;
			}else{
				solver.add(i,x1,y[i][j]);
				out[x1]+=y[i][j];
			}
		}
		if(sum<mx){
			solver.add(i,m+i,mx-sum);
			out[m+i]+=mx-sum;
		}
		in[i]=mx;
	}
	for(int i=1;i<=m;i++){
		if(out[i]<mx){
			solver.add(n+i,i,mx-out[i]);
			in[n+i]+=mx-out[i];
			out[i]=mx;
		}
	}
	for(int i=n+1,j=m+1;;){
		if(in[i]==mx) i++;
		else if(out[j]==mx) j++;
		else{
			int del1=mx-out[j],del2=mx-in[i];
			if(del1<del2){
				in[i]+=del1;
				out[j]+=del1;
				solver.add(i,j,del1);
				j++;
			}else{
				in[i]+=del2;
				out[j]+=del2;
				solver.add(i,j,del2);
				i++;
			}
		}
		if(i>=n+m+1&&j>=n+m+1) break;
	}
	cout<<mx<<"\n";
	for(int i=1;i<=org_m;i++){
		if(cpy[i]) cout<<1;
		else cout<<0;
	}
	cout<<"\n";
	//return 0;
	int time=0;
	while(time<mx){
		solver.init(n,m,0);
		time+=solver.solve(time);
	}
	cout<<ans.size()<<"\n";
	for(auto [i,j,s,d]:ans){
		cout<<i<<" "<<j<<" "<<s<<" "<<d<<"\n";
	}
	return 0;
}