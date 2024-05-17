#include <bits/stdc++.h>

using namespace std;
#define fast cin.tie(0); cin.sync_with_stdio(0);
#define ll long long
//
int main(){
	fast;
    int n, m, cnt=0;
    char c;
    set<pair<int, int>> s;
    set<char> results;
    cin >> n >> m >> c;
    char arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x;
            cin >> x;
            arr[i][j]=x;
            if(x == c){
                pair<int, int> obj;
                obj.first = i; obj.second = j;
                s.insert(obj);
            }
        }
    }
    for(auto b = s.begin(), e=s.end();b!=e;b= next(b)){
        if(b->first > 0 && arr[b->first -1][b->second] != '.' && arr[b->first -1][b->second] != c){
            results.insert(arr[b->first -1][b->second]);
        }
        if(b->first < n-1 && arr[b->first+1][b->second] != '.' && arr[b->first +1][b->second] != c){
            results.insert(arr[b->first+1][b->second]);
        }
        if(b->second > 0 && arr[b->first][b->second-1] != '.' && arr[b->first][b->second-1] != c){
            results.insert(arr[b->first][b->second-1]);
        }
        if(b->second < m-1 && arr[b->first][b->second+1] != '.' && arr[b->first][b->second+1] != c){
            results.insert(arr[b->first][b->second+1]);
        }
    }
    cout << results.size();
    return 0;
}