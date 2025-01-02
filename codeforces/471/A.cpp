#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define v vector 
#define IO {cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);}
#define pb push_back
#define LOOP(i,j) for(int i=0;i<j;i++)
#define w(x) while(x--)
#define pii pair<int,int>

void solve(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    v<int> n={a,b,c,d,e,f};
    sort(n.begin(),n.end());
    if(n[0]==n[1]&&n[2]==n[3]&&n[1]==n[2]){
        if(n[4]==n[5]){
            cout<<"Elephant";
        }else{
            cout<<"Bear";
        }
    }else if(n[2]==n[3]&&n[4]==n[5]&&n[3]==n[4]){
        if(n[0]==n[1]){
            cout<<"Elephant";
        }else{
            cout<<"Bear";
        }
    }else if(n[1]==n[2]&&n[3]==n[4]&&n[2]==n[3]){
        if(n[0]==n[5]){
            cout<<"Elephant";
        }else{
            cout<<"Bear";
        }
    }else{
        cout<<"Alien";
    }
}

int main(){
    IO 
    solve();
    return 0;
}