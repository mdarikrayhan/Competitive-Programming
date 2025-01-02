#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> a( maxn ), b( maxn ), c( maxn ), posA(3*maxn, maxn), posB(3*maxn, maxn), posC(3*maxn, maxn);
int cont, limB, limC;
set<pair<int, int>> pareto;
multiset<int> s;
map<int, int> conv;
int converte( int n ){ return (( conv[n] ) ? conv[n] : conv[n] = ++cont ); }

void insere( int x ){
  if( posB[x] == maxn || posC[x] == maxn ) return;
  // cout << "X: " << x << endl;
  auto it = pareto.lower_bound({posC[x], posB[x]});
  if( it->second > posB[x] ) return;
  while( prev(it)->second < posB[x] ){
    s.erase(s.find(prev(it)->first + it->second));
    // cout << "REMOVE: " << prev(it)->first + it->second << endl;
    s.erase(s.find(prev(prev(it))->first + prev(it)->second));
    // cout << "REMOVE: " << prev(prev(it))->first + prev(it)->second << endl;
    s.insert(prev(prev(it))->first + it->second);
    // cout << "INSERE: " << prev(prev(it))->first + it->second << endl;
    pareto.erase(prev(it));
    it = pareto.lower_bound({posC[x], posB[x]});
  }
  s.erase(s.find(prev(it)->first + it->second));
  // cout << "REMOVE: " << prev(it)->first + it->second << endl;
  s.insert(prev(it)->first + posB[x]);
  // cout << "INSERE: " << prev(it)->first + posB[x] << endl;
  s.insert(posC[x] + it->second);
  // cout << "INSERE: " << posC[x] + it->second << endl;
  pareto.insert({ posC[x], posB[x] });
}

int main(){
  int n; cin >> n;
  for( int i = 1; i <= n; i++ ){ cin >> a[i]; a[i] = converte(a[i]); posA[a[i]] = min( posA[a[i]], i ); }
  for( int i = 1; i <= n; i++ ){ cin >> b[i]; b[i] = converte(b[i]); posB[b[i]] = min( posB[b[i]], i ); }
  for( int i = 1; i <= n; i++ ){ cin >> c[i]; c[i] = converte(c[i]); posC[c[i]] = min( posC[c[i]], i ); }
  for( int i = 1; i <= n; i++ ){
    if( posA[b[i]] == maxn && posB[b[i]] == i && posC[b[i]] == maxn ) limB = i;
    if( posA[c[i]] == maxn && posB[c[i]] == maxn && posC[c[i]] == i ) limC = i;
  }
  pareto.insert({ maxn, limB });
  pareto.insert({ limC, maxn });
  s.insert(limC + limB);
  // cout << "INSERE: " << limC + limB << endl;
  for( int i = limB + 1; i <= n; i++ ) if( posA[b[i]] == maxn && posB[b[i]] == i && posC[b[i]] > limC ) insere(b[i]);

  int resp = n + *s.begin();
  for( int i = n; i > 0; i-- ){
    if( posA[a[i]] < i || posB[a[i]] <= limB || posC[a[i]] <= limC ){ resp = min( resp, i - 1 + *s.begin()); continue; }
    if( posB[a[i]] == maxn && posC[a[i]] == maxn ) break;
    if( posB[a[i]] < maxn && posC[a[i]] < maxn ) insere(a[i]);
    else if( posB[a[i]] < maxn ){
      auto it = prev(pareto.end());
      while( prev(it)->second <= posB[a[i]] ){
        s.erase(s.find(prev(it)->first + it->second));
        s.erase(s.find(prev(prev(it))->first + prev(it)->second));
        s.insert(prev(prev(it))->first + it->second);
        pareto.erase(prev(it));
        it = prev(pareto.end());
      }
      limB = posB[a[i]];
      s.erase(s.find(prev(it)->first + it->second));
      s.insert(prev(it)->first + limB);
      pareto.erase(it);
      pareto.insert({ maxn, limB });
    }
    else{
      auto it = pareto.upper_bound({limC, maxn});
      while( it->first <= posC[a[i]] ){
        it++;
        s.erase(s.find(prev(it)->first + it->second));
        s.erase(s.find(prev(prev(it))->first + prev(it)->second));
        s.insert(prev(prev(it))->first + it->second);
        pareto.erase(prev(it));
        it = pareto.upper_bound({limC, maxn});
      }
      limC = posC[a[i]];
      s.erase(s.find(prev(it)->first + it->second));
      s.insert(limC + it->second);
      pareto.erase(prev(it));
      pareto.insert({ limC, maxn });
    }
    resp = min( resp, i - 1 + *s.begin());
  }
  cout << resp << endl;
}
