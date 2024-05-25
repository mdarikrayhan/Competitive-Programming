// Se importan librerías 
#include <bits/stdc++.h>
using namespace std;
 
// Se definen variables
long long answer = 0;
long long n;
long long m;
long long k;
const long long N = 1e5;
long long d[N];
long long a[N];
vector <vector <pair <long long, long long>>> vecc(N);
 
// Func. principal
int main() {
 
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        long long a , b , c;
        cin >> a >> b >> c;
        vecc[a].push_back({b, c});
        vecc[b].push_back({a, c});
    }
    
    for (int i = 0; i < k; ++i) {
        long long u, v;
        cin >> u >> v;
 
        if (a[u] == 0) {
            a[u] = v;
        }
        
        else {
            a[u] = min(a[u] , v);
            answer++;
        }
    }
 
    for(long long i = 2; i <= n; i++) {
        d[i] = 1e18;
    }
 
    set<pair<long long, long long> > sett;
    sett.insert({0, 1});
 
    while (sett.size() > 0) {
        long long v = (*sett.begin()).second;
        long long x = (*sett.begin()).first;
        sett.erase(sett.begin());
        if(a[v] > 0) {
            if(x > a[v])x = a[v];
            else a[v] = 0, answer ++;
        }
        for (auto j : vecc[v]) {
            long long jf = j.first;
            long long js = j.second;
            if (d[jf] > x + js) {
                sett.erase({d[jf] , jf});
                d[jf] = x + js;
                sett.insert({d[jf] , jf});
            }
        }
    }
 
    cout << answer << '\n';
}
 	    			 			   	  		  		 	 	