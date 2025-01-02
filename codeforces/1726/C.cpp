//********************************************************************************************************************************************************************//
//*                ██████╗    ███╗░░░███╗
//*               ██╔═══██╗   ████╗░████║
/*                ██║   ██║   ██╔████╔██║
 *                ██║   ██║   ██║╚██╔╝██║
 *                ╚██████╔╝   ██║░╚═╝░██║
 **************************************************************************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define murimuri ios::sync_with_stdio(false);cin.tie(nullptr);
#define inarr(arr, n) for (ll i = 0; i < n; i++) cin>>arr[i]
#define vinp(x) for(auto &i:x) cin>>i
#define vll vector<ll>
//declaring size in vector pair reduces runtime error when running codes containing vector pair
#define vpll vector<pair<ll,ll>>
#define mapll map<ll,ll>
#define sll set<ll>
#define in(n) ll n;cin>>n
#define inn(n,k) ll n,k;cin>>n>>k
#define innn(x,y,z) ll x,y,z; cin>>x>>y>>z
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define on(n) cout<<n<<endl
#define os(n) cout<<n<<" "
#define ff first
#define ss second
#define pb emplace_back
#define rr return
// to findout distance from starting of vector to element which greater than or equal to x
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
// to findout distance from starting of vector to element which greater than x
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))


//rotate(v.begin(),v.begin()+v.size()-r,v.end()); //for rotating vector r times right
//rotate(v.begin(),v.begin()+r,v.end()); //for rotating vector r times left
#define all(x) x.begin(), x.end()
#define fi(l, r) for(ll i=l;i<r;i++)
#define fj(l, r) for(ll j=l;j<r;j++)
#define fir(r, l) for(ll i=r;i>=l;i--)
#define fjr(r, l) for(ll j=r;j>=l;j--)
//cout << fixed<<setprecision(15); ///activate it if the answers are in decimal.

/*(a+b)%M=((a%M)+(b%M))%M
        * (a-b)%M=((a%M)-(b%M)+M)%M
                  * (a*b)%M=((a%M)*(b%M))%M
                            * (a/b)%M=((a%M)*((b^-1)%M))%M
                                   */


const ll mod=1e9+7;

ll power(ll n,ll a){ ll res=1; while(a){ if(a%2) res*=n,a--; else   n*=n,a/=2;} return res;}

bool isPowerOfTwo(ll n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}

bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}

ll modpower(ll n,ll a,ll p){ ll res=1; while(a){ if(a%2) res= ((res*n)%p) ,a--; else n=((n*n)%p),a/=2;} return res;}

ll fastprime(ll a){ if (a != 2 && a % 2 == 0 || a < 2) return 0;  for(ll i = 3; i * i <= a; i += 2) if(a % i == 0) return 0; return 1;}

ll mod_mul_inverse(ll a,ll b) {return modpower(a , b-2, b);}

ll gcd(ll a, ll b){return (b == 0 ? a : gcd(b, a % b));}

ll ask(ll l, ll r) {
    cout << "? " << l << ' ' << r << endl;
    fflush(stdout);
    ll ans;
    cin >> ans;
    return ans;
}
bool sortbysec(const pair<ll,ll> a,
               const pair<ll,ll> b)
{
    if (a.second!=b.second){
        return a.second<b.second;
    }
    else{
        return a.first<b.first;

    }
}
//********************************************************************************************************************************************************************//

void akiramenai() {
    in(n);
    vector<char> vec(2*n);
    vinp(vec);

    ll ans=0;
    fi(0,2*n-1){
        if(vec[i]=='(' and vec[i+1]=='('){
            ++ans;
        }
    }

    on(ans+1);
}
int main() {
    murimuri;

    ll t=1;
    cin >> t;
    while (t--) {
        akiramenai();
    }
}
/* TIPS:
-1. Never Ignore The Constraints Section (can also be used to solve problems if they are limited)
0. Remember Pre Computation is always helpful
1. If WA comes and you are sure about the solution, then check the constraints & edge cases.
2. If too many people have solved a question you are stuck on, then always remember: The solution is
   100% easy and you need to calm down and think EASY, nothing complicated.
3. Read the question again after getting two wrong submissions. You are 100% missing something important
   in the question.
4. If TLE comes in question, then check if one of the test cases generate infinite output.
   It will give TLE.
5. If question looks unsolvable from front, try going from back. Works mostly from the back.
6. Stuck on implmentation? Think and then implement Data Structures that best fit the q like set,maps,stacks,queue.
7. Agar Question pe stuck ho and primary logic nahi aa raha dimaag mae then test case se ek pattern deduce karne ka try karo
8. Often Parity Is A good factor for obervation or computation
*/
