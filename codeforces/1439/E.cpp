// LUOGU_RID: 119432107
#include<bits/stdc++.h>
using namespace std;
int read(){char ch(getchar());int res(0);while(ch<48||ch>57)ch=getchar();while(ch>=48&&ch<=57)res=(res<<1)+(res<<3)+(ch^48),ch=getchar();return res;}
int n,m,q;
using pr=pair<int,int>;
map<int,vector<pr>> mp;
pair<bool,pr>get(pr p){
    if(!p.first&&!p.second)return {0,{-1,0}};
    if (!((p.first-1)&p.second))return {0,{p.first&~(p.second-1),p.second}};
    else return {1,{p.first,p.second&~(p.first-1)}};
}
inline int d(pr x){
	return x.first+x.second;
}
int main(){
    int m=read();bool rt=0;
    while(m--){
        pr v1,v2;v1.first=read(),v1.second=read(),v2.first=read(),v2.second=read();
        while (1){
            if(d(v1)==0&&d(v2)==0){rt=1;break;}
            int d1=get(v1).first,d2=get(v2).first;
            pr n1=get(v1).second,n2=get(v2).second;
            if(d1==d2&&n1==n2){
                int x1=d(v1),x2=d(v2);
				if(x1>x2) swap(x1,x2);
                mp[(d1?n1.first:n1.second)*2+d1].push_back({x1-1,x2});
                break;
            }
            if(d(n1)>d(n2))swap(n1,n2),swap(d1,d2),swap(v1,v2);
            mp[(d2?n2.first:n2.second)*2+d2].push_back({d(n2),d(v2)});
            v2=n2;
        }
    }
    map<int,bool>flip;
	if(rt)flip[0]^=1;
    for(auto &i:mp){
        sort(i.second.begin(),i.second.end());
		int cur=-1;
        for(auto &j:i.second){
            if(j.first>cur){
                if(cur>=0)flip[cur]^=1;
                flip[j.first]^=1;
            }
            cur=max(cur,j.second);
        }
        if(cur>=0)flip[cur]^=1;
    }
    int ans=0;
	for(auto &i:flip)if(i.second)++ans;
    cout<<ans<<endl;
    return 0;
}