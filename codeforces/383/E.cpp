#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ldb long double
#define pii pair<int,int>
#define mkp make_pair
#define mkt make_tuple
#define fr first
#define se second
#define uset unordered_set
#define umap unordered_map
#define pqueue priority_queue
#define all(_box) _box.begin(),_box.end()
#define ppc __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
#define lbd lower_bound
#define ubd upper_bound
#define deb(x) cerr<<#x<<'='<<(x)<<' '
using namespace std;
const int N=1e4+4;
const int L=1<<24;
int n;
int f[L+4];

void tran(){
    for(int o=1;o!=L;o<<=1)
        for(int i=0;i<L;i+=2*o)
            for(int j=0;j<o;j++)
                f[i+j+o]+=f[i+j];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        sort(all(s));
        int x=1<<(s[0]-'a');
        int y=1<<(s[1]-'a');
        int z=1<<(s[2]-'a');
        if(x==z)f[x]++;
        else if(x!=y&&y!=x){
            f[x]++,f[y]++,f[z]++;
            f[x|y]--,f[x|z]--,f[y|z]--;
            f[x|y|z]++;
        }
        else f[x]++,f[z]++,f[x|z]--;
    }
    tran();
    ll ans=0;
    for(int i=0;i<L;i++)
        ans^=1ll*f[i]*f[i];
    cout<<ans;
}