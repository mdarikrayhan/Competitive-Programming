#include <bits//stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define V vector
#define VI V<int>
#define VL V<ll>
#define VP V<pair<int,int>>
#define rep(i, a, b, step) for (int i = int(a); i <= int(b); i+=step)
#define repl(i,a,b,step) for(int i=int(a);i>=int(b);i-=step)
#define sn <<'\n'
#define ed <<endl
#define sz size()
#define print cout<<
#define mpII map<int,int>
#define mine min_element
#define maxe max_element
#define mpIV map<int,VI>
#define mpLL map<ll,ll>
#define all(v) begin(v),end(v)
#define pb push_back
#define pq priority_queue
#define rev reverse
#define pk pop_back()
#define ff first
#define ss second
#define ts to_string
#define ub upper_bound
#define lb lower_bound
#define testcase int t;cin>>t;while(t--)
map<pair<char,char>,bool>check;
string a,b,c,d,posk;
void nav(int dir,string pos){
    if(dir==1)pos[0]++;
    if(dir==2)pos[0]--;
    if(dir==3)pos[1]++;
    if(dir==4)pos[1]--;
    if(pos[0]<'a' or pos[0]>'h' or pos[1]<'1' or pos[1]>'8' or pos==c)return;
    check[{pos[0],pos[1]}]=1;
    nav(dir,pos);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>a>>b>>c>>d;
    for(char i='1';i<='8';i++)
        for(char j='a';j<='h';j++)
            if(abs(i-'0'-(c[1]-'0'))<2 and abs(j-'a'-(c[0]-'a'))<2){
                check[{j,i}]=1;
            }
    rep(i,1,4,1){
        nav(i,a);nav(i,b);
    }
    for(char i='1';i<='8';i++)
        for(char j='a';j<='h';j++)
            if(abs(i-'0'-(d[1]-'0'))<2 and abs(j-'a'-(d[0]-'a'))<2){
                if(!check[{j,i}]){
                    print "OTHER";return 0;
                }
            }
    print "CHECKMATE";
}