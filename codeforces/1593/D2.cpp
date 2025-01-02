    #include<iostream>
    #include <iomanip>
    #include<math.h>
    #include <bits/stdc++.h>
    #include<set>
    #include<map>
    #include<queue>
    #include <fstream>
    using namespace std;
    // #include <ext/pb_ds/assoc_container.hpp> 
    // using namespace __gnu_pbds;
    // typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
    // // lower_bound,upperbound swapped for multiset
    // //change less_equal to equal for set
    #define float long double
    #define PYes cout<<"Yes\n"
    #define PNo cout<<"No\n"
    #define PYES cout<<"YES\n"
    #define PNO cout<<"NO\n"
    #define pq priority_queue
    #define int long long
    #define endl '\n'
    #define f(i,a,b) for(int i=a;i<b;i++)
    #define fe(i,a,b) for(int i=a;i<=b;i++)
    #define ff(i,a,b) for(int i=b-1;i>=a;i--)

    // // pbds
    // s.find_by_order()
    // s.order_of_key()

    typedef vector< int > vi;
    typedef vector< vi > vvi;
    typedef pair< int,int > ii;
    typedef vector<pair<int,int>> vp;
    #define sz(a) int((a).size())
    #define pb push_back

    #define all(c) (c).begin(),(c).end()
    #define tr(c,i) for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
    #define present(c,x) ((c).find(x) != (c).end())
    #define cpresent(c,x) (find(all(c),x) != (c).end())
    const int inf = 1LL<<60;
    const int N=1e9;





    void solve() {
        int n;
        cin>>n;
        int a[n];
        f(i,0,n)cin>>a[i];
        map<int,int>m1;
        f(i,0,n){
            m1[a[i]]++;
        }
        for(ii i:m1){
            if(i.second>=n/2){cout<<-1<<endl;return;}
        }
        map<ii,set<int>>m;
        f(i,0,n){
            f(j,i+1,n){
                int x=abs(a[i]-a[j]);
                for(int k=1;k*k<=x;k++){
                    if(x%k==0){
                        m[make_pair(k,(a[i]%k+k)%k)].insert(i),m[make_pair(k,(a[i]%k+k)%k)].insert(j);
                        int y=x/k;
                        m[make_pair(y,(a[i]%y+y)%y)].insert(i),m[make_pair(y,(a[i]%y+y)%y)].insert(j);
                    }
                }
            }
        }
        
        int ans=1;    
        for(auto i:m){
            if((i.second).size()>=n/2)ans=i.first.first;
            // cout<<i.first<<" "<<i.second.size()<<endl;
            // if(i.first==36){
            //     for(int j:i.second)cout<<a[j]<<" ";cout<<endl;
            // }
            
        }
        cout<<ans<<endl;
        return;
    }








    int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int t;
        cin >> t;
        while (t--) {
            solve();
        }
        return 0;
    }