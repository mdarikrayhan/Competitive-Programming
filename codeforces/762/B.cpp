#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    long long int sum = a+b+c;
    int m; cin >> m;
    vector<pair <int, char>> prices;
    int x; string s;
    for(int i =0; i<m ; ++i){
           cin >> x >> s;
            prices.push_back({x,s[0]});
    }

    sort(prices.begin(), prices.end());
    
    // for each prices if there is left then allocate else allocate it to the both connected or skip this mouse
      char beta;
      long long int total = 0;
      for(int i  = 0; i<m; ++i){
        beta = prices[i].second;

        if(beta == 'P')
        {
            if(b!=0){

             total +=prices[i].first;
             b--;
            }
            else if(c!=0){
                total += prices[i].first;
                c--;
            }
            else{
                continue;
            }
        }

        if(beta == 'U')
        {
            if(a!=0){

             total +=prices[i].first;
             a--;
            }
            else if(c!=0){
                total += prices[i].first;
                c--;
            }
            else{
                continue;
            }
        }

      }
    cout << sum - (a+b+c) << " " << total << "\n";

    return 0;
}