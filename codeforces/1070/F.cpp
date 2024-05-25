#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    map<string, vector<int>> x;
    for(int i =0 ; i < n; i++){
        string h; cin >> h;
        int inf; cin >> inf;
        x[h].push_back(inf);
    }
    long long sum = 0;
    int s1 = min(x["10"].size(), x["01"].size());
    sort(x["10"].begin(), x["10"].end(), greater<int>());
    sort(x["01"].begin(), x["01"].end(), greater<int>());
    for(int i = 0; i < s1; i++){
        sum += x["10"][i];
        sum += x["01"][i];
    }
    sort(x["11"].begin(), x["11"].end(), greater<int>());
    for(int i = 0; i < x["11"].size(); i++){
        sum += x["11"][i];
    }
    if(x["01"].size() > s1){
        swap(x["01"], x["10"]);
    }
    for(int i = s1; i < x["10"].size(); i++){
        x["00"].push_back(x["10"][i]);
    }
    sort(x["00"].begin(), x["00"].end(), greater<int>());
    for(int i =0 ; i < min(x["11"].size(), x["00"].size()); i++){
        sum += x["00"][i];
    }
    cout << sum << "\n";
    return 0;
}
