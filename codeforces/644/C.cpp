#include <bits/stdc++.h>
using namespace std;
int n,t;
string s;
map <string, set <string> > mp;
map <set <string>, vector <string> > ans;
#define S it.second

int main()
{
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>s; s+='/';
        t=s.find('/',7);
        mp[s.substr(0,t)].insert(s.substr(t));
    }
    for(auto it : mp) ans[S].push_back(it.first);
    int kil=0;
    for(auto it : ans) if (S.size()>1) kil++;
    cout<<kil<<'\n';
    for(auto it : ans)
        if (S.size()>1){
            cout<<S[0];
            for(int i=1;i<S.size();++i) cout<<' '<<S[i];
            cout<<'\n';
        }
}