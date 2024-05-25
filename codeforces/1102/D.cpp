#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
constexpr ll mod = 1e9+7;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> nums(3,0);
    for(auto c : s)
        ++nums[c-'0'];
    int k = n/3;
    int i=0;
    while(nums[0]<k){
        if(nums[s[i]-'0']>k){
            --nums[s[i]-'0'];
            ++nums[0];
            s[i]='0';
        }
        ++i;
    }
    i=n-1;
    while(nums[2]<k){
        if(nums[s[i]-'0']>k){
            --nums[s[i]-'0'];
            ++nums[2];
            s[i]='2';
        }
        --i;
    }
    i=0;
    while(nums[1]<k && i<n){
        if(nums[s[i]-'0']>k && s[i]-'0'>1){
            --nums[s[i]-'0'];
            ++nums[1];
            s[i]='1';
        }
        ++i;
    }
    i=n-1;
    while(nums[1]<k && i>=0){
        if(nums[s[i]-'0']>k && s[i]-'0'<1){
            --nums[s[i]-'0'];
            ++nums[1];
            s[i]='1';
        }
        --i;
    }
    cout << s << endl;
}
 		     	       		    	