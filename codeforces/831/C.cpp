//Jury Marks
#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

int main() {
    
    int i, j, k, n, quotes = 0; //quotes -> possibilidades confirmadas
    ll point, mark, acum = 0; // acum -> usada para calculo das diferencas
    vector<ll> score_initial, score_partial;
    set<ll> diff; //arvore de busca para as diferencas (apos notas dos juizes) aplicadas ao score inicial
       
    cin >> k >> n;
    
    for (i=0; i<k; i++) {
        cin >> mark;
        acum += mark;
        diff.insert(acum);
    }
    quotes = diff.size();

    for (i=0; i<n; i++) {
        cin >> point;
        score_partial.push_back(point);
    }

    point = score_partial[0];
    for (ll elem: diff) score_initial.push_back(point-elem);
    
    for (i=0;i<score_initial.size();i++) {
        for (j=1;j<score_partial.size();j++) {
            if (diff.find(score_partial[j]-score_initial[i]) == diff.end()) {
                quotes--;
                break;
            }
        }
    }
    cout << quotes << "\n";
}
 	   		 		 	  			 		 		 		 			