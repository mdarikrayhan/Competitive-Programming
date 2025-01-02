#include<bits/stdc++.h>
using namespace std;

#define LL            long long
#define int              LL
#define F              first
#define S              second
#define pb              push_back
#define PI              acos(-1.0)
#define pll             pair<LL,LL>
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))
#define all(v) v.begin(),v.end()
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define Faster       ios_base::sync_with_stdio(0);cin.tie(nullptr);
#ifdef VAMP
#include "ehp.h"
#else
#define debug(...)
#endif

const int M = 998244353;
const int N = 3005;


void solve ( LL &t )
{
	LL n, m, k, cnt = 0, cnt2 = 0, e = 0, h = 0, p = 0, sum = 0, sumb = 0, ans = 0, ans2 = 0, a, b, c, d, res = 1;
	LL mx = 0, w, q, mn = LLONG_MAX, odd = 0, even = 0, one = 0, zero = 0;
	cin >> k;
	string str; cin>>str;
	n=str.size();
	vector<pll>v;
	for(int i=0;i<(n+1)/2;i++){
        if(str[i]=='?' && str[n-1-i]=='?'){
            v.pb({i,n-1-i});
        }
        else if(str[i]=='?'){
               str[i]=str[n-1-i];
        }
        else if(str[n-1-i]=='?') str[n-1-i]=str[i];
        else if(str[i]!=str[n-1-i]){
               cout<<"IMPOSSIBLE"<<endl;
               return;
        }
	}
	map<char,int>mp;
	for(int i=0;i<n;i++){
          mp[str[i]]++;
	}
	vector<char>vec;
	for(int i=0;i<k;i++){
          char ch='a'+i;
          if(mp[ch]==0){
              vec.pb(ch);
          }
	}
	if(vec.size()>v.size()){
         cout<<"IMPOSSIBLE"<<endl;
        return;
	}
	e=v.size()-1;
	for(int i=vec.size()-1;i>=0;i--){
           int pos=v[e].F;
           int pos2=v[e--].S;
           str[pos]=vec[i];
           str[pos2]=vec[i];
	}
	for(int i=e;i>=0;i--){
            int pos=v[i].F;
           int pos2=v[i].S;
           str[pos]='a';
           str[pos2]='a';
	}
	cout<<str<<endl;












}



signed main()
{
#ifdef VAMP
	clock_t tStart = clock();
	freopen ( "input.txt", "r", stdin );
	freopen ( "output.txt", "w", stdout );
#endif
	Faster
	int tc = 1, t = 1;
//	cin >> tc;

	while ( tc-- ) solve ( t );


#ifdef VAMP
	fprintf ( stderr, "\n>> Runtime: %.10fs\n", ( double ) ( clock() - tStart ) / CLOCKS_PER_SEC );
#endif
}
