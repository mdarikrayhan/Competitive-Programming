// LUOGU_RID: 159040456
#include<bits/stdc++.h>

using namespace std;
char s[200005];
int al[200005],ar[200005],ans;
int cnt[35],mm;
bool check(int x,int y){
    cnt[x]--;cnt[y]--;mm-=2;
    bool pd=true;
    for(int i=0;i<26;i++)
        if(cnt[i]*2>mm+1){
            pd=false;
            break;
        }
    cnt[x]++;cnt[y]++;mm+=2;
    return pd;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        int n=strlen(s+1);
        vector<int>vt;
        for(int i=1;i<n;i++)
            if(s[i]==s[i+1])vt.push_back(i);
        int m=vt.size(),x=0;mm=vt.size();ans=0;
        for(int i=0;i<26;i++)cnt[i]=0;
        for(auto y:vt)cnt[s[y]-'a']++;
        for(int i=0;i<26;i++)
            if(cnt[i]>cnt[x])x=i;
        int dl=0;stack<pair<int,int> > st;
        if(cnt[x]*2>=m-1){
            for(auto y:vt){
                int rl=y-dl;
                if(st.empty())st.push({y,rl});
                else {
                    bool pd1=(s[y]-'a'==x),pd2=(s[st.top().first]-'a'==x);
                    if(pd1^pd2){
                        al[++ans]=st.top().second+1;ar[ans]=rl;
                        dl+=ar[ans]-al[ans]+1;
                        st.pop();
                    }
                    else st.push({y,rl});
                }
            }
        }
        else {
            for(auto y:vt){
                int rl=y-dl;
                if(st.empty())st.push({y,rl});
                else {
                    int r=s[y]-'a',l=s[st.top().first]-'a';
                    if(l!=r&&check(l,r)){
                        cnt[l]--;cnt[r]--;mm-=2;
                        al[++ans]=st.top().second+1;ar[ans]=rl;
                        dl+=ar[ans]-al[ans]+1;
                        st.pop();
                    }
                    else st.push({y,rl});
                }
            }
        }
        int rev=n-dl;
        // cerr<<"!!"<<rev<<" "<<dl<<endl;
        while(!st.empty()){
            auto [y,rl]=st.top();st.pop();
            al[++ans]=rl+1;ar[ans]=rev;
            rev-=ar[ans]-al[ans]+1;
        }
        al[++ans]=1;ar[ans]=rev;
        printf("%d\n",ans);
        for(int i=1;i<=ans;i++)printf("%d %d\n",al[i],ar[i]);
    }
    return 0;
}