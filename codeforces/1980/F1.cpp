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

int n,m,a[li],k,flag,t,x[li],y[li];
int cev;
string s;
vector<int> v;

int32_t main(void){
	fio();
	cin>>t;
	while(t--){
		cin>>m>>k>>n;
		map<int,int> mpp;
		FOR{
			cin>>x[i]>>y[i];
			mpp[y[i]]=max(mpp[y[i]],x[i]);
		}
		int mx=0;
		int son=1;
		cev=0;
		map<int,int> no;
		for(auto go:mpp){
			cev+=(go.fi-son)*(m-mx);
			if(mx==go.se)no[go.fi]=1;
			mx=max(mx,go.se);
			mpp[go.fi]=mx;
			son=go.fi;
			//~ cout<<cev _ mx _ go.fi<<endl;
		}
		cev+=(k+1-son)*(m-mx);
		cout<<cev<<endl;
		for(int i=1;i<=n;i++){
			if(mpp[y[i]]>x[i] || no[y[i]])cout<<"0 ";
			else cout<<"1 ";
		}
		cout<<endl;
	}
	return 0;
}
