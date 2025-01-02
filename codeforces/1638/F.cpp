#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<int> vi;
typedef pair<int,int> pi;

const int N=10005;
int n,h[N];
int pre[N], suf[N];
int f0[N], f1[N];

signed main(){
    #ifndef ONLINE_JUDGE
    assert(freopen(".in","r",stdin));
    // assert(freopen(".out","w",stdout));
    #endif
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n;
    rep(i,1,n){
        cin>>h[i];
    }
    int ans=0;
    rep(i,1,n){
        int mn=h[i];
        rep(j,i,n){
            mn=min(mn, h[j]);
            f0[j]=max(f0[j], mn*(j-i+1));
            f1[i]=max(f1[i], mn*(j-i+1));
        }
    }
    rep(i,1,n){
        f0[i]=max(f0[i], f0[i-1]);
        ans=max(ans, f0[i]+f1[i+1]);
    }

    rep(i,2,n-1){
        int mn=h[i];
        rep(j,i,n-1){
            mn=min(mn, h[j]);
            if(h[i-1]>=mn || h[j+1]>=mn){
                continue;
            }
            // tot++;
            memset(pre, 0, sizeof(pre));
            memset(suf, 0, sizeof(suf));
            suf[i-1]=h[i-1];
            per(k,i-2,1){
                suf[k]=min(suf[k+1], h[k]);
            }
            pre[j+1]=h[j+1];
            rep(k,j+2,n){
                pre[k]=min(pre[k-1], h[k]);
            }
            
            function<void()> calc0=[&](){
                vector< array<int,3> > info;
                per(k,n,j+1){
                    if(k<n && pre[k]==pre[k+1]){
                        continue;
                    }
                    info.pb({k, pre[k], (k-i+1)*pre[k]});
                }
                rep(i,1,(int)info.size()-1){
                    info[i][2]=max(info[i][2], info[i-1][2]);
                }
                int idx=0;
                per(k,i-1,1){
                    while(idx<(int)info.size() && suf[k]+info[idx][1]<=mn){
                        idx++;
                    }
                    if(idx!=0){
                        ans=max(ans, suf[k]*(j-k+1)+info[idx-1][2] );
                    }
                    if(idx!=(int)info.size()){
                        ans=max(ans, suf[k]*(j-k+1)+(mn-suf[k])*(info[idx][0]-i+1) );
                    }
                }
            };
            function<void()> calc1=[&](){
                vector< array<int,3> > info;
                rep(k,1,i-1){
                    if(k>1 && suf[k]==suf[k-1]){
                        continue;
                    }
                    info.pb({k, suf[k], (k-i+1)*suf[k]});
                }
                rep(i,1,(int)info.size()-1){
                    info[i][2]=max(info[i][2], info[i-1][2]);
                }
                int idx=0;
                rep(k,j+1,n){
                    while(idx<(int)info.size() && pre[k]+info[idx][1]<=mn){
                        idx++;
                    }
                    if(idx!=0){
                        ans=max(ans, pre[k]*(k-i+1)+info[idx-1][2] );
                    }
                    if(idx!=(int)info.size()){
                        ans=max(ans, pre[k]*(k-i+1)+(mn-pre[k])*(j-info[idx][0]+1) );
                    }
                }
            };
            function<void()> calc2=[&](){
                vi info;
                int p0=i-1, p1=j+1;
                rep(_,1,n-(j-i+1)){
                    if(suf[p0]>=pre[p1]){
                        info.pb(suf[p0--]);
                    }
                    else{
                        info.pb(pre[p1++]);
                    }
                }
                rep(k,0,(int)info.size()-1){
                    ans=max(ans, (j-i+1)*(mn-info[k])+(j-i+2+k)*info[k] );
                }
            };
            calc0();
            calc1();
            calc2();
        }
    }
    cout<<ans<<'\n';
}