/*
{وَاللَّهُ غَالِبٌ عَلَى أَمْرِهِ وَلَكِنَّ أَكْثَرَ النَّاسِ لَا يَعْلَمُونَ}
 */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define OSO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10;
const int MOD=1e8;
vector<bool> isPrime(N);
void FIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
ll fixed_mod(ll a,ll b)
{
    return ((a%b)+b)%b;
}
ll fast_power(ll a,ll b)
{
    if(!b) return 1;
    ll ret= fast_power(a,b/2);
    return (b & 1 ? ret * ret * a : ret * ret);
}
vector<ll> get_divisors(ll n)
{
    vector<ll> ret;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ret.push_back(i);
            if(n/i!=i)
            {
                ret.push_back(n/i);
            }
        }
    }
    return ret;
}
vector<int> get_multiples(int x,int n)
{
    vector<int> ret;
    for(int i=x;i<=n;i+=x)
    {
        ret.push_back(i);
    }
    return ret;
}
bool is_prime(ll x)
{
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    if(x!=1)
    {
        return true;
    }
    return false;
}
set<ll> get_prime_divisors(ll n)
{
    set<ll> st;
    for(ll i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            st.insert(i);
        }
    }
    if(n!=1)
    {
        st.insert(n);
    }
    return st;
}
void sieve()
{
    fill(isPrime.begin(),isPrime.end(),true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=N;i++)
    {
        if(is_prime(i))
        {
            for(int j=i+i;j<=N;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
}
int set_bit_one(int num,int idx)
{
    return num | (1<<idx);
}
int set_bit_zero(int num,int idx)
{
    return num & ~(1<<idx);
}
int flip_bit(int &num,int idx)
{
    return num ^ (1<<idx);
}
int last_bit_value(int num)
{
    return num&~(num-1);
}
int number_of_one_bits(int num)
{
    int cnt=0;
    while(num)
    {
        cnt++;
        num&=(num-1);
    }
    return cnt;
}
int number_of_bits(int num)
{
    int cnt=0;
    while(num)
    {
        cnt++;
        num>>=1;
    }
    return cnt;
}
void do_it()
{
    int n,m;
    cin>>n>>m;
    if(n==1||m==1||(n==m&&n==2))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
int main()
{
    OSO
    FIO();
    int t=1;
    cin>>t;
    while(t--)
        do_it();
    return 0;
}