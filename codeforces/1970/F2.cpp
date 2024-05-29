#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define nl "\n"
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<pair<ll,ll>> vpll;
#define pb push_back 
#define Sort(a) sort(a.begin(),a.end())
#define all(x) (x).begin(), (x).end()
const ll f = 1e9+7;
int n,m;
map<string,pii> pos;
int tme;
int scorer,scoreb;
map<string,bool> carry;
set<pii> rg,bg;

void move(string s,char move){
    int x=pos[s].first;
    int y=pos[s].second;
    if(move=='D'){
        x++;
    }
    if(move=='U'){
        x--;
    }
    if(move=='L'){
        y--;
    }
    if(move=='R'){
        y++;
    }
    pos[s]={x,y};
    if(carry[s]){
        
        pos[".Q"]={x,y};
    }
}

int ctch(string s,string s2){
    if(s2==".Q"){
        carry[s]=true;
        return 0;
    }
    else{
        if(s[0]=='R'){
            cout<<tme<<" "<<"RED CATCH GOLDEN SNITCH"<<nl;
            scorer+=10;

        }
        else{
            cout<<tme<<" "<<"BLUE CATCH GOLDEN SNITCH"<<nl;
            scoreb+=10;

        }
        return 1;
    }
}

void thrw(string s){
    carry[s]=false;
    if(rg.find(pos[".Q"])!=rg.end()){
        pos[".Q"]={(n+1)/2,(m+1)/2};
        cout<<tme<<" "<<"BLUE GOAL"<<nl;
        scoreb++;
    }
    else if(bg.find(pos[".Q"])!=bg.end()){
        pos[".Q"]={(n+1)/2,(m+1)/2};
        cout<<tme<<" "<<"RED GOAL"<<nl;
        scorer++;
    }
}
set<string> eli;
void check(){
    for(auto j:pos){
        string s=j.first;
        if(pos[s]==pos[".B"]){
            if(s[0]=='R' || s[0]=='B'){
                if(eli.find(s)==eli.end()){
                    cout<<tme<<" "<<s<<" "<<"ELIMINATED"<<nl;
                    eli.insert(s);
                }
            }
        }
    }
}
void solve(){
    scorer=0;
    scoreb=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            string s;
            cin>>s;
            if(s=="RG")rg.insert({i,j});
            else if(s=="BG")bg.insert({i,j});
            else
            pos[s]={i,j};
            // cout<<s<<" ";
        }
        // cout<<nl;

    }
    int t;
    cin>>t;
    for(tme=0;tme<t;tme++){

        string s;
        cin>>s;
        string y;
        cin>>y;
        if(y=="C"){
            string y2;
            cin>>y2;
            if(ctch(s,y2))break;
        }
        else if(y=="T"){
            thrw(s);
        }
        else{
            move(s,y[0]);
            // cout<<tme<<" "<<s<<" "<<pos[s].first<<" "<<pos[s].second<<nl;
            check();
        }
        
    }
    cout<<"FINAL SCORE: "<<scorer<<" "<<scoreb;

}                     
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
