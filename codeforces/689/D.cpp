// LUOGU_RID: 159814239
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define il inline
#define pii pair<int,int > 
#define mkp make_pair
typedef long long ll;

const int N = 2e5+20;
const int ms= 1e9+7;

int mxa[N][20],mni[N][20],a[N],b[N],n;
int lg2[N],pw2[20];

template<typename T>il void inpt(T &A){
	T x=0;bool b=0;char ch=getchar();
	while(ch<'0'||ch>'9')b|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=b?-x:x;
}


il void solv(){
	cin>>n;
	for(int i=2;i<=n;++i)lg2[i]=lg2[i>>1]+1;
	pw2[0]=1;for(int i=1;i<20;++i)pw2[i]=pw2[i-1]<<1;
	for(int i=1;i<=n;++i)inpt(a[i]),mxa[i][0]=a[i];
	for(int i=1;i<=n;++i)inpt(b[i]),mni[i][0]=b[i];
	for(int j=1;j<=lg2[n];++j){
		for(int i=1;i+pw2[j]-1<=n;++i){
			mxa[i][j]=max(mxa[i][j-1],mxa[i+pw2[j-1]][j-1]);
			mni[i][j]=min(mni[i][j-1],mni[i+pw2[j-1]][j-1]);
		}
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		if(a[i]>b[i]){
			continue;
		}else{
			int l=i,r=n;
			while(l<=r){
				int md=l+(r-l)/2,pos=lg2[md-i+1];
				if(max(mxa[i][pos],mxa[md-pw2[pos]+1][pos])<min(mni[i][pos],mni[md-pw2[pos]+1][pos])){
					l=md+1;
				}else{
					r=md-1;
				}
			}
			int x=l;
			l=i,r=n;
			while(l<=r){
				int md=l+(r-l)/2,pos=lg2[md-i+1];
				if(max(mxa[i][pos],mxa[md-pw2[pos]+1][pos])<=min(mni[i][pos],mni[md-pw2[pos]+1][pos])){
					l=md+1;
				}else{
					r=md-1;
				}
			}
			int y=r;
			ans+=y-x+1;
		}
	}
	cout<<ans<<endl;
}

signed main(){
	int tt;
//	cin>>tt;
	tt=1;
	while(tt--){
		solv();
	}
	return 0;
}