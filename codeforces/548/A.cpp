#include<bits/stdc++.h>
#define ll long long
#define  endl '/n'
using namespace std;

ll prefixXor[(3*100000)+1];

int binarytodecimal(string &s){
    int len=s.length();
    int sum=0;
    for(int i=len-1;i>=0;i--){
        int num=(s[i]-'0');
        sum+=(num*(1<<(len-i-1)));
    }
    return sum;
}

string decimaltobinary(int num){
    string res="";
    while(num>0){
        if(num%2==0)  res="0"+res;
        else  res="1"+res;
        num=num>>1;
    }
    return res;
}

void solve() {
    // Enter your code here.
    string s;
    cin>>s;
    int k;
    cin>>k;
    bool flag=false;
    int rem=(s.size())%k;
    if(s.size()<k) cout<<"NO";
    else if(s.size()==1 || s.size()==k) cout<<"YES";
    else if(rem!=0) cout<<"NO";
    else{
        int quo=(s.size()/k);
        for(int i=0;i<s.size();i=i+quo){
            string s1=s.substr(i,quo);
            string s2=s1;
            reverse(s1.begin(),s1.end());
            if(s1!=s2){
                flag=true;
                break;
            }
        }
        if(flag==true) cout<<"NO";
        else cout<<"YES";
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
        cout << '\n';
    }
    return 0;
}