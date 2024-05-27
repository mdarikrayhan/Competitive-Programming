#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<unordered_map>
#include<vector>
#include<bitset>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<assert.h>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned long long
#define lc (x<<1)
#define rc (x<<1|1)
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
#define cout (cerr<<">> ",cout)
const int Mx=500005,p=998244353;
int read(){
	char ch=getchar();
	int Alice=0,Aya=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-') Aya=-Aya;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		Alice=(Alice<<3)+(Alice<<1)+(ch^48),ch=getchar();
	return (Aya==1?Alice:-Alice);
}
int n,aEx,bEx,a[Mx],b[Mx];
bool used[Mx];
int bel[Mx];
signed main(){
	n=read(),aEx=read(),bEx=read();
	priority_queue<pii>A,B,AmB,BmA;
	for(int i=1;i<=n;i++){
		a[i]=read();
		A.push(mkp(a[i],i));
	}
	for(int i=1;i<=n;i++){
		b[i]=read();
		B.push(mkp(b[i],i));
	}
	for(int i=1;i<=aEx;i++) BmA.push(mkp(0,1e9));
	for(int i=1;i<=bEx;i++) AmB.push(mkp(0,1e9));
	int ans=0;
	while(!A.empty()||!B.empty()){
		int mx=-1e18,mxid=-1;
		if(!A.empty()){
			while(!A.empty()&&used[A.top().se]){
				A.pop();
			}
			if(!A.empty()){
				pii x=A.top();
				if(bEx==0){
					while(!BmA.empty()&&BmA.top().se!=1e9) BmA.pop();
				}
				int t=BmA.top().fi;
				if(BmA.top().se!=1e9&&bEx||BmA.top().se==1e9&&aEx){
					if(x.fi+t>0){
						mxid=1,mx=x.fi+t;
					}
					else{
						while(!A.empty()) A.pop();
					}
				}
			}
		}
		if(!B.empty()){
			while(!B.empty()&&used[B.top().se]){
				B.pop();
			}
			if(!B.empty()){
				pii x=B.top();
				if(aEx==0){
					while(!AmB.empty()&&AmB.top().se!=1e9) AmB.pop();
				}
				int t=AmB.top().fi;
				//cout<<AmB.top().fi<<endl;
				if(AmB.top().se!=1e9&&aEx||AmB.top().se==1e9&&bEx){
					if(x.fi+t>0){
						if(x.fi+t>mx) mx=x.fi+t,mxid=2;
					}
					else{
						while(!B.empty()) B.pop();
					}
				}
			}
		}
		if(mxid==-1) break;
		//cout<<aEx<<' '<< bEx<<" "<<mxid<<" : "<<mx<<endl;
		ans+=mx;
		if(mxid==1){
			pii x=A.top();
			used[x.se]=1;
			int t=BmA.top().fi;
			if(x.fi+t>0){
				if(BmA.top().se!=1e9){
					bEx--;
					bel[BmA.top().se]=2;
				}
				else{
					aEx--;
				}
				BmA.pop();
				bel[A.top().se]=1;
				A.pop();
				BmA.push(mkp(b[x.se]-a[x.se],x.se));
			}
		}
		if(mxid==2){
			pii x=B.top();
			used[x.se]=1;
			int t=AmB.top().fi;
			if(x.fi+t>0){
				if(AmB.top().se!=1e9){
					aEx--;
					bel[AmB.top().se]=1;
				}
				else{
					bEx--;
				}
				AmB.pop();
				bel[B.top().se]=2;
				B.pop();
				AmB.push(mkp(a[x.se]-b[x.se],x.se));
			}
		}
		//cout<<aEx<<" "<<bEx<<endl;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) if(bel[i]==1) cout<<i<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++) if(bel[i]==2) cout<<i<<" ";
	return 0;
}
/*
Hello!!
Sample:
2 1 1
1 17
5 20
-------------------
*/

