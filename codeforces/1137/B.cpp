// LUOGU_RID: 160032568
#include <bits/stdc++.h>
#define ull unsigned long long  
using namespace std;
typedef long long ll;

const int N = 5e5+10;
const int mod1=19491001;
const int mod2=993244853;
const int mod3=1e9+17;
const int p1=233;
const int p2=677;
const int p3=233;

string s1,s2,t;
ll pow1[N],pow2[N],pow3[N],hsh1[N],hsh2[N],hsh3[N];
int t1,t2,ntr;
int main() {
    cin>>s1>>s2;
    pow1[0]=1,pow2[0]=1,pow3[0]=1;
    for(int i=0;i<s2.size();++i){
        pow1[i+1]=pow1[i]*p1%mod1;
        pow2[i+1]=pow2[i]*p2%mod2;
        pow3[i+1]=pow3[i]*p3%mod3;
        hsh1[i+1]=(hsh1[i]*p1%mod1+(s2[i]-'0'+1)+mod1)%mod1;
        hsh2[i+1]=(hsh2[i]*p2%mod2+(s2[i]-'0'+1)+mod2)%mod2;
        hsh3[i+1]=(hsh3[i]*p3%mod3+(s2[i]-'0'+1)+mod3)%mod3;
    }
    for(int i=0;i<s1.size();++i){
        if(s1[i]=='0') t1++;
        if(s1[i]=='1') t2++;
    }
    // for(int i=1;i<=s2.size();++i){
    //     cout<<pow1[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=s2.size();++i){
    //     cout<<pow2[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=s2.size();++i){
    //     cout<<pow3[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=s2.size();++i){
    //     cout<<hsh1[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=s2.size();++i){
    //     cout<<hsh2[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=s2.size();++i){
    //     cout<<hsh3[i]<<" ";
    // }
    // cout<<endl;
    for(int i=1;i<s2.size();++i){
        if(hsh1[i]==(((hsh1[s2.size()]-hsh1[s2.size()-i]*pow1[i])%mod1+mod1))%mod1&&hsh2[i]==(((hsh2[s2.size()]-hsh2[s2.size()-i]*pow2[i])%mod2+mod2))%mod2&&hsh3[i]==(((hsh3[s2.size()]-hsh3[s2.size()-i]*pow3[i])%mod3+mod3))%mod3){
            ntr=max(ntr,i);
        }
    }
    // cout<<ntr<<endl;
    for(int i=ntr;i<s2.size();++i){
        t+=s2[i];
    }
    string ans;
    int pos=0;
    while(ans.size()<s1.size()){
        if(t1==0){
            while(t2){
                t2--;
                ans+='1';
            }
            goto end;
        }
        if(t2==0){
            while(t1){
                t1--;
                ans+='0';
            }
            goto end;
        }
        if(ans.size()<s2.size()){
            if(s2[ans.size()]=='1') t2--;
            if(s2[ans.size()]=='0') t1--;
            ans+=s2[ans.size()];
        }
        else{
            if(t[pos]=='0') t1--;
            if(t[pos]=='1') t2--;
            ans+=t[pos];
            pos=(pos+1)%t.size();
        }
    }
    end:;
    cout<<ans;
    return 0;
}