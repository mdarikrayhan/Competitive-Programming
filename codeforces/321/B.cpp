#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e+18

bool is_prime(int a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
void show(vector<int>a){for(auto x:a)cout<<x<<" "; cout<<endl;}





void solve()
{
	int n,m;
	cin>>n>>m;

	vector<int>a,d,c;

	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int x;
		cin>>x;

		if(s=="ATK"){
			a.push_back(x);
		}else d.push_back(x);
	}

	for(int i=0;i<m;i++){
		int x;
		cin>>x;

		c.push_back(x);
	}

	sort(a.begin(),a.end());
	sort(d.begin(),d.end());
	sort(c.begin(),c.end());
	

	int ans1=0, ans2=0;

	int na = a.size();
	int nd = d.size();



	for (int i=m-1,j=0; i>=0 && j<na;i--,j++)
		if (c[i] > a[j])
        	ans1 += c[i] - a[j];


  	int cnt = 0;

  	vector<int>vis(m);


  	for(int i=0;i<nd;i++){
  		for(int j=0;j<m;j++){
  			 if (c[j] > d[i] && !vis[j])
  			 {
       			vis[j] = 1;
            	cnt++;
            	break;
        	}
  		}
  	}

  	for(int i=0;i<na;i++){
  		for(int j=0;j<m;j++){
  			if(c[j]>=a[i] && !vis[j]){
  				vis[j] = 1;
            	cnt++;
            	ans2 += c[j] - a[i];
            	break;
  			}
  		}
  	}

  	for (int i=0;i<m;i++)
    	if (!vis[i])
        	ans2+=c[i];

    int ans;

  	if(cnt==n){
  		ans=max(ans1,ans2);
  	}else{
  		ans=ans1;
  	}

  	cout<<ans<<endl;
}


signed main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

	int t=1;

	while(t--)solve();
}