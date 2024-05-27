#include <bits/stdc++.h>
#define f first
#define s second
#define ent '\n'
#define int long long

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("Ofast,unroll-loops,fast-math,O3")

typedef long long ll;
using namespace std;
const int mod = 1e9+7;
const int mx = 1e5 + 12;

bool DEL[mx];
bool del[mx];
bool p[mx];
int a[mx];
int n, m, k, X;
int cnt;

int ask(int tp, int x){
    char c = 'A';
    if(tp == 1){
        c = 'B';
    }
    if(tp == 2){
        c = 'C';
    }
    cout << c << ' ' << x << endl;
    if(c == 'C'){
        exit(0);
    }
    int ans;
    cin >> ans;
    return ans;
}

void tup(){
    for(int i=2;i<=n;i++){
        ask(1, i);
    }
    for(int i=n;i>=1;i--){
        if(ask(0, i)){
            ask(2, i);
        }
    }
}

int upd(int x){
    int val = 0;
    for(int i=x;i<=n;i+=x){
        if(!del[i]){
            val++;
        }
        del[i]=1;
    }
    return val;
}

void solve(){
    vector<int> pq, pr;
    p[1] = 1;
    for(int i=2;i<=n;i++){
        if(!p[i]){
            if(i*i <= n){
                pq.push_back(i);
            }
            else{
                pr.push_back(i);
            }
            for(int j=i*2;j<=n;j+=i){
                p[j] = 1;
            }
        }
    }
    int q = 1;
    for(int i=0;i<pr.size();i+=100){
        int j = min((int)pr.size() - 1, i+99), cnt = ask(0, 1);
        for(int k=i;k<=j;k++){
            cnt -= upd(pr[k]);
            ask(1, pr[k]);
        }
        if(ask(0, 1) != cnt){
            for(int k=i;k<=j;k++){
                if(ask(0, pr[k])){
                    q = pr[k];
                    break;
                }
            }
            break;
        }
    }
    for(int x:pq){
        ask(1, x);
    }
    for(int x:pq){
        int t = x;
        while(t <= n && ask(0, t)){
            q *= x;
            t *= x;
        }
    }
    ask(2, q);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin >> t;
    while(t--){
        cin >> n;
        if(n <= 4500){
            tup();
        }
        else{
            solve();
        }
    }
}