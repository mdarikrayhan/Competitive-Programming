#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'
#define x first
#define y second
//#define int long long
typedef long long ll;
typedef pair<int,int>PII;
typedef unsigned long long ULL;
const int N =5e5+10 , M = 15 ;
const ll INF = 1e18,mod=998244353;
const int P=131;
//int dx[]= {-1,0,1,0};
//int dy[]= {0,-1,0,1};
using ull = unsigned long long;
int dx[]= {-1,-1,0,1,1,1,0,-1};
priority_queue<int,vector<int>,greater<int>>qq;

int n;
int x[N]; 
int s=1000000;
int q[N];
bool mp[1000005];

void solve() {
	scanf("%d",&n);
	
	ll sum=0;
	int len=1;
	for(int i=1;i<=n;i++){
		 scanf("%d",&x[i]);
		 mp[x[i]]=1;
	}
	for(int i=1;i<=n;i++){
		if(mp[s-x[i]+1]){
			sum+=s-x[i]+1;
		}else{
			mp[s-x[i]+1]=1;
			q[len++]=s-x[i]+1;
		}
	}
	for(int i=s;i>0;i--){
		if(sum==0) break;
		if(!mp[i]){
			if(sum>=i){
				sum-=i;
				q[len++]=i;
				q[len++]=s-i+1;
				sum-=s-i+1;
			}
		}
	}
	printf("%d\n",len-1);
	for(int i=1;i<len;i++){
		printf("%d ",q[i]);
	}
	 

	

}
int main() {
//	FAST;
	int t;
	t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}

