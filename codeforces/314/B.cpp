using namespace std;
#include <bits/stdc++.h>

//---MACROS--//

//                                                  -| BANKAI |-
#define ll long long
#define loop(i,m,n) for(long long int i=m;i<n;i++)
#define rloop(i,m,n) for(long long int i=m;i>=n;i--)
#define pb push_back
#define F first
#define S second
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define all(v) v.begin(),v.end()
#define test cout<<"B A N K A I"<<endl
#define Fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl "\n"
#define MP make_pair

vector<int> factors(int n) {
    // Takes sqrt(n) time. Go for Sieve till sqrt(n) if time Squeezes (sqrt(n)/log(n)).
    vector<int> f;
    for (int x = 2; x*x <= n; x++){
        while (n%x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}

///------------------------------------------------------------------------------------------------------------------


void solve()
{
    int b,d;
    string a,c;
    cin>>b>>d;
    cin>>a>>c;

    int lena = a.size();
    int lenc = c.size();

    vector<int> take(lenc,0);

    loop(i,0,lenc)
    {
        loop(j,0,lena)
        {
            if(c[(i+take[i])%lenc] == a[j])
            {
                take[i]++;
            }
        }
    }

    int took = 0;
    loop(i,0,b)
    {
        took += take[took % lenc];
    }

    int tims = took/lenc;

    int ans = tims/d;

    cout<<ans<<nl;

}


///         Beware of Long Long

///-----------------------------------------------------------------------------------------------------------------------

int main(){
    std::cout<<std::setprecision(10)<<std::fixed;
    Fast
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int t = 1;
    //cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
