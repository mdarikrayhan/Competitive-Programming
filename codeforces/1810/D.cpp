#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
typedef long long ll;
#ifdef ONLINE_JUDGE
#define endl "\n"
#endif
#define fastio                                                                                                         \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define int long long
#define ok cout << "ok" << endl;
#define debug(x)                                                                                                       \
    for (auto k : x)                                                                                                   \
        cout << k << " ";                                                                                              \
    cout << endl;
typedef long double ld;
typedef double dd;
int MOD = 1000000007;
int ceil(int a, int b)
{
    return (a % b == 0) ? a / b : 1 + (a / b);
}

int f(pair<int,int>& p,pair<int,int> p2){
    if (p.first==-1 && p.second==-1){
        p=p2;
        return 1;
    }
    vector<pair<int,int>> v;v.push_back(p);v.push_back(p2);
    sort(v.begin(),v.end());
    if (v[1].first>v[0].second){
        return 0;
    }

    else{
        p.first=v[1].first;
        if (v[1].second<v[0].second) p.second=v[1].second;
        else p.second=v[0].second;
        return 1;
    }
    
}

int f2(int d,int a, int b){
    if (d>=1 && d<=a) return 1;
    return 2+(d-(a+1))/(a-b);
}

signed main()
{

    fastio int t;
    t = 1;
    cin >> t;
    int cnt=0;
    while (t--)
    {
        int q;cin>>q;
        pair<int,int> p={-1,-1};
        vector<int> ans;
        for (int i=0;i<q;i++){
            
            int tt;cin>>tt;
            if (tt==1){
                int a,b,n;cin>>a>>b>>n;
                pair<int,int> p2;
                if (n==1) {
                    p2.first=1;p2.second=a;
                }
                else{
                    p2.first=(n-1)*a-(n-2)*b+1;
                    p2.second=n*a-(n-1)*b;
                }
                //cout<<a<<" "<<b<<" "<<n<<endl;
                //cout<<p2.first<<" "<<p2.second<<endl;
                int x=f(p,p2);
               // cout<<p.first<<" "<<p.second<<endl;
                ans.push_back(x);
                cnt++;
            }
            else{
                int a,b;cin>>a>>b;
                if (p.first==-1 && p.second==-1){
                    ans.push_back(-1);cnt++;
                }
                else{
                    int d1=f2(p.first,a,b),d2=f2(p.second,a,b);
                    if (d1==d2) {
                        ans.push_back(d1);cnt++;
                    }
                    else{
                        ans.push_back(-1);cnt++;
                    }
                }
                
                if (cnt==296){
                   // cout<<p.first<<"b"<<p.second<<"b"<<a<<"b"<<b<<endl;
                }
            }
            
            // if (p.first>p.second) {
            //     //cout<<p.first<<" "<<p.second<<endl;
            // }

            //cout<<p.first<<" "<<p.second<<endl;
        }
        debug(ans)
        
    }
}