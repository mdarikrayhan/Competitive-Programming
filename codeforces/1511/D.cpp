#include<iostream>
#include<vector>
using namespace std;

int n,k;
vector<char> a, ans;

int main(){
    cin>>n>>k;
    a.resize(k);
    for(int i=0; i<k; i++) a[i] = 'a'+i;
    while(ans.size() < n){
        for(int i=0; i<k; i++){
            ans.push_back('a'+i);
            for(int j=i+1; j<k; j++){
                ans.push_back('a'+i);
                ans.push_back('a'+j);
            }
        }
    }
    for(int i=0; i<n; i++) cout<<ans[i];
    cout<<endl;
}