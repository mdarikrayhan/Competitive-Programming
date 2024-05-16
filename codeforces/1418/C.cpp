#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Pb push_back
#define S second
#define F first
#define Fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Endl '\n'
#define V vector<ll>
#define Vv vector<vector<pair<int,int>>>
#define Vp vector<pair<ll,ll>>
#define No cout << "NO" << Endl
#define Yes cout << "YES" << Endl
const int N = 2e5 + 5;
ll Memo[N][2];
int n, a[N];
ll Dp(int Ind, int Turn)
{
    if(Ind > n){
        return 0;
    }
    ll &Ret = Memo[Ind][Turn];
    if(Ret != -1){
        return Ret;
    }
    if(Turn == 1){
        Ret = min(Dp(Ind + 2, 0), Dp(Ind +1, 0));
    }
    else {
        int Cost1 = (a[Ind] == 1), Cost2 = Cost1 + (a[Ind+1] == 1);
        Ret = min(Cost1 + Dp(Ind + 1, 1), Cost2 + Dp(Ind + 2, 1));
    }
    return Ret;
}
int main()
{
    int Tc = 1;
    Fastio;
    cin>>Tc;
    while(Tc--)
    {
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        a[n+1] = -1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=1;j++){
                Memo[i][j] = -1;
            }
        }
        cout << Dp(1, 0) << Endl;
    }
    return 0;
}
