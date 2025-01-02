#include <bits/stdc++.h>
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define time_taken_start int begtime = clock();
#define time_taken_end                                                                    \
    int endtime = clock();                                                                \
    cerr << "\n\n"                                                                        \
         << "Time elapsed: " << (endtime - begtime) * 1000 / CLOCKS_PER_SEC << " ms\n\n"; \
    return 0;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define MOD 1000000007
#define mod 998244353
#define inf 100000000000000007
#define eps 0.000000000001
#define PI acosl(-1)
#define pdd pair<ld, ld>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define vpl vector<pll>
#define vll vector<ll>
#define mseti multiset<ll>
#define msetd multiset<ll, greater<ll>>
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define stp fixed << setprecision(20)
#define endl '\n'

void printv(vector<int> &v)
{
    for (auto e : v)
        cout << e << " ";
    cout << endl;
}

ull binpow(ull a, ull b, ull m)
{
    if (b == 0 || a == 1)
        return 1;
    ull x = binpow(a, b / 2, m);
    x = (x * x) % m;
    if (b % 2)
        x = (x * a) % m;
    return x;
}

int find(int p, vector<int> &par)
{
    if (par[p] == p)
        return p;
    return par[p] = find(par[p], par);
}

void Union(int x, int y, vector<int> &par, vector<int> &sz)
{
    int p1 = find(x, par);
    int p2 = find(y, par);
    if (p1 != p2)
    {
        if (sz[p1] >= sz[p2])
        {
            par[p2] = p1;
            sz[p1] += sz[p2];
        }
        else
        {
            par[p1] = p2;
            sz[p2] += sz[p1];
        }
    }
}

void update(int n,int l,int r,int pos,int x,vector<int> &tree){
    if(l>pos || r<pos) return;
    if(l==r){
        tree[n]+=x;
        return;
    }
    int m=(l+r)/2;
    update(2*n+1,l,m,pos,x,tree);
    update(2*n+2,m+1,r,pos,x,tree);
    tree[n]=tree[2*n+1]+tree[2*n+2];
}

int search(int n,int l,int r,int i,int j,vector<int> &tree){
    if(l>j || r<i) return 0;
    if(l>=i && r<=j) return tree[n];
    int m=(l+r)/2;
    int s1=search(2*n+1,l,m,i,j,tree);
    int s2=search(2*n+2,m+1,r,i,j,tree);
    return s1+s2;
}

void solve()
{
    int a1,a2,a3,a4;
    cin>>a1>>a2>>a3>>a4;
    if(a1<max(a3,a4) || a2<max(a3,a4) || abs(a3-a4)>1) cout<<-1<<endl;
    else{
        string ans;
        if(a3==a4){
            if(a1>=(a4+1)){
                for(int i=0;i<a4;i++){
                    ans+="47";
                    a1--;
                    a2--;
                }
                ans+="4";
                a1--;
            }else{
                for(int i=0;i<a4;i++){
                    ans+="74";
                    a1--;
                    a2--;
                }
                ans+="7";
                a2--;
            }
        }else if(a3>a4){
            for(int i=0;i<a3;i++){
                ans+="47";
                a1--;
                a2--;
            }
        }else{
            for(int i=0;i<a4;i++){
                ans+="74";
                a1--;
                a2--;
            }
        }
        //cout<<a1<<" "<<a2<<endl;
        if(a1<0 || a2<0) cout<<-1<<endl;
        else{
            if(a1>0){
                string s;
                for(int i=0;i<ans.size();i++){
                    s+=ans[i];
                    if(a1>0 && ans[i]=='4'){
                        while(a1>0){
                            s+='4';
                            a1--;
                        }
                    }
                }
                ans=s;
            }
            if(a2>0){
                string s;
                for(int i=ans.size()-1;i>=0;i--){
                    s+=ans[i];
                    if(a2>0 && ans[i]=='7'){
                        while(a2>0){
                            s+='7';
                            a2--;
                        }
                    }
                }
                ans=string(s.rbegin(),s.rend());
            }
            cout<<ans<<endl;
        }
    }
}

int main()
{
    FAST
#ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    time_taken_start
        ll t = 1;
     //cin>>t;
    for (ll i = 0; i < t; i++)
    {
        // cout<<"Case #"<<i+1<<": ";
        solve();
    }
    time_taken_end
}