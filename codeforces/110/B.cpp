#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define mp make_pair
#define float long double
#define yes  cout << "YES" << endl;
#define no  cout << "NO" << endl;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define PI 3.141592653589793
#define Mod 1000000007

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<pair<int,int> > vpii;
typedef vector<pair<long long,long long> > vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef priority_queue<ll> pq;
typedef priority_queue<pair<ll,ll> > pqp;

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

/*
****************************************LOVE YOU MAA***************************************************
**********************************FAMILY ABOVE ALL*****************************************************
**************************************GIVE ME SOME SUNSHINE , GIVE ME SOME RAIN************************
******************************GIVE ME ANOTHER CHANCE , I WANNA GROW UP ONCE AGAIN**********************
**************************************YE DIL MAANGE MORE***********************************************
**************************SHAURYAM DAKSHAM YUDDHE,BALIDAAN PARAM DHARMA********************************
*/

int main()
{    
    IOS;
    
    ll n;
    cin>>n;
    string s="abcd",st;
    string ans="";
    while(n>=4)
    {
        ans+=s;
        n-=4;
    }
    if(n)
    {
        st=s.substr(0,n);
        ans+=st;
    }

    cout<<ans<<endl;

    return 0;
}