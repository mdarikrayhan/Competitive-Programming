#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void f(ll a){
    for(ll i = 0;i < a;i++)cout << "|";
}

void Void(){
    ll a , b , c;
    string x;cin >> x;
    for(ll i = 0;i < x.size();i++){
        if(x[i] == '+'){
            for(ll j = i + 1;j < x.size();j++){
                if(x[j] == '='){
                    a = i;
                    b = j - i - 1;
                    c = x.size() - j - 1;
                    break;
                }
            }
            break;
        }
    }
    if(a + b < c){
        c--;
        a++;
    }
    else if(a + b > c){
        if(a > 1){
            a--;
        }
        else{
            b--;
        }
        c++;
    }
    if(a + b == c){
        f(a);cout << "+";f(b);cout<<"=";f(c);
    }
    else{
        cout << "Impossible\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t = 1;
    //cin >> t;
    while(t--)Void();
    return 0;
}
