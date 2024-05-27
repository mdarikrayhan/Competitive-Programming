// LUOGU_RID: 159159932
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,mod=1e9+7;
signed main()
{
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s; cin>>s;
    string a="",b="";
    bool ok=false;
    int numa=0,numb=0,sa=0,sb=0;
    auto make=[&](char x)->int{
        if(x>='A'&&x<='Z') return x-'A'+10;
        return x-'0';
    };
    for(auto c:s){
        if(!ok&&c!=':'){
            a+=c,sa=max(sa,make(c));
            if(c!='0') numa++;
        }
        else if(c==':') ok=true;
        else if(ok){
            b+=c,sb=max(sb,make(c));
            if(c!='0') numb++;
        }
    }
    if(sa>23||sb>59) return cout<<0,0;
    if(numa<=1&&numb<=1){
        bool check=false;
        if(numa&&a.back()=='0'||numb&&b.back()=='0') check=true;
        if(!check) return cout<<-1,0;
    }
    auto check=[&](string x,int z,int limit)->bool{
        int ans=0,len=x.length()-1;
        for(int i=0;i<=len;i++){
            ans+=pow(z,len-i)*make(x[i]);
            if(ans>limit) return false;
        }
        return true;
    };
    int should=max(sa,sb)+1;
    for(int i=should;i;i++){
        if(check(a,i,23)&&check(b,i,59)) cout<<i<<' ';
        else{
            if(i==should) cout<<0;
            return 0;
        }
    }
    return 0;
}
