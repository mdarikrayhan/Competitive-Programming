#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve() {
int n;
cin >> n;
vector<int> arr;
for(int i=0;i<n;i++){
    int temp;
    cin >> temp;
    arr.push_back(temp);
}
if(n%2==0){
    int min=INT_MAX;
    int a=0;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
            a=i;
        }
    }
    if(a%2){
        cout << "Mike" << endl;
    }
    else{
        cout << "Joe" << endl;
    }
}
else{
    cout<<"Mike"<<endl;
}
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int T = 1;
cin >> T;
while(T--) {
solve();
}
return 0;
}