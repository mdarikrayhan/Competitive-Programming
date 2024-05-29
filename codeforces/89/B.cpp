#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
map<string,int> d;
int border[105]={};
int spacing[105]={};
string name;
vector<vector<int>> e(205);
int deg[105]={};
map<pair<int,int>,int> simp;
string s;
int w[105]={};
int h[105]={};
int type[105]={};
bool vis[105]={};
void dfs(int u){
    int bruh=0;
    vis[u]=1;
    for (auto v:e[u]){
        if (!vis[v])dfs(v);
        if (type[u]==1){
            h[u]=max(h[v],h[u]);
            w[u]+=w[v]*simp[{u,v}];
        }
        else{

             w[u]=max(w[v],w[u]);
                h[u]+=h[v]*simp[{u,v}];
        }
        bruh+=simp[{u,v}];
    }
    if (bruh){
        w[u]+=border[u]*2;
        h[u]+=border[u]*2;
    }
    if (type[u]==1) w[u]+=max((long long)0,(bruh-1))*spacing[u];
    else h[u]+=max((long long)0,(bruh-1))*spacing[u];
    return;
}
map<string,int> added;
signed main(){
    cin>>n;
    int cnt=0;
    for (int i=1;i<=n;i++){
        cin>>s;
        if (s=="HBox" or s=="VBox"){
            cin>>name;
            d[name]=++cnt;

            if (s=="HBox") type[cnt]=1;
            else type[cnt]=2;
            border[cnt]=spacing[cnt]=0;
        }
        else if (s=="Widget"){
            cin>>name;
            string x="";
            int j=0;
            for (;j<name.size();j++){
                if (name[j]=='(') break;
                x+=name[j];
            }
            d[x]=++cnt;
            j++;
            int num=d[x];
            for (;j<name.size();j++){
                if (name[j]==',') break;
                w[num]=w[num]*10+name[j]-48;
            }
            j++;
            for (;j<=name.size();j++){
                if (name[j]==')') break;
                h[num]=h[num]*10+name[j]-48;
            }

        }
        else{
            name="";
            int j=0;
            for (j=0;j<s.size();j++){
                if (s[j]=='.') break;
                name+=s[j];
            }
            j++;
            string tt="";
            for (;j<s.size();j++){
                if (s[j]=='(') break;
                tt+=s[j];
            }
            j++;
            string val="";
            int so=0;
            for (;j<s.size();j++){
                if (s[j]==')') break;
                val+=s[j];
                so=so*10+(s[j]-48);
            }
            int num=d[name];
            if (tt=="pack"){
                int num_2=d[val];
                deg[num_2]++;
                if (!simp[{num,num_2}])e[num].push_back(num_2);
                simp[{num,num_2}]++;
            }
            else{
                if (tt=="set_spacing") spacing[num]=so;
                else border[num]=so;
            }
        }
    }
    for (int i=1;i<=cnt;i++) if (deg[i]==0) dfs(i);
    for (auto i:d){
        cout<<i.first<<" "<<w[i.second]<<" "<<h[i.second]<<endl;
    }


}
