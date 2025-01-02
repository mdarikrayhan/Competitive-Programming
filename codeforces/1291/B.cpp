/*
	     author:khamzin 
 	~~>Aibek aga is the best<~~
	  created on 13.01.2024
	  20.10.2023 15:23:50
	        *** ***
                             		*/
//https://instagram.fnqz2-1.fna.fbcdn.net/v/t51.2885-19/436788140_977894893203246_1290296853494711934_n.jpg?stp=dst-jpg_s320x320&_nc_ht=instagram.fnqz2-1.fna.fbcdn.net&_nc_cat=106&_nc_ohc=mBjeZQ1ZQToAb7dmb--&edm=AOQ1c0wBAAAA&ccb=7-5&oh=00_AfBOo-7tnrNJAK2czeX4k6yGZhSG6ucZEdIYGHkT9wyE3g&oe=6626C224&_nc_sid=8b3546
#include <bits/stdc++.h>

#define EmirBey ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
#define fopen(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
#define all(x) (x).begin(), (x).end()
#define rb rbegin()
#define re rend()
#define len(x) (int)x.size()
#define sz size()
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define elif else if
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define lb(v,x) (int)(lower_bound(all(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(all(v),x)-v.begin())

using namespace std;

const int N=1e6+234 , inf = (int)3e18+1 , mod = (int)1e9+7;

int binpow(int a, int b){
	if (b==0) return 1;
	int res=binpow(a,b/2);        // d                                   a
	int x=1;
	if (b%2==1) x=a;
	return res*res*x%mod;
}                                // b 

int n,a[N];

void putin(){ 
	cin>>n;
	for(int i=0 ; i<n ; i++){
		cin>>a[i];
	}
	int pr=0,su=0;
	for(int i=0 ; i<n; i++){
		if(a[i]>=i)pr=i;
		else break;
	}
	for(int i=n-1 ; i>=0 ; i--){
		if(a[i]>=n-i-1)su=i;
		else break;
	}
	if(pr>=su)cout<<"Yes\n";
	else cout<<"No\n";
}

signed main()
{
    int tt;
   	cin>>tt;
    while(tt--) putin();
}
  