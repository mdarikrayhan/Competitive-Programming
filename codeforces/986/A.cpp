#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define N 200005
#define pb push_back
#define pl pair<ll,ll> 
vector<ll>pinv{838709685,129032259};
ll mod=1e9+7;
/***extended euclidean***/
ll exgcd(ll a,ll b,ll&x,ll&y)
{
    if(a>b)
    {
        return exgcd(b,a,y,x);
    }
    if(a==0)
    {
        x=0,y=1;
        return b;
    }
    ll x1,y1;
    ll ans=exgcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return ans; 
}
 
/***modulo expo***/
ll pw(ll x,ll n,ll m)
{
    ll res=1;
    while(n>0)
    {
        if(n % 2 ==1)
        res=(res * x)%m;
        x=(x*x)%m;
        n=n/2;
    }
    return res;
}
/***modular arithmetic***/
ll modm(ll a,ll b,ll m) {return ((a%m)*(b%m))%m;}
ll mods(ll a,ll b,ll m) {return (a%m-b%m+m)%m;}
ll moda(ll a,ll b,ll m) {return (a%m+b%m)%m;}
ll modinverse(ll A,ll M)
{
    return pw(A,M-2,M) % M;
}
/***mex of an array***/
ll mex(vector<ll>&ans,ll n)
{
	ll c=0,i;
	sort(ans.begin(),ans.end());
	for(i=0;i<n;i++)
	{
		if(ans[i]>c)
		return c;
		else if(ans[i]==c)
		c++;
	}
	return c;
}
 
/***precomputations***/
ll fact[N],invfact[N];
/**factorials**/
void pre1()
{
    fact[0]=1;
    for(ll i=1;i<N;i++)
    {
    fact[i]=(fact[i-1]*i);
    fact[i]%=mod;
    }
    invfact[N-1]=modinverse(fact[N-1],mod);
    for(ll i=N-2;i>=0;i--)
    {
        invfact[i]=invfact[i+1]*(i+1);
        invfact[i]%=mod;
    }
}
 
 
/***fermat's little theorem***/
ll ncr(ll n,ll r) // % mod;
{
    if(n < r) return 0; 
    ll v  = (fact[n] * invfact[n-r]) % mod;
    v = (v * invfact[r]) % mod;
    return v;
}
//solving...
// struct Node{
//     Node* links[2];
//     int cnt[2];
//     Node(){
//         cnt[0] = cnt[1] = 0;
//         links[0] = links[1] = NULL;
//     }
//    bool containsKey(int bit){
//       return (links[bit]!=nullptr);
//    }
//    Node* get(int bit){
//       return links[bit];
//    }
//    void put(int bit, Node* node){
//       links[bit] = node;
//       node->cnt[bit]++;
//    }
// };
// class Trie{
//    Node* root;
//    public:
//    Trie(){
//       root = new Node();
//    }
//    void insert(int a){
//       Node* node = root;
//       for(int i = 30; i >= 0; i--){
//          int bit = ((a & (1 << i)) > 0);
//          if(!node->containsKey(bit))
//         { node->put(bit, new Node());
//          node = node -> get(bit);
//         }
//         else
//         {
//             node = node -> get(bit);
//             node->cnt[bit]++;
//         }
//       }
//    }
//    int getMAX(int a){

//       Node* node = root;
//       int res = 0;
//       for(int i = 30; i >= 0; i--){
//          int bit = ((a & (1 << i)) > 0);
//          if(node->containsKey(bit)&&node->cnt[bit]>1)
//             res |= (bit*(1 << i)),node = node->get(bit);
//          else
//          { 
//             node = node->get(1-bit);
//             res|=(1-bit)*(1<<i);
//          }
//       }return res;
//    }
// };
    // class Node{
    //     public:
    //     Node*links[2];
    //     int ind=-1;
    //     bool hasbit(int bit)
    //     {return (links[bit]!=NULL);}
    //     Node*get(int bit)
    //     {return links[bit];}
    //     void put(int bit,Node*node){
    //         links[bit]=node;
    //     }
    // };
    // class trie{
    //     Node*root;
    //     public:
    //         trie()
    //         {   
    //         root=new Node();
    //         }
    //         void insert(int num,int ind){
    //             Node*node=root;
    //             for(int i=31;i>=0;i--){
    //                 int bit=((1<<i)&num)==0?0:1;
    //                 if(!node->hasbit(bit))
    //                 node->put(bit,new Node());
    //                 node=node->get(bit);
	// 				node->ind=ind;
    //             }
    //         }
    //         int getres(int curr,int ele,int x)
    //         {
	// 			Node*node=root;
	// 			int res=1e9,xorr=0;
	// 			for(int i=31;i>=0;i--)
	// 			{
	// 				int bit=((1<<i)&ele)==0?0:1;
	// 				int bit2=((1<<i)&x)==0?0:1;
	// 				if(node->hasbit(1-bit))
	// 				{
	// 					node=node->get(1-bit);
	// 					xorr|=bit2*(1<<i);
	// 					if(!bit2)
	// 					res=min(res,abs(curr-node->ind));
	// 					if(xorr>=x)
	// 					res=min(res,abs(curr-node->ind));
	// 				}
	// 				else if(!bit2)
	// 				{
	// 					node=node->get(bit);
	// 					if(xorr>=x)
	// 					res=min(res,abs(curr-node->ind));
	// 				}
	// 				else break;
	// 			}
	// 			return res;
    //         }

    // };
