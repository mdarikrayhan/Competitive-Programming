#include <iostream>
#include <vector>
using namespace std;
const int N=1e6+5;
int T,n,a[N],b[N];
vector<int> p[N<<1];
bool check(){
	if(p[0].empty()) return true;
	int l=0,r=1,c=0;
	for(int i=1;i<2*n;++i){
		bool fl=false,fr=false,fm=false;
		for(auto v:p[i]) if(v>=l&&v<=r){
			if(v==l) fl=true;
			else if(v==r) fr=true;
			else fm=true;
		}
		if(fm){
			if(r-l>2||fl||fr) return false;
			c=1;
			++l;
			continue;
		}
		if(c){
			if(fl||fr) return false;
			++r;
			c=0;
			continue;
		}
		if(!fl) ++l;
		if(fr) ++r;
		if(l==r) return true;
	}
	return true;
}
void solve(){
	cin>>n;
	for(int i=0;i<2*n;++i) p[i].clear();
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		if(a[i]+b[i]<2*n) p[a[i]+b[i]].push_back(a[i]);
	}
	cout<<(check()?"YES\n":"NO\n");
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}
