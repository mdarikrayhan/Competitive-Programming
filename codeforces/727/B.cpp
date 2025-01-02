#include<bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin>>s;
    s+='E';

    auto str2num=[&](string x) -> double {
        reverse(x.begin(),x.end());
        int len=0,fl=0;
        for(int i=0;i<x.size();i++){
            if(x[i]=='.'){
                if(len==2)fl=1;
            }else len++;
        }
        double res_d=0,res_i=0;
        if(fl){
            res_d=(x[0]-'0')*0.01+(x[1]-'0')*0.1;
            for(int i=x.size()-1;i>=2;i--){
                if(isdigit(x[i]))res_i=res_i*10+x[i]-'0';
            }
        }else{
            // res_d=x[0]*0.01+x[1]*0.1;
            for(int i=x.size()-1;i>=0;i--){
                if(isdigit(x[i]))res_i=res_i*10+x[i]-'0';
                // cerr<<i<<":"<<res_i<<" "<<res_d<<'\n';
            }
        }
        return res_d+res_i;
    };

    double ans=0.0;
    string tmp="";
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])||s[i]=='.')tmp.push_back(s[i]);
        else if(tmp.size()){
            // cerr<<"tmp:"<<tmp<<'\n';
            ans+=str2num(tmp);
            tmp="";
            // cerr<<"ans:"<<ans<<'\n';
        }
    }
    // cerr<<ans<<'\n';

    auto num2str=[&](double x) -> void {
        int q=(int)x;
        string r;
        int len=0;
        while(q){
            if(len==3)r.push_back('.'),len=0;
            r.push_back((char)(q%10+'0'));
            q/=10;
            len++;
        }
        reverse(r.begin(),r.end());
        if(!r.size())cout<<"0";
        else cout<<r;
        if(x-(int)x>=1e-2){  
            double p=x-(int)x;
            int q1=(int)(p*10)%10;
            int q2=(int)((round)(p*100))%10;
            cout<<"."<<q1<<q2<<'\n';
        }
    };

    num2str(ans);
}

signed main(){
    solve();
}