// class hashing
// {
//     public:
//     int n;
//     vector<ll>primes{(1000000009)*1LL,(1000000007)*1LL};
//     vector<vector<ll>>inv;
//     const ll p=31;
//     vector<vector<ll>>hashes;
//     vector<vector<ll>>powers;
//     hashing(string a)
//     {
//         n=a.size();
//         int k=primes.size();
//         powers.resize(k);
//         hashes.resize(k);
//         inv.resize(k);
//         for(int i=0;i<k;i++)
//         {
//             powers[i].resize(n+1);
//             powers[i][0]=1;
//             for(int j=1;j<=n;j++)
//             powers[i][j]=(powers[i][j-1]*p)%primes[i];
//         }
//         for(int i=0;i<k;i++)
//         {
//             inv[i].resize(2*n+2);
//             inv[i][0] = 1;
//             for(int j = 1;j<=2*n+1; ++j)
//             inv[i][j]=(pinv[i]*inv[i][j-1])%primes[i];
//         }
//         for(int i=0;i<k;i++)
//         {
//             hashes[i].resize(n);
//             hashes[i][0]=a[0]-97+1;
//             for(int j=1;j<n;j++)
//             {
//                 int fac=a[j]-97+1;
//                 hashes[i][j]=(hashes[i][j-1]+fac*powers[i][j])%primes[i]; 
//             }
//         }
//     }
//     vector<ll>substr_hash(int l,int r)
//     {
//         int k=primes.size();
//         vector<ll>hash(k);
//         for(int i=0;i<k;i++)
//         {
//             ll a=hashes[i][r],b=l==0?0LL:hashes[i][l-1];
//             ll diff=a-b;
//             diff=diff%primes[i];
//             diff=(diff+primes[i])%primes[i];
//             ll d=powers[i][l];
//             ll res=(diff*inv[i][l])%primes[i];
//             hash[i]=res;
            
//         }
//         return hash;
//     }
//     bool cmp(int l1, int r1, int l2, int r2){ // use this for comparing strings faster
//         int k=primes.size();
//         if(l1 > l2){
//             swap(l1, l2);
//             swap(r1, r2);
//         }
//         for(int i = 0; i <k; i++){
//             ll val1 = mods(hashes[i][r1], (l1 > 0 ? hashes[i][l1 - 1] : 0LL), primes[i]);
//             ll val2 = mods(hashes[i][r2], (l2 > 0 ? hashes[i][l2 - 1] : 0LL), primes[i]);
//             if(modm(val1, powers[i][l2 - l1], primes[i]) != val2)
//                 return false;
//         }   
//         return true;
//     }
    
vector<vector<int>>g;
vector<int>v;
vector<vector<ll>>dis;
ll n,m,k,s;
void f(int k){
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(v[i]!=k)continue;
        dis[i][k]=0;
        q.push(i);
    }
    while(q.size())
    {
        int node=q.front();
        q.pop();
        for(auto&i:g[node])
        {
            if(dis[i][k]<=1+dis[node][k])continue;
            dis[i][k]=1+dis[node][k];
            q.push(i);
        }
    }
}
void solve()
{
    cin>>n>>m>>k>>s;
    g.assign(n+1,vector<int>());
    v.assign(n+1,0);
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=0;i<m;i++)
    { 
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dis.assign(n+1,vector<ll>(k+1,1e18));
    for(int i=1;i<=k;i++)f(i);

    for(int i=1;i<=n;i++)
    {
        priority_queue<int>pq;
        for(ll j=1;j<=k;j++)pq.push(-1*dis[i][j]);
        int res=0,c=s;
        while(c--)
        {
            res+=pq.top();
            pq.pop();
        }
        cout<<-1LL*res<<" ";
    }
    cout<<endl;


}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    while(t--)
    solve();
}