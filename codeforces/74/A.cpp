#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s[n];
    int x, y;
    pair<int, int>sum[n]={{0, 0}};
    for(int i=0; i<n; i++){
        cin >>s[i];
        cin >> x >> y;
        sum[i].second = i;
        sum[i].first = sum[i].first+x*100-y*50;
        for(int j=2; j<7; j++){
            cin >> x;
            sum[i].first = sum[i].first+x;
        }
    }
    pair<int,int>ans = *max_element(sum, sum+n);
    cout << s[ans.second];
}