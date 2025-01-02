// LUOGU_RID: 156770786
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=23;
ll s[N],len[N],t[N],oid[N];
ll f[1<<N],fr[1<<N],idx[1<<N],tim[1<<N],timk[1<<N];
// tim: 办理时间，timk: tim 在 tr[timk[i]] 之前 (<=)

ll tl[N],tr[N];

int ps[N],dt[N];

string binstr(int x){
    string s;
    for(int i=0;i<23;i++){
        s+=to_string((x>>i)&1);
    }
    return s;
}

int main(){
    // freopen("err.txt","w",stderr);
    int n,p;
    cin>>n>>p;
    vector<tuple<ll,ll,ll,ll>> v;
    for(int i=0;i<n;i++){
        int s,len,t;
        cin>>s>>len>>t;
        v.push_back({s,len,t,i});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        tie(s[i],len[i],t[i],oid[i])=v[i];
        // cerr<<"> "<<i<<" "<<s[i]<<" "<<len[i]<<" "<<t[i]<<" "<<oid[i]<<endl;
    }
    memset(f,0x3f,sizeof(f));
    for(int i=0;i<n;i++){
        tl[i]=s[i],tr[i]=s[i]+len[i]-1;
    }
    tl[n]=3e9;
    tr[n]=3e9;

    f[0]=1;
    if(tl[0]==1){
        cout<<"NO"<<endl;
        return 0;
    }

    // - 到访的时间晚于签证通过的时间
    for(int i=0;i<1<<n;i++){
        if(f[i]>3e9) continue;
        bool err=0;
        if((i|(1<<7)|(1<<5)|(1<<9)|(1<<8))==(1<<n)-1)err=1;
        // if(err)cerr<<"f "<<binstr(i)<<" "<<f[i]<<"  "<<fr[i]<<"  "<<idx[i]<<"  "<<tim[i]<<"  "<<timk[i]<<endl;
        for(int j=0;j<n;j++){
            if((i>>j)&1) continue;
            int i_=i|(1<<j);
            ll tim_=i?tim[i]+t[idx[i]]:1;
            ll l=tim_,r=tim_+t[j];
            int lk=0,rk=0;
            while(l<=tr[n-1]){
                while(l>tr[lk]) lk++;
                while(r>tr[rk]) rk++;
                // if(err)cerr<<"? "<<i<<" "<<j<<"  "<<l<<" "<<r<<"  "<<lk<<" "<<rk<<endl;
                if(l>=tl[lk]){
                    l=tr[lk]+1;
                    r=l+t[j];
                    if(err)cerr<<"continue1"<<endl;
                    continue;
                }
                int rk_=rk-(r<tl[rk]);
                // if(err)cerr<<"!! "<<r<<" "<<tl[rk]<<" "<<rk_<<endl;
                ll mask=(1<<(rk_+1))-(1<<lk);
                if(i_&mask){
                    l=tr[lk]+1;
                    r=l+t[j];
                    if(err)cerr<<"continue2"<<endl;
                    continue;
                }
                break;
            }
            // if(err)cerr<<"?? "<<i<<" "<<j<<"  "<<l<<" "<<r<<"  "<<lk<<" "<<rk<<endl;
            tim_=l;
            if(l>tr[n-1]) continue;
            if(rk-1>=j) continue;
            // if(err)cerr<<">> "<<i<<"->"<<i_<<" "<<j<<"   "<<tim_<<" "<<lk<<" "<<rk<<endl;
            if(f[i_]>tim_+t[j]){
                f[i_]=tim_+t[j];
                fr[i_]=i;
                idx[i_]=j;
                tim[i_]=tim_;
                timk[i_]=rk;
            }
        }
    }
    if(p==1){
        if(f[(1<<n)-1]>3e9){
            cout<<"NO"<<endl;
            return 0;
        }
        cout<<"YES"<<endl;
        for(int i=(1<<n)-1;i;i=fr[i]){
            ps[oid[idx[i]]]=1;
            dt[oid[idx[i]]]=tim[i];
        }
        for(int i=0;i<n;i++){
            cout<<ps[i]<<" "<<dt[i]<<endl;
        }
        return 0;
    }else{
        for(int p=0;p<1<<n;p++){
            int q=(1<<n)-1-p;
            if(f[p]>3e9||f[q]>3e9) continue;
            cout<<"YES"<<endl;
            for(int i=p;i;i=fr[i]){
                ps[oid[idx[i]]]=1;
                dt[oid[idx[i]]]=tim[i];
            }
            for(int i=q;i;i=fr[i]){
                ps[oid[idx[i]]]=2;
                dt[oid[idx[i]]]=tim[i];
            }
            for(int i=0;i<n;i++){
                cout<<ps[i]<<" "<<dt[i]<<endl;
            }
            return 0;
        }
        cout<<"NO"<<endl;
        return 0;
    }
    return 0;
}

