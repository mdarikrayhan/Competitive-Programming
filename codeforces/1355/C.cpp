#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define fi first
#define se second
//#define up unordered_map
#define us unordered_set
typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int,int> ii;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;


void solve() {
int a,b,c,d;
cin>>a>>b>>c>>d;
map<int,int> pairs;
for(int i=a+b;i<=b+c;i++){
    int l=max(a,i-c);
    int r=min(b,i-b);
    pairs[i]=r-l+1;
}
ll count=0;
for(auto &i:pairs){
    if(i.fi <= c) continue;
    ll temp=1ll*i.se*(min(i.fi-1,d)-c+1);
    count+=temp;
}
cout<<count<<endl;
}

int main(){
solve();
}


