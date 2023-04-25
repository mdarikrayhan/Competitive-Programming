#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
int i,j,k,n,m,t;
int su(int a,int b){a+=b;return (a>=M)?a-M:a;}
int pre=1,res=1,tmp;
struct SB{
	ll f,g;
	bool add(ll x){
		while((-g&g)&(x+x)){g-=(-g&g);x<<=2;}
		if(g&&(-g&g)<=x)return 0;
		if(!g)res=su(res,M-f);
		g|=x;
		return 1;
	}
};
vector<SB>v1;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		for(auto i:s){
			vector<SB>v2;
			i-='0';
			tmp=res;res=su(pre,M-res);
			for(auto s:v1){
				if(!s.add(i+1))continue;
				v2.push_back(s);
			}
			if(i)v2.push_back({tmp,2});
			pre=su(pre,res);swap(v1,v2);
		}
		cout<<res<<'\n';
	}
}