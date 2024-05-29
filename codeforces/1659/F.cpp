#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=200010;
int n,s,head[N],ver[N<<1],ne[N<<1],idx=2;
void add(int x,int y){
    ver[idx]=y,ne[idx]=head[x],head[x]=idx++;
}
int deg[N],a[N];
bool vis[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;cin>>T;
    while(T--){
        cin>>n>>s;
        for(int i=1;i<n;i++){
            int x,y;cin>>x>>y;
            add(x,y),add(y,x);
            deg[x]++,deg[y]++;
        }
        for(int i=1;i<=n;i++)cin>>a[i];
        int rt=0;
        for(int i=1;i<=n;i++)
            if(deg[i]>1){
                if(rt){
                    rt=-1;
                }
                else{
                    rt=i;
                }
            }
        bool ok=1;
        for(int i=1;i<=n;i++)ok&=(a[i]==i);
        if(rt==-1||ok){
            cout<<"Alice\n";
        }
        else{
            auto check=[&](){
                bool ok=1;
                for(int i=1;i<=n;i++)ok&=(a[i]==i);
                if(ok){
                    cout<<"Alice\n";
                }
                else if(a[rt]!=rt){
                    cout<<"Bob\n";
                }
                else{
                    for(int i=1;i<=n;i++)vis[i]=0;
                    int c=0;
                    for(int i=1;i<=n;i++)
                        if(!vis[i]){
                            int x=i;vis[x]=1;x=a[x];
                            while(!vis[x]){
                                c++;
                                vis[x]=1;
                                x=a[x];
                            }
                        }
                    cout<<((c&1)?"Alice\n":"Bob\n");
                }
            };
            if(s==rt){
                check();
            }
            else{
                if(a[rt]!=rt){
                    int x=0;
                    for(int i=1;i<=n;i++)
                        if(a[i]==rt)x=i;
                    if(a[rt]==s){
                        cout<<"Bob"<<'\n';
                    }
                    else{
                        swap(a[rt],a[x]);
                        check();
                    }
                }
                else{
                    if(n==3){
                        cout<<"Bob\n";
                    }
                    else{
                        // if(n==83890){
                        //     cout<<"RT "<<rt<<' '<<s<<'\n';
                        //     for(int i=1;i<=n;i++){
                        //         if(a[i]!=i){
                        //             cout<<i<<' '<<a[i]<<'\n';
                        //         }
                        //     }
                        //     cout<<"WWWWWWWWW\n";
                        // }
                        int c=0;
                        for(int i=1;i<=n;i++)
                            if(a[i]!=i){
                                c++;
                            }
                        if(c==2&&a[s]==s){
                            cout<<"Alice\n";
                        }
                        else{
                            for(int i=1;i<=n;i++)
                                if(i!=rt&&i!=s){
                                    for(int j=i+1;j<=n;j++)
                                        if(j!=rt&&j!=s){
                                            swap(a[i],a[j]);
                                            break;
                                        }
                                    break;
                                }
                            check();
                        }
                    }
                }
            }
        }

        idx=2;
        for(int i=1;i<=n;i++){
            head[i]=deg[i]=0;
        }

    }

    return 0;
}