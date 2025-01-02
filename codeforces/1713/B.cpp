///   ***   ---   |||       Starting coding in the name of great merciful,creator of the universe,  ALLAH.        |||   ---   ***   ///
///   ***   ---  |||                                                 Allahu_akbor                                   |||   ---   ***   ///
///   ***   -  |||                                         آ اِلَهَ اِلّا اللّهُ مُحَمَّدٌ رَسُوُل اللّهِ (ﷺ)                          |||   ---   ***   ///


#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define ha cout<<"YES"<<endl;
#define na cout<<"NO"<<endl;
#define op0(n) for(int i = 0; i < (n); i++);
#define op1(n) for(int i = 1; i <= (n); i++);
#define opr0(n) for(int i = (n)-1; i >= 0; i--);
#define opr1(n) for(int i = (n); i >= 1; i--);

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

//#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
//#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
//void faltu () {            cerr << endl;}
//template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
ll lcm(ll a, ll b) {
    return a * (b / gcd(a, b));
}
//         *** *** *** *** ***               Alhamdulillah, Starting to Code... ... .. .            *** *** *** //
int main()
{
    optimize();
      ll t;
      cin >> t;
      while(t--){
        int n; cin >> n; int a [ n +1];
          vi v; 
          int pv = -1; 
          for ( int  i = 0; i <n;i++)
          {
          	     cin >> a [ i ];
          	     if(a[i]!=pv)v.PB(a[i]); 
          	     pv = a[i]; 
          }
          
          ll temp = 0;
          for ( int i = 1 ; i <v.size()-1; i++)
          {
          	    if(v[i]<v[i-1] and v[i]<v[i+1])
          	    {
          	    	    temp = 1;
          	    }
          }
          if(temp){
            na;
          }
          else{
            ha;
          }
          
          

      }
      
      
    
    return 0;
}

//     *** *** *** *** ***           Fee_Amanillah, Finishing the code in the name of Allah       *** *** *** *** //


