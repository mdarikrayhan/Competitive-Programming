#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //policy based ds library
using namespace __gnu_pbds; //"" 
using namespace std;

//Aliases
using ll=long long int;
using uul=unsigned long long;
using ld=long double;

//Constants (faster than define)
constexpr ll INF=2e18;
constexpr ld EPS=1e-9;
constexpr ll MOD=1e18+7;

//Macros
#define F first   //using vector<pair> v[i].F
#define S second  //using vector<pair> v[i].S
#define all(x) x.begin(),x.end() //sort(v.begin(),v.end())
#define allr(x) x.rbegin(),x.rend() //reverse sort
#define int long long
#define pb push_back
// #define mk make_pair
#define vi vector<int>
#define mii unordered_map<int,int> 
#define pqb priority_queue<int> //min-heap
#define pqs priority_queue<int,vi,greater<int>> //max-heap
#define setbits(x) __builtin_popcountll(x) //No of 1(set bits) 5->101 =>2
#define zrobits(x) __builting_ctzll(x) //No of 0's after 1st 1 in binary rep.
#define ps(x,y) fixed<<setprecision(y)<<x //y after . in double
// #define mk(arr,n,type) type *arr=new type[n]; //dynamically create any type data st.
#define w(x) int x;cin>>x;while(x--)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //random array suffler->suffle(arr,arr+n,rng)
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;



//Macros
#define ll long long int

//Utility functions

//Mathematical Functions
// gcd - greatest common divisor
int GCD(int a,int b)
{
    if(b==0)return a;
    return GCD(b,a%b);
}
// lcm - largest common multiplier
int LCM(int a,int b)
{
    return (a*b)/GCD(a,b);
}
//x^n mod m
int modpow(int x,int n,int m=MOD) 
{
    if(x==0 && n==0)return 0;
    int res=1;
    while(n>0)
    {
        if(n%2) res=(res*x)%m;
        x=(x*x)%m;
        n/=2;
    }
    return res;
}
//moduler inverse (x^(m-2))%m (multiplicative)
int modinv(int x,int m=MOD)
{
    return modpow(x,m-2,m);
}

int sieve(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return -1;
        }
    }
    return n;
}
vector<int>power2;
void pre()
{
    int temp=1;
    for(int i=1;i<=59;i++)
    {
        temp*=2;
        power2.push_back(temp);
    }
}
int isPowerOf2(int n)
{
    for(int i=0;i<power2.size();i++)
    {
        if(power2[i]==n)
        {
            return i+1;
        }
    }
    return -1;
}


bool comp(const pair<int,int>&a,const pair<int,int>&b)
{
    if(a.first==b.first)
    {
        return a.second<b.second;
    }
    return a.first<b.first;
}
bool cmp(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.second<b.second;
}
struct myvector{
    int preFixSum;
    int element;
    int index;
};

