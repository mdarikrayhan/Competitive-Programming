// LUOGU_RID: 160582172
#include<bits/stdc++.h>
using namespace std;
const int mn=233;
int t,h;
int k,x[5];
int ans;
bool iss[mn];

void ask(int p){
    iss[p]=true;
    cout<<"? "<<p<<endl;
    fflush(stdout);
    cin>>k;
    for(int i=1;i<=k;i++) cin>>x[i];
}

int dfs(int p,int hp,int rl){   //当前节点，希望深度，实际深度，距离上一次明确深度节点的 dis
    int pk,px[5];
    ask(p);
    if(k==2){
        ans=p;
        return 0;
    }
    if(k==1) return h-1;
    if(hp==1) return 0;
    pk=k;for(int i=1;i<=k;i++) px[i]=x[i];
    int pget=0;
    bool isto=0;
    for(int i=1;i<=pk;i++) if(!iss[px[i]]){
        if(isto && rl){
            if(hp==2){
                ans=px[i];
                return 0;
            }
            pget=dfs(px[i],hp-1,hp-1);
        }
        else pget=dfs(px[i],hp-1,0);
        if(ans) return 0;
        if(pget==hp) rl=hp;
        else if(pget) return pget-1;
        isto=true;
    }
    return 0;
}

void bfs(){
    memset(iss,0,sizeof(iss));
    ans=0;
    ask(1);
    if(k==2){
        ans=1;
        return;
    }
    if(k==1){
        dfs(x[1],h-1,h-1);
        return;
    }

    int rt1=x[1],pt1=x[1],rt2=x[2],pt2=x[2],lst=x[3],tim=0;
    bool is1=false,is2=false;
    for(tim=1;true;tim++){
        ask(pt1);
        if(k==2){
            ans=pt1;
            return;
        }
        if(k==1) is1=true;
        else{
            if(!iss[x[1]]) pt1=x[1];
            else pt1=x[2];
        }

        ask(pt2);
        if(k==2){
            ans=pt2;
            return;
        }
        if(k==1) is2=true;
        else{
            if(!iss[x[1]]) pt2=x[1];
            else pt2=x[2];
        }
        if(is1 || is2) break;
    }
    memset(iss,0,sizeof(iss));
    iss[1]=true;
    if(is1 && is2) dfs(lst,h-tim-1,h-tim-1);
    else if(is1) dfs(rt2,h-tim-1,h-tim-1);
    else dfs(rt1,h-tim-1,h-tim-1);
}

int main(){
    cin>>t;
    while(t--){
        cin>>h;
        bfs();
        cout<<"! "<<ans<<endl;
        fflush(stdout);
    }

    return 0;
}