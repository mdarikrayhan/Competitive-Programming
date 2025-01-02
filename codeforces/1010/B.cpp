#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
// typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;//for just using as a set
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;//for using multiset
//find by order=value at that index
//orderof key= gives index of that number // if number 7 not in the set but it will show the index number if it was there in sorted array.
//remember index is 0 based & if a number is already there then it will give the lowerbound
#define MAX 1e6+1
class disjointSet{
    vector<int> rank,parent,size;
public:
    disjointSet(int n){
        rank.resize(n+1,0);//for both 0based and 1 based indexing
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findupar(int node){//finds the ultimate parent//O(4alpha)==constant
        if(node==parent[node]){
            return node;
        }
        else{
            return parent[node]=findupar(parent[node]);
        }
    }
    void unionbyrank(int u,int v){//O(4alpha)==constant
        int ulpu=findupar(u);
        int ulpv=findupar(v);
        if(ulpv==ulpu){
            return;
        }
        if(rank[ulpu]<rank[ulpv]){
            parent[ulpu]=parent[ulpv];
        }
        else if(rank[ulpu]>rank[ulpv]){
            parent[ulpv]=parent[ulpu];
        }
        else{
            parent[ulpv]=parent[ulpu];
            rank[ulpu]++;
        }
    }
    void unionbysize(int u,int v){//O(4alpha)==constant
        int ulpu=findupar(u);
        int ulpv=findupar(v);
        if(ulpv==ulpu){
            return;
        }
        if(size[ulpu]<size[ulpv]){
            parent[ulpu]=ulpv;
            size[ulpv]+=size[ulpu];
        }
        else{
            parent[ulpv]=ulpu;
            size[ulpu]+=size[ulpv];
        }
    }
};
bool cmp(const pair<int, int>& a,const pair<int, int>& b){
    if (a.first != b.first)
        return (a.first < b.first);
    else
        return (a.second > b.second);
}
int mod_power(int x,int y,int m){//for calculating inverse through this check that m is prime x is indivisible by m and then a^(m-2)mod m=(a^-1)mod m
    int res=1;//put y=m-2 to get inverse mod
    while(y>0){
        if(y%2==1){
            res=(res*1LL*x)%m;
            y--;
        }
        else{
            x=(x*1LL*x)%m;
            y/=2;
        }
    }
    return res;
}
int bin_exp(int x,int y){//for calculating inverse through this check that m is prime x is indivisible by m and then a^(m-2)mod m=(a^-1)mod m
    int res=1;//put y=m-2 to get inverse mod
    while(y>0){
        if(y%2==1){
            res=(res*1LL*x);
            y--;
        }
        else{
            x=(x*1LL*x);
            y/=2;
        }
    }
    return res;
}
//vector<int> prime(MAX);
//void SieveOfEratosthenes(){
    //for(int i=2;i<MAX;i++){
        //prime[i]=1;
    //}
    //for (int p = 2; p * p <= MAX; p++) {
        //if (prime[p] == true) {
            //for (int i = p * p; i <= MAX; i += p)
                //prime[i] = false;
        //}
    //}
//}
//vector<int> smp(MAX);
//void spf(){
//	smp[0]=1;
//	for(int i=1;i<MAX;i++){
//		smp[i]=i;
//	}
//	for(int i=2;i*i<MAX;i++){
//		if(smp[i]==i){
//			for(int k=i*i;k<MAX;k=k+i){
//				if(smp[k]==k){
//					smp[k]=i;
//				}
//			}
//		}
//	}
//}
vector<int> dj(vector<vector<pair<int,int>>> &adj,int n,int src){
    vector<int> dist(n);
    int ans=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<n;i++) dist[i]=1e18;//length of dist array is equal to number of nodes in graph
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(dis!=dist[node]){
            continue;
        }
        for(auto it:adj[node]){
            int edgeweight=it.second;
            int adjnode=it.first;
            if(dis+edgeweight<dist[adjnode]){
                dist[adjnode]=dis+edgeweight;
                pq.push({dist[adjnode],adjnode});
            }
        }
    }
    return dist;
}
vector<int> bfs(vector<vector<int>> &adj,int n,int src){
    vector<int> dist(n,1e18);
    dist[src]=0;
    queue<int> q;
    vector<int> vis(n);
    vis[src]=1;
    q.push(src);
    while(!q.empty()){
        int a=q.front();q.pop();
        for(auto i:adj[a]){
            if(vis[i]==0){
                q.push(i);
                dist[i]=dist[a]+1;
                vis[i]=1;
            }
        }
    }
    return dist;
}
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
int count_relprime_till_l(int n,int l){//counts the number of relative prime numbers of n under l;
    vector<int> prime;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            prime.push_back(i);
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1){
        prime.push_back(n);
    }
    //prime vector contains prime factorization of n
    pair<int,int> p={0,0};
    int len=prime.size();
    for(int i=1;i<(1<<len);i++){// did this for subset making if(n==3) i= 001,010,011,100 and so on
        int mult=1;
        for(int j=0;j<len;j++){
            if(i&(1<<j)){
                mult*=prime[j];
            }
        }
        if(__builtin_popcount(i)%2==1){// built in function counts the number of set bits
            p.second+=l/mult;
        }
        else{
            p.first+=l/mult;
        }
    }
    return l-(p.second-p.first);//rel prime= l-(not rel prime)
}

int ask(int y){
    cout<<y<<endl;
    int z;
    cin>>z;
    return z;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin>>m>>n;
    vector<int> temp(n);
    bool flag=false;
    for(int i=0;i<n;i++){
        int z=ask(m);
        if(z==0){
            flag=true;
            break;
        }
        else{
            if(z==1){
                temp[i]=0;
            }
            else{
                temp[i]=1;
            }
        }
    }
    if(flag){
        exit(0);
    }
    int l=1,r=m+1,mid=l+(r-l)/2;
    int k=0;
    while(l+1<r){
        // cout<<l<<" "<<r<<endl;
        int z=ask(mid);
        if(z==0){
            exit(0);
        }
        if(temp[k]==0){
            z*=-1;
        }
        if(z==-1){
            r=mid;
        }
        else{
            l=mid;
        }
        mid=l+(r-l)/2;
        k++;k%=n;
    }
    int z=ask(l);
    if(z==0){
        exit(0);
    }
    return 0;
}