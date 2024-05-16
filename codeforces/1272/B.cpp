#include <bits/stdc++.h>

using namespace std ; 

#define f first
#define s second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ll long long int
#define ld long double
#define ed endl
#define B begin
#define rb rbegin
#define E end
#define re rend
#define bs binary_search
#define ub upper_bound
#define lb lower_bound
#define tc() long long int test_case ; cin >> test_case ; while(test_case--)
#define cout(a) cout << a << endl
#define all(v) sort(v.begin(),v.end())
#define rall(v) sort(v.rbegin(),v.rend())
#define rev(v) reverse(v.begin(),v.end())
#define sz(s) s.size() ;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define fr(n) for(ll i=1;i<=n;i++)
#define rfr(n) for(ll i=n;i>=1;i--) 
#define in(n) ll n ; cin>>n ;
#define inf INT_MAX ;
#define cast(val) val ? cout("YES") : cout("NO") ;
#define clr(x,y) memset(x,y,sizeof x)

void solve()
{
    string s ; 
    cin>>s ;
    ll len = sz(s) ; 
    ll up=0,lo=0,rg=0,lf=0 ; 
    for(ll i=0;i<len;i++){
        if(s[i]=='L')lf++;
        if(s[i]=='R')rg++;
        if(s[i]=='U')up++;
        if(s[i]=='D')lo++;
    }
    ll mn , mn2 ; 
    mn = min(lf,rg) ; 
    mn2 = min(up,lo) ;
     
    if(mn==0){
        if(mn2==0)cout(0);
        else {
            cout(2);
            cout("UD");
        }
        return ;
    }
    else if(mn2==0){
        if(mn==0)cout(0);
        else{
            cout(2);
            cout("LR");
        }
        return ;
    }
    string one="",two="",Ans="";

    while(mn--){
        one+="L";
        two+="R";
    }
    while(mn2--){
        one+="U";
        two+="D";
    }

    Ans = one+two ; 
    len = sz(Ans);
    cout(len);
    cout(Ans);
        
}

int main()
{
   FastRead;
   tc()
    solve();
}