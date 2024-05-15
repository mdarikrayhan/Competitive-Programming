#include <bits/stdc++.h>

#define endl "\n"
using namespace std;

typedef pair<int,int> PII;
const int N = 2e5+5;
int n;
int a[N];

int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x*f;
}


void solve(){
    int n,m;
    cin>>n>>m;
    if(n == 1 & m == 1){
        cout<<0<<endl;
        return;
    }
    if(n == 1 || m == 1){
        cout<<1<<endl;
    }
    else cout<<2<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin>>_;
    while(_--){
        solve();
    }
}
