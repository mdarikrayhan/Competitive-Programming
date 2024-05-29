#include<iostream>
#include<vector>
using namespace std;

const int o=1e6;
int n,m,ans[o],cur;vector<int> vec;
inline int qry(int u,int v){cout<<"? "<<u<<" "<<v<<endl;int x;cin>>x;return x;}
inline void asw(int*a){cout<<"!";for(int i=1;i<n;++i) cout<<" "<<ans[i];cout.flush();}
inline int ask(int u,int v){int t=cur;cur=qry(u,v);return cur-t;}
int main(){
	cin>>n>>m;ask(0,1);
	for(int i=1;i<n;++i) vec.push_back(i);
	for(int flg=0;1;) if(ask(0,1)>0) flg=1;else if(flg) break;
	ask(0,-1);
	
	for(int i=0,flg=1,l,r,md;i<n*m;++i) if(ask(0,1)>0) flg=1;else if(flg&&!vec.empty()){
		ask(0,-1);
		
		for(l=flg=0,r=vec.size()-1;l<r;ask(0,1))
		{
			md=l+r>>1;
			if(!flg) for(int j=r;j>md;--j) ask(vec[j],-1);
			else for(int j=l;j<=md;++j) ask(vec[j],1);
			if(ask(0,-1)<0) r=md,flg=0;else l=md+1,flg=1;
		}
		for(int j=flg;j<=m;++j) ask(vec[l],-1);
		ans[vec[l]]=(i-m-1+n*m)%(n*m);vec.erase(vec.begin()+l);
		--i;ask(0,-1);flg=(ask(0,1)>0);
	}
	asw(ans);
	return 0;
}
