#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define maxll INT64_MAX
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define vi vector<int>v;
#define vpiin vector<pair<int,int>>v(n);
#define vf(i) v[i].first
#define vs(i) v[i].second
#define vvi vector<vector<int>>v;\
#define all(v) v.begin(),v.end()


void pv(vector<ll>v)
{
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
string bin(ll n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}
void inline yes()
{
    cout<<"YES"<<endl;
}
void inline no()
{
    cout<<"NO"<<endl;
}

vector<bool>primes(ll n)
{
    vector<bool>v(n+1,1);
    rep(j,2,n+1)
    {
        if(v[j])
        {
            for(int k=2*j;k<=n;k+=j)v[k]=0;
        }
    }
    return v;
}

ll lcm(ll a, ll b)
{
    return (a*b)/__gcd(a,b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    tc=1;
    rep(i,0,tc)
    {
        string s;
        getline(cin,s);
        string p="";
        ll l=0,h=0;
        while(h<s.size())
        {
            while(s[h]==' '&&h<s.size())
            {
                h++;
            }
            if(h==s.size())break;
            //cout<<l<<" "<<h<<endl;
            if(s[h]=='"')
            {
                h++;
                while(s[h]!='"'&&h<s.size())
                {
                    p+=s[h];
                    h++;
                }
                cout<<"<"<<p<<">"<<endl;
                p.clear();
                h++;
            }
            else
            {
                while(s[h]!=' '&&h<s.size())
                {
                    p+=s[h];
                    h++;
                }
                cout<<"<"<<p<<">"<<endl;
                p.clear();
                h++;
            }
        }
    }
    return 0;
}