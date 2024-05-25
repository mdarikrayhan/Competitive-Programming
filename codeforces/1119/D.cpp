    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    using namespace std;
    using ll = long long;
    using ld = long double;
    #pragma GCC optimize("Ofast","inline","-ffast-math")
    #pragma GCC target("avx,sse2,sse3,sse4,mmx")    
    #define int long long int
    #define vi vector<int>
    #define vvi vector<vector<int>>
    #define vsi vector<set<int>>
    #define vpi vector<pair<int,int>>
    #define vb vector<bool>
    #define pii pair<int,int>
    #define fr(i,n) for(int i=0; i<(n); i++)
    #define rep(i,a,n) for(int i=(a); i<=(n); i++)
    #define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
    #define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
    #define acc(v)  accumulate(v.begin(),v.end(),0ll)     // find the total sum in vector 
    #define endll "\n";
    #define ff first
    #define ss second
    #define pb push_back
    #define FLASH ios_base::sync_with_stdio(false);cin.tie(NULL);
    #define mod 1000000007 //change this line to change the Modulo
    #define sqrt sqrtl
    #define bcnt __builtin_popcount
    #define all(a) a.begin(),a.end()
    #define rall(a) a.rbegin(),a.rend()
    #define yes {cout<<"YES"<<endl;}
    #define no {cout<<"NO"<<endl;}
    #define hello {cout<<"Hello"<<endl;cerr<<"Hello"<<endl;}
    // ==================================<Modulo operations>==================================
    void modadd(int &a , int b) {a=((a%mod)+(b%mod))%mod;}
    void modsub(int &a , int b) {a=((a%mod)-(b%mod)+mod)%mod;}
    void modmul(int &a , int b) {a=((a%mod)*(b%mod))%mod;}
    int expo(int a, int b,int m) {a %= mod; ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
    int inv(int a, int b) {return expo(a, b - 2, b);}
    int nCr(int n, int r,int m, int *fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
    // ==================================<Debug Module>=======================================
    void debug() {cerr << endl;}
    template<typename T, typename... Args>
    void debug(const T& first, const Args&... args) {cerr << first << " ";debug(args...);}
    // ==================================<Debug Module Ends>==================================

    // ================================== take ip/op like vector,pairs directly!==================================
    template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
    template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
    template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
    template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<endl; return cout; }
    template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
    // ===================================END Of the input module ================================================

    /*----------------------------------------------- PBDS -------------------------------------------------*/
    template <class T> using oset = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
    template <class T> using moset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
    // find_by_order(k)  returns iterator to kth element starting from 0;
    // order_of_key(k) returns count of elements strictly smaller than k;
    /*----------------------------------------------- PBDS ends --------------------------------------------*/
    /*=========================================== SOLUTION ==================================================*/

    void solve()
    {
        int n;
        cin>>n;
        vi a(n);
        cin>>a;
        vi diff;
        diff.push_back(0);
        sort(all(a));
        for(int i=1;i<n;i++)
        {
            diff.pb(a[i]-a[i-1]);
        }
        int m=diff.size();
        sort(all(diff));
        vi pref(m,0);
        pref[0]=diff[0];
        for(int i=1;i<diff.size();i++)
        {
            pref[i]=pref[i-1]+diff[i];
        }
        int q;
        cin>>q;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            int len=(r-l+1);
            int ans=0;
            auto it=upper_bound(all(diff),len);
            it--;
            int ind=it-diff.begin();
            ans=len+(pref[ind]+(m-1-ind)*(len));
            cout<<ans<<" ";
        }
        cout<<endll;
    }
    /*============================================= MAIN ====================================================*/
    
    int32_t main() {
            // your code goes here
            FLASH
            int t=1;
            // cin>>t;
            int p=0;
            while(++p<=t)
            {
                solve();
            }
            return 0;
    }
    //Thoughts
    /*
        
    */