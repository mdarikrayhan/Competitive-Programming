// LUOGU_RID: 156972120
#include<iostream>
#define int long long
#define mod 12345
using namespace std;
int n,c;
int tong[30];
char a[1010];
int x[1010];
int gcd(int x,int y){
	if(y==0){
		return x;
	}
	return gcd(y,x%y);
}
int lcm(int x,int y){
	return x*y/gcd(x,y);
}
int cnt[30];
int f[130][130];
int p[130];
int ga[30];
int tot=1;
int jing[30];
void dfs(int i){
	if(i>25){
		int cun=1;
		int zong=0;
		for(int j=0;j<=25;j++){
			zong+=cun*cnt[j];
			cun*=tong[j];
			ga[j]=0;
		}
		for(int j=1;j<=c;j++){
			if(ga[a[j]-'A']==1){
				continue;
			}
			if(cnt[a[j]-'A']%x[j]==0){
				ga[a[j]-'A']=1;
			}
			else{
				ga[a[j]-'A']=-1;
			}
		}
		p[zong]=1;
		for(int j=0;j<=25;j++){
			if(ga[j]==-1){
				p[zong]=0;
				break;
			}
		}
		for(int j=0;j<=25;j++){
			if(jing[j]==0){
				continue;
			}
			cnt[j]=(cnt[j]+1)%tong[j];
			int xin=0;
			cun=1;
			for(int k=0;k<=25;k++){
				xin+=cun*cnt[k];
				cun*=tong[k];
			}
			cnt[j]=(cnt[j]-1+tong[j])%tong[j];
			f[zong][xin]++;
		}
		return ;
	}
	for(int j=0;j<tong[i];j++){
		cnt[i]=j;
		dfs(i+1);
	}
}
int t[130][130];
int ans[130][130];
void ksm(){
	for(int i=0;i<tot;i++){
		ans[i][i]=1;
	}
	while(n){
		if(n%2==1){
			for(int i=0;i<tot;i++){
				for(int j=0;j<tot;j++){
					t[i][j]=ans[i][j];
					ans[i][j]=0;
				}
			}
			for(int i=0;i<tot;i++){
				for(int j=0;j<tot;j++){
					for(int k=0;k<tot;k++){
						ans[i][j]=(ans[i][j]+t[i][k]*f[k][j])%mod;
					}
				}
			}
		}
		for(int i=0;i<tot;i++){
			for(int j=0;j<tot;j++){
				t[i][j]=f[i][j];
				f[i][j]=0;
			}
		}
		for(int i=0;i<tot;i++){
			for(int j=0;j<tot;j++){
				for(int k=0;k<tot;k++){
					f[i][j]=(f[i][j]+t[i][k]*t[k][j])%mod;
				}
			}
		}
		n/=2;
	}
}
signed main(){
	cin>>n>>c;
	for(int i=0;i<=25;i++){
		tong[i]=1;
	}
	for(int i=1;i<=c;i++){
		cin>>a[i]>>x[i];
		tong[a[i]-'A']=lcm(x[i],tong[a[i]-'A']);
		jing[a[i]-'A']=1;
	}
	for(int i=0;i<=25;i++){
		tot=tot*tong[i];
	}
	dfs(0);
	ksm();
	int fin=0;
	for(int i=0;i<tot;i++){
		if(p[i]==1){
			fin=(fin+ans[0][i])%mod;
		}
	}
	cout<<fin;
	return 0;
}