#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long lo; 
 
#define fi first
#define se second
#define endl "\n"
#define pb push_back
#define int long long
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR for(int i=1;i<=n;i++)
#define mid ((start+end)/2)
#define ort ((bas+son)/2)
#define _ << " " <<
 
const lo inf = 1000000000;
const lo li = 500005;
const lo mod = 1000000007;
 
int n,m,a[li],k,flag,t,dp[li],dp2[li],last[li];
int cev;
string s;
vector<int> v[li];
 
int32_t main(void){
	fio();
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<=n;i++){
			v[i].clear();
			dp[i]=0,dp2[i]=0;
		}
		last[0]=-1;
		FOR{
			cin>>k;
			for(int j=1;j<=k;j++){
				int x;
				cin>>x;
				v[i].pb(x);
				last[x]=-1;
			}
		}
		set<int> st,oldu;
		dp[0]=1;
		oldu.insert(0);
		for(int i=1;i<=n;i++){
			int mx=last[0];
			for(auto go:v[i]){
				mx=max(mx,last[go]);
				
			}
			if(v[i].empty()){dp[i]	=1;last[0]=i;oldu.insert(i);}
			if(~mx){
				auto it=oldu.lower_bound(mx);
				if(it!=oldu.begin()){
					it--;
					//~ cout<<*it _ "BBB" _ i _ st.size() _ endl;
					auto itt=st.upper_bound(*it);
					if(itt==st.end()){
						dp[i]=1;
						oldu.insert(i);
					}
				}
			}
			for(auto go:v[i]){
				if(~last[go])st.insert(last[go]);
				last[go]=i;
			}
		}
		map<int,int> mpp;
		flag=0;
		int tut=0,say=0;
		for(int i=n;i>=1;i--){
			for(auto go:v[i]){
				say++;
				if(mpp.find(go)!=mpp.end()){flag=1;break;}
				mpp[go]=1;
			}
			if(flag)break;
			if(v[i].empty())tut=1;
			if(tut)dp2[i-1]=m;
			else dp2[i-1]=say;
		}
		cev=dp2[0];
		FOR{
			//~ cout<<i _ dp[i] _ dp2[i] _ "AA"<<endl;
			if(dp[i])cev=max(cev,dp2[i]);
		}
		cout<<cev<<endl;
	}
	return 0;
}
