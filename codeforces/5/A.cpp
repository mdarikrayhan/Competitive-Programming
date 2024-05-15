#include <bits/stdc++.h>
using ll = long long int;
using namespace std;

#define fi(l, r) for (ll i = l; i < r; i++)
#define fj(l, r) for (ll j = l; j < r; j++)
#define in(n) ll n; cin >> n
#define inarr(arr,n) for (ll i = 0; i < n; i++) { cin >> arr[i]; }


bool have_plus (string s){
    if(s[0] == '+'){
        return true;
    }
    return false;
}

bool have_minus (string s){
    if(s[0] == '-'){
        return true;
    }
    return false;
}

string msg(string s){
    string mes;
    ll index =0;
    while(s[index] != ':' ){
        index++;
    }
    index++;
    for(ll i=index;i<s.size();i++){
        mes.push_back(s[i]);
    }
    return mes;
}

void solve() {
    vector<string> seq;
    string line;


    while(getline(cin,line)){
        seq.push_back(line);
    }

    ll in_room =0;
    string mesg;
    ll l=0;
    for(ll i=0;i<seq.size();i++){
        if((have_plus(seq[i]))){
            in_room++;
        }
        else if((have_minus(seq[i]))){
            in_room--;
        }
        else{
            mesg = msg(seq[i]);
            l = l + (mesg.length()*in_room);
        }
    }

    cout<<l<<endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
        solve();
    
}