        #include <bits/stdc++.h>
        //#include <ext/pb_ds/assoc_container.hpp>
        //#include <ext/pb_ds/tree_policy.hpp>
        using namespace std;
        #define endl cout<<"\n" 
        #define yes cout << "YES\n"
        #define no cout << "NO\n"
        typedef  long long int ll;
        typedef long double ld;
        #define roundUp(a, b) ((a + b - 1) / b)
        #define print(x) cout << x << '\n';
        #define  pb push_back
        #define rep(i,a,b)   for(ll i=a;i<b;i++)
        #define rev(i,a,b)   for(ll i=a;i>=b;--i)
        #define fastio()     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
        #define all(x) (x).begin(), (x).end()
        #define scin(str) getline(cin, str)
        #define v(a,b,c) vector<a>b(c)
        //ordered_set s;// f+=s.size()-s.order_of_key(l.second);s.insert(l.second);
        //typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
        ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
        ll min(ll a,ll b){if(a>b){return b;}else{return a;}}
        ll lcm(ll a,ll b) {return((a/gcd(a,b))*b);}
        ll fact(ll n) {if (n == 0) {return 1;} else {return n * fact(n - 1);}}
        //int p =1e9+7;
        ll total(vector<ll>vec){ll s=0;ll n=vec.size();rep(i,0,n){s+=vec[i];}return s;}
        ll mini(vector<ll>a){ll s=10e9;for(int i=0;i<a.size();i++){s=min(a[i],s);}return s;}
        ll maxi(vector<ll>a){ll m=0;for(int i=0;i<a.size();i++){m=max(m,a[i]);}return m;}

        ll suck_it(ll ind,vector<ll>&a,vector<ll>&dp,ll sum)
        {
            if(ind==0)
            {
                return 0;
            }
            ll doo=suck_it(ind-1,a,dp,sum)+(sum+(-2*(a[ind])));
            ll dont=suck_it(ind-1,a,dp,sum)+(sum+(a[ind]));
            a[ind-1]=-1*a[ind-1];
            return max(doo,dont);
        }

        void fuck_it()
        {
            ll n,s=0;cin>>n;
            v(ll,a,n);v(ll,b,n);v(ll,c,n);
            for(int i=0;i<n;i++){cin>>a[i]>>b[i];s+=a[i];}
            for(int i=0;i<n;i++)
            {
                c[i]=b[i];
            }sort(all(c));
            for(int i=0;i<n;i++)
            {
                ll d=s-a[i];
                if(b[i]==c[n-1])
                {
                cout<<((d)*c[n-2])<< " " ;
                }
                else
                {
                    cout<<((d)*c[n-1])<< " " ;
                }
            }
            endl;
        }

        int32_t main()
        {
            //cout<<fixed;
            //cout<<setprecision(10);
            ll tc;
            tc=1;
            //cin>>tc;
            while(tc--)
            {
                fuck_it();
            }
        }

