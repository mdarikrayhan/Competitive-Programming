
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long int l;
typedef int i ;
typedef vector<int> vi ;
typedef set<int> si;
#define pb push_back
#define f1(i,a,b) for(int i = a ;i<=b;i++)
#define ln endl
#define f2(i,a,b) for(int i = a ;i<b;i++)
#define f3(i,a,b) for(int i = a ;i>=b;i--)
#define f4(i,a,b) for(int i = a ;i>b;i--)
#define ll             long long int 
#define ulli           unsigned long long int 
#define li             long int 
#define ff(i,a,b)      for(int i=a;i<b;i++)
#define fb(i,b,a)      for(int i=b;i>=a;i--)
#define w(t)           while(--t >= 0)
#define l(s)           s.length()
#define ci(n)          cin>>n;
#define fast           ios_base::sync_with_stdio(false);
#define sa(a,n)        sort(a,a+n)
#define sv(v)          sort(v.begin(),v.end())
#define cy             cout<<"YES\n"
#define cn             cout<<"NO\n"
#define nl             cout<<"\n"
#define minus          cout<<"-1\n";
#define vi             vector<int>
#define pb             push_back
#define tc             int t; cin>>t;
#define pp             pair<int,int>
#define input(a,n)     for(int i=0;i<n;i++) cin>>a[i];
#define mod            1000000007
#define co(n)          cout<<n;
#define ret            return 0
#define mi             map<int,int>
#define output(a,n)    for(int i=0;i<n;i++) cout<<a[i]<<" ";   
#define forn(i, n)     ff(i, 0, n)
#define sz(v)          int((v).size())
int fhcf(int m,int n){
    
    if(m == 0){
        
        return n;
    }
    
    return fhcf(n%m , m);
    
    
  
    
}
void solve(){
    string s;
    cin>>s;
    int n = s.size();
    int p = 0 ;
    char c = s[p];
    int ans = -1 ;
    
    for(int i = 1 ; i < n ; i++){
        
        
        if(s[i] == c){
            ans++;
            p++;
            i = p;
            c = s[p];
        }
        
        
        
        
    }
    
    s = s.substr(ans + 1);
    
    cout<<s<<ln;
    
    
    
    
    
}

int main()
{
    fast;
    int t;
    cin>>t;
    w(t)
    {
        solve();
    }
    return 0;
}


