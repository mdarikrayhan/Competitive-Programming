#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define v vector 
#define pii pair<int,int>
#define IO {cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);}
#define LOOP(i,j) for(int i=0;i<j;i++) 
#define w(x) while(x--)
#define pb push_back

void solve(){
    ll t,x,y,m=INT_MAX;
    cin>>t>>x;
    v<ll> n;
    LOOP(i,t){
        cin>>y;n.pb(y);
        m=min(m,y);
    }
        sort(n.begin(),n.end(),greater<int>());
        ll val=0,i=0;
        while(n[i]-m>0){
            val+=n[i]-m;
            i++;
        }
        if(val>=x){
            cout<<m;
        }else{
            bool flag=false;
            x-=val;
            while(x>0&&!flag){
                x-=t;
                m--;
                if(m<0){
                    flag=true;
                }
            }
            if(flag){
                cout<<"-1";
            }else{
                cout<<m;
            }
        }
}

int main(){
    IO
    solve();
    return 0;
}