#pragma gcc diagnostic "-std=c++1z"
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define f first
#define s second
#define MOD 1000000007
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
using namespace std;
int n,m,T,k;
void test_case() {
     cin>>n;
     string s; int cntb=0;
     cin>>s;
     for (int i=0; i<n; i++) {
          if (s[i]=='(') cntb++;
          else cntb--;
     }
     if (cntb) {
          cout<<"0"<<endl<<"1 1"<<endl;
          return;
     }
     int cur=0,cnt=0;
     for (int i=0; i<n; i++) {
          if (s[i]=='(') cnt++;
          else cnt--;
          if (cnt<0) {
               cnt=0; cur=i+1;
          }
     }
     string s1="";
     for (int i=cur; i<cur+n; i++) {
          int j=i%n; s1.pb(s[j]);
     }
     s=s1; s=" "+s;
     stack<int> st; st.push(0);
     vector<int> l(n+1,0),f(n+1,0),c(n+1,0);
     for (int i=1; i<=n; i++) {
          if (s[i]=='(') {
               c[st.top()]++;
               l[i]=l[st.top()]+1;
               st.push(i);
          }
          else {
               f[st.top()]=i;
               st.pop();
          }
     }
     int cnt1=0;
     for (int i=1; i<=n; i++) {
          if (l[i]==1) cnt1++;
     }
     int mx=-1,ind=0;
     for (int i=1; i<=n; i++) {
          if (l[i]==2 && mx<c[i]+2+(cnt1-1)) {
               mx=c[i]+2+(cnt1-1); ind=i;
          }
          if (l[i]==1 && mx<c[i]+1) {
               mx=c[i]+1; ind=i;
          } 
     }
     if (ind==0 || cnt1>mx) {
          cout<<cnt1<<endl<<"1 1"<<endl;
          return;
     }
     int a=ind,b=f[ind];
     a+=cur; if (a>n) a-=n;
     b+=cur; if (b>n) b-=n;
     cout<<mx<<endl<<a<<" "<<b<<endl;
}
main () {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	T=1; 
	while (T--) test_case();
}
