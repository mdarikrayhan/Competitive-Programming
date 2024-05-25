#include<bits/stdc++.h>
using namespace std;
//*****************************************************************************************************
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string>vs;
typedef vector<double> vdd;
typedef vector<char>vc;
typedef set<int> si;
typedef set<string> ss;
typedef set<ll> sll;
typedef set<char>sc;
typedef multiset<int> mi;
typedef multiset<string> ms;
typedef multiset<ll> ml;
typedef multiset<char> mc;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef map<string,int> msi;
typedef map<char,int> mci;
typedef map<int,bool> mib;
typedef vector<pair<int,int>>vpii;
typedef vector<pair<ll,ll>>vpll;
//*****************************************************************************************************
#define endl '\n'
#define pb push_back
#define in insert
#define f first
#define s second
//*****************************************************************************************************
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define mem(a,b) memset(a, b, sizeof(a) )
#define aa() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define testcase int t;cin>>t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
#define fore(a) for(auto u:a)
#define foreach(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

//****************************************************************************************************

int main()
{
    aa();

        int n;
        cin>>n;
        vi v(n);
        forn(i,n)cin>>v[i];
        int m;
        cin>>m;
        vi v1(m);
        forn(i,m)cin>>v1[i];
        sort(all(v));
        sort(rall(v1));
        int d=v[0];
        int c=0;
        ll sum=0;
        for(int i=0;i<m;i++)
        {
            c++;
            if(c<d)
            {
                sum+=v1[i];
            }
            else
            {
                sum+=v1[i];
                c=0;
                if(i+2<m)
                {
                    i=i+2;
                }
                else break;
            }
        }
       cout<<sum<<endl;


    return 0;
}


