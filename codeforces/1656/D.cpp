#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <map>
#include <bitset>
#include <stack>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <queue>
#define forn(i,aa,bb) for(int i=aa;i<=bb;++i)
#define LL long long 
using namespace std;
const int N=2e5+5;
const LL mod=998244353;
const LL MAXM=2e9;
LL n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        LL now=1,noww=n;
        while (noww%2==0) now<<=1,noww/=2;
        now*=2;
        if (now>MAXM || now*(now+1)/2>n) {
            now/=2;
            n=n/now;
            if (n==1) cout<<"-1\n";
            else cout<<n<<'\n';
        } 
        else cout<<now<<'\n';
    }
}
