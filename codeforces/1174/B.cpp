#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // Input
    int n;
    cin >> n;
    vector<int> a;
    int evensCount = 0;
    int oddsCount = 0;
    vector<int> evens, odds;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
        if(x % 2 == 0){
            evensCount++;
            evens.push_back(x);
        }else{
            oddsCount++;
            odds.push_back(x);
        }
    }
    
    // Problem solving
    // for i + j to be odd it has to be one odd one even
    if(evensCount && oddsCount) sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << ' ';
    }
    
    return 0;
}