void printBinary(int num)
{
    for(int i=10;i>=0;i--)
    {
        cout<<((num>>i)&1);
    }
    cout<<endl;
}
void checkSetBit(int num,int i)
{
    i;
    int mask=(1<<i);
    if((num & mask)==0)
    {
        cout<<"Not Set"<<endl;
    }
    else
    {
        cout<<"Set"<<endl;
    }
    return;
}
void setBitCount(int num)
{
    // cout<<__builtin_popcount(num);
    //Alternative
    //from msb to lsb i am checking i-th bit is set or not.
    int cnt=0;
    for(int i=10;i>=0;i--)
    {
        int a=((1<<i)&num);
        if(a!=0)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return;
}
void setBit(int num,int i) //OR
{
    int mask=(1<<i);
    int a=(num | mask);
    printBinary(a);
    return;
}
void unsetBit(int num,int i) //AND
{
    int mask=(1<<i);
    int a=(num & ~mask);
    printBinary(a);
    return;
}
void toggleBit(int num,int i)
{
    int mask=(1<<i);
    int a=(num ^ mask);
    printBinary(a);
    return;
}
void checkOddEven(int n)
{
    //'+,-,*'are fast but '%,/' are slow 
    //so this approach is better than n%2
    if((n&1)!=0)
    {
        cout<<"Odd"<<endl;
    }
    else
    {
        cout<<"Even"<<endl;
    }
    return;
}
void divideBy2(int num)
{
    cout<<(num>>1)<<endl;
    return;
}
void multiplyBy2(int num)
{
    cout<<(num<<1)<<endl;
    return;
}
void checkPowerOf2(int num)
{
    //Bcz any power of 2 has only one set bit and if I do -1 from that
    //It will make LSB's 1 and that bit 0 So if I do & of them this will be 0.
    if(num&(num-1)) //non-zero
    {
        cout<<"Not Power of 2"<<endl;
    }
    else
    {
        cout<<"Power of 2"<<endl;
    }
    return;
}
void solve1(int tc)
{
    int n;
    cin>>n;
    printBinary(n);
    int i=3;
    checkSetBit(n,i);
    setBit(n,2);
    unsetBit(n,i);
    toggleBit(n,5);
    setBitCount(n);
    checkOddEven(n);
    divideBy2(n);
    multiplyBy2(n);
    //Trick 1:
    //Only diff btw 'A' and 'a' is that 'a'has 5th bit set
    //but 'A' doesn't have that.(for all capital 5th is unset)
    char A='A';
    char a='A'|(1<<5);
    cout<<a<<endl;
    //Trick 2:
    //If I wanna make uppercase to lowercase :do OR operation with ' '(space)
    //If I wanna make lowercase to uppercase :do AND operation with '_'(underscore)

    //Trick 3:
    //I want to unset all LSB till i-th bit
    int b=(n&(~((1<<(i+1))-1)));
    printBinary(b);
    //I want to unset all MSB till i-th bit
    int c=(n&((1<<(i+1))-1));
    printBinary(c);

    //Trick 4: Check If a number is a power of 2
    checkPowerOf2(n);
    return;
}
vector<vector<int>> subsets(vector<int>& nums) 
{
    int n=nums.size();
    vector<vector<int>>subsets;
    int subset_ct=(1<<n); //total 2^n or (1<<n) subsets
    for(int mask=0;mask<subset_ct;mask++) //each i represents a subset
    {
        vector<int>subset;
        for(int i=0;i<n;i++)  //checking particuler set bit for a subset
        {
            if((mask&(1<<i))!=0) //If the i-th bit is set that means curr subset includes nums[i] 
            {
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}
int mod=1e9+7;
int binaryExpr(int a,int b)
{
    if(b==0) return 1;
    int res=binaryExpr(a,b/2);
    if(b&1) //odd power
    {
        return (a*((res*1LL*res)%mod))%mod;
    }
    else
    {
        return (res*1LL*res)%mod;
    }
}
void solve(int tc)
{
    int n,k;
    cin>>n>>k;
    vi paints;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        paints.pb(d);
    }
    mii lastIdx;
    mii mxDist;
    mii secMxDist;
    for(int i=0;i<n;i++)
    {
        if(mxDist.find(paints[i])==mxDist.end())
        {
            mxDist[paints[i]]=i;
            lastIdx[paints[i]]=i;
        }
        else
        {
            if(mxDist[paints[i]]<i-1-lastIdx[paints[i]])
            {
                int t=mxDist[paints[i]];
                mxDist[paints[i]]=i-1-lastIdx[paints[i]];
                secMxDist[paints[i]]=max(t,secMxDist[paints[i]]);
            }
            else
            {
                secMxDist[paints[i]]=max(i-1-lastIdx[paints[i]],secMxDist[paints[i]]);
            }
            lastIdx[paints[i]]=i;
        }
    }
    for(auto it:lastIdx)
    {
        int key=it.F;
        int val=it.S;
        if(mxDist[key]<n-1-val)
        {
            int t=mxDist[key];
            mxDist[key]=n-1-val;
            secMxDist[key]=max(secMxDist[key],t);
        }
        else
        {
            // cout<<key<<" "<<mxDist[key]<<endl;
            secMxDist[key]=max(secMxDist[key],n-1-val);
        }
    }
    int ans=INT_MAX;
    for(auto it:mxDist)
    {
        int t=max((it.S)/2,secMxDist[it.F]);
        ans=min(ans,t);
        // cout<<it.first<<" "<<it.S<<"  "<<secMxDist[it.F]<<" "<<t<<endl;
    }
    cout<<ans<<endl;
    return;
}
void coder_pie()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int32_t main()
{
    coder_pie();
    int tests=1;
    cin>>tests;
    for(int tt=1;tt<=tests;tt++)
    {
        solve(tt);
    }
    return 0;
}

