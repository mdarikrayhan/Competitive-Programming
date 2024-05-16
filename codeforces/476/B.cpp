#include <bits/stdc++.h> 
using namespace std;

#define ll long long 



#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)

#define fi first
#define se second
#define mp make_pair
#define pb push_back

double fact(int n){
	double ans=1;
	while(n){
		ans*=n;
		n--;
	}
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
    t=1;//cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int count1=0,count2=0,q=0;
        int n=s1.size();
        for(int i=0;i<n;i++){
        	if(s1[i]=='+')count1++;
        	else count1--;
        }
        for(int i=0;i<n;i++){
        	if(s2[i]=='+')count2++;
        	else if(s2[i]=='-') count2--;
        	else q++;
        }
        int diff=count1-count2;
        if(abs(diff)>q||(diff+q)%2)cout<<(double)0.0<<endl;
        else {
        	if(diff==0){
        		if(q){
        		printf("%0.9lf",(fact(q)/(fact(q/2)*fact(q/2)))/pow(2,q));
        		}
        		else cout<<(double)1.0<<endl;
        	}
        	else{
        		printf("%.9lf",(fact(q)/(fact((q+diff)/2)*fact((q-diff)/2)))/pow(2,q));
        	}
        	
        }
        
    }
}