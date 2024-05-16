/*   /\_/\
*   (= ._.)
*   / >  \>
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair <int,int> pi;
typedef set<int> si;
typedef set<long long> sll;
typedef unordered_map<long long,long long> ull;
#define f first
#define s second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;i++)
void printvec( vector<ll> v){
     for(int i=0;i<v.size();i++){ cout<<v[i]<<" "; }
     cout<<endl;
}
ll gcd(ll a, ll b){
if(b == 0) return a;
return gcd(b, a % b);
}
ll lcm(ll a, ll b){

return a*b/gcd(a,b);
}
bool isPrime(ll n)
{
     if (n <= 1)
        return false;
for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 return true;
}


void solve(){
    int n,m;
    cin>>n>>m;
    vi v(m+1,0);
    FOR(i,0,m){
        int x;
        cin>>x;
        FOR(j,0,x){
            int y;
            cin>>y;
            v[y]=1;

        }
    }
    FOR(i,1,m+1){
        if(v[i]==0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;

}



    

int main(){
    fast;
    // ifstream read("revegetate.in");
    // ofstream out("revegetate.out");
	int sura=1;
    //cin>>sura;
     while(sura--){
        solve();
        }
    return 0;
}
/*   /\_/\
*   (= ._.)
*   / >  \>
*/