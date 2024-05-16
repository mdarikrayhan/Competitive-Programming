#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define fi first
#define pb push_back
#define se second
#define os ios_base::sync_with_stdio(false);
#define INFI 0x3f3f3f3f
#define all(v) v.begin(),v.end()
#define YN(b) ((b)?cout << "YES":cout <<"NO")
#define fre freopen("input.in","r",stdin); freopen("out.out","w",stdout);
#define cases()   ll t; cin >> t; while(t--)
#define oper min
#define NEUT ((ll)1e9*2)
using namespace std;
typedef long long ll;
typedef long long expbi;
//typedef vector<ll> vi;
typedef vector<pair<ll,ll>> vii;
typedef pair<ll,ll> pii;

typedef long long expbi;
expbi binex(expbi valor, expbi exponente){
        expbi ans=1;
        while(exponente){
            if(exponente&1){
                ans*=valor;
            }
            //valor%=10;
            //ans%=10;
            valor*=valor;
            exponente>>=1;
        }
        return ans;
}


const int MAXN=1e5*5+5;

int main(){
    os;
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << min({b,a,(b+a)/3}) << "\n";
    return 0;
}