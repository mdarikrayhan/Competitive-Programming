#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define endl '\n'
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--) 
#define fast_io ios_base::sync_with_stdio(0);
#define show(x) cout<<x<<endl;
#define pret(x) cout<<x<<endl; return 0;
#define disp(x) cout<<x<<" ";
#define let(x,y) cout<<x<<" "<<y<<endl;
ll MOD=1e9+7;
ll MAX=1e17;

map<string,vector<string> >ans;

string reverse(string a){
    int n=a.size();
    for (int i = 0; i < n/2; ++i)
    {
        swap(a[i],a[n-1-i]);
    }
    return a;
}

bool g(string a , string b){
    for (int i = 0; i < a.size(); ++i)
    {
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}

void f(string s,set<string>myset){
    vector<string> v,u;
    for(auto it=myset.begin();it!=myset.end();++it){
        string x=(*it);
        u.push_back(reverse(x));
    }
    sort(u.begin(),u.end());
    for (int i = 0; i < u.size(); ++i)
    {
        bool w=0;
        for (int j = i+1; j < u.size(); ++j)
        {
            if(g(u[i],u[j])) {
                w=1;
                break;
            }
        }
        if(!w) v.push_back(u[i]);
    }
    for (int i = 0; i < v.size(); ++i)
    {
        v[i] = reverse(v[i]);
    }
    ans[s]=v;
}

int main(){
    fast_io;
    int n;
    cin>>n;
    string s,y;
    map<string,set<string> >mymap;
    for (int i = 0; i < n; ++i)
    {
        cin>>s;
        int x;
        cin>>x;
        for (int j = 0; j < x; ++j)
        {
            cin>>y;
            mymap[s].insert(y);
        }
    }
    int counter=0;
    for(auto it=mymap.begin();it!=mymap.end();++it){
        f((*it).first,(*it).second);
        counter++;
    }
    show(counter);
    for(auto it=ans.begin();it!=ans.end();++it){
        disp((*it).first);
        vector<string> t = (*it).second;
        disp(t.size());
        for (int i = 0; i < t.size(); ++i)
        {
            disp(t[i]);
        }
        cout<<endl;
    }
    return 0;
}