#include<bits/stdc++.h>
#include<bitset>
#define _for(i,x,y) for(int i=x;i<=y;++i)
#define _forp(i,x,y,z) for(int i=x;i<=y;i+=z)
#define _rep(i,x,y) for(int i=x;i<y;++i)
using namespace std;
int T,W,F,n,a[105];
bool f[1000005];
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>T;
	while(T--){
		cin>>W>>F>>n;
		_for(i,1,n) cin>>a[i];
      	_for(i,0,1000000) f[i]=0;
		f[0]=1;
		int sum=0;
		_for(i,1,n){
			sum+=a[i];
		}
		_for(i,1,n){
			for(int j=sum;j>=a[i];--j){
				f[j]|=f[j-a[i]];
			}
		}
		int ans=1e9;
		_for(i,0,1000000){
			if(f[i]){
				ans=min(ans,max(1+(i-1)/W,1+(sum-i-1)/F));
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}



