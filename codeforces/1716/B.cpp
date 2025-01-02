// 07
// Oh Hm Bhi Bna Lenge !!!
#include <bits/stdc++.h>
using namespace std;
#define int long long int

#define FAST()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

int mod = 1e9 + 7;
int M = 998244353;
vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

#define all(X) X.begin(), X.end()
#define vi vector<int>
#define rep(a, b, i) for (int i = a; i < b; i++)
#define repR(a, b, i) for (int i = a - 1; i >= b; i--)
#define inpt(A)                        \
    for (int i = 0; i < A.size(); i++) \
    cin >> A[i]
void solve()
{
    int n;
    cin>>n;
    cout<<n<<"\n";
    vector<int>arr1(n);
    rep(0,n,i) arr1[i]=i+1;
    int j=n-1;
    while(n--){
        for(auto i:arr1) cout<<i<<" ";
        cout<<"\n";
        if(j-1>=0)
        swap(arr1[j],arr1[j-1]);
        j--;
    }

}
int32_t main()
{
    FAST();
    cout << fixed << setprecision(9);
    int TEST = 1;
    cin >> TEST;
    while (TEST--)
    {
        solve();
        // cout << "\n";
    }
}