// Problem: C. Меньшие или равные
// Contest: Codeforces - Codeforces Round 479 (Div. 3)
// URL: https://codeforces.com/problemset/problem/977/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define noSuccess t--
#define int long long
#define pb push_back 
#define pf push_front
#define F first	
#define S second
#define Spotify ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(s) s.begin(),s.end()
#define sr(a) sort(a+1,a+1+n);reverse(a+1,a+1+n)
#define s(a) sort(a+1,a+1+n)
#define in insert
#define upb upper_bound
#define issrt(a) is_sorted(a+1,a+1+n)
#define yes "YES\n"
#define no "NO\n"
#define sz size
#define pii pair<int,int>
const bool KB0F_G0LD = true;
//#KB0 SILA

using namespace std;
const int maxn = 1e6;
void tryAgain(){
  int n,k;
  cin>>n>>k;
  int a[n+5];
  map<int,int>mp;
  set<int>st;
  int x=-1;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    mp[a[i]]++;
    st.in(a[i]);
  }
  int cal=0;
  for(auto to : st){
    if(cal+mp[to]==k){
      x=to;
      break;
    }
    cal+=mp[to];  
  }
  if(k==0){
    if(mp[1]>0) cout<<-1;
    else cout<<1;
  }
  else cout<<x;
}
signed main(){
  // freopen("something.in", "r", stdin);
  // freopen("something.out", "w", stdout);
  Spotify
  int t = 1;
  // cin >> t;
	while(noSuccess){
		tryAgain();
	}
}