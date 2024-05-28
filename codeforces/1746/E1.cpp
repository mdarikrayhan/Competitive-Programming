// LUOGU_RID: 160476440
#include <bits/stdc++.h>
using namespace std;
namespace Le0{
int n;
list<int> g;
int qry(list<int> s,list<int> t=list<int> ()){
    cout<<"? "<<s.size()+t.size()<<" ";
    for(int x:s) cout<<x<<" ";
    for(int x:t) cout<<x<<' ';
    cout<<endl;
    string res;cin>>res;
    return res=="YES"?1:0;
}
int main(){
    cin>>n;
    if(n==1){cout<<"! 1"<<endl;}
    for(int i=1;i<=n;i++) g.push_back(i);
    while(g.size()>3){
        int len=g.size();
        len/=4;
        list<int> s1,s2,s3,s4;
        for(int i=1;i<=len;i++){
            s1.push_back(g.front());
            g.pop_front();
        }
        for(int i=1;i<=len;i++){
            s2.push_back(g.front());
            g.pop_front();
        }
        for(int i=1;i<=len;i++){
            s3.push_back(g.front());
            g.pop_front();
        }
        while(g.size()){
            s4.push_back(g.front());
            g.pop_front();
        }
        // for(int x:s1) cout<<x<<" ";cout<<endl;
        // for(int x:s2) cout<<x<<" ";cout<<endl;
        // for(int x:s3) cout<<x<<" ";cout<<endl;
        // for(int x:s4) cout<<x<<" ";cout<<endl;
        int as1=qry(s1,s2),as2=qry(s2,s3);
        if(!as1&&as2){
            for(int x:s2) g.push_back(x);
            for(int x:s3) g.push_back(x);
            for(int x:s4) g.push_back(x);
        }
        if(!as1&&!as2){
            for(int x:s1) g.push_back(x);
            for(int x:s3) g.push_back(x);
            for(int x:s4) g.push_back(x);
        }
        if(as1&&!as2){
            for(int x:s1) g.push_back(x);
            for(int x:s2) g.push_back(x);
            for(int x:s4) g.push_back(x);
        }
        if(as1&&as2){
            for(int x:s1) g.push_back(x);
            for(int x:s2) g.push_back(x);
            for(int x:s3) g.push_back(x);
        }
    }
    int res=1,res2=2;
    if(g.size()==3){
        int x=g.front();g.pop_front();
        int y=g.front();g.pop_front();
        int z=g.front();g.pop_front();
        list<int> l,r;
        l.push_back(x);l.push_back(y);
        r.push_back(y);r.push_back(z);
        int as1=qry(l),as2=qry(r);
        if(!as1&&!as2) res=x,res2=z;
        else if(!as1&&as2) res=y,res2=z;
        else if(as1&&!as2) res=x,res2=y;
        else{
            l.clear();l.push_back(x);
            as1=qry(l);
            if(!as1){
                res=y,res2=z;
            }
            else{
                l.clear();l.push_back(z);
                as2=qry(l);
                if(!as2) res=x,res2=y;
                else res=x,res2=z;
            }
        }
    }
    if(res&&res2){
        list<int> s;
        s.push_back(res);
        cout<<"! "<<res<<endl;
        string as;cin>>as;
        if(as==":)") return 0;
        cout<<"! "<<res2<<endl;
        cin>>as;
    }
    else if(res) {
        cout<<"! "<<res<<endl;
        string as;cin>>as;
    }
    else{
        cout<<"! "<<res2<<endl;
        string as;cin>>as;
    }
    return 0;
}
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    return Le0::main();
}