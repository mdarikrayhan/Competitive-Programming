// in the name of ALLAH

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
	      string s;
	            cin >> s;
				ll si=s.size();
				
				ll k;        cin>> k;
				map<char,int>m;
				for(int i=0 ; i<si ; i++){
					m[s[i]]++;
				}
				ll cnt=0;
				ll d=0;
				ll p=0;
				vector<pair<int,char>> v;
				for(auto u: m){
					v.pb({u.second,u.first});
				}
				p=0;d=0;
				
				sort(v.begin(),v.end());
				vector<char>ss;
			
				for(auto u: v){
					cnt+=u.first;
					if(cnt<=k){
						ss.pb(u.second);
					}
					
				}
				cout<<v.size()-ss.size()<<endl;
				for(int i=0 ; i<si ; i++){
					ll d=ss.size();
					bool ok=false;
					for(int j=0 ; j<d ; j++){
                       if(s[i]==ss[j]){
						   ok=true;
						   break;
					   }
					}
					if(ok==false)cout<<s[i];
				}			
}
