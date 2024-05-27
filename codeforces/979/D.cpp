#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define xout cout << " "
#define xln cout << "\n"
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define F first
#define S second
#define ld long double
#define oo 100000 + 5
#define all(A) A.begin(), A.end()

const int M = 998244353;
ll powll(ll a, ll b, ll c = 0)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
            if (c)
                res %= c;
        }
        a *= a;
        if (c)
            a %= c;
        b >>= 1;
    }
    return res;
}
const ll N = 100000;
ll n, m, k, g, g1, g2,x;
struct trie{
    struct Node{
        int to[2]={-1,-1};
        int mn=oo;
    };
    vector<Node> nodes;
    int newnd(){
        nodes.pb(Node{});
        return nodes.size()-1;
    }
    void build(){
        nodes.clear();
        nodes.pb(Node{});
    }
    void insert(int x,int rt=0,int bt=20){
        if(nodes[rt].to[(x>>bt)&1]==-1){
            newnd();
            nodes[rt].to[(x>>bt)&1]=nodes.size()-1;
        }
        if(bt<0){
            nodes[rt].mn=x;
        }else{
        insert(x,nodes[rt].to[(x>>bt)&1],bt-1);
        nodes[rt].mn=min(nodes[rt].mn,nodes[nodes[rt].to[(x>>bt)&1]].mn);
        }
    }
    int check(int rt,int bt,int up,int xr){
        if(rt==-1||up<nodes[rt].mn)return -1;
        if(bt<0)return nodes[rt].mn;
        int x=check(nodes[rt].to[!((xr>>bt)&1)],bt-1,up,xr);
        if(x==-1){
            x=check(nodes[rt].to[((xr>>bt)&1)],bt-1,up,xr);
        }
        return x;
    }
};
trie T[100001];
vector<int> dev[100001];
int main(){
    for(int i=1;i<=100000;i++)T[i].build();
    for(int i=1;i<=100000;i++)
    for(int j=i;j<=100000;j+=i)dev[j].pb(i);
    int q;
    cin>>q;
    int ty,x,k,s,r,g;
    for(int i=0;i<q;i++){
        cin>>ty;
        if(ty==1){
            cin>>x;
            for(int d:dev[x])T[d].insert(x);
        }else{
            cin>>x>>k>>s;
            r=-1;
            for(int d:dev[x]){
                if(d%k!=0)continue;
                g=T[d].check(0,20,s-x,x);
                if(g==-1)continue;
                if(r==-1)r=g;
                else
                if((x^g)>(x^r)){
                    r=g;
                }
            }
            cout<<r;xln;
        }
    }
}