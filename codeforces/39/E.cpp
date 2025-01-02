#include<bits/stdc++.h>
#include<tuple>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> du;
typedef tuple<ll,ll,ll> tri;
#define INF 1e16
#define mod 1000000007
#define eps 1e-9
const int MAXN = 100005, MAXK = 505;
ll n,a,b,t,sg[100065][32],ans[100065][32];//0:first win,1:second win
// C(a+b-1,b-1);
void f(ll a,ll b){
	if(sg[a][b]!=-1)
		return ;
	if(ans[a][b]>=n){
		sg[a][b]=1;
		return ;
	}
	f(a,b+1);
	sg[a][b]=!sg[a][b+1];
	if(!sg[a][b])
		f(a+1,b),sg[a][b]|=!sg[a+1][b];
	//cout<<a<<" "<<b<<" "<<sg[a][b]<<endl;
	return ;
}
void solve(){
    cin>>a>>b>>n;
	for(ll i=0;i<=100000;i++)
		for(ll j=0;j<=30;j++)
			sg[i][j]=-1;
	for(ll i=1;i<=100000;i++)
		ans[i][1]=min(n+1,i);
	for(ll i=1;i<=100000;i++)
		for(ll j=2;j<=30;j++)
			ans[i][j]=min(n+1,ans[i][j-1]*i);
	f(a,b);
	if(a==1&&ans[a+1][b]>=n)
		cout<<"Missing\n";
	else if(!sg[a][b])
		cout<<"Stas\n";
	else
		cout<<"Masha\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}