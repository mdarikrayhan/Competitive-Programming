#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void func(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    if(v[0]!=1){
        cout<<"No\n";
        return;
    }
    set<int>s;
    s.insert(1);
    for(int i=1;i<n;i++){
        int x = v[i];
        if(s.find(x) == s.end()){
            cout<<"No\n";
            return;
        }
        else{
            auto it = s.end();
            do{
                it--;
                int temp = *it + x;
                //cout<<temp<<"\n";
                if(temp<5001)s.insert(temp);
            }
            while(it!=s.begin());
        }
    }
    cout<<"Yes\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;

    while(t--) func();


    return 0;
}