#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MOD 1000000007 

void solve(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int>v(n);


    string rs;
    //reverse(rs.begin(), rs.end());

    int c1 = 2;
    int c2 = 1;
        stack<int>st1, st2;
    bool ct1 = false, ct2 = false;
    

        for(int i = 0;i < n;i++){
            if(s[i] == '('){
                if(!st2.empty()){
                    v[st2.top()] = c2;
                    //cout << i <<"*"<<st2.top();
                    v[i] = c2;
                    st2.pop();
                    ct1 = true;
                    
                }
                else 
                st1.push(i);
            }else if(s[i] == ')'){
                if(!st1.empty()){
                    v[st1.top()] = c1;
                    //cout << i <<"#"<<st1.top();
                    v[i] = c1;
                    st1.pop();
                    ct2 = true;
                }
                else {
                    st2.push(i);
                }
            }
            //cout << st1.size() <<"& "<<st2.size()<< endl;
        }

        

        if(!st1.empty() || !st2.empty()){
            cout << -1 << endl;return;
        }
        else if(ct1 && ct2){
            cout << 2 << endl;
            for(auto i : v)cout << i <<" ";
            cout << endl;
            
        }
        else{
            cout << 1 << endl;
            for(int i = 0;i < n;i++){
                cout << 1 <<" ";
            }
            cout << endl;
        } 
        

    

}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;

    for(int i = 1;i <= t;i++) {
        solve();
    }

    return 0;
}