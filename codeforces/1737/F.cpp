// LUOGU_RID: 159790039
#include<bits/stdc++.h>
#define F(i,a,b) for(int i(a),i##i##end(b);i<=i##i##end;++i)
#define R(i,a,b) for(int i(a),i##i##end(b);i>=i##i##end;--i)
#define File(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define ll long long
#define fir first
#define sec second
using namespace std;
int m,n;
pair<int,int>rk[20];
int inv[20];
vector<int>ans[(1<<20)+1];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	for(cin>>T;T;--T){
		cin>>m;
		int sum(0);
		n=1;
		F(i,1,m) cin>>rk[i].fir,sum+=rk[i].fir,n*=(rk[i].fir+1),rk[i].sec=i;
		rk[m+1].fir=1;
		--n;
		F(i,1,n) ans[i].clear(),ans[i].resize(m+1);
		if(sum>=m+3){
			cout<<"-1\n";
			continue;
		}
		sort(rk+1,rk+m+1,greater<pair<int,int> >());
		F(i,1,m) inv[rk[i].sec]=i;
		int len;
		if(rk[1].fir==3){
			ans[1][1]=3;
			ans[2][1]=1;
			ans[3][1]=2;
			len=3;
			F(i,2,m){
				F(j,1,len) ans[len+j+1]=ans[j];
				ans[len+1][i]=1;
				F(j,1,len) ans[j][i]=(j&1);
				F(j,len+2,len<<1|1) ans[j][i]=(!(j&1));
				swap(ans[len+1],ans[(len>>1)+1]);
				len=len<<1|1;
			}
		}else{
			switch(rk[1].fir+rk[2].fir){
				case 2:{
					ans[1][1]=1;
					len=1;
					break;
				}
				case 3:{
					ans[1][1]=2;
					ans[2][1]=1;
					len=2;
					break;
				}
				case 4:{
					ans[1][1]=2,ans[1][2]=2;
					ans[2][1]=1,ans[2][2]=0;
					ans[3][1]=1,ans[3][2]=2;
					ans[4][1]=2,ans[4][2]=0;
					ans[5][1]=1,ans[5][2]=1;
					ans[6][1]=0,ans[6][2]=2;
					ans[7][1]=2,ans[7][2]=1;
					ans[8][1]=0,ans[8][2]=1;
					len=8;
					break;
				}
			}
			F(i,rk[2].fir==2?3:2,m){
				F(j,1,len) ans[(len<<1|1)-j]=ans[j];
				len<<=1;
				F(j,1,len) ans[j][i]=(!(j&1));
				ans[++len][i]=1;
			}
		}
		F(i,1,n){
			F(j,1,m) cout<<ans[i][inv[j]]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}