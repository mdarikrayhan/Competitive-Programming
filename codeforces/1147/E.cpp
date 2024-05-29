#include<bits/stdc++.h>
using namespace std;
#define N 100100
vector<pair<int,int>>qq;
string s;
void ask(){
    if(qq.empty()){
        s="";
        return;
    }
    cout<<"Q "<<qq.size()<<" ";
    for(auto a:qq)cout<<a.first<<" "<<a.second<<" ";
    cout<<endl;
    cin>>s;
}
bool conNext[N];
int n;
vector<int>adj[N][2];
int blockAns[N];
vector<int>buk[3];
void solve(){
    for(int a=0;a<n;++a){
        adj[a][0].clear();
        adj[a][1].clear();
    }
    cin>>n;
    qq.clear();
    for(int a=1;a+1<=n;a+=2)qq.push_back({a,a+1});
    ask();
    for(int a=0;a<qq.size();++a){
        int u=2*a+1,v=2*a+2;
        conNext[u]=s[a]=='1';
    }
    qq.clear();
    for(int a=2;a+1<=n;a+=2)qq.push_back({a,a+1});
    ask();
    for(int a=0;a<qq.size();++a){
        int u=2*a+2,v=2*a+3;
        conNext[u]=s[a]=='1';
    }
    qq.clear();
    vector<int>block;
    for(int a=1;a<=n;++a){
        block.push_back(a);
        int i=a;
        while(i<n&&conNext[i])++i;
        a=i;
    }
    if(block.size()==1){
        cout<<"A "<<n<<" 0 0"<<endl;
        for(int a=1;a<=n;++a)cout<<a<<" ";cout<<endl<<endl<<endl;
        return;
    }
    for(int a=0;a+2<block.size();++a){
        if(a%4<=1){
            qq.push_back({block[a],block[a+2]});
        }
    }
    ask();
    qq.clear();
    string s1=s;
    for(int a=0;a+2<block.size();++a){
        if(a%4>1){
            qq.push_back({block[a],block[a+2]});
        }
    }
    ask();
    string s2=s;
    auto getNext=[&](int i)->bool{
        return ((i&3)<=1?s1[2*(i/4)+(i&1)]:s2[2*(i/4)+(i&1)])=='1';
    };
    blockAns[0]=0,blockAns[1]=1;
    for(int a=2;a<block.size();++a){
        if(getNext(a-2))blockAns[a]=blockAns[a-2];
        else blockAns[a]=3-blockAns[a-2]-blockAns[a-1];
    }
    buk[0].clear();buk[1].clear();buk[2].clear();
    for(int a=0;a<block.size();++a){
        int rp=(a+1==block.size()?n:block[a+1]-1);
        for(int b=block[a];b<=rp;++b){
            buk[blockAns[a]].push_back(b);
        }
    }
    cout<<"A "<<buk[0].size()<<" "<<buk[1].size()<<" "<<buk[2].size()<<endl;
    for(int a=0;a<3;++a){
        for(auto b:buk[a])cout<<b<<" ";
        cout<<endl;
    }
}
signed main(){
    iostream::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    for(int a=0;a<t;++a)solve();